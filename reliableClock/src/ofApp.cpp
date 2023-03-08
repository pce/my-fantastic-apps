#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mainFont.load("fonts/abstract.ttf", 24);
    ofBackground(0);
//    ofSetBackgroundAuto(false);
    ofSetFullscreen(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    
    auto paddedS = std::to_string(s);
    paddedS.insert(0, 2U - std::min(std::string::size_type(2), paddedS.length()), '0');

    auto paddedM = std::to_string(m);
    paddedM.insert(0, 2U - std::min(std::string::size_type(2), paddedM.length()), '0');

    auto paddedH = std::to_string(h);
    paddedH.insert(0, 2U - std::min(std::string::size_type(2), paddedH.length()), '0');
    
    currentTime = paddedH + ":" + paddedM + ":" + paddedS;

}

//--------------------------------------------------------------
void ofApp::draw(){

    // tailed dotts for seconds
    // tailed dotts for hour
    // tailed dotts for minutes
    
    // set the color of the dots with an alpha value
    // ofColor dotColor = ofColor(255, 255, 255, 10);
    ofColor dotColor = ofColor(255, 255, 255);

    // enable alpha blending
    // ofEnableAlphaBlending();

    // calculate the center of the screen
    ofPoint center = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);

    // calculate the radius of the invisible circle
    float radius = ofGetWidth() * 0.4;

    // calculate the position of the second dot
    float sxAngle = ofGetSeconds() * 6; // calculate the angle based on the current second (1 minute = 360 degrees / 60 seconds)
    ofPoint sx = ofPoint(center.x + radius * cos(ofDegToRad(sxAngle)), center.y + radius * sin(ofDegToRad(sxAngle)));

    // calculate the position of the minute dot
    float mxAngle = ofGetMinutes() * 6; // calculate the angle based on the current minute (1 hour = 360 degrees / 60 minutes)
    ofPoint mx = ofPoint(center.x + radius * cos(ofDegToRad(mxAngle)), center.y + radius * sin(ofDegToRad(mxAngle)));

    // calculate the position of the hour dot
    float hxAngle = ofGetHours() * 30 + ofGetMinutes() * 0.5; // calculate the angle based on the current hour (12 hours = 360 degrees / 12 hours), and add the minute angle (1 hour = 30 degrees / 60 minutes)
    ofPoint hx = ofPoint(center.x + radius * cos(ofDegToRad(hxAngle)), center.y + radius * sin(ofDegToRad(hxAngle)));

    // draw the dots
    ofSetColor(dotColor);

    ofDrawCircle(sx, 3);
    ofDrawCircle(mx, 6);
    ofDrawCircle(hx, 12);

    // disable alpha blending
    // ofDisableAlphaBlending();
    
    mainFont.drawString(currentTime, 100, 100);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
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
