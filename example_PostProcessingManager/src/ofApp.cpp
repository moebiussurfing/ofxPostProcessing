#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    
    //setup manager
    manager.setup(ofGetWidth(), ofGetHeight());

    // Setup box positions
    for (unsigned i = 0; i < NUM_BOXES; ++i)
    {
        posns.push_back(ofVec3f(ofRandom(-300, 300), ofRandom(-300, 300), ofRandom(-300, 300)));
        cols.push_back(ofColor::fromHsb(255 * i / (float)NUM_BOXES, 255, 255, 255));
    }
    
    // Setup light
    light.setPosition(1000, 1000, 2000);
    
    // create our own box mesh as there is a bug with
    // normal scaling and ofDrawBox() at the moment
    boxMesh = ofMesh::box(20, 20, 20);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    manager.updateValues();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // setup gl state
    ofEnableDepthTest();
    light.enable();
    
    // begin scene to post process
    manager.begin(cam);
    
    // draw boxes
    for (unsigned i = 0; i < posns.size(); ++i)
    {
        ofSetColor(cols[i]);
        ofPushMatrix();
        ofTranslate(posns[i]);
        boxMesh.draw();
        ofPopMatrix();
    }
    
    ofDrawAxis(100);
    
    // end scene and draw
    manager.end();
    
    ofDisableDepthTest();
    
    if(!hideGui)
        manager.drawGui(ofGetWidth() - 220, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g')
        hideGui = !hideGui;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    manager.windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
