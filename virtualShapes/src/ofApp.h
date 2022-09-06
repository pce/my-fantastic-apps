#pragma once

#include "ofMain.h"

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
    void drawShapes();
    void drawText();
    
    ofTrueTypeFont mainFont;
    
    string currentTitle[4]{"a big turtle", "sighs", "because of", "the mighty snake"};
    
    int mainFontSize = 24;
    
    int titleX{0};
    int titleY{120};
    int textX{0};
    int textY{120};
    int textZ{500};

    int lineX{0};
    int lineY{0};

    int numOfLines{360};
    
    int numOfTriangles{9};
};
