#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


#define OSC_PORT 12345


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
private:
    ofTrueTypeFont font;
    ofTrueTypeFont smallfont;
    ofImage logoImage;
    // video
    std::vector<ofVideoPlayer> videoPlayers;
    int curmovie{0};
    // osc
    ofxOscReceiver receiver;
    ofxOscSender sender;
    int movienum{0};
    // xml
    ofXml xml;
};
