//
//  Particle.cpp
//  spectacular
//
//  Created by Patrick on 24.08.21.
//

#include "Particle.hpp"

Particle::Particle() {};

Particle::Particle(int xpos, int ypos, float velx, float vely, float r) :
x(xpos),
y(ypos),
vx(velx),
vy(vely),
radius(r) {
    
};

void Particle::setup(int xpos, int ypos, float velx, float vely, float r) {
    x = xpos;
    y = ypos;
    vx = velx;
    vy = vely;
    radius = r;
}

void Particle::update() {
    vy = vy + gravity;
    y += vy;
    x += vx;
}
void Particle::draw() {
    ofSetColor(255);
    ofDrawSphere(x, y, radius*2, radius*2);
    // ofDrawBox(x, y, radius*2, radius*2);

}
