#pragma once
#include "SDL.h"
#include "controller.h"
#include "entity.h"
#include "net.h"

using namespace std;

class Engine {
	SDL_Surface *SCREEN;
	SDL_Event EVENT;
	Controller *control;
	Entity *player;
	NetPlayer *netPlayer;
	Net *net;
	int SPEED;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int SPRITE_SIZE;
	int STATE_END;

public:
	Engine();
	Engine(int width, int height);
	void Init();
	void Update();
	void Exit();
	void setState(int state);
	int getSpeed();
	int getState();
	int getWidth();
	int getHeight();
	int getSpriteSize();
};