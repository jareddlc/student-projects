#pragma once
#include "SDL.h"


using namespace std;

class Engine;

class Controller {
	Uint8 *keyState;
	SDL_Rect coordinate;
	Engine *engine;
	int speed;
	int width;
	int height;
	int spriteSize;

public:
	Controller(Engine *engine);
	void Update();
	SDL_Rect getCoordinate();
	int getX();
	int getY();
};