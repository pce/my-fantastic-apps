#pragma once

#include "ofxSimpleScene.hpp"

class TitleScene : public ofxSimpleScene {
    
public:
    
    int mainFontSize = 24;
    
    int titleX{0};
    int titleY{120};
    int textX{0};
    int textY{120};
    int textZ{500};
    
    int lineX{0};
    int lineY{0};
    
    int numOfLines{360};
    
    ofTrueTypeFont mainFont;
    string currentTitle[4]{"a big turtle", "sighs", "because of", "the mighty snake"};

    TitleScene() {
        name = typeid(this).name();
    }
    
    void setup() {
        mainFont.load("fonts/Waukegan LDO Extended Bold.ttf", mainFontSize);
        ofBackground(0);
        lineX = renderWidth * .5;
        lineY = renderHeight * .5;
        titleY = (mainFontSize * 4) + ofGetHeight() * .5;
        titleX = (mainFontSize * 2) + ofGetWidth();
    }

    void update() {
        titleX--;
        if (titleX <= -renderWidth - renderWidth * .5) {
            titleX = renderWidth + ((renderWidth * .5) / 4);
        }
    }
    
    void draw() {
        ofEnableAlphaBlending();
        ofFill();
        // ofSetRectMode(OF_RECTMODE_CENTER);
        // ofBackground(0);
        drawShapes();
        drawText();
        
        ofDisableAlphaBlending();
        ofLogNotice("TitleScene alpha") << alpha;
    }
    
    void drawText(){
        
        float maxDistance = 50;
        float time = ofGetElapsedTimef();
        float x, y, angle, distance;
        
        for (int line=0; line<4; line++) {
            x = titleX;
            y = titleY;
            
            angle = ofNoise(0.0 + (time * 2.0)) * TWO_PI;
            distance = ofNoise(5.0 + (time * 2.0)) * maxDistance;
            
            x += distance * cos(angle) * 0.1;
            y += distance * sin(angle) * 0.1;
            
            ofSetColor(ofColor::darkSlateBlue, 255*alpha);
            
            mainFont.drawString(currentTitle[line], x, y + line * (mainFontSize*2)+1);
            
            ofSetColor(ofColor::darkSlateGray, 255*alpha);
            mainFont.drawString(currentTitle[line], x, y + line * (mainFontSize*2));
            
            ofSetColor(ofColor::ghostWhite, 255*alpha);
            mainFont.drawString(currentTitle[line], titleX, titleY + line * (mainFontSize*2));
        }
    }
    
    
    void drawShapes(){
        ofSetColor(ofColor::ghostWhite, 255*alpha);
        
        ofNoFill();
        int radius{720};
        for (int degree=0; degree < numOfLines; degree++) {
            float x = 0 + radius * cos(degree * DEG_TO_RAD);
            float y = radius * sin(degree * DEG_TO_RAD);
            
            x = ofMap(ofNoise(x, ofGetElapsedTimef()), x, renderWidth, 0, renderWidth*2);
            y = ofMap(ofNoise(y, ofGetElapsedTimef()), y, renderHeight, 0, renderHeight*2);
            
            ofDrawCircle(
                         x,
                         y,
                         x * 0.5);
            
//            ofDrawLine(lineX, lineY, x, y);
            //        ofLog(OF_LOG_NOTICE, "x is " + ofToString(x));
        }
    }
    
//    void teardown() { cleanUp(); }
    
    
};
