#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);

    ofDisableAlphaBlending();
    ofEnableDepthTest();
    light.enable();
    light.setPosition(ofVec3f(100,100,200));
    light.lookAt(ofVec3f(0,0,0));

    image.load("hans-reniers-DELDTYAjPrg-unsplash.jpg");
    // image.load("ryan-spencer-XGKaRnWjv1c-unsplash.jpg");
    // image.resize(ofGetWidth()/4, ofGetHeight()/4);
    image.resize(ofGetWidth()/16, ofGetHeight()/16);

    // prepare spheres to draw
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,255);
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    
    cam.begin();
	
    ofScale(1, -1, 1);
    
    // cam.setPosition(-3.79, -623.5, 402);
    // ofLog() << "cam x:" << cam.getX() << " y:" << cam.getY() << " z:" << cam.getZ();
    // x: -3.79, y: -623.5, Z: 402
    
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    // float intensityThreshold = 100.0;
    float intensityThreshold = 50.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            
            // ofLog() << "intensity: " << intensity;
            
            float _x = static_cast<float>(x);
            float _y = static_cast<float>(y);
            float _z = 0.8*16;
            float _size = 0.8*16;
            

            if (intensity >= intensityThreshold) {
                
                int brightness = c.getBrightness();
                if (brightness > 250) {
                    _z *= 2;
                    _y *= 16;
                    _x *= 16;
                    _size *= 1.5;
                } else if (brightness > 200) {
                    _y *= 16;
                    _x *= 16;
                    _z *= 3;
                    _size *= 1;
                } else if (brightness > 100) {
                    _z *= 2;
                    _y *= 16;
                    _x *= 16;
                    _size *= .5;
                } else {
                    _y *= 16;
                    _x *= 16;
                    _z *= 4;
                    _size *= .25;
                }
                
                ofDrawBox(_x, _y, _z, _size);
                
            }

        }
    }
    
    ofPopMatrix();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
