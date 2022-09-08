//
//  ofxSceneManager.cpp
//  virtualShapes
//
//  Created by Patrick on 08.09.22.
//

#include "ofxSimpleSceneManager.hpp"


ofxSimpleSceneManager::ofxSimpleSceneManager() {}
//ofxSimpleSceneManager::~ofxSimpleSceneManager() {}

ofxSimpleScene* ofxSimpleSceneManager::getActiveScene() {
    return scenes.at(activeIndex);
}

int ofxSimpleSceneManager::getSceneCount(){
    return scenes.size();
}

ofxSimpleScene* ofxSimpleSceneManager::getSceneByIndex(int index) {
    return scenes.at(index);
}

int ofxSimpleSceneManager::getActiveIndex() {
    return activeIndex;
}

void ofxSimpleSceneManager::setActiveScene(int index) {
    activeIndex = index;
}

ofxSimpleScene* ofxSimpleSceneManager::loadScene(ofxSimpleScene* scene) {
    scenes.push_back(scene);
}

void ofxSimpleSceneManager::setup() {
    for (auto scenePointer : scenes) {
        scenePointer->setup();
    }
}

void ofxSimpleSceneManager::update() {
    scenes[activeIndex]->update();
}


void ofxSimpleSceneManager::draw() {
    scenes[activeIndex]->draw();
}
