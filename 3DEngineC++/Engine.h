#pragma once
#include "GameObject.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Freeglutobjects.h"
#include "Point3D.h"
#include "Line3D.h"
#include "Lines3D.h"
#include "Triangle3D.h"
#include "FanStrip3D.h"
#include "Quad3D.h"
#include "Cube3D.h"
#include "Spectator.h"
#include "TexturableObjects.h"
#include <iostream>
#include <algorithm>

class Engine
{
public:
	Engine(int width, int height, bool fullscreen);
	void run();
	~Engine();
	static void setBackgroundColor(float red, float green, float blue);
	static void setMaxFPS(unsigned int FPS);

private:
	int width, height;
	bool fullscreen;
	static float r, g, b;
	static unsigned int maxFPS;
	static int frameCount;
	static int currentTime, previousTime;
	static int fps;
	static float specPosX, specPosY, specPosZ;
	static float specLookAtX, specLookAtY, specLookAtZ;
	static float specVecX, specVecY, specVecZ;
	static float camPosX, camPosY, camPosZ;

	static float fov;
	static float aspectRatio;
	static float nearClip;
	static float farClip;
	static float left;
	static float right;
	static float bottom;
	static float top;


	static void update(int value);
	static void render();
	static void reshape(int width, int height);
	static void calculateFPS();
	static void changeProjection(bool perspective);
	static void handleSpecialKeyPress(int key, int x, int y);

};
