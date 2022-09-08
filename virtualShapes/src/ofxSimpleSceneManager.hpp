//
//  ofxSceneManager.hpp
//  virtualShapes
//
//  Created by Patrick on 08.09.22.
//

#ifndef ofxSceneManager_hpp
#define ofxSceneManager_hpp

#include "ofxSimpleScene.hpp"

using namespace std;

class ofxSimpleSceneManager {
public:
    ofxSimpleSceneManager();
    virtual ~ofxSimpleSceneManager() {}

    ofxSimpleScene* getActiveScene();
    int getActiveIndex();
    int getSceneCount();

    ofxSimpleScene* getSceneByIndex(int index);
    // - ofxScene* getSceneByName(string name);
    ofxSimpleScene* loadScene(ofxSimpleScene *scene);

    void setActiveScene(int index);
    void setup();
    void update();
    void draw();

    // events:
    // - sceneLoaded
    // - senceUnloaded
    // - activeSceneChanged
    

private:
    vector<ofxSimpleScene*> scenes;
    int activeIndex;
    
};


#endif /* ofxSceneManager_hpp */
