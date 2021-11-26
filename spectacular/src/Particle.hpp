//
//  Particle.hpp
//  spectacular
//
//  Created by Patrick on 24.08.21.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#include "ofMain.h"


class Particle {
public:
    Particle();
    Particle(int xpos, int ypos, float velx, float vely, float r);
    // ~Particle();

    
    float x;
    float y;
    float vx;
    float vy;
    float radius;
    float gravity{0};
    
    void setup(int xpos, int ypos, float velx, float vely, float r);
    void update();
    void draw();

    
};

#endif /* Particle_hpp */
