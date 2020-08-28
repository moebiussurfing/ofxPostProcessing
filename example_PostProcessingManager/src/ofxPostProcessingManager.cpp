
#include "ofxPostProcessingManager.h"

//TODO: add more efects and parameters
//TODO: add gui listener for update, not update everyframe


//---------------------------------------
void ofxPostProcessingManager::setup(int w, int h){
    
    post.init(w, h);
    
    reInit();
    
    //---------
    setupGui();
}

void ofxPostProcessingManager::reInit() {
    //0-Fxaa
    post.createPass<FxaaPass>()->setEnabled(false);
    //1-Bloom
    bloomPass = post.createPass<BloomPass>();
    //2-dof
    dof = post.createPass<DofPass>();
    //3-Kaleidoscope
    kaleidoscope = post.createPass<KaleidoscopePass>();
    //4-Noisewarp
    post.createPass<NoiseWarpPass>()->setEnabled(false);
    //5-Pixelate
    post.createPass<PixelatePass>()->setEnabled(false);
    //6-EdgePass
    post.createPass<EdgePass>()->setEnabled(false);
    //7-VerticalTilt
    post.createPass<VerticalTiltShifPass>()->setEnabled(false);
    //8-GodRays
    godRays = post.createPass<GodRaysPass>();
    //9-LimbDarkening
    limbDarkening=post.createPass<LimbDarkeningPass>();
    //10-Ssao
    ssao=post.createPass<SSAOPass>();
    //11-ZoomBlur
    zoomBlur = post.createPass<ZoomBlurPass>();
    
    //12-gRGBShiftPass
    rgbPass = post.createPass<RGBShiftPass>();
    
    //13-FilmGrainLines
    filmGrainLinesPass = post.createPass<FilmGrainLinesPass>();
    
    //14-DotScreen
    dotScreenPass = post.createPass<DotScreenPass>();
    
    //15-Glitch
    glitchPass = post.createPass<DigitalGlitchPass>();
    
    //16-Fire Lava
    lavaFire = post.createPass<FirePass>();
    
    //17-Bad TV
    badTv = post.createPass<BadTVPass>();
    
    //18-Color ACES Filmic Filter
    colorACES = post.createPass<ACESFilmicToneMappingPass>();
    
    //19-Noise Grains Filter
    noiseGrain = post.createPass<NoisePass>();
    
    //20-TiltShift Filter
    tiltShift = post.createPass<TiltShiftPass>();
    
    //21-SuperShader
    superShader = post.createPass<SuperPass>();
    
    //22-glitch Automated Filter
    glitchAuto = post.createPass<GlitchAutomatedPass>();
    
    //23-gSpaceColor
    spaceColor = post.createPass<SpaceColorMovePass>();
    
    //24-Dither Pass
    dither = post.createPass<DitherPass>();
    
    gDoEdgePass = false;
    gDoVerticalTiltShift = false;
}
//---------------------------------------
void ofxPostProcessingManager::updateValues(){

    //TODO: check pointers are not null
    
    post[0]->setEnabled(gDoFxaa);
    post[1]->setEnabled(gDoBloom);
    post[2]->setEnabled(gDoDof);
    post[3]->setEnabled(gDoKaleidoscope);
    post[4]->setEnabled(gDoNoiseWarp);
    post[5]->setEnabled(gDoPixelate);
    post[6]->setEnabled(gDoEdgePass);
    post[7]->setEnabled(gDoVerticalTiltShift);
    post[8]->setEnabled(gDoGodRays);
    post[9]->setEnabled(gDoLimbDarkening);
    post[10]->setEnabled(gDoSsao);
    post[11]->setEnabled(gZoomBlur);
    post[12]->setEnabled(gRGBShiftPass);
    post[13]->setEnabled(gFilmGrainLines);
    post[14]->setEnabled(gDotScreen);
    post[15]->setEnabled(gGlitch);
    post[16]->setEnabled(gLavaFire);
    post[17]->setEnabled(gBadTv);
    post[18]->setEnabled(gcolorACES);
    post[19]->setEnabled(gNoise);
    post[20]->setEnabled(gTiltShift);
    post[21]->setEnabled(gSup);
    post[22]->setEnabled(gGlitchAuto);
    post[23]->setEnabled(gSpaceColor);
    post[24]->setEnabled(gDither);
    //post[25]->setEnabled();
    //post[26]->setEnabled();
    
    // 1- Bloom
    if(post[1]->getEnabled())
        bloomPass->setBlurXY(gBloomBlurX, gBloomBlurY);
    
    // 3- Kaleidoscope
    if(post[3]->getEnabled())
        kaleidoscope->setSegments(gKaleiSegments);
    
    // 2- DOF
    if(post[2]->getEnabled())
    {
        dof->setAperture(gDofAperture);
        dof->setMaxBlur(gDofMaxBlur);
        dof->setFocus(gDofFocus);
    }
    
    // 8- GOD Rays
    if(post[8]->getEnabled()) {
        godRays->setLightDirDOTviewDir(gGodRaysLightDotView);
        godRays->setLightPositionOnScreen(gLightPositionOnScreen);
    }
    
    // 10- SSAO
    if(post[10]->getEnabled())
    {
        ssao->setAoClamp(gSsaoAoClamp);
        ssao->setLumInfluence(gSsaoLumInfluence);
    }
    
    // 11- ZoomBlur
    if(post[11]->getEnabled())
    {
        zoomBlur->setCenterX(gZoomCenterXY->x);
        zoomBlur->setCenterY(gZoomCenterXY->y);
        //zoomBlur->setClamp(gZoomClamp);
        //zoomBlur->setDecay(gZoomDecay);
        zoomBlur->setWeight(gZoomWeight);
        zoomBlur->setDensity(gZoomDensity);
        zoomBlur->setExposure(gZoomExposure);
    }
    
    // 12- RGB Pass
    if(post[12]->getEnabled())
    {
        rgbPass->setAngle(gRGBAngle);
        rgbPass->setAmount(gRGBAmount);
    }
    
    // 13- FilmGrainLines Pass
    if(post[13]->getEnabled()) {
        filmGrainLinesPass->setCount(gFilmGrainLCount);
        filmGrainLinesPass->setGrayScale(gFilmGrainLGrayScale);
        filmGrainLinesPass->setnIntensity(gFilmGrainLnIntensity);
        filmGrainLinesPass->setsIntensity(gFilmGrainLsIntensity);
    }
    
    // 14- DotScreen Pass
    if(post[14]->getEnabled())  {
        dotScreenPass->setSize(ofVec2f(gDotScrSize->x, gDotScrSize->y));
        dotScreenPass->setAgnle(gDotScrAngle);
        dotScreenPass->setScale(gDotScrScale);
        dotScreenPass->setCenter(ofVec2f(gDotScrCenter->x, gDotScrCenter->y));
    }
    
    // 15- Glitch Pass
    if(post[15]->getEnabled()) {
        
        gGlitchCol = ofRandom(0.00001, 0.3);
        gGlitchDistX = ofSignedNoise(ofGetFrameNum() * 0.04);
        gGlitchDistY = ofSignedNoise(ofGetFrameNum() * 0.01);
        gGlitchAngle = ofRandom(0, TWO_PI);
        
        glitchPass->setByp(gGlitchByp);
        glitchPass->setCols(gGlitchCol);
        glitchPass->setSeed(gGlitchSeed);
        glitchPass->setSeedX(gGlitchSeedX);
        glitchPass->setSeedY(gGlitchSeedY);
        glitchPass->setDistortionX(gGlitchDistX);
        glitchPass->setDistortionY(gGlitchDistY);
        glitchPass->setAngle(gGlitchAngle);
        glitchPass->setAmount(gGlitchAmount);
    }
    
    // 16- Lava Fire Pass
    //if(post[16]->getEnabled()) {
    //}
    
    // 17- Bad TV Effect
    if(post[17]->getEnabled()) {
        badTv->setSpeed(gBadTvSpeed);
        badTv->setRollSpeed(gBadTvRoll);
        badTv->setDistortion(gBadTvDist);
        badTv->setDistortion2(gBadTvDist2);
    }
    
    // 18- COLOR ACES FILMIC FILTER
    if(post[18]->getEnabled()) {
        colorACES->setExposure(gcolorACESExp);
    }
    
    // 19- Noise Grain Filter
    if(post[19]->getEnabled()) {
        noiseGrain->setSpeed(gNoiseSpeed);
        noiseGrain->setAmount(gNoiseAmt);
    }
    
    // 20
    if(post[20]->getEnabled()) {
        tiltShift->setFocusPos(gTiltFocus);
        tiltShift->setRange(gTitltRange);
        tiltShift->setOffset(gTiltOffset);
        tiltShift->setStrength(gTiltStrength);
    }
    
    // 21
    if(post[21]->getEnabled()) {
        superShader->setGlowAmount(gSupGlowAmt);
        superShader->setGlowSize(gSupGlowSize);
        superShader->setVigOffset(gSupVigOff);
        superShader->setVigDark(gSupVigDark);
        superShader->setBrightness(gSupBri);
        superShader->setContrast(gSupCont);
        superShader->setSaturation(gSupSat);
        superShader->setRGBShiftAmount(gRGBShfAmt);
    }
    
    // 22 Automated Glitch
    if(post[22]->getEnabled()) {
        glitchAuto->setSpeed(gGliAutoSpeed);
        glitchAuto->setAmount(gGliAutoAmt);
    }
    
    // 23 Space Color
    if(post[23]->getEnabled()) {
        spaceColor->setSpeed(gSpaceColorSpeed);
        spaceColor->setOpacity(gSpaceColorOpacity);
    }
    
    
    // 24
    if(post[24]->getEnabled()) {
        dither->setScale(gDitherScale);
     }
    
    // 25
    /*if(post[25]->getEnabled()) {
     
     }*/
}
//---------------------------------------
void ofxPostProcessingManager::setupGui(){
    gui.setDefaultTextPadding(6);
    gui.setDefaultWidth(220);
    gui.setDefaultHeight(14);
    gui.setup("POST PROCESSING FX");
    gui.add(gDebugDraw.setup("ENABLE DEBUG DRAW", false));
    
    //0-Fxaa
    gui.add(gDoFxaa.setup("FXXA", false));
    
    //1-Bloom
    gBloomGroup.setName(bloomPass->getName() + " GROUP");
    gBloomGroup.add(gBloomBlurX.setup("Blur X", 0.000953125, 0, 0.01 )->getParameter());
    gBloomGroup.add(gBloomBlurY.setup("Blur Y", 0.000953125, 0, 0.01 )->getParameter());
    gui.add(gDoBloom.setup(bloomPass->getName(), false));
    gui.add(gBloomGroup);
    
    //2-dof
    gDofApertureGroup.setName(dof->getName() + " GROUP");
    gDofApertureGroup.add(gDofFocus.setup("Dof-Focus", 0.9, 0.0, 1.0)->getParameter());
    gDofApertureGroup.add(gDofAperture.setup("Dof-Aperture", 0.2, 0.0, 1.0)->getParameter());
    gDofApertureGroup.add(gDofMaxBlur.setup("Dof-MaxBlur", 0.05, 0.0, 1.0)->getParameter());
    gui.add(gDoDof.setup(dof->getName(), false));
    gui.add(gDofApertureGroup);
    
    //3-Kaleidoscope
    gKaliGroup.setName(kaleidoscope->getName() + " GROUP");
    gKaliGroup.add(gKaleiSegments.setup("Segments", 2.f, -20, 20)->getParameter());
    gui.add(gDoKaleidoscope.setup(kaleidoscope->getName(), false));
    gui.add(gKaliGroup);
    
    //4-Noisewarp
    gui.add(gDoNoiseWarp.setup("NoiseWarp", false));
    gui.add(gDoPixelate.setup("Pixelate", false));
    //gui.add(gDoEdgePass.setup("EdgePass", false));
    //gui.add(gDoVerticalTiltShift.setup("VerticalTiltShift", false));
    
    //8-GodRays
    gGodRaysGroup.setName(godRays->getName() + " GROUP");
    gGodRaysGroup.add(gGodRaysLightDotView.setup("GodRays-Light", 0.3, 0.0, 1.0)->getParameter());
    gGodRaysGroup.add(gLightPositionOnScreen.setup("Light Position", glm::vec3(0), glm::vec3(0), glm::vec3(1))->getParameter());
    gui.add(gDoGodRays.setup(godRays->getName(), false));
    gui.add(gGodRaysGroup);
    
    //9-LimbDarkening
    gui.add(gDoLimbDarkening.setup("LimbDarkening", false));
    
    //10-Ssao
    gSsaoGroup.setName(ssao->getName() + " GROUP");
    gSsaoGroup.add(gSsaoAoClamp.setup("Ssao-AoClamp", 0.65, 0.0, 1.0)->getParameter());
    gSsaoGroup.add(gSsaoLumInfluence.setup("Ssao-LumInfluence", 0.25, 0.0, 1.0)->getParameter());
    gui.add(gDoSsao.setup(ssao->getName(), false));
    gui.add(gSsaoGroup);
    
    // 11- ZoomBlur
    gZoomBlurGroup.setName(zoomBlur->getName() + " GROUP");
    gZoomBlurGroup.add(gZoomCenterXY.setup("Zoom Center XY", glm::vec2(0.5, 0.5), glm::vec2(0, 0), glm::vec2(1, 1))->getParameter());
    //gui.add(gZoomClamp.setup("Clamp",1,0,1));
    //gui.add(gZoomDecay.setup("Decay",0.9,0,1));
    gZoomBlurGroup.add(gZoomWeight.setup("Weight",0.25,0,1)->getParameter());
    gZoomBlurGroup.add(gZoomDensity.setup("Density",0.25,0,1)->getParameter());
    gZoomBlurGroup.add(gZoomExposure.setup("Exposure",0.48,0,1)->getParameter());
    gui.add(gZoomBlur.setup(zoomBlur->getName(), false));
    gui.add(gZoomBlurGroup);
    
    // 12- RGB Pass
    gRGBGroup.setName(rgbPass->getName() + " GROUP");
    gRGBGroup.add(gRGBAngle.setup("Angle", 0, 0, TWO_PI)->getParameter());
    gRGBGroup.add(gRGBAmount.setup("Amount", 0.005,0,1)->getParameter());
    gui.add(gRGBShiftPass.setup(rgbPass->getName(), false));
    gui.add(gRGBGroup);
    
    // 13- FilmGrainLines Pass Params
    gFilmGrainGroup.setName(filmGrainLinesPass->getName() + " GROUP");
    gFilmGrainGroup.add(gFilmGrainLCount.setup("Count", 1096,1, 10000)->getParameter());
    gFilmGrainGroup.add(gFilmGrainLGrayScale.setup("GrayScale",false)->getParameter());
    gFilmGrainGroup.add(gFilmGrainLnIntensity.setup("N Intensity",0.5,0,1)->getParameter());
    gFilmGrainGroup.add(gFilmGrainLsIntensity.setup("S Intensity",0.5,0,1)->getParameter());
    gui.add(gFilmGrainLines.setup(filmGrainLinesPass->getName(), false));
    gui.add(gFilmGrainGroup);
    
    
    // 14- DotScreen Pass params
    gDotScreenGroup.setName(dotScreenPass->getName() + " GROUP");
    gDotScreenGroup.add(gDotScrCenter.setup("Center", ofVec2f(0.5), ofVec2f(0), ofVec2f(1.0,1.0))->getParameter());
    gDotScreenGroup.add(gDotScrSize.setup("Size", ofVec2f(256, 256), ofVec2f(0), ofVec2f(1000))->getParameter());
    gDotScreenGroup.add(gDotScrScale.setup("Scale",1.0,0,1)->getParameter());
    gDotScreenGroup.add(gDotScrAngle.setup("Angle",1.57,0,TWO_PI)->getParameter());
    gui.add(gDotScreen.setup(dotScreenPass->getName(), false));
    gui.add(gDotScreenGroup);
    
    
    // 15- Digital Glitch Pass Params
    gGlicthGroup.setName(glitchPass->getName() + " GROUP");
    gGlicthGroup.add(gGlitchAmount.setup("Amount", 0.006, 0.00001, 0.1)->getParameter());
    gGlicthGroup.add(gGlitchByp.setup("Bypass", false)->getParameter());
    gGlicthGroup.add(gGlitchAngle.setup("Angle", 0.02, 0, TWO_PI)->getParameter());
    gGlicthGroup.add(gGlitchSeed.setup("Seed", 0.02, 0, 1)->getParameter());
    gGlicthGroup.add(gGlitchSeedX.setup("Seed X", 0.02, 0, 1)->getParameter());
    gGlicthGroup.add(gGlitchSeedY.setup("Seed Y", 0.02, 0, 1)->getParameter());
    gGlicthGroup.add(gGlitchDistX.setup("Distortion X", 0.02, -1, 1)->getParameter());
    gGlicthGroup.add(gGlitchDistY.setup("Distortion Y", 0.02, -1, 1)->getParameter());
    gGlicthGroup.add(gGlitchCol.setup("Column", 0.03, 0, 1)->getParameter());
    gui.add(gGlitch.setup(glitchPass->getName(), false));
    gui.add(gGlicthGroup);
    
    // 16- Lava Fire
    
    // 17- Bad TV Pass Params
    gBadTVGroup.setName(badTv->getName() + " GROUP");
    gBadTVGroup.add(gBadTvDist.setup("Distortion 1", 3.0, 0.0, 20.0)->getParameter());
    gBadTVGroup.add(gBadTvDist2.setup("Distortion 2", 5.0, 0.0, 20.0)->getParameter());
    gBadTVGroup.add(gBadTvSpeed.setup("Speed", 3.0, 0.0, 20.0)->getParameter());
    gBadTVGroup.add(gBadTvRoll.setup("Roll Speed", 0.1, 0.0, 1.0)->getParameter());
    gui.add(gBadTv.setup(badTv->getName(), false));
    gui.add(gBadTVGroup);
    
    // 18- Color ACES Filmic Filter Paramas
    gcolorACESGroup.setName(colorACES->getName() + " GROUP");
    gcolorACESGroup.add(gcolorACESExp.setup("Exposure", 1.0, 0.0, 1.0)->getParameter());
    gui.add(gcolorACES.setup(colorACES->getName(), false));
    gui.add(gcolorACESGroup);
    
    // 19- Noise Grain Filter Params
    gNoiseGroup.setName(noiseGrain->getName() + " GROUP");
    gNoiseGroup.add(gNoiseAmt.setup("Amount", 0.128, 0, 1)->getParameter());
    gNoiseGroup.add(gNoiseSpeed.setup("Speed", 0.08, 0, 1)->getParameter());
    gui.add(gNoise.setup(noiseGrain->getName(), false));
    gui.add(gNoiseGroup);
    
    // 20- Tilt Shift Filter Params
    gTiltShiftGroup.setName(tiltShift->getName() + " GROUP");
    gTiltShiftGroup.add(gTiltFocus.setup("Focus", 0.35, 0, 1)->getParameter());
    gTiltShiftGroup.add(gTitltRange.setup("Range", 0.5, 0, 1)->getParameter());
    gTiltShiftGroup.add(gTiltOffset.setup("Offset", 0.05, 0, 1)->getParameter());
    gTiltShiftGroup.add(gTiltStrength.setup("Strength", 0.5, 0, 1)->getParameter());
    gui.add(gTiltShift.setup(tiltShift->getName(), false));
    gui.add(gTiltShiftGroup);
    
    // 21- SuperShader Filter Params
    gSupGroup.setName(superShader->getName() + " GROUP");
    gSupGroup.add(gSupGlowAmt.setup("Glow Amount", 0.5, 0., 1.)->getParameter());
    gSupGroup.add(gSupGlowSize.setup("Glow Size", 4.0, 0., 20.)->getParameter());
    gSupGroup.add(gSupVigOff.setup("Vignette Offset", 1.0, 0., 1.)->getParameter());
    gSupGroup.add(gSupVigDark.setup("Vignette Darkness", 1.0, 0., 1.)->getParameter());
    gSupGroup.add(gSupBri.setup("Brightness", 0.0, -1., 1.)->getParameter());
    gSupGroup.add(gSupCont.setup("Contrast", 0.0, -1., 1.)->getParameter());
    gSupGroup.add(gSupSat.setup("Saturation", 0.0, 0., 1.)->getParameter());
    gSupGroup.add(gRGBShfAmt.setup("RGB Shift Amount", 0.01, 0., 1.)->getParameter());
    gui.add(gSup.setup(superShader->getName(), false));
    gui.add(gSupGroup);
    
    // 22- Glitch Automated Filter Params
    gGliAutoGroup.setName(glitchAuto->getName() + " GROUP");
    gGliAutoGroup.add(gGliAutoSpeed.setup("Speed", 0.6, 0 , 1)->getParameter());
    gGliAutoGroup.add(gGliAutoAmt.setup("Amount", 0.2, 0 , 1)->getParameter());
    gui.add(gGlitchAuto.setup(glitchAuto->getName(), false));
    gui.add(gGliAutoGroup);
    
    // 23- Space Color
    gSpaceColorGroup.setName(spaceColor->getName() + " GROUP");
    gSpaceColorGroup.add(gSpaceColorSpeed.setup("Speed", 1, 0, 5)->getParameter());
    gSpaceColorGroup.add(gSpaceColorOpacity.setup("Opacity", 0.1, 0, 1)->getParameter());
    gui.add(gSpaceColor.setup(spaceColor->getName(), false));
    gui.add(gSpaceColorGroup);
    
    // 24-
    gDitherGroup.setName(dither->getName() + " GROUP");
    gDitherGroup.add(gDitherScale.setup("Scale", 1, 0, 1)->getParameter());
    gui.add(gDither.setup(dither->getName(), false));
    gui.add(gDitherGroup);
    
    // 25-
    
    // 26-
    gui.minimizeAll();
}
//---------------------------------------
void ofxPostProcessingManager::drawGui(int x, int y){
    gui.setPosition(x, y);
    
    if(gDebugDraw)
        post.debugDraw();
    
    gui.draw();
    
    
}
//---------------------------------------
void ofxPostProcessingManager::begin(){
    post.begin();
}
//---------------------------------------
void ofxPostProcessingManager::begin(ofCamera& cam){
    post.begin(cam);
}

//---------------------------------------
void ofxPostProcessingManager::end(){
    post.end();
}

void ofxPostProcessingManager::windowResized(int w, int h) {
    
    //post.getPasses().clear();
    post.init(w,h);
    
    
    //reInit();
}
