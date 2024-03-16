#include "Spectator.h"

void Spectator::setPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}

void Spectator::setLookAt(float x, float y, float z) {
    lookX = x;
    lookY = y;
    lookZ = z;
}

void Spectator::setUpVector(float x, float y, float z) {
    upX = x;
    upY = y;
    upZ = z;
}

void Spectator::update() {
    gluLookAt(posX, posY, posZ, lookX, lookY, lookZ, upX, upY, upZ);
}
