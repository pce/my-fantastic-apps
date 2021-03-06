#pragma once

#include "ofMain.h"
#include "AppState.h"

#define HAVE_OFX_GUI

#ifdef HAVE_OFX_GUI
#include "ofxGui.h"
#endif

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void drawSpheres();
    void drawBoxes();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void factorChanged(int & factor);

    ofLight light;
    ofTexture mTex;
    ofEasyCam cam;
    ofImage image;

    float degrees{0};
    
    ofParameter<int> factor{4};
    ofParameter<bool> bFill;

    AppState state;
    
    bool bShowGui;
#ifdef HAVE_OFX_GUI
    ofxPanel gui;
#endif
};
