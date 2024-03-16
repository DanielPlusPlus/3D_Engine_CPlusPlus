#pragma once
#include <map>
class Mouse
{
private:
	static std::map<int, bool> buttonDown;
	static std::map<int, bool> buttonUp;
	static std::map<int, bool> buttonHeld;
	static int x, y;
public:
	static bool isbuttonDown(int button);
	static bool isbuttonUp(int button);
	static bool isbuttonHeld(int button);
	static int getX();
	static int getY();
	static void clear();
	static void mouseCallBack(int button, int state, int x, int y);
	static void motionCallBack(int xm, int ym);
};