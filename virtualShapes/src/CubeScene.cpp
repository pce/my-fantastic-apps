//
//  CubeScene.cpp
//  virtualShapes
//
//  Created by Patrick on 08.09.22.
//

#include "CubeScene.hpp"


CubeScene::CubeScene(){
    name = typeid(this).name();
}

void CubeScene::setup() {
    ofBackground(0);
    for(auto box : boxes) {
        box.set(50,50,50);
    }
}

void CubeScene::update() {
    
    if (spinBack) {
        spinX-=.01;
        spinY-=.01;
    } else {
        spinX+=.01;
        spinY+=.01;
    }

    if(spinX < 0){
        spinBack=false;
    }
    if(spinY < 0){
        spinBack=false;
    }
    
    if(spinX > maxSpinX){
        spinBack=true;
    }
    if(spinY > maxSpinY){
        spinBack=true;
    }
}

void CubeScene::draw() {
    ofEnableAlphaBlending();
    ofFill();
    // ofSetRectMode(OF_RECTMODE_CENTER);
    // ofBackground(0);
//    box.setPosition(ofGetWidth()*.5, ofGetHeight()*.75, 0);
    
    int boxRowCount = 4;
    
    for(auto box : boxes) {
        for (int x=0; x <= boxRowCount; x++) {
            for (int y=0; y <= boxRowCount; y++) {
                ofLogNotice("(ofGetWidth() / boxRowCount) * x") << (ofGetWidth() / boxRowCount) * x;
                ofLogNotice("ofGetWidth()") << ofGetWidth();
                box.setPosition((ofGetWidth() / boxRowCount) * x, (ofGetHeight() / boxRowCount) * y, 0);
                box.rotateDeg(spinX, 1.0, 0.0, 0.0);
                box.rotateDeg(spinY, 0, 1.0, 0.0);
                box.draw();
            }
        }
    }

    ofDisableAlphaBlending();
    ofLogNotice("TitleScene alpha") << alpha;
}
