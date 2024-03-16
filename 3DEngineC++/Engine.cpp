#include "Engine.h"
#include "Light.h"

unsigned int Engine::maxFPS;
int Engine::frameCount = 0;
int Engine::currentTime;
int Engine::previousTime;
int Engine::fps;
float Engine::r = 0.0f;
float Engine::g = 0.0f;
float Engine::b = 0.0f;

float Engine::fov = 45.0f;
float Engine::aspectRatio = 8.0f / 6.0f;
float Engine::nearClip = 0.1f;
float Engine::farClip = 20.0f;
float Engine::left = -4.0f;
float Engine::right = 4.0f;
float Engine::bottom = -3.0f;
float Engine::top = 3.0f;

float Engine::specPosX = 0.0f;
float Engine::specPosY = 0.0f;
float Engine::specPosZ = 5.0f;
float Engine::specLookAtX = 0.0f;
float Engine::specLookAtY = 0.0f;
float Engine::specLookAtZ = -1.0f;
float Engine::specVecX = 0.0f;
float Engine::specVecY = 1.0f;
float Engine::specVecZ = 0.0f;

float Engine::camPosX = 0.0f;
float Engine::camPosY = 0.0f;
float Engine::camPosZ = 5.0f;

float cameraSpeed = 0.5f;

Cube3D cube;
Spectator spectator;

Engine::Engine(int width, int height, bool fullscreen) : width(width), height(height), fullscreen(fullscreen)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    glutCreateWindow("Game Engine");

    if (fullscreen)
    {
        glutFullScreen();
    }

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(render);
    glutTimerFunc(0, update, 0);
    glutReshapeFunc(reshape);
    glutMouseFunc(Mouse::mouseCallBack);
    glutMotionFunc(Mouse::motionCallBack);
    glutPassiveMotionFunc(Mouse::motionCallBack);
    glutKeyboardUpFunc(Keyboard::callBackUp);
    glutKeyboardFunc(Keyboard::callBackDown);
    glutSpecialFunc(handleSpecialKeyPress);
    previousTime = glutGet(GLUT_ELAPSED_TIME);

    spectator.setPosition(specPosX, specPosY, specPosZ);
    spectator.setLookAt(specLookAtX, specLookAtY, specLookAtZ);
    spectator.setUpVector(specVecX, specVecY, specVecZ);
    spectator.update();

    Light::setup();

}

void Engine::run()
{
    glutMainLoop();
}

Engine::~Engine()
{
    glutDestroyWindow(glutGetWindow());
}

void Engine::setBackgroundColor(float red, float green, float blue)
{
    r = std::clamp(red, 0.0f, 1.0f);
    g = std::clamp(green, 0.0f, 1.0f);
    b = std::clamp(blue, 0.0f, 1.0f);
    glClearColor(r, g, b, 1.0f);
}

void Engine::setMaxFPS(unsigned int FPS)
{
    maxFPS = FPS;
}

void Engine::handleSpecialKeyPress(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        cube.rotate(5.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (key == GLUT_KEY_DOWN) {
        cube.rotate(5.0f, glm::vec3(-1.0f, 0.0f, 0.0f));
    }
    if (key == GLUT_KEY_LEFT) {
        
        cube.rotate(5.0f, glm::vec3(0.0f, -1.0f, 0.0f));
    }
    if (key == GLUT_KEY_RIGHT) {
        
        cube.rotate(5.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    }
    glutPostRedisplay();
}

void Engine::update(int value)
{
    calculateFPS();
    if (Keyboard::isKeyDown('l')) //enablelight
    {
        Light::enablelight();
    }
    if (Keyboard::isKeyDown('i')) //disable light
    {
        Light::disablelight();
    }
    if (Keyboard::isKeyDown('g')) //gouradshading
    {
        Light::enableGouraudShading();
    }
    if (Keyboard::isKeyDown('f')) //flatshading
    {
        Light::enableFlatShading();
    }
    if (Keyboard::isKeyDown('t')) //translate object
    {
        cube.translate(glm::vec3(0.5f, 0.5f, 0.5f));
    }
    if (Keyboard::isKeyDown('c')) //scale object
    {
        cube.scale(glm::vec3(0.3f, 0.9f, 0.8f));
    }
    if (Keyboard::isKeyDown('p'))
    {
        changeProjection(true);
    }
    if (Keyboard::isKeyDown('o'))
    {
        fov += 1;
        changeProjection(true);
    }
    if (Keyboard::isKeyDown('O'))
    {
        fov -= 1;
        changeProjection(true);
    }
    if (Keyboard::isKeyDown('P'))
    {
        changeProjection(false);
    }

    if (Keyboard::isKeyDown('w'))
    {
        spectator.setPosition(specPosX + specLookAtX*cameraSpeed, specPosX + specLookAtY * cameraSpeed, specPosX + specLookAtZ * cameraSpeed);
        spectator.update();
    }
    if (Keyboard::isKeyDown('a'))
    {
        spectator.setPosition(specPosX - (specLookAtY*specVecZ - specVecY*specLookAtZ) * cameraSpeed, 
            specPosX - (specLookAtZ*specVecX - specVecZ*specLookAtX) * cameraSpeed, 
            specPosX - (specLookAtX * specVecY - specVecX*specLookAtY) * cameraSpeed);
        spectator.update();
    }
    if (Keyboard::isKeyDown('s'))
    {
        spectator.setPosition(specPosX - specLookAtX * cameraSpeed, specPosX - specLookAtY * cameraSpeed, specPosX - specLookAtZ * cameraSpeed);
        spectator.update();
    }
    if (Keyboard::isKeyDown('d'))
    {
        spectator.setPosition(specPosX + (specLookAtY * specVecZ - specVecY * specLookAtZ) * cameraSpeed,
            specPosX + (specLookAtZ * specVecX - specVecZ * specLookAtX) * cameraSpeed,
            specPosX + (specLookAtX * specVecY - specVecX * specLookAtY) * cameraSpeed);
        spectator.update();
    }
    if (Keyboard::isKeyDown('u'))
    {
        spectator.setPosition(specPosY + specVecX * cameraSpeed, specPosY + specVecY * cameraSpeed,specPosY + specVecZ * cameraSpeed);
        spectator.update();
    }
    if (Keyboard::isKeyDown('n'))
    {
        spectator.setPosition(specPosY - specVecX * cameraSpeed, specPosY - specVecY * cameraSpeed, specPosY - specVecZ * cameraSpeed);
        spectator.update();
    }
    if (Keyboard::isKeyDown('1'))
    {
        camPosY += cameraSpeed;
        glTranslatef(-camPosX, -camPosY, 0.0f);
    }
    if (Keyboard::isKeyDown('2'))
    {
        camPosY -= cameraSpeed;
        glTranslatef(-camPosX, -camPosY, 0.0f);
    }
    if (Keyboard::isKeyDown('3'))
    {
        camPosX += cameraSpeed;
        glTranslatef(-camPosX, -camPosY, 0.0f);
    }
    if (Keyboard::isKeyDown('4'))
    {
        camPosX -= cameraSpeed;
        glTranslatef(-camPosX, -camPosY, 0.0f);
    }
    if (Keyboard::isKeyDown(27))
    {
        exit(0);
    }
    int targetMillis = 1000 / maxFPS;
    int elapsedMillis = glutGet(GLUT_ELAPSED_TIME) - previousTime;
    int remainingMillis = targetMillis - elapsedMillis;

    glutPostRedisplay();
    Keyboard::clear();
    Mouse::clear();
    glutTimerFunc(1000 / maxFPS, update, 0);
}


void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*
    //Punkt (pixel)
    float points[] = { 0,0,0,0.1,0.1,0 };
    float colors6[] = { 1,0,0,1,0,0 };
    Point3D point;
    point.render(points,colors6,2);

    //Odcinek
    Line3D line2;
    float lines[] = {
        -0.6f,-0.6f,0.0f,
        0.6f,-0.6f,0.0f
    };
    float colors5[] = { 1, 1, 0, 1,0,0 };

    line2.render2(lines,colors5,2);

    //Linia ³amana
    Lines3D lines2;
    float polylines[] = { 0.0f, 0.0f, 0.0f, 1.0f, .3f, 0.0f, 0.1f, 0.5f, 0.0f };
    float colors4[] = { 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f };
    lines2.render(polylines,colors4,3);
    */
    Triangle3D triangle;
    float triangles[] = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
    };
    float colors3[] = {
        1.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,
        0.0f,0.0f,1.0f
    };
    triangle.render(triangles,colors3,3);
    /*
    //Pasy i wachlarze
    FanStrip3D fs;
    float fanVertices[] = {
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.0f, 0.1f, 0.0f
    };

    float stripVertices[] = {
        0.0f, 0.0f, 0.0f,
        5.0f, 0.0f, 0.0f,
        0.0f, 5.0f, 0.0f,
        5.0f, 5.0f, 0.0f,
        0.0f, 10.0f, 0.0f
    };
    float colors[] = {1,1,0,
        0,0,1,
        1,1,1,
        0,1,0,
        1,0,0
    };
    fs.renderFan(fanVertices,colors,5);
    //fs.renderStrip(stripVertices,colors,5);
    //Czworok¹t
    Quad3D quad;
    float colors2[] = {
        0,1,0,
        0,1,0,
        0,1,0,
        0,1,0
    };
    float quads[] = { -0.2,0,0,-0.2,0.4,0,0.4,0.4,0,0.4,0,0 };
    quad.render(quads, colors2, 4);

    //Szeœcian
    float cube_vert[] =
    {
        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f
    };

    float cube_norm[] = {
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f
    };

    float cube_cols[] = {
        1.0f, 0.3f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 1.0f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 1.0f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 0.3f, 0.3f
    };

    unsigned char cube_ind[] = {
        0, 1, 2,
        2, 1, 3,
        4, 5, 6,
        6, 5, 7,
        0, 1, 5,
        0, 5, 4,
        2, 3, 7,
        2, 7, 6,
        0, 4, 6,
        0, 6, 2,
        1, 5, 7,
        1, 7, 3
    };

    Cube3D cube;
    cube.render(cube_vert, cube_norm, cube_cols, cube_ind);
    */

    float cube_vert[] =
    {
        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f
    };

    float cube_norm[] = {
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f
    };

    float cube_cols[] = {
        1.0f, 0.3f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 1.0f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 1.0f, 0.3f,
        1.0f, 0.3f, 0.3f,
        1.0f, 0.3f, 0.3f
    };

    unsigned char cube_ind[] = {
        0, 1, 2,
        2, 1, 3,
        4, 5, 6,
        6, 5, 7,
        0, 1, 5,
        0, 5, 4,
        2, 3, 7,
        2, 7, 6,
        0, 4, 6,
        0, 6, 2,
        1, 5, 7,
        1, 7, 3
    };

    float textureCoordinates[] = {

        0.0f, 0.0f,
        1.0f, 0.0f, 
        0.0f, 1.0f, 
        1.0f, 1.0f,

        1.0f, 0.0f,  
        0.0f, 1.0f,  
        1.0f, 1.0f,  
        0.0f, 0.0f,


    };

    //cube.render(cube_vert, cube_norm, cube_cols, cube_ind);
    //Tekstury
    BitmapHandler texture(1024, 1024);
    texture.loadFromFile("texture1.jpg");
    TexturableObjects cubeTexture;
    cubeTexture.texture = texture;

    cubeTexture.bindTexture();

    cube.renderTextureColored(cube_vert, cube_norm,cube_cols, cube_ind, textureCoordinates);

    cubeTexture.unbindTexture();

    glutSwapBuffers();
    glFlush();
}

void Engine::reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<float>(width) / height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Engine::changeProjection(bool perspective) {
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (perspective) {
        gluPerspective(fov, aspectRatio, nearClip, farClip);
    }
    else {
        glOrtho(left, right, bottom, top, nearClip, farClip);
    }

    glMatrixMode(GL_MODELVIEW);
}

void Engine::calculateFPS()
{
    frameCount++;
    currentTime = glutGet(GLUT_ELAPSED_TIME);

    if (currentTime - previousTime > 1000)
    {
        fps = frameCount * 1000.0 / (currentTime - previousTime);
        std::cout << "FPS: " << fps << std::endl;

        frameCount = 0;
        previousTime = currentTime;
    }
}