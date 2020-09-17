// Copyright AudioKit. All Rights Reserved. Revision History at http://github.com/AudioKit/AudioKit/

#if !os(tvOS)
import Foundation
import CoreMIDI
import os.log

/// This MIDIListener looks for midi system real time (SRT)
/// midi system messages.
open class MIDISystemRealTimeListener: NSObject {
    enum SRTEvent: MIDIByte {
        case stop = 0xFC
        case start = 0xFA
        case `continue` = 0xFB
    }

    public enum SRTState {
        case stopped
        case playing
        case paused

        func event(event: SRTEvent) -> SRTState {
            switch self {
            case .stopped:
                switch event {
                case .start:
                    return .playing
                case .stop:
                    return .stopped
                case .continue:
                    return .playing
                }
            case .playing:
                switch event {
                case .start:
                    return .playing
                case .stop:
                    return .paused
                case .continue:
                    return .playing
                }
            case .paused:
                switch event {
                case .start:
                    return .playing
                case .stop:
                    return .stopped
                case .continue:
                    return .playing
                }
            }
        }
    }

    var state: SRTState = .stopped
    var observers: [MIDISystemRealTimeObserver] = []
}

extension MIDISystemRealTimeListener: MIDIListener {
    public func receivedMIDINoteOn(noteNumber: MIDINoteNumber, velocity: MIDIVelocity, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDINoteOff(noteNumber: MIDINoteNumber, velocity: MIDIVelocity, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDIController(_ controller: MIDIByte, value: MIDIByte, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDIAftertouch(noteNumber: MIDINoteNumber, pressure: MIDIByte, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDIAftertouch(_ pressure: MIDIByte, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDIPitchWheel(_ pitchWheelValue: MIDIWord, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDIProgramChange(_ program: MIDIByte, channel: MIDIChannel, portID: MIDIUniqueID?, offset: MIDITimeStamp) {
        // Do nothing
    }

    public func receivedMIDISystemCommand(_ data: [MIDIByte], portID: MIDIUniqueID?, offset: MIDITimeStamp) {
                if data[0] == MIDISystemCommand.stop.rawValue {
            Log("Incoming MMC [Stop]", log: OSLog.midi)
            let newState = state.event(event: .stop)
            state = newState

            sendStopToObservers()
        }
        if data[0] == MIDISystemCommand.start.rawValue {
            Log("Incoming MMC [Start]", log: OSLog.midi)
            let newState = state.event(event: .start)
            state = newState

            sendStartToObservers()
        }
        if data[0] == MIDISystemCommand.continue.rawValue {
            Log("Incoming MMC [Continue]", log: OSLog.midi)
            let newState = state.event(event: .continue)
            state = newState

            sendContinueToObservers()
        }
    }

    public func receivedMIDISetupChange() {
        // Do nothing
    }

    public func receivedMIDIPropertyChange(propertyChangeInfo: MIDIObjectPropertyChangeNotification) {
        // Do nothing
    }

    public func receivedMIDINotification(notification: MIDINotification) {
        // Do nothing
    }
}

extension MIDISystemRealTimeListener {
    public func addObserver(_ observer: MIDISystemRealTimeObserver) {
        observers.append(observer)
    }

    public func removeObserver(_ observer: MIDISystemRealTimeObserver) {
        observers.removeAll { $0 == observer }
    }

    public func removeAllObserver(_ observer: MIDISystemRealTimeObserver) {
        observers.removeAll()
    }

    func sendStopToObservers() {
        observers.forEach { (observer) in
            observer.stopSRT(listener: self)
        }
    }

    func sendStartToObservers() {
        observers.forEach { (observer) in
            observer.startSRT(listener: self)
        }
    }

    func sendContinueToObservers() {
        observers.forEach { (observer) in
            observer.continueSRT(listener: self)
        }
    }
}

#endif
