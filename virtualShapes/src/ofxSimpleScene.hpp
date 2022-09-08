//
//  ofxScene.hpp
//  virtualShapes
//
//  Created by Patrick on 08.09.22.
//

#ifndef ofxSimpleScene_hpp
#define ofxSimpleScene_hpp

#include "ofMain.h"

class ofxSimpleScene : public ofBaseApp {
public:
    ofxSimpleScene();
    bool isLoaded{false};
    string name{"undefined"};
    // 0-1, belongs to a Transition
    float alpha{1.0};
protected:
    float renderWidth{.0};
    float renderHeight{.0};

};


#endif /* ofxSimpleScene_hpp */
