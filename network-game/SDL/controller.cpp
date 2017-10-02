#include "controller.h"
#include "engine.h"
#include <Windows.h>

Controller::Controller(Engine *egn){
	engine = egn;
	keyState = SDL_GetKeyState(NULL);
	coordinate.x = 0;
	coordinate.y = 0;
	speed = engine->getSpeed();
	width = engine->getWidth();
	height = engine->getHeight();
	spriteSize = engine->getSpriteSize();
}

void Controller::Update()
{
	//Handle Movement
	if(keyState[SDLK_LEFT] || keyState[SDLK_a]){
		coordinate.x -= speed;
	}
	if(keyState[SDLK_RIGHT] || keyState[SDLK_d]){
		coordinate.x += speed;
	}
	if(keyState[SDLK_UP] || keyState[SDLK_w]){
		coordinate.y -= speed;
	}
	if(keyState[SDLK_DOWN] || keyState[SDLK_s]){
		coordinate.y += speed;
	}
	//Handle Escape Key
	if(keyState[SDLK_ESCAPE]){
		engine->setState(1);
	}

	//hanldles Collisions
	if (coordinate.x < 0)
	{
		coordinate.x = 0;
	}
	else if(coordinate.x > width-spriteSize)
	{
		coordinate.x = width-spriteSize;
	}
	if (coordinate.y < 0)
	{
		coordinate.y = 0;
	}
	else if(coordinate.y > height-spriteSize)
	{
		coordinate.y = height-spriteSize;
	}
}

SDL_Rect Controller::getCoordinate()
{
	return coordinate;
}

int Controller::getX()
{
	return coordinate.x;
}
int Controller::getY()
{
	return coordinate.y;
}