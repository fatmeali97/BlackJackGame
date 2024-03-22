#pragma once
#include <string>
#include <SDL.h>

class Card
{
public:
	void SetFace(std::string face);  // картата
	std::string GetFace();
	//void SetPower(int power);
	//int GetPower();

	void DrawFace(SDL_Renderer* ren, int angle); // зареждаме лицето на картата
	void DrawBack(SDL_Renderer* ren, int angle); // винаги 1 гръб
	void DrawFaceVertical(SDL_Renderer* ren);
	void SetPosition(int x, int y);

private:
	int xPos = 0;
	int yPos = 0;
	std::string face;
	//int m_power;
};

