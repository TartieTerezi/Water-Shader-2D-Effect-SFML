#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H


#include "GameState.h"


struct Data
{
	sf::RenderWindow* window;
	sf::Event event;
	bool isLoaded = false;
	float dt;
	sf::Clock clock;
	sf::RenderTexture RT;
};

#endif // !GAME_MANAGER_H


