//
//  ArrowParticle.hpp
//  spectacular
//
//  Created by Patrick on 25.08.21.
//

#ifndef ArrowParticle_hpp
#define ArrowParticle_hpp

#include <stdio.h>

#include "ofMain.h"
#include "Particle.hpp"


class ArrowParticle : public Particle {
public:
    ArrowParticle();
    // ArrowParticle(int xpos, int ypos, float velx, float vely, float r);
    // ~ArrowParticle();

    
//    float x;
//    float y;
//    float vx;
//    float vy;
//    float radius;
//    float gravity{0};
//
//    void setup(int xpos, int ypos, float velx, float vely, float r);
//    void update();
    void draw();

    
};

#endif /* ArrowParticle_hpp */
