#include "entity.h"
#include <Windows.h>

Entity::Entity(string filename){
	//Initialize SDL_Image
	int flags = IMG_INIT_JPG|IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if(initted & flags != flags)
	{
		OutputDebugStringA("IMG_Init: Failed to init required jpg and png support!\n");
		OutputDebugStringA(IMG_GetError());
	}
	temp   = SDL_LoadBMP(filename.c_str());
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
}

void Entity::Update()
{
}

SDL_Surface* Entity::getSprite()
{
	return sprite;
}

SDL_Surface* Entity::load_image(string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());

    if(loadedImage != NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }

    return optimizedImage;
}

