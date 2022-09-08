
#include "ofApp.h"

#include "RadialLineScene.h"
#include "TitleScene.h"
#include "CubeScene.hpp"

//--------------------------------------------------------------
void ofApp::setup() {

    // setup for nice jaggy-less rendering
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    // load scenes
    titleScene = (TitleScene*) sceneManager.loadScene(new TitleScene());
    sceneManager.loadScene(new RadialLineScene());
    cubeScene = (CubeScene*) sceneManager.loadScene(new CubeScene());
    sceneManager.setup();
    ofSetLogLevel("ofxSimpleSceneManager", OF_LOG_VERBOSE); // lets see whats going on inside
    ofLog(OF_LOG_NOTICE, "number of scenes:" + ofToString(sceneManager.getSceneCount()));
    // gui
    panel.setup("panel");
    panel.add(cubeScene->maxSpinX.set("MAX spinX", .32, 1, 90));
    panel.add(cubeScene->maxSpinY.set("MIN spinX", .32, 1, 90));
//    panel.add(cubeScene->spinX.set("spinX", .32, .1, 90));
//    panel.add(cubeScene->spinY.set("spinX", .32, .1, 90));

    // set scenes
    sceneManager.setActiveScene(0);
    lastScene = sceneManager.getActiveIndex();
}

//--------------------------------------------------------------
void ofApp::update() {
    sceneManager.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

    sceneManager.draw();

//    cubeScene.spinX;
//    cubeScene.spinY;
    
    // to ofDrawBitmapString
    ofSetColor(200);
    ofDrawBitmapString("Current Scene Index: " + ofToString(sceneManager.getActiveIndex()),
                       12, ofGetHeight()-8);
    
    
    
    if( bShowPanel ){
        panel.draw();
    }
    

}

// current scene input functions are called automatically before calling these
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    int index = 0;
    switch(key) {
    
        case 'p':
            bShowPanel = !bShowPanel;
            break;

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
