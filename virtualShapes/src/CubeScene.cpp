//
//  CubeScene.cpp
//  virtualShapes
//
//  Created by Patrick on 08.09.22.
//

#include "CubeScene.hpp"


CubeScene::CubeScene(){
    name = typeid(this).name();
//    palette = array<ofColor, 6>{ ofColor::lightCoral, ofColor::coral, ofColor::darkorange, ofColor::yellow, ofColor::darkSalmon, ofColor::lightSalmon};
    
    // dark salmon fColor::fromHex(0xE9967A)
    
    palette = array<ofColor, 6>{ ofColor::fromHex(0xE9967A, 0.8), ofColor::fromHex(0xE9967A, 0.9), ofColor::fromHex(0xE9967A, 1.0), ofColor::fromHex(0xE9967A, 1.0), ofColor::fromHex(0xE9967A, 0.9), ofColor::fromHex(0xE9967A, 0.8)};

}

void CubeScene::setup() {
    ofBackground(0);
    for(auto box : boxes) {
        box.set(50); // box.set(50,50,50);
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

    if( spinX < 0 ){
        spinBack=false;
    }
    if( spinY < 0 ){
        spinBack=false;
    }
    
    if( spinX > maxSpinX ){
        spinBack=true;
    }
    if( spinY > maxSpinY ){
        spinBack=true;
    }
    
    
    if( time + 9 < ofGetElapsedTimef() ) {
        playNextSubScene = true;
        time = ofGetElapsedTimef();
    }

    if (ofGetFrameNum() % 10 == 0) {
        activeColor++;
        if (activeColor >= palette.size()) {
            activeColor = 0;
        }
    }
    
}

void CubeScene::draw() {
    ofEnableAlphaBlending();
    if (playNextSubScene) {
        playNextSubScene = false;
        activeSubScene++;
        if (activeSubScene > subSceneCount - 1) {
            activeSubScene = 0;
        }
    }

    switch(activeSubScene) {
        case 0:
            drawColorCubes();
            break;
        case 1:
            drawPolarCubes();
            break;
        case 2:
        default:
            drawRandomCubes();
            break;
    }
    // ofDisableAlphaBlending(); // default since 0.8
    ofLogNotice("CubeScene alpha") << alpha;
    ofDisableAlphaBlending();
}

void CubeScene::drawPolarCubes() {
    ofFill();

    int boxRowCount = 4;
    for(auto box : boxes) {
        for (int x=0; x <= boxRowCount; x++) {
            for (int y=0; y <= boxRowCount; y++) {
                ofLogNotice("(ofGetWidth() / boxRowCount) * x") << (ofGetWidth() / boxRowCount) * x;
                ofLogNotice("ofGetWidth()") << ofGetWidth();
                
                // angle to be in radians to use sin / cos
                float angle = ofRandom(ofDegToRad(360.0));
                float distance = ofRandom(35);

                box.rotateDeg(angle, 1.0, 0.0, 0.0);
                box.rotateDeg(angle, 0, 1.0, 0.0);
                
                // Formula for converting from polar to Cartesian coordinates:
                // x = cos(polar angle) * (polar distance)
                // y = sin(polar angle) * (polar distance)
                
                float xOffset = cos(angle) * distance;
                float yOffset = sin(angle) * distance;

                box.set(ofRandom(15,50));
                // ofScale(ofRandom(3),ofRandom(3),ofRandom(3));
                box.setPosition(
                                (ofGetWidth() * .5) + xOffset,
                                (ofGetHeight() * .5) + yOffset,
                                0);
                
                // Some fun Coloring
                box.setSideColor(box.SIDE_FRONT, ofColor::red);
                box.setSideColor(box.SIDE_LEFT, ofColor::green);
                box.setSideColor(box.SIDE_RIGHT, ofColor::blue);
                box.setSideColor(box.SIDE_TOP, ofColor::darkRed);
                box.setSideColor(box.SIDE_BACK, ofColor::darkGreen);
                box.setSideColor(box.SIDE_BOTTOM, ofColor::darkBlue);

                box.draw();
            }
        }
    }

}


void CubeScene::drawColorCubes() {
    ofFill();

    int boxRowCount = 4;
    for(auto box : boxes) {
        for (int x=0; x <= boxRowCount; x++) {
            for (int y=0; y <= boxRowCount; y++) {
                ofLogNotice("(ofGetWidth() / boxRowCount) * x") << (ofGetWidth() / boxRowCount) * x;
                ofLogNotice("ofGetWidth()") << ofGetWidth();
                // ofScale(ofRandom(3),ofRandom(3),ofRandom(3));
                box.setPosition((ofGetWidth() / boxRowCount) * x, (ofGetHeight() / boxRowCount) * y, 0);
                box.rotateDeg(spinX, 1.0, 0.0, 0.0);
                box.rotateDeg(spinY, 0, 1.0, 0.0);
                // Some fun Coloring
                box.setSideColor(box.SIDE_FRONT, ofColor::red);
                box.setSideColor(box.SIDE_LEFT, ofColor::green);
                box.setSideColor(box.SIDE_RIGHT, ofColor::blue);
                box.setSideColor(box.SIDE_TOP, ofColor::darkRed);
                box.setSideColor(box.SIDE_BACK, ofColor::darkGreen);
                box.setSideColor(box.SIDE_BOTTOM, ofColor::darkBlue);

                box.draw();
            }
        }
    }

}


void CubeScene::drawRandomCubes() {
    ofNoFill();
    ofScale(1,1,1);

    int boxRowCount = 4;
    int w = ofGetWidth();
    int h = ofGetHeight();

    float scale = ofMap(sin(ofGetElapsedTimef()), .1, 2.f, .1, 2.f, true);
    // ofLogNotice("scale") << scale;

    for(auto box : boxes) {
        ofScale(scale,1,1);
        for (int x=0; x <= boxRowCount; x++) {
            for (int y=0; y <= boxRowCount; y++) {
                ofSetColor(palette[activeColor]);
                // ofScale(scale,scale,scale);
                box.setPosition((w / boxRowCount) * x, (h / boxRowCount) * y, 0);
                box.rotateDeg(spinX, 1.0, 0.0, 0.0);
                box.rotateDeg(spinY, 0, 1.0, 0.0);
                box.draw();
            }
        }
        ofScale(1,1,1);
    }
    // ofLogNotice("(ofGetWidth() / boxRowCount) * x") << (w / boxRowCount) * x;
    // ofLogNotice("ofGetWidth()") << w;
}
