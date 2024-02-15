//Game.cpp
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


				TextureManager::Instance()->loadTexture("./assets/10013144.jpg",
					"background",
					renderer);

				TextureManager::Instance()->loadCards("./assets/cardBackBlue.png",
					"cardBack_blue",
					renderer);
				TextureManager::Instance()->loadCards("./assets/cardBackGreen.png",
					"cardBack_green",
					renderer);


				TextureManager::Instance()->loadCards("./assets/cardSpadesJ.png",
					"SpadesJ",
					renderer);

				TextureManager::Instance()->loadCards("./assets/cardClubsA.png",
					"ClubsA",
					renderer);

				TextureManager::Instance()->loadCards("./assets/cardDiamondsQ.png",
					"DiamondsQ",
					renderer);


			}
			else
			{
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else
		{
			std::cout << "window init failed\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}



void Game::render()
{
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	//Background Image upload
	TextureManager::Instance()->drawTexture("background", { 0, 0, backgroundWidht, backgroundHeight }, renderer);


	if (isBackOfCard)
	{
		//Dealer Cards
		TextureManager::Instance()->drawCards("cardBack_blue", { cardPosX + 350 , cardPosY + 50, 140, 190 }, renderer, 5);
		TextureManager::Instance()->drawCards("cardBack_blue", { cardPosX + 750 , cardPosY + 50, 140, 190 }, renderer, -5);

		//Gamer Cards
		TextureManager::Instance()->drawCards("cardBack_green", { cardPosX + 350 , cardPosY + 500, 140, 190 }, renderer, -5);
		TextureManager::Instance()->drawCards("cardBack_green", { cardPosX + 750 , cardPosY + 500, 140, 190 }, renderer, 5);
	}
	else
	{
		//Open cards
		TextureManager::Instance()->drawCards("SpadesJ", { cardPosX + 350 , cardPosY + 50, 140, 190 }, renderer, 5);
		TextureManager::Instance()->drawCards("ClubsA", { cardPosX + 750 , cardPosY + 50, 140, 190 }, renderer, -5);
		TextureManager::Instance()->drawCards("DiamondsQ", { cardPosX + 350 , cardPosY + 500, 140, 190 }, renderer, -5);
		TextureManager::Instance()->drawCards("DiamondsQ", { cardPosX + 750 , cardPosY + 500, 140, 190 }, renderer, 5);
	}



	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: running = false; break;

		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_1)
			{
				if (!isBackOfCard) // ??? ?? ? ????; 
				{
					isBackOfCard = true;
				}
			}

			if (event.key.keysym.sym == SDLK_2)
			{
				if (isBackOfCard) // ?????? ? ????;
				{
					isBackOfCard = false;
				}
			}

		}

		default: break;

		}
	}
}

void Game::update()
{



}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning()
{
	return Game::running;
}



Game::Game()
{
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
}

Game::~Game()
{
	delete window;
	delete renderer;
}