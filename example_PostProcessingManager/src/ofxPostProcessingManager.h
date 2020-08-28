#pragma once

#include "ofMain.h"
#include "ofxPostProcessing.h"
#include "ofxGui.h"

class ofxPostProcessingManager{

public:
    
    void setup(int w, int h);
    
    void updateValues();
    
    void drawGui(int x, int y);
    void setupGui();
    
    void begin();
    void begin(ofCamera& cam);
    
    void end();
    
    void windowResized(int w, int h);
private:
    
    void reInit();
    
    ofxPostProcessing post;
    
    DofPass::Ptr dof;
    GodRaysPass::Ptr godRays;
    LimbDarkeningPass::Ptr limbDarkening;
    SSAOPass::Ptr ssao;
    ZoomBlurPass::Ptr zoomBlur;
    KaleidoscopePass::Ptr kaleidoscope;
    RGBShiftPass::Ptr rgbPass;
    BloomPass::Ptr bloomPass;
    FilmGrainLinesPass::Ptr filmGrainLinesPass;
    DotScreenPass::Ptr dotScreenPass;
    DigitalGlitchPass::Ptr glitchPass;
    FirePass::Ptr lavaFire;
    BadTVPass::Ptr badTv;
    ACESFilmicToneMappingPass::Ptr colorACES;
    NoisePass::Ptr noiseGrain;
    TiltShiftPass::Ptr tiltShift;
    SuperPass::Ptr superShader;
    GlitchAutomatedPass::Ptr glitchAuto;
    SpaceColorMovePass::Ptr spaceColor;
    DitherPass::Ptr dither;
    
    //gui------------------------------------------
    
    ofxPanel gui;
    ofxToggle gDebugDraw;
    
    ofxToggle gDoFxaa;
    ofxToggle gDoBloom;
    ofxToggle gDoDof;
    ofxToggle gDoKaleidoscope;
    ofxToggle gDoNoiseWarp;
    ofxToggle gDoPixelate;
    ofxToggle gDoEdgePass;
    ofxToggle gDoVerticalTiltShift;
    ofxToggle gDoGodRays;
    ofxToggle gDoLimbDarkening;
    ofxToggle gDoSsao;
    ofxToggle gZoomBlur;
    ofxToggle gVerticalShift;
    ofxToggle gHorizontalShift;
    ofxToggle gRGBShiftPass;
    ofxToggle gFilmGrainLines;
    ofxToggle gDotScreen;
    ofxToggle gGlitch;
    ofxToggle gLavaFire;
    ofxToggle gBadTv;
    ofxToggle gcolorACES;
    ofxToggle gNoise;
    
    
    // BLOOM
    ofParameterGroup gBloomGroup;
    ofxFloatSlider gBloomBlurX, gBloomBlurY;
    
    // DOF
    ofParameterGroup gDofApertureGroup;
    ofxFloatSlider gDofAperture, gDofMaxBlur, gDofFocus;
    
    // GODRAYS
    ofParameterGroup gGodRaysGroup;
    ofxFloatSlider gGodRaysLightDotView;
    ofxVec3Slider gLightPositionOnScreen;
    
    // SSAO
    ofParameterGroup gSsaoGroup;
    ofxFloatSlider gSsaoAoClamp, gSsaoLumInfluence;
    
    // ZOOM BLUR
    ofParameterGroup gZoomBlurGroup;
    ofxVec2Slider gZoomCenterXY;
    ofxFloatSlider gZoomClamp, gZoomDecay, gZoomWeight, gZoomDensity, gZoomExposure;
    
    // KALEIDOSCOPE
    ofParameterGroup gKaliGroup;
    ofxFloatSlider gKaleiSegments;
    
    // RGB SHIFT PASS
    ofParameterGroup gRGBGroup;
    ofxFloatSlider gRGBAmount, gRGBAngle;
    
    // FILM GRAIN
    ofParameterGroup gFilmGrainGroup;
    ofxFloatSlider gFilmGrainLnIntensity,gFilmGrainLsIntensity, gFilmGrainLCount;
    ofxToggle gFilmGrainLGrayScale;
    
    // DOT SCREEN
    ofParameterGroup gDotScreenGroup;
    ofxFloatSlider gDotScrAngle, gDotScrScale;
    ofxVec2Slider gDotScrSize, gDotScrCenter;
    
    // GLITCH
    ofParameterGroup gGlicthGroup;
    ofxFloatSlider gGlitchAmount, gGlitchAngle, gGlitchSeed, gGlitchSeedX, gGlitchSeedY, gGlitchDistX, gGlitchDistY, gGlitchCol;
    ofxToggle gGlitchByp;
    
    // LAVA FIRE
    
    
    // BAD TV PASS
    ofParameterGroup gBadTVGroup;
    ofxFloatSlider gBadTvDist,gBadTvDist2,gBadTvSpeed,gBadTvRoll;
    
    // colorACES
    ofParameterGroup gcolorACESGroup;
    ofxFloatSlider gcolorACESExp;
    
    // Noise Grain
    ofParameterGroup gNoiseGroup;
    ofxFloatSlider gNoiseSpeed, gNoiseAmt;
    
    // TiltShift
    ofParameterGroup gTiltShiftGroup;
    ofxToggle gTiltShift;
    ofxFloatSlider gTiltFocus, gTitltRange, gTiltOffset, gTiltStrength;
    
    // SuperShader
    ofxToggle gSup;
    ofParameterGroup gSupGroup;
    ofxFloatSlider gSupGlowAmt, gSupGlowSize, gSupVigOff, gSupVigDark, gSupBri, gSupCont, gSupSat, gRGBShfAmt;
    
    // Glitch Automated
    ofxToggle gGlitchAuto;
    ofParameterGroup gGliAutoGroup;
    ofxFloatSlider gGliAutoSpeed,gGliAutoAmt;
    
    // Space Color
    ofxToggle gSpaceColor;
    ofParameterGroup gSpaceColorGroup;
    ofxFloatSlider gSpaceColorSpeed, gSpaceColorOpacity;
    
    // Dither
    ofxToggle gDither;
    ofParameterGroup gDitherGroup;
    ofxFloatSlider gDitherScale;
    
};
