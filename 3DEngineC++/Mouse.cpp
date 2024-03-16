#include "Mouse.h"
#include <gl\freeglut.h>

std::map<int, bool> Mouse::buttonDown;
std::map<int, bool> Mouse::buttonUp;
std::map<int, bool> Mouse::buttonHeld;
int Mouse::x = 0;
int Mouse::y = 0;

bool Mouse::isbuttonDown(int button)
{
	return buttonDown[button];
}

bool Mouse::isbuttonUp(int button)
{
	return buttonUp[button];
}

bool Mouse::isbuttonHeld(int button)
{
	return buttonHeld[button];
}

int Mouse::getX()
{
	return x;
}

int Mouse::getY()
{
	return y;
}

void Mouse::clear()
{
	for (auto& button : buttonDown)
	{

		if (buttonDown[button.first] == true)
		{
			buttonDown[button.first] = false;
			buttonHeld[button.first] = true;
		}
	}
	for (auto& button : buttonUp)
	{
		buttonUp[button.first] = false;
	}
}

void Mouse::mouseCallBack(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		buttonDown[button] = true;
	}
	else if (state == GLUT_UP)
	{
		buttonUp[button] = true;
		buttonHeld[button] = false;
	}
}

void Mouse::motionCallBack(int xm, int ym)
{
	x = xm;
	y = ym;
}