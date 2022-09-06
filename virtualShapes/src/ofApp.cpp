#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mainFont.load("fonts/Waukegan LDO Extended Bold.ttf", mainFontSize);
    ofBackground(0);
    lineX = ofGetWidth() * .5;
    lineY = ofGetHeight() * .5;
    titleY = (mainFontSize * 4) + ofGetHeight() * .5;
    titleX = (mainFontSize * 2) + ofGetWidth();
}

//--------------------------------------------------------------
void ofApp::update(){
    titleX--;
    if (titleX <= -ofGetWidth() - ofGetWidth() * .5) {
        titleX = ofGetWidth() + ((ofGetWidth() * .5) / 4);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    drawText();
    drawShapes();
}

void ofApp::drawText(){

    float maxDistance = 50;
    float time = ofGetElapsedTimef();
    float x, y, angle, distance;

    for (int line=0; line<4; line++) {
        ofSetColor(126);
        
        x = titleX;
        y = titleY;
        
        angle = ofNoise(0.0 + (time * 2.0)) * TWO_PI;
        distance = ofNoise(5.0 + (time * 2.0)) * maxDistance;
        
        x += distance * cos(angle) * 0.1;
        y += distance * sin(angle) * 0.1;
 
        ofSetColor(ofColor::darkSlateBlue);
        mainFont.drawString(currentTitle[line], x, y + line * (mainFontSize*2)+1);
 
        ofSetColor(ofColor::darkSlateGray);
        mainFont.drawString(currentTitle[line], x, y + line * (mainFontSize*2));

        ofSetColor(ofColor::ghostWhite);
        mainFont.drawString(currentTitle[line], titleX, titleY + line * (mainFontSize*2));

        
    }
}


void ofApp::drawShapes(){
    ofSetColor(255);
    
    ofFill();
    int radius{720};
    for (int degree=0; degree < numOfLines; degree++) {
        float x = 0 + radius * cos(degree * DEG_TO_RAD);
        float y = radius * sin(degree * DEG_TO_RAD);

        x = ofMap(ofNoise(x, ofGetElapsedTimef()), x, ofGetWidth(), 0, ofGetWidth()*2);
        y = ofMap(ofNoise(y, ofGetElapsedTimef()), y, ofGetHeight(), 0, ofGetHeight()*2);

        ofDrawCircle(
                     x,
                     y,
                     50);
        
        ofDrawLine(lineX, lineY, x, y);
//        ofLog(OF_LOG_NOTICE, "x is " + ofToString(x));
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
    titleX = x;
    titleY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    textX = x;
    textY = y;

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
