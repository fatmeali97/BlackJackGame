#pragma once
#include "Game.h"
#include <string>
#include <map>

class TextureManager
{
public:
	bool loadTexture(const char* fileName,
		std::string id,
		SDL_Renderer* ren);

	bool loadCards(const char* fileName,
		std::string id,
		SDL_Renderer* ren);

	void drawTexture(std::string id,
		SDL_Rect destRect,
		SDL_Renderer* ren,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawCards(std::string id,
		SDL_Rect destRect,
		SDL_Renderer* ren,
		double angle,
		SDL_RendererFlip flip = SDL_FLIP_NONE);


	static TextureManager* Instance()
	{
		if (instance == 0)
		{
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}

private:
	TextureManager() {}
	std::map<std::string, SDL_Texture*> textureMap;
	std::map<std::string, SDL_Texture*> CardsMap;
	static TextureManager* instance;


};

