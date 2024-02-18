#pragma once
#include <string>
#include <SDL.h>

class Card
{
public:
	void SetFace(std::string face);  // картата


	void DrawFace(SDL_Renderer* ren); // зареждаме лицето на картата
	void DrawBack(SDL_Renderer* ren); // винаги 1 гръб

	void SetPosition(int x, int y);

private:
	int xPos;
	int yPos;
	std::string face;

};

