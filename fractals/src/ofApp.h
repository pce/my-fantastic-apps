#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
        void setupMainmesh();
		void update();
        void updateMainmesh();
		void draw();
        void drawMainmesh();
        void drawLines();
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
    bool bSmooth{true};
    ofVboMesh mainMesh;
    ofMesh mesh;
    ofCamera cam;
    float extrusionAmount{300};
};
