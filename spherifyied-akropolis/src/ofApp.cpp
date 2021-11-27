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
    image.resize(ofGetWidth()/4, ofGetHeight()/4);

    // prepare spheres to draw

}

//--------------------------------------------------------------
void ofApp::update(){
    degrees++;
    // ofLog() << "deg: " << degrees;
    
    if (static_cast<int>(degrees) % 270 == 0) {
        if (state == AppState::SPHERE) {
            state = AppState::BOX;
        } else {
            state = AppState::SPHERE;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,255);
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0, 0, 0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    cam.begin();

    ofRotateXDeg(degrees);
    
	ofScale(1, -1, 1);

    switch (state) {
        case AppState::SPHERE:
            drawSpheres();
            break;
        case AppState::BOX:
            drawBoxes();
            break;
    }
    
    cam.end();
}

void ofApp::drawSpheres() {
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    // float intensityThreshold = 150.0;
    float intensityThreshold = 50.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                
                int brightness = c.getBrightness();
                // cout << brightness << endl;
                if (brightness > 200) {
                    ofSetColor(ofColor::blue);
                    ofDrawSphere(static_cast<float>(x)*4, static_cast<float>(y)*4, 0.8*4);
                } else if (brightness > 100) {
                    ofSetColor(ofColor::darkBlue);
                    ofDrawSphere(static_cast<float>(x)*4, static_cast<float>(y)*4, 0.4*4);
                } else {
                    ofSetColor(ofColor::cyan);
                    ofDrawSphere(static_cast<float>(x)*4, static_cast<float>(y)*4, 0.0);
                }
            }

        }
    }
    
    ofPopMatrix();
}

void ofApp::drawBoxes() {
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    int factor = 4;
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
            float _z = 0.8*factor;
            float _size = 0.8*factor;
            

            if (intensity >= intensityThreshold) {
                
                int brightness = c.getBrightness();
                if (brightness > 250) {
                    ofSetColor(ofColor::darkBlue);
                    _z *= 2;
                    _y *= factor;
                    _x *= factor;
                    _size *= 1.5;
                } else if (brightness > 200) {
                    ofSetColor(ofColor::blue);
                    _y *= factor;
                    _x *= factor;
                    _z *= 3;
                    _size *= 1;
                } else if (brightness > 100) {
                    ofSetColor(ofColor::cyan);
                    _z *= 2;
                    _y *= factor;
                    _x *= factor;
                    _size *= .5;
                } else {
                    ofSetColor(ofColor::aliceBlue);
                    _y *= factor;
                    _x *= factor;
                    _z *= factor;
                    _size *= .25;
                }
                ofDrawBox(_x, _y, _z, _size);
            }
        }
    }
    ofPopMatrix();
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
