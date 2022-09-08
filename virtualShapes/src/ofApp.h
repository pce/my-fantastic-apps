#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "ofxSimpleSceneManager.hpp"

class TitleScene;
class CubeScene;

class ofApp : public ofBaseApp{
    
public:
    
    ofApp() {};
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    void windowResized(int w, int h);
    
    // rendering
    ofxSimpleSceneManager sceneManager;
    int lastScene;
    
    // gui
    bool bShowPanel{false};
    ofxPanel panel;
    
    // keep a pointer to the Title Scene, so we can modify it more easily
    TitleScene *titleScene;
    CubeScene *cubeScene;

};



