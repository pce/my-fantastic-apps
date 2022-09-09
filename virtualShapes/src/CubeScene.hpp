//
//  CubeScene.hpp
//  virtualShapes
//
//  Created by Patrick on 08.09.22.
//

#ifndef CubeScene_hpp
#define CubeScene_hpp

#include "ofMain.h"
#include "ofxSimpleScene.hpp"

class CubeScene : public ofxSimpleScene {

public:
    CubeScene();
    void setup();
    void update();
    void draw();
    ofParameter<float> maxSpinX{10};
    ofParameter<float> maxSpinY{10};
    float spinX{0.1};
    float spinY{0.1};
    bool spinBack{false};
    
private:
    ofBoxPrimitive boxes[25];
};


#endif /* CubeScene_hpp */
