// Copyright AudioKit. All Rights Reserved. Revision History at http://github.com/AudioKit/AudioKit/

#pragma once

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#if !TARGET_OS_TV
#import <CoreAudioKit/CoreAudioKit.h>
#endif

//! Project version number for AudioKit.
FOUNDATION_EXPORT double AudioKitVersionNumber;

//! Project version string for AudioKit.
FOUNDATION_EXPORT const unsigned char AudioKitVersionString[];

#import <AudioKit/AKDSPBase.hpp>
#import <AudioKit/AKSoundpipeDSPBase.hpp>

#import <AudioKit/DSPKernel.hpp>
#import <AudioKit/ExceptionCatcher.h>
#import <AudioKit/AKGlobals.hpp>

#import <AudioKit/AKParameterRamp.hpp>

// Testing
#import <AudioKit/md5.h>
#import <AudioKit/DebugDSP.h>

// Analysis
#import <AudioKit/AKAmplitudeTrackerAudioUnit.h>
#import <AudioKit/AKFrequencyTrackerAudioUnit.h>
#if !TARGET_OS_TV
#import <AudioKit/AKMicrophoneTrackerEngine.h>
#endif

// Sporth
#import <AudioKit/AKOperationGeneratorAudioUnit.h>
#import <AudioKit/AKOperationEffectAudioUnit.h>
#import <AudioKit/AKSporthStack.h>

// Effects / Modulation
#import <AudioKit/AKModulatedDelay_Typedefs.h>
#import <AudioKit/AKModulatedDelay.hpp>
#import <AudioKit/AKModulatedDelayDSP.hpp>

// Generators / Polysynths
#import <AudioKit/AKFMOscillatorBankAudioUnit.h>
#import <AudioKit/AKMorphingOscillatorBankAudioUnit.h>
#import <AudioKit/AKOscillatorBankAudioUnit.h>
#import <AudioKit/AKPhaseDistortionOscillatorBankAudioUnit.h>
#import <AudioKit/AKPWMOscillatorBankAudioUnit.h>
#import <AudioKit/AKSynthDSP.hpp>

// Generators / Filter Polysynths
#import <AudioKit/AKFMOscillatorFilterSynthAudioUnit.h>
#import <AudioKit/AKMorphingOscillatorFilterSynthAudioUnit.h>
#import <AudioKit/AKOscillatorFilterSynthAudioUnit.h>
#import <AudioKit/AKPhaseDistortionOscillatorFilterSynthAudioUnit.h>
#import <AudioKit/AKPWMOscillatorFilterSynthAudioUnit.h>

// Playback
#import <AudioKit/AKWaveTableAudioUnit.h>
#import <AudioKit/AKDiskStreamerAudioUnit.h>
#import <AudioKit/AKPresetManager.h>
#import <AudioKit/AKSampler_Typedefs.h>
#import <AudioKit/AKCoreSampler.hpp>
#import <AudioKit/AKCoreSynth.hpp>
#import <AudioKit/AKSamplerDSP.hpp>

#if !TARGET_OS_TV
#import <AudioKit/AKCallbackInstrumentAudioUnit.h>
#endif

// EZAudio
#import <AudioKit/EZAudio.h>

// Taps
#import <AudioKit/AKRenderTap.h>
#import <AudioKit/AKLazyTap.h>
#import <AudioKit/AKTimelineTap.h>

// Utilities
#import <AudioKit/ParameterRamper.hpp>
#import <AudioKit/AKTimeline.h>

// Sequencer
#import <AudioKit/AKSamplerMetronome.h>
#if !TARGET_OS_TV
#import <AudioKit/AKSequencerEngine.hpp>
#endif

// Automation
#import <AudioKit/AKParameterAutomation.hpp>
#import <AudioKit/AKLinearParameterRamp.hpp>

// Swift/ObjC/C/C++ Inter-operability
#import <AudioKit/AKInterop.h>

// Custom interop
AK_API void akCombFilterReverbSetLoopDuration(AKDSPRef dsp, float duration);
AK_API void akConvolutionSetPartitionLength(AKDSPRef dsp, int length);
AK_API void akFlatFrequencyResponseSetLoopDuration(AKDSPRef dsp, float duration);
AK_API void akVariableDelaySetMaximumTime(AKDSPRef dsp, float maximumTime);

// Custom debug
#define AKPhaseDistortionOscillatorDebugPhase 0
#define AKOscillatorDebugPhase 0

// Autogenerated creates
AK_API AKDSPRef akAmplitudeEnvelopeCreateDSP(void);
AK_API AKDSPRef akAutoPannerCreateDSP(void);
AK_API AKDSPRef akAutoWahCreateDSP(void);
AK_API AKDSPRef akBalancerCreateDSP(void);
AK_API AKDSPRef akBandPassButterworthFilterCreateDSP(void);
AK_API AKDSPRef akBandRejectButterworthFilterCreateDSP(void);
AK_API AKDSPRef akBitCrusherCreateDSP(void);
AK_API AKDSPRef akBoosterCreateDSP(void);
AK_API AKDSPRef akBrownianNoiseCreateDSP(void);
AK_API AKDSPRef akChowningReverbCreateDSP(void);
AK_API AKDSPRef akClipperCreateDSP(void);
AK_API AKDSPRef akCombFilterReverbCreateDSP(void);
AK_API AKDSPRef akConvolutionCreateDSP(void);
AK_API AKDSPRef akCostelloReverbCreateDSP(void);
AK_API AKDSPRef akDCBlockCreateDSP(void);
AK_API AKDSPRef akDripCreateDSP(void);
AK_API AKDSPRef akDynamicRangeCompressorCreateDSP(void);
AK_API AKDSPRef akEqualizerFilterCreateDSP(void);
AK_API AKDSPRef akFaderCreateDSP(void);
AK_API AKDSPRef akFlatFrequencyResponseReverbCreateDSP(void);
AK_API AKDSPRef akFMOscillatorCreateDSP(void);
AK_API AKDSPRef akFormantFilterCreateDSP(void);
AK_API AKDSPRef akHighPassButterworthFilterCreateDSP(void);
AK_API AKDSPRef akHighShelfParametricEqualizerFilterCreateDSP(void);
AK_API AKDSPRef akKorgLowPassFilterCreateDSP(void);
AK_API AKDSPRef akLowPassButterworthFilterCreateDSP(void);
AK_API AKDSPRef akLowShelfParametricEqualizerFilterCreateDSP(void);
AK_API AKDSPRef akMetalBarCreateDSP(void);
AK_API AKDSPRef akModalResonanceFilterCreateDSP(void);
AK_API AKDSPRef akMoogLadderCreateDSP(void);
AK_API AKDSPRef akMorphingOscillatorCreateDSP(void);
AK_API AKDSPRef akOscillatorCreateDSP(void);
AK_API AKDSPRef akPannerCreateDSP(void);
AK_API AKDSPRef akPeakingParametricEqualizerFilterCreateDSP(void);
AK_API AKDSPRef akPhaseDistortionOscillatorCreateDSP(void);
AK_API AKDSPRef akPhaseLockedVocoderCreateDSP(void);
AK_API AKDSPRef akPhaserCreateDSP(void);
AK_API AKDSPRef akPinkNoiseCreateDSP(void);
AK_API AKDSPRef akPitchShifterCreateDSP(void);
AK_API AKDSPRef akPluckedStringCreateDSP(void);
AK_API AKDSPRef akPWMOscillatorCreateDSP(void);
AK_API AKDSPRef akResonantFilterCreateDSP(void);
AK_API AKDSPRef createRolandTB303FilterDSP(void);
AK_API AKDSPRef akStereoDelayCreateDSP(void);
AK_API AKDSPRef akStereoFieldLimiterCreateDSP(void);
AK_API AKDSPRef akStringResonatorCreateDSP(void);
AK_API AKDSPRef akTanhDistortionCreateDSP(void);
AK_API AKDSPRef akThreePoleLowpassFilterCreateDSP(void);
AK_API AKDSPRef akToneComplementFilterCreateDSP(void);
AK_API AKDSPRef akToneFilterCreateDSP(void);
AK_API AKDSPRef akTremoloCreateDSP(void);
AK_API AKDSPRef akVariableDelayCreateDSP(void);
AK_API AKDSPRef akVocalTractCreateDSP(void);
AK_API AKDSPRef akWhiteNoiseCreateDSP(void);
AK_API AKDSPRef akZitaReverbCreateDSP(void);

// Autogenerated parameters

typedef NS_ENUM(AUParameterAddress, AKAmplitudeEnvelopeParameter) {
    AKAmplitudeEnvelopeParameterAttackDuration,
    AKAmplitudeEnvelopeParameterDecayDuration,
    AKAmplitudeEnvelopeParameterSustainLevel,
    AKAmplitudeEnvelopeParameterReleaseDuration,
};

typedef NS_ENUM(AUParameterAddress, AKAutoPannerParameter) {
    AKAutoPannerParameterFrequency,
    AKAutoPannerParameterDepth,
};

typedef NS_ENUM(AUParameterAddress, AKAutoWahParameter) {
    AKAutoWahParameterWah,
    AKAutoWahParameterMix,
    AKAutoWahParameterAmplitude,
};


typedef NS_ENUM(AUParameterAddress, AKBandPassButterworthFilterParameter) {
    AKBandPassButterworthFilterParameterCenterFrequency,
    AKBandPassButterworthFilterParameterBandwidth,
};

typedef NS_ENUM(AUParameterAddress, AKBandRejectButterworthFilterParameter) {
    AKBandRejectButterworthFilterParameterCenterFrequency,
    AKBandRejectButterworthFilterParameterBandwidth,
};

typedef NS_ENUM(AUParameterAddress, AKBitCrusherParameter) {
    AKBitCrusherParameterBitDepth,
    AKBitCrusherParameterSampleRate,
};

typedef NS_ENUM (AUParameterAddress, AKBoosterParameter) {
    AKBoosterParameterLeftGain,
    AKBoosterParameterRightGain
};

typedef NS_ENUM(AUParameterAddress, AKBrownianNoiseParameter) {
    AKBrownianNoiseParameterAmplitude,
};

typedef NS_ENUM(AUParameterAddress, AKClipperParameter) {
    AKClipperParameterLimit,
};

typedef NS_ENUM(AUParameterAddress, AKCombFilterReverbParameter) {
    AKCombFilterReverbParameterReverbDuration,
};

typedef NS_ENUM(AUParameterAddress, AKCostelloReverbParameter) {
    AKCostelloReverbParameterFeedback,
    AKCostelloReverbParameterCutoffFrequency,
};

typedef NS_ENUM(AUParameterAddress, AKDripParameter) {
    AKDripParameterIntensity,
    AKDripParameterDampingFactor,
    AKDripParameterEnergyReturn,
    AKDripParameterMainResonantFrequency,
    AKDripParameterFirstResonantFrequency,
    AKDripParameterSecondResonantFrequency,
    AKDripParameterAmplitude,
};

typedef NS_ENUM(AUParameterAddress, AKDynamicRangeCompressorParameter) {
    AKDynamicRangeCompressorParameterRatio,
    AKDynamicRangeCompressorParameterThreshold,
    AKDynamicRangeCompressorParameterAttackDuration,
    AKDynamicRangeCompressorParameterReleaseDuration,
};

typedef NS_ENUM(AUParameterAddress, AKEqualizerFilterParameter) {
    AKEqualizerFilterParameterCenterFrequency,
    AKEqualizerFilterParameterBandwidth,
    AKEqualizerFilterParameterGain,
};

typedef NS_ENUM (AUParameterAddress, AKFaderParameter) {
    AKFaderParameterLeftGain,
    AKFaderParameterRightGain,
    AKFaderParameterFlipStereo,
    AKFaderParameterMixToMono
};

typedef NS_ENUM(AUParameterAddress, AKFlatFrequencyResponseReverbParameter) {
    AKFlatFrequencyResponseReverbParameterReverbDuration,
};

typedef NS_ENUM(AUParameterAddress, AKFMOscillatorParameter) {
    AKFMOscillatorParameterBaseFrequency,
    AKFMOscillatorParameterCarrierMultiplier,
    AKFMOscillatorParameterModulatingMultiplier,
    AKFMOscillatorParameterModulationIndex,
    AKFMOscillatorParameterAmplitude,
};

typedef NS_ENUM(AUParameterAddress, AKFormantFilterParameter) {
    AKFormantFilterParameterCenterFrequency,
    AKFormantFilterParameterAttackDuration,
    AKFormantFilterParameterDecayDuration,
};

typedef NS_ENUM(AUParameterAddress, AKHighPassButterworthFilterParameter) {
    AKHighPassButterworthFilterParameterCutoffFrequency,
};

typedef NS_ENUM(AUParameterAddress, AKHighShelfParametricEqualizerFilterParameter) {
    AKHighShelfParametricEqualizerFilterParameterCenterFrequency,
    AKHighShelfParametricEqualizerFilterParameterGain,
    AKHighShelfParametricEqualizerFilterParameterQ,
};

typedef NS_ENUM(AUParameterAddress, AKKorgLowPassFilterParameter) {
    AKKorgLowPassFilterParameterCutoffFrequency,
    AKKorgLowPassFilterParameterResonance,
    AKKorgLowPassFilterParameterSaturation,
};

typedef NS_ENUM(AUParameterAddress, AKLowPassButterworthFilterParameter) {
    AKLowPassButterworthFilterParameterCutoffFrequency,
};

typedef NS_ENUM(AUParameterAddress, AKLowShelfParametricEqualizerFilterParameter) {
    AKLowShelfParametricEqualizerFilterParameterCornerFrequency,
    AKLowShelfParametricEqualizerFilterParameterGain,
    AKLowShelfParametricEqualizerFilterParameterQ,
};

typedef NS_ENUM(AUParameterAddress, AKMetalBarParameter) {
    AKMetalBarParameterLeftBoundaryCondition,
    AKMetalBarParameterRightBoundaryCondition,
    AKMetalBarParameterDecayDuration,
    AKMetalBarParameterScanSpeed,
    AKMetalBarParameterPosition,
    AKMetalBarParameterStrikeVelocity,
    AKMetalBarParameterStrikeWidth,
};

typedef NS_ENUM(AUParameterAddress, AKModalResonanceFilterParameter) {
    AKModalResonanceFilterParameterFrequency,
    AKModalResonanceFilterParameterQualityFactor,
};

typedef NS_ENUM(AUParameterAddress, AKMoogLadderParameter) {
    AKMoogLadderParameterCutoffFrequency,
    AKMoogLadderParameterResonance,
};

typedef NS_ENUM(AUParameterAddress, AKMorphingOscillatorParameter) {
    AKMorphingOscillatorParameterFrequency,
    AKMorphingOscillatorParameterAmplitude,
    AKMorphingOscillatorParameterIndex,
    AKMorphingOscillatorParameterDetuningOffset,
    AKMorphingOscillatorParameterDetuningMultiplier,
};

typedef NS_ENUM(AUParameterAddress, AKOscillatorParameter) {
    AKOscillatorParameterFrequency,
    AKOscillatorParameterAmplitude,
    AKOscillatorParameterDetuningOffset,
    AKOscillatorParameterDetuningMultiplier,
};

typedef NS_ENUM(AUParameterAddress, AKPannerParameter) {
    AKPannerParameterPan,
};

typedef NS_ENUM(AUParameterAddress, AKPeakingParametricEqualizerFilterParameter) {
    AKPeakingParametricEqualizerFilterParameterCenterFrequency,
    AKPeakingParametricEqualizerFilterParameterGain,
    AKPeakingParametricEqualizerFilterParameterQ,
};

typedef NS_ENUM(AUParameterAddress, AKPhaseDistortionOscillatorParameter) {
    AKPhaseDistortionOscillatorParameterFrequency,
    AKPhaseDistortionOscillatorParameterAmplitude,
    AKPhaseDistortionOscillatorParameterPhaseDistortion,
    AKPhaseDistortionOscillatorParameterDetuningOffset,
    AKPhaseDistortionOscillatorParameterDetuningMultiplier,
};

typedef NS_ENUM(AUParameterAddress, AKPhaseLockedVocoderParameter) {
    AKPhaseLockedVocoderParameterPosition,
    AKPhaseLockedVocoderParameterAmplitude,
    AKPhaseLockedVocoderParameterPitchRatio,
};

typedef NS_ENUM(AUParameterAddress, AKPhaserParameter) {
    AKPhaserParameterNotchMinimumFrequency,
    AKPhaserParameterNotchMaximumFrequency,
    AKPhaserParameterNotchWidth,
    AKPhaserParameterNotchFrequency,
    AKPhaserParameterVibratoMode,
    AKPhaserParameterDepth,
    AKPhaserParameterFeedback,
    AKPhaserParameterInverted,
    AKPhaserParameterLfoBPM,
};

typedef NS_ENUM(AUParameterAddress, AKPinkNoiseParameter) {
    AKPinkNoiseParameterAmplitude,
};

typedef NS_ENUM(AUParameterAddress, AKPitchShifterParameter) {
    AKPitchShifterParameterShift,
    AKPitchShifterParameterWindowSize,
    AKPitchShifterParameterCrossfade,
};

typedef NS_ENUM(AUParameterAddress, AKPluckedStringParameter) {
    AKPluckedStringParameterFrequency,
    AKPluckedStringParameterAmplitude,
};

typedef NS_ENUM(AUParameterAddress, AKPWMOscillatorParameter) {
    AKPWMOscillatorParameterFrequency,
    AKPWMOscillatorParameterAmplitude,
    AKPWMOscillatorParameterPulseWidth,
    AKPWMOscillatorParameterDetuningOffset,
    AKPWMOscillatorParameterDetuningMultiplier,
};

typedef NS_ENUM(AUParameterAddress, AKResonantFilterParameter) {
    AKResonantFilterParameterFrequency,
    AKResonantFilterParameterBandwidth,
};

typedef NS_ENUM(AUParameterAddress, AKRolandTB303FilterParameter) {
    AKRolandTB303FilterParameterCutoffFrequency,
    AKRolandTB303FilterParameterResonance,
    AKRolandTB303FilterParameterDistortion,
    AKRolandTB303FilterParameterResonanceAsymmetry,
};

typedef NS_ENUM(AUParameterAddress, AKStereoDelayParameter) {
    AKStereoDelayParameterTime,
    AKStereoDelayParameterFeedback,
    AKStereoDelayParameterDryWetMix,
    AKStereoDelayParameterPingPong,
};

typedef NS_ENUM(AUParameterAddress, AKStereoFieldLimiterParameter) {
    AKStereoFieldLimiterParameterAmount,
};

typedef NS_ENUM(AUParameterAddress, AKStringResonatorParameter) {
    AKStringResonatorParameterFundamentalFrequency,
    AKStringResonatorParameterFeedback,
};

typedef NS_ENUM(AUParameterAddress, AKTanhDistortionParameter) {
    AKTanhDistortionParameterPregain,
    AKTanhDistortionParameterPostgain,
    AKTanhDistortionParameterPositiveShapeParameter,
    AKTanhDistortionParameterNegativeShapeParameter,
};

typedef NS_ENUM(AUParameterAddress, AKThreePoleLowpassFilterParameter) {
    AKThreePoleLowpassFilterParameterDistortion,
    AKThreePoleLowpassFilterParameterCutoffFrequency,
    AKThreePoleLowpassFilterParameterResonance,
};

typedef NS_ENUM(AUParameterAddress, AKToneComplementFilterParameter) {
    AKToneComplementFilterParameterHalfPowerPoint,
};

typedef NS_ENUM(AUParameterAddress, AKToneFilterParameter) {
    AKToneFilterParameterHalfPowerPoint,
};

typedef NS_ENUM(AUParameterAddress, AKTremoloParameter) {
    AKTremoloParameterFrequency,
    AKTremoloParameterDepth,
};

typedef NS_ENUM(AUParameterAddress, AKVariableDelayParameter) {
    AKVariableDelayParameterTime,
    AKVariableDelayParameterFeedback,
};

typedef NS_ENUM(AUParameterAddress, AKVocalTractParameter) {
    AKVocalTractParameterFrequency,
    AKVocalTractParameterTonguePosition,
    AKVocalTractParameterTongueDiameter,
    AKVocalTractParameterTenseness,
    AKVocalTractParameterNasality,
};

typedef NS_ENUM(AUParameterAddress, AKWhiteNoiseParameter) {
    AKWhiteNoiseParameterAmplitude,
};

typedef NS_ENUM(AUParameterAddress, AKZitaReverbParameter) {
    AKZitaReverbParameterPredelay,
    AKZitaReverbParameterCrossoverFrequency,
    AKZitaReverbParameterLowReleaseTime,
    AKZitaReverbParameterMidReleaseTime,
    AKZitaReverbParameterDampingFrequency,
    AKZitaReverbParameterEqualizerFrequency1,
    AKZitaReverbParameterEqualizerLevel1,
    AKZitaReverbParameterEqualizerFrequency2,
    AKZitaReverbParameterEqualizerLevel2,
    AKZitaReverbParameterDryWetMix,
};
