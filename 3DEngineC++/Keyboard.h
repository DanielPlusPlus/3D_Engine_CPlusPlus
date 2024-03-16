#pragma once
#include <map>
class Keyboard
{
private:
	static std::map<unsigned char, bool> keyDown;
	static std::map<unsigned char, bool> keyUp;
	static std::map<unsigned char, bool> keyHeld;
public:
	static void clear();
	static bool isKeyDown(unsigned char key);
	static bool isKeyUp(unsigned char key);
	static bool isKeyHeld(unsigned char key);
	static void callBackDown(unsigned char key, int x, int y);
	static void callBackUp(unsigned char key, int x, int y);
};
