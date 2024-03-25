#pragma once
#include <SDL.h>
#include <vector>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <memory>
#include "Card.h"
#include "Player.h"
#include "Interface.h"


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
	
	void Compare();
	void GiveDealerCard(int givenCard, std::vector <Card> &cards); 
	void GivePlayerCard(int givenCard, std::vector <Card>& cards);
	std::string getRandomFace(); 

private:
	SDL_Window* window = NULL;

	SDL_Renderer* renderer = NULL;
	bool running;
	int const backgroundWidht = 1280;
	int const backgroundHeight = 720;

	int cardPosX = backgroundWidht / 2 - 200; //layout
	int cardPosY = 0; //layout
	void loadTextures();
	void initPlayerCards();
	void initDealerCards();
	void ChangeLayout(); //factory

	enum GameState
	{
		ReadyToStartGame,
		PlayersHaveTwoCards,
		Playing,
		GameResult
	}; //gameStates

	GameState state;
	std::vector <Card> playerCards;
	std::vector <Card> dealerCards;

	std::unique_ptr<Interface> layout;

	Balance balance;
	Player player;
	void IncreasedId(int increaseValue);
	int m_layoutId = 0; 

	double m_power; //card
	void ResetGame();
	void GameOver();
	void Win();
	void Lose();

	bool isWiningGame = false;
	bool isLosingGame = false;
	bool IsGameOver = false;
	bool IsStartingNewGame = true;

	//Factory* factory;
};