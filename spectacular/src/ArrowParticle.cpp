//
//  ArrowParticle.cpp
//  spectacular
//
//  Created by Patrick on 25.08.21.
//

#include "ArrowParticle.hpp"

ArrowParticle::ArrowParticle() {};
/*
ArrowParticle::ArrowParticle(int xpos, int ypos, float velx, float vely, float r) :
x(xpos),
y(ypos),
vx(velx),
vy(vely),
radius(r) {
    
};
*/

void ArrowParticle::draw() {
    ofSetColor(255);

    ofVec3f arrowTailPoint = ofVec3f(x,y,0);
    // ofVec3f arrowHeadPoint = ofVec3f(x+150,y+100,0);
    ofVec3f arrowHeadPoint = ofVec3f(x*radius,y*radius,0);
    ofDrawArrow(arrowTailPoint, arrowHeadPoint, 20.0);
    
}
