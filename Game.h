#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Card.h"

class Game
{
public:
	Game();
	~Game();
	bool init(const char* title,
		int xpos,
		int ypos,
		int width,
		int height,
		int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
	
	std::string getRandomFace(); 
	
	static double calculatePlayerPoints();
	static double calculateDealerPoints();

private:
	void loadTextures();

	void initPlayerCards();
	void initDealerCards();
	void initCardsValue();


	// void setNewPoints(double playerPoints = 0.0, double dealerPoints = 0.0);

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	int const backgroundWidht = 1280;
	int const backgroundHeight = 720;

	int cardPosX = 0;
	int cardPosY = 0;

	enum GameState
	{
		ReadyToStartGame,
		PlayerHaveTwoCards,
		PlayerHaveThreeCards,
		GameResult
	};
	GameState state;

	Card playerCard1;
	Card playerCard2;
	Card playerCard3;

	Card dealerCard1;
	Card dealerCard2;

	static double playerPoints;
	static double dealerPoints;
};