#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


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

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	int const backgroundWidht = 1280;
	int const backgroundHeight = 720;

	int cardPosX = 0;
	int cardPosY = 0;

	//first state of game - cards back; 
	bool isBackOfCard = true;


};