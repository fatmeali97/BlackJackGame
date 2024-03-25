#pragma once
#include <SDL.h>
#include <vector>
#include "Card.h"

namespace constant
{
	const double dealerDealerYpos = 50;
	const double playerDealerYpos = 450;
	const double dealerXpos = 150;
	const double playerXpos = 1280 - 250;
	const double cardOffset = 60;
	const double verticalAngle = 2;
	const double circleAngle = -2;
	const double horizontalAngleDealer = 86;
	const double horizontalAnglePlayer = -96;
}

class Interface
{
public:
	Interface();
	virtual ~Interface();
	Interface(int x, int y);
	virtual void SetPosition(int x, int y) = 0;
	virtual void DrawBackground(SDL_Renderer* ren) {};
	virtual void DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards) {};
	virtual void DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards) {};

protected:
	int const backgroundWidht = 1280;
	int const backgroundHeight = 720;
	int xPos = 0;
	int yPos = 0;
};

