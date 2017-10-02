#include "engine.h"
#include <Windows.h>


Engine::Engine(){
	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	SPRITE_SIZE = 16;
	SPEED = 1;
	STATE_END = 0;
}

Engine::Engine(int width, int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	SPRITE_SIZE = 16;
	SPEED = 1;
	STATE_END = 0;
}

void Engine::Init()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	//Sets Icon
	SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);

	//Sets Title Bar
	SDL_WM_SetCaption("Jared De La Cruz - Player1", "Jared De La Cruz - Player1");

	//Creats The Window
	SCREEN = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

	//Creates Controller
	control = new Controller(this);

	//Creates Player
	player = new Entity("player.bmp");

	//Creates netPlayer
	netPlayer = new NetPlayer();

	//Creates Network
	net = new Net("player1",netPlayer);
	net->Init();
	if(net->Error() != -1)
	{
		net->SendMsg("Requesting Connection...\r\n");
	}
}

void Engine::Update()
{
	//Handles Close Button
	if(SDL_PollEvent(&EVENT)){
		//Event found
		switch(EVENT.type){
			//Close Button Clicked
			case SDL_QUIT:
				STATE_END = 1;
		}
	}

	//Handles controller
	control->Update();

	//Creates localPlayer to send to server
	net->setData(control->getX(),control->getY());

	//Handles network
	net->Update();

	//Fill Background
	SDL_FillRect(SCREEN,NULL,SDL_MapRGB(SCREEN->format,62,62,66));

	//Draw The Sprite
	SDL_BlitSurface(player->getSprite(), NULL, SCREEN, &control->getCoordinate());
	SDL_BlitSurface(player->getSprite(), NULL, SCREEN, &netPlayer->getCoordinate());

	//Update SCREEN
	SDL_UpdateRect(SCREEN, 0, 0, 0, 0);
	SDL_Flip(SCREEN);
	//SDL_Delay(2);

}

void Engine::Exit()
{
	delete control;
	delete player;
	SDL_Quit();
}

void Engine::setState(int x)
{
	STATE_END = x;
}

int Engine::getState()
{
	return STATE_END;
}

int Engine::getHeight()
{
	return SCREEN_HEIGHT;
}

int Engine::getWidth()
{
	return SCREEN_WIDTH;
}

int Engine::getSpriteSize()
{
	return SPRITE_SIZE;
}

int Engine::getSpeed()
{
	return SPEED;
}

