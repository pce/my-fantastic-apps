#include "ofApp.h"


void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(72,128,216);
    ofEnableAntiAliasing();
    setupMainmesh();
    cam.setFov(120);
    
}


void ofApp::setupMainmesh(){
    // mesh
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    mesh.addVertex(ofVec3f(20,20));
    mesh.addVertex(glm::vec3((w-20)*.5,40,100));
    mesh.addVertex(ofVec3f(w-20,20));
    mesh.addVertex(ofVec3f(w-20,h-20));
    mesh.addVertex(ofVec3f(20, h-20));
    mesh.addColor(ofColor::red);
    mesh.addColor(ofColor::salmon);
    mesh.addColor(ofColor::red);
    mesh.addColor(ofColor::blue);
    mesh.addColor(ofColor::blue);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
}

void ofApp::updateMainmesh(){
    // cam
    // let's move the camera when you move the mouse
    float rotateAmount = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 360);
    
    glm::vec3 camDirection(0,0,1);
    glm::vec3 centre(ofGetWidth()*.5, ofGetHeight()*.5, 255*.5);
    glm::vec3 camDirectionRotated = glm::rotate(camDirection, rotateAmount, glm::vec3(1,0,0));

    glm::vec3 camPosition = centre + camDirectionRotated * extrusionAmount;

    cam.setPosition(camPosition);
    cam.lookAt(centre);
}

void ofApp::drawMainmesh() {
    //this is an annoying thing that is used to flip the camera
    cam.setScale(1,-1,1);

    ofEnableDepthTest();
    // disable camera
    cam.begin();
    mesh.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    // update camera
    updateMainmesh();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawMainmesh();
    
    //draw framerate for fun
    ofTranslate(0,0,0);
    ofSetColor(255);
    string msg = "fps: " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(msg, 10, 20);
}

void ofApp::drawLines(){
    mesh.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 's':
            bSmooth = !bSmooth;
            if (bSmooth) {
                ofEnableAntiAliasing();
            } else {
                ofDisableAntiAliasing();
            }
            break;
        case 'f':
            ofToggleFullscreen();
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
