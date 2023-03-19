#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();
    void drawBox();
    void drawLines();
    void drawGrid();
    void drawShapes();
    void handleFile(ofFileDialogResult openFile);


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
    // sound
    ofSoundPlayer track;
    // fft
    static constexpr size_t nBandsToGet = 128;
    std::array<float, nBandsToGet> fftSmoothed{{0}};
    float *soundSpectrum;
    // ani
    float rotation{0};
    int animatedGridSize{100};
    uint64_t lastTime{0};
    int counter{0};
    ofColor bgColor1;
    ofColor bgColor2;
    
    // cam
    ofEasyCam cam;
    ofParameter<float> camX{52.0};
    ofParameter<float> camY{69.0};
    ofParameter<float> camZ{69.0};
    ofLight light;

    // gui
    ofParameter<float> fftDecay;
    ofParameter<float> multFactor;
    ofParameter<bool> bEnableMouseInput;
    ofParameter<bool> bAnimateGrid;
    ofParameter<bool> bEnableLight;
    ofParameter<bool> bShowOuterCube;
    ofParameter<ofColor> color1;
    ofParameter<ofColor> color2;
    ofParameter<ofColor> color3;
    ofParameter<int> gridSize;
    ofParameter<int> bgSpeedMs;
    ofParameter<int> bgHue;
    // scenes
    ofParameter<bool> bShowGridScene;
    ofParameter<bool> bShowCubeScene;
    ofParameter<bool> bShowLinesScene;
    
    // ofParameter<int> factor{4};
    ofxPanel gui;
    bool bShowGui{false};
};
