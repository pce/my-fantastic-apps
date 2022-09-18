#pragma once

#include "ofxSimpleScene.hpp"

class RadialLineScene : public ofxSimpleScene {
    
public:
    
    int lineX{0};
    int lineY{0};
    
    int numOfLines{360};
            
    RadialLineScene(){
        name = typeid(this).name();
    }
    
    void setup() {
        ofBackground(0);
        lineX = ofGetWidth() * .5;
        lineY = ofGetHeight() * .5;
    }
    
    void update() {
        
    }
    
    
    void draw() {
        ofEnableAlphaBlending();
        ofFill();
        ofSetColor(255, 0, 0, 255*alpha);
        
        drawShapes();
        
        ofDisableAlphaBlending();
    }
    
    
    void drawShapes(){
        //        ofSetColor(255);
        ofNoFill();
        int radius{720};
        for (int degree=0; degree < numOfLines; degree++) {
            
            float angle = ofDegToRad(degree);
                        
            float distance = ofRandom(1.8);
            
            float x = distance + radius * cos(angle);
            float y = distance + radius * sin(angle);
//            float x = 0 + radius * cos(degree * DEG_TO_RAD);
//            float y = radius * sin(degree * DEG_TO_RAD);

            x = ofMap(ofNoise(x, ofGetElapsedTimef()), x, renderWidth, 0, renderWidth*2);
            y = ofMap(ofNoise(y, ofGetElapsedTimef()), y, renderHeight, 0, renderHeight*2);
            
            ofDrawLine(lineX, lineY, x, y);
            //        ofLog(OF_LOG_NOTICE, "x is " + ofToString(x));
        }
    }
    
    //    void teardown() { cleanUp(); }

};
