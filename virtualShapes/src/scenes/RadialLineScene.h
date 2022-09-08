#pragma once

#include "../ofxSimpleScene.hpp"

class RadialLineScene : public ofxSimpleScene {
    
public:
    
    int lineX{0};
    int lineY{0};
    
    int numOfLines{360};
    
    float renderHeight{0};
    float renderWidth{0};
    //    ofxApp *app;
    
    
    // set the scene name through the base class initializer
    RadialLineScene(){
        //        app = ofxGetAppPtr();
        //        renderWidth = app->getRenderWidth();
        //        renderHeight = app->getRenderHeight();
        renderWidth = 800;
        renderHeight = 600;
    }
    
    // scene setup
    void setup() {
        ofBackground(0);
        lineX = ofGetWidth() * .5;
        lineY = ofGetHeight() * .5;
    }
    
    // called when scene is entering, this is just a demo and this
    // implementation is not required for this class
    /*
    void updateEnter() {
        
        // called on first enter update
        if(isEnteringFirst()) {
            ofLogNotice("RadialLineScene") << "update enter";
        }
        
        // fade scene calculates normalized alpha value for us
        ofxFadeScene::updateEnter();
        
        // finished entering?
        if(!isEntering()) {
            ofLogNotice("RadialLineScene") << "update enter done";
        }
    }
    */
    
    // normal update
    void update() {
        
    }
    
    // called when scene is exiting, this is just a demo and this
    // implementation is not required for this class
    /*
    void updateExit() {
        
        // called on first exit update
        if(isExitingFirst()) {
            ofLogNotice("RadialLineScene") << "update exit";
        }
        
        // fade scene calculates normalized alpha value for us
        ofxFadeScene::updateExit();
        
        // finished exiting?
        if(!isExiting()) {
            ofLogNotice("RadialLineScene") << "update exit done";
        }
    }*/
    
    // draw
    void draw() {
        ofEnableAlphaBlending();
        ofFill();
        //        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(255, 0, 0, 255*alpha);
        
        //     ofBackground(0);
        
        drawShapes();
        
        // drawText();
        
        
        ofDisableAlphaBlending();
    }
    
    
    void drawShapes(){
        //        ofSetColor(255);
        
        ofNoFill();
        int radius{720};
        for (int degree=0; degree < numOfLines; degree++) {
            float x = 0 + radius * cos(degree * DEG_TO_RAD);
            float y = radius * sin(degree * DEG_TO_RAD);
            
            x = ofMap(ofNoise(x, ofGetElapsedTimef()), x, renderWidth, 0, renderWidth*2);
            y = ofMap(ofNoise(y, ofGetElapsedTimef()), y, renderHeight, 0, renderHeight*2);
            
            //            ofDrawCircle(
            //                         x,
            //                         y,
            //                         50);
            
            ofDrawLine(lineX, lineY, x, y);
            //        ofLog(OF_LOG_NOTICE, "x is " + ofToString(x));
        }
    }
    
    
    // cleanup
    void exit() {
        // clear();
    }
    
    
    
};
