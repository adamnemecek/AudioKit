// Copyright AudioKit. All Rights Reserved. Revision History at http://github.com/AudioKit/AudioKit/

import AudioKit
import XCTest

class StringResonatorTests: XCTestCase {

    func testDefault() {
        let engine = AKEngine()
        let input = Oscillator()
        engine.output = AKOperationEffect(input) { $0.stringResonator() }
        input.start()
        let audio = engine.startTest(totalDuration: 1.0)
        audio.append(engine.render(duration: 1.0))
        testMD5(audio)
    }

}
