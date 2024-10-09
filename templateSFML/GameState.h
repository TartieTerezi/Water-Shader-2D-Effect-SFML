#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Common.h"

enum States
{
	INTRO,
	MENU,
	INGAME,
	CREDIT,
	SETTINGS,
	SETTINGSINGAME,
	WINSCREEN,
	PAUSE,
	SOUNDS,
	SOUNDSINGAME,
};

enum States GetState(States);
void SetState(States*, States);

#endif