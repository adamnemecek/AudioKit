//
//  OCSCabasa.h
//  Objective-C Sound
//
//  Created by Aurelius Prochazka on 10/28/12.
//  Copyright (c) 2012 Hear For Yourself. All rights reserved.
//

#import "OCSAudio.h"
#import "OCSParameter+Operation.h"

/** Semi-physical model of a cabasa sound.
 
 This one of the PhISEM percussion opcodes. PhISEM (Physically Informed Stochastic Event Modeling) is an algorithmic approach for simulating collisions of multiple independent sound producing objects.
 */

@interface OCSCabasa : OCSAudio

/// Instantiates the cabasa
/// @param duration Period of time over which all sound is stopped.
/// @param amplitude Amplitude of output. As these instruments are stochastic this is only a approximation.
- (id)initWithDuration:(OCSConstant *)duration
             amplitude:(OCSConstant *)amplitude;


/// Set an optional count
/// @param count The number of beads, teeth, bells, timbrels, etc. The default value is 512.
- (void)setOptionalCount:(OCSConstant *)count;

/// Set an optional damping factor
/// @param dampingFactor The damping factor as part of this equation "damping = 0.998 + (dampingFactor * 0.002)" The default damping is 0.997 which means that the default value of dampingFactor is -0.5. The maximum damping is 1.0 (no damping). This means the maximum value for dampingFactor is 1.0.
- (void)setOptionalDampingFactor:(OCSConstant *)dampingFactor;

/// Set an optional energy return
/// @param energyReturn Amount of energy to add back into the system. The value should be in range 0 to 1.
- (void)setOptionalEnergyReturn:(OCSConstant *)energyReturn;


@end