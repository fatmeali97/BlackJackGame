#include "TextureManager.h"
#include <iostream>

bool TextureManager::loadTexture(const char* fileName,
	std::string id,
	SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);

	if (tempSurface == 0)
	{
		return false;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tex != 0) {
		textureMap[id] = tex;
		return true;
	}

	return false; // something went wrong
}

void TextureManager::drawTexture(std::string id,
	SDL_Rect destRect,
	SDL_Renderer* ren,
	SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(ren, textureMap[id], NULL, &destRect, 0, 0, flip);
}


void TextureManager::drawCards(std::string id,
	SDL_Rect destRect,
	SDL_Renderer* ren,
	double angle,
	SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(ren, CardsMap[id], NULL, &destRect, angle, 0, flip);
}


bool TextureManager::loadCards(const char* fileName, std::string id, SDL_Renderer* ren)
{
	// ??????? ????? ???? ???????????? ??; ????????? ?? ? ?????????? tempSurface
	SDL_Surface* tempSurface = IMG_Load(fileName);

	if (tempSurface == 0)
	{
		std::cout << "Can't load image!" << std::endl;
		return false;
	}
	// ????????? Texture ?? ???? ?????? tempSurface;
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);

	// ??????????? ?????? ?? tempSurface;
	SDL_FreeSurface(tempSurface);

	if (tex != 0)
	{
		// ????????? ? map<std::string, SDL_Texture*> CardsMap; 
		// id ?????? ?? ? ???????? ? ???????? ?????, ? SDL_Texture - ????? ????? texture - tex;
		CardsMap[id] = tex;
		return true;
	}

	std::cout << SDL_GetError() << std::endl;
	return false; // something went wrong 
}



TextureManager* TextureManager::instance = 0;