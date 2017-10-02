#pragma once
#include "SDL_image.h"
#include <string>

using namespace std;

class Entity {
	SDL_Surface *sprite,*temp;
public:
	Entity(string filename);
	void Update();
	SDL_Surface *getSprite();
	SDL_Surface *load_image(string filename);
};