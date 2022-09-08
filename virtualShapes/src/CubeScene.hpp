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
    ofParameter<float> maxSpinX{0};
    ofParameter<float> maxSpinY{0};
    float spinX{0.1};
    float spinY{0.1};

private:
    ofBoxPrimitive box;
    
};


#endif /* CubeScene_hpp */
