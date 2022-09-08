
#include "ofApp.h"

#include "scenes/RadialLineScene.h"
#include "scenes/TitleScene.h"

//--------------------------------------------------------------
void ofApp::setup() {

    // setup for nice jaggy-less rendering
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    // load scenes
    titleScene = (TitleScene*) sceneManager.loadScene(new TitleScene());
    sceneManager.loadScene(new RadialLineScene());
    sceneManager.setup();
    ofSetLogLevel("ofxSimpleSceneManager", OF_LOG_VERBOSE); // lets see whats going on inside
    
    // start with a specific scene
    ofLog(OF_LOG_NOTICE, "number of scenes:" + ofToString(sceneManager.getSceneCount()));
    // set now to true in order to ignore the scene fade and change now
    // sceneManager.gotoScene(sceneManager.getNumScenes()-1);
    sceneManager.setActiveScene(1);

    lastScene = sceneManager.getActiveIndex();
}

//--------------------------------------------------------------
void ofApp::update() {
    sceneManager.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

    // the current scene is automatically drawn before this function
    sceneManager.draw();

//    ofNoFill();
//    ofSetColor(255);
//    ofSetRectMode(OF_RECTMODE_CORNER);
//    ofDrawRectangle(1, 1, getRenderWidth()-2, getRenderHeight()-2);
//    ofFill();

    
    // to ofDrawBitmapString
    ofSetColor(200);
    ofDrawBitmapString("Current Scene Index: " + ofToString(sceneManager.getActiveIndex()),
                       12, ofGetHeight()-8);
    
    ofLog(OF_LOG_NOTICE, "number of scenes:" + ofToString(sceneManager.getSceneCount()));

}

// current scene input functions are called automatically before calling these
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    int index = 0;
    switch(key) {
    
        case 'd':
            break;
            
        case 'a':
            break;
            
        case 'c':
            break;
            
        case 'm':
            break;
            
        case 'n':
            break;
            
        case 'q':
            break;
            
        case 'f':
            ofToggleFullscreen();
            break;
    
        case OF_KEY_LEFT:
            index = sceneManager.getActiveIndex();
            if (index <= 0) {
                index = sceneManager.getSceneCount()-1;
            } else {
                index--;
            }
            sceneManager.setActiveScene(index);

            break;
            
        case OF_KEY_RIGHT:
            index = sceneManager.getActiveIndex();
            if (index >= sceneManager.getSceneCount()-1) {
                index = 0;
            } else {
                index++;
            }
            sceneManager.setActiveScene(index);
            break;
            
        case OF_KEY_DOWN:
        case OF_KEY_UP:
        case '-':
        case '=':
        case 'o':
        case OF_KEY_BACKSPACE:
            break;

    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
//    transformer.setNewScreenSize() is automatically called if the transformer is set
}
