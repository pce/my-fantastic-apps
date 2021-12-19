#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    track.load("sounds/arrowparticles.mp3");
    track.setLoop(true);
    track.play();
    gui.setup("lovelyFFT");
    gui.add(bEnableLight.set("EnableLight", false));
    gui.add(bEnableMouseInput.set("EnableMouseInput", false));
    gui.add(bShowOuterCube.set("ShowOuterCube", true));
    gui.add(multFactor.set("multiply", 200, 10, 300));
    gui.add(color1.set("color BG1",ofColor::darkBlue));
    gui.add(color2.set("color BG2",ofColor::black));
    gui.add(color3.set("color Primary",ofColor::snow));
    gui.add(bAnimateGrid.set("AnimateGrid", true));
    gui.add(gridSize.set("GridSize", 58, 10, 800));
    gui.add(bShowGridScene.set("ShowGridScene", true));
    gui.add(bShowCubeScene.set("ShowCubeScene", true));

    gui.loadFromFile("settings.xml");
    
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
    animatedGridSize = ofMap(sin(ofGetElapsedTimef()), -1, 1, 20, rotation);
    if(animatedGridSize < 15) {
        bShowGridScene=false;
    }
    if(ofGetElapsedTimef() > 36 && ofGetElapsedTimef() <= 37){
        bShowGridScene=true;
    }
    // ofLog() << animatedGridSize;
    // strobes
    // ofLog() << ofGetElapsedTimef();
    //    if(animatedGridSize < 5) {
    //        animatedGridSize = ofRandom(6, 10);
    //    }
    
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
    
    if(bShowGridScene){
        drawGrid();
    }

    cam.begin();
    //    if(bEnableLight){
    //        ofEnableLighting();
    //
    //    }
    if(bShowCubeScene){
        drawBox();
    }
    cam.end();
    
    if(bShowGui){
        ofDisableLighting();
        gui.draw();
    }
}

void ofApp::drawBox(){
    ofNoFill();
    
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

void ofApp::drawGrid(){

    if(bAnimateGrid){
        gridSize = animatedGridSize;
    }
    
    for(int x = gridSize;  x < ofGetWidth(); x+=gridSize){
        for(int y = gridSize;  y < ofGetHeight(); y+=gridSize){
            ofSetColor(color3);
            ofDrawCircle(x, y, 10);
            ofSetColor(color3, 128);
            ofDrawLine(x, y, ofGetWidth()/2, ofGetHeight()/2);
        }
    }
    
}


void ofApp::drawLines(){

    
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
