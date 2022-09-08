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
    box.set(50,50,50);
}

void CubeScene::update() {
    spinX+=.01;
    spinY+=.01;
    if(spinX > maxSpinX){
        spinX=0;
    }
    if(spinY > maxSpinY){
        spinY=0;
    }
}

void CubeScene::draw() {
    ofEnableAlphaBlending();
    ofFill();
    // ofSetRectMode(OF_RECTMODE_CENTER);
    // ofBackground(0);
//    box.setPosition(ofGetWidth()*.5, ofGetHeight()*.75, 0);
    box.setPosition(ofGetWidth()*.5, ofGetHeight()*.75, 0);
    box.rotateDeg(spinX, 1.0, 0.0, 0.0);
    box.rotateDeg(spinY, 0, 1.0, 0.0);
    
    box.draw();

    ofDisableAlphaBlending();
    ofLogNotice("TitleScene alpha") << alpha;
}
