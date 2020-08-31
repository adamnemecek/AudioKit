// Copyright AudioKit. All Rights Reserved. Revision History at http://github.com/AudioKit/AudioKit/

import AudioKit

class AKTableTests: AKTestCase {

    func testReverseSawtooth() {
        input = AKOscillator(waveform: AKTable(.reverseSawtooth))
        output = input
        AKTest()
    }

    func testSawtooth() {
        input = AKOscillator(waveform: AKTable(.sawtooth))
        output = input
        AKTest()
    }

    func testSine() {
        input = AKOscillator(waveform: AKTable(.sine))
        output = input
        // This is just the usual tested sine wave
        AKTestNoEffect()
    }

    func testTriangle() {
        input = AKOscillator(waveform: AKTable(.triangle))
        output = input
        AKTest()
    }

}
