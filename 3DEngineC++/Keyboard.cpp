#include "Keyboard.h"
#include <iostream>

std::map<unsigned char, bool> Keyboard::keyDown;
std::map<unsigned char, bool> Keyboard::keyUp;
std::map<unsigned char, bool> Keyboard::keyHeld;

void Keyboard::clear()
{
	for (auto& key : keyDown)
	{
		keyDown[key.first] = false;
	}
	for (auto& key : keyUp)
	{
		keyUp[key.first] = false;

	}
}

bool Keyboard::isKeyDown(unsigned char key)
{
	return keyDown[key];
}

bool Keyboard::isKeyUp(unsigned char key)
{
	return keyUp[key];
}
bool Keyboard::isKeyHeld(unsigned char key)
{
	return keyHeld[key];
}
void Keyboard::callBackDown(unsigned char key, int x, int y)
{
	if (keyDown.find(key) != keyDown.end())
	{
		if (keyHeld[key] != true)
		{
			keyDown[key] = true;
		}
		keyHeld[key] = true;
	}
	else
	{
		keyDown[key] = true;
	}

}
void Keyboard::callBackUp(unsigned char key, int x, int y)
{
	keyUp[key] = true;
	keyHeld[key] = false;
}