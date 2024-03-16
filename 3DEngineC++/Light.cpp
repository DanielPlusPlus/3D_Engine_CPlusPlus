#include "Light.h"

void Light::setup() {

    float amb[] = { 0.3f, 0.3f, 0.3f, 1.0f }; // RGBA
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
    float diff[] = { 0.7f, 0.7f, 0.7f, 1.0f }; // RGBA
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
    float spec[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // RGBA
    glLightfv(GL_LIGHT0, GL_SPECULAR, spec);
    float pos[] = { 0.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1.0);

    float mambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mambient);
    float mdiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mdiffuse);
    float mspecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mspecular);
    float mshininess[] = { 50.0f };
    glMaterialfv(GL_FRONT, GL_SHININESS, mshininess);

    // Wczanie oœwietlenia
    enablelight();

    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glEnable(GL_COLOR_MATERIAL);
}


void Light::enableFlatShading() {
    enablelight();
    glShadeModel(GL_FLAT);
}

void Light::enableGouraudShading() {
    enablelight();
    glShadeModel(GL_SMOOTH);
}

void Light::disablelight()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void Light::enablelight()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}