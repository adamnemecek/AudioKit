//
//  AKSampleBuffer.hpp
//  ExtendingAudioKit
//
//  Created by Shane Dunne on 2018-02-21.
//  Copyright © 2018 Shane Dunne & Associates. All rights reserved.
//

#pragma once

// AKSampleBuffer represents an array of sample data, which can be addressed with a real-valued
// "index" via linear interpolation.

struct AKSampleBuffer
{
    float *pSamples;
    int nChannelCount;
    int nSampleCount;
    float fStart, fEnd;
    bool bLoop;
    float fLoopStart, fLoopEnd;
    float noteHz;
    
    AKSampleBuffer();
    ~AKSampleBuffer();
    
    void init(int nChannelCount, int sampleCount);
    void deinit();
    
    void setData(unsigned nIndex, float data);
    
    // Use double for the real-valued index, because oscillators will need the extra precision.
    inline float interp(double fIndex, float gain)
    {
        if (pSamples == 0 || nSampleCount == 0) return 0.0f;
        
        int ri = int(fIndex);
        double f = fIndex - ri;
        int rj = ri + 1;
        
        float si = ri < nSampleCount ? pSamples[ri] : 0.0f;
        float sj = rj < nSampleCount ? pSamples[rj] : 0.0f;
        return gain * ((1.0 - f) * si + f * sj);
    }
    
    inline void interp(double fIndex, float* pOutLeft, float* pOutRight, float gain)
    {
        if (pSamples == 0 || nSampleCount == 0)
        {
            *pOutLeft = *pOutRight = 0.0f;
            return;
        }
        if (nChannelCount == 1)
        {
            *pOutLeft = *pOutRight = interp(fIndex, gain);
            return;
        }
        
        int ri = int(fIndex);
        double f = fIndex - ri;
        int rj = ri + 1;
        
        float si = ri < nSampleCount ? pSamples[ri] : 0.0f;
        float sj = rj < nSampleCount ? pSamples[rj] : 0.0f;
        *pOutLeft = gain * ((1.0 - f) * si + f * sj);
        si = ri < nSampleCount ? pSamples[nSampleCount + ri] : 0.0f;
        sj = rj < nSampleCount ? pSamples[nSampleCount + rj] : 0.0f;
        *pOutRight = gain * ((1.0 - f) * si + f * sj);
    }
};

// AKMappedSampleBuffer is a derived version with added MIDI note-number and velocity ranges
struct AKMappedSampleBuffer : public AKSampleBuffer
{
    // Any of these members may be negative, meaning "no value assigned"
    int noteNumber;     // closest MIDI note-number to this sample's frequency (noteHz)
    int min_note, max_note;     // minimum and maximum note numbers for mapping
    int min_vel, max_vel;       // min/max MIDI velocities for mapping
};
