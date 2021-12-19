#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    track.load("sounds/arrowparticles.mp3");
    track.setLoop(true);
    track.play();
    gui.setup("panel");
    gui.add(bEnableLight.set("bEnableLight", false));
    gui.add(bEnableMouseInput.set("bEnableMouseInput", false));
    gui.add(bShowOuterCube.set("bShowOuterCube", true));
    gui.add(multFactor.setup("multiply", 200, 10, 300));
    gui.add(color1.set("color1",ofColor::darkBlue));
    gui.add(color2.set("color2",ofColor::black));
    gui.add(color3.set("color3",ofColor::snow));

    // gui.add(factor.set("factor", 5, 1, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    float rotVal;

    float * val = ofSoundGetSpectrum(nBandsToGet);        // request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) {
            fftSmoothed[i] = val[i];
            
            if (val[i] > rotVal) rotVal = val[i];
        }
        
    }
    rotation += rotVal;
    // ofLogVerbose() << rotation;

    // zoom
    zoom = ofMap(sin(ofGetElapsedTimef()), -1, 1, 70, rotation);
    // ofLog() << zoom;
    
    if(bEnableLight){
        light.enable();
        light.setPosition(ofVec3f(100,100,rotation));
        light.lookAt(ofVec3f(0,0,0));
    }else{
        light.disable();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(color1, color2, OF_GRADIENT_CIRCULAR);

    if(!bEnableMouseInput){
        cam.setupPerspective();
        cam.disableMouseInput();
        cam.setPosition(0, 0, zoom);
    }else{
        cam.enableMouseInput();
    }
    
    cam.begin();
//    if(bEnableLight){
//        ofEnableLighting();
//
//    }
    drawBox();
    cam.end();
    
    if (bShowGui) {
        ofDisableLighting();
        gui.draw();
    }
}

void ofApp::drawBox(){
    ofNoFill();
    
    // ofSetColor(ofColor::snow);
    ofSetColor(color3);

    // draw something circular
    ofRotateZDeg(ofDegToRad(rotation));
    ofRotateXDeg(rotation);
    ofRotateYDeg(ofDegToRad(rotation));

    if(bShowOuterCube){
        ofDrawBox(128);
    }
    
    // float width = (float)(5*128) / nBandsToGet;
    for (int i = 0;i < nBandsToGet; i++){
        ofDrawBox(-(fftSmoothed[i] * multFactor));
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'd':
            bShowGui = !bShowGui;
            break;
    }
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
