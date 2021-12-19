#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    track.load("sounds/arrowparticles.mp3");
    track.setLoop(true);
    track.play();
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
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor::darkBlue, ofColor::black, OF_GRADIENT_CIRCULAR);

    cam.disableMouseInput();
    cam.setupPerspective();
    cam.setPosition(0, 0, zoom);
    cam.begin();
    drawBox();
    cam.end();
}

void ofApp::drawBox(){
    ofNoFill();
    
    ofSetColor(ofColor::snow);
    
    // draw something circular
    ofRotateZDeg(ofDegToRad(rotation));
    ofRotateXDeg(rotation);
    ofRotateYDeg(ofDegToRad(rotation));

    ofDrawBox(128);
    
    // float width = (float)(5*128) / nBandsToGet;
    for (int i = 0;i < nBandsToGet; i++){
        ofDrawBox(-(fftSmoothed[i] * 200));
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
