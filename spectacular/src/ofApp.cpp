#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    setupCenterParticles();
}

void ofApp::setupCenterParticles() {
    for (int i = 0; i < 100; i++) {
        float velX = ofRandom(-2, 2);
        float velY = ofRandom(-2, 2);
        particles[i].setup(ofRandom(ofGetWidth()/2), 0, velX, velY, 2.2);
        // particles[i].setup(ofGetWidth()/2, ofGetHeight()/2, velX, velY, 2.2);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int maxH = ofGetHeight();
    for (int i = 0; i < 100; i++) {
        particles[i].update();
        if (particles[i].x > maxH) {
            maxH = particles[i].x;
        }
    }
    
    if (maxH > ofGetHeight()) {
        // setup new sys, if previous delete
        // setupNewParticles();
        setupCenterParticles();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::yellow, ofColor::darkRed, OF_GRADIENT_CIRCULAR);
        
    for (int i = 0; i < 100; i++) {
        particles[i].draw();
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
    setupCenterParticles();
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
