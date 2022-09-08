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
    bool isLoaded{false};
    string name;
    // 0-1, belongs to a Transistion
    float alpha{1.0};
};


#endif /* ofxSimpleScene_hpp */
