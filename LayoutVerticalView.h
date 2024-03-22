#pragma once
#include "Interface.h"

class LayoutVerticalView : public Interface
{
public:
	LayoutVerticalView();
	virtual ~LayoutVerticalView();
	LayoutVerticalView(int x, int y);
	virtual void SetPosition(int x, int y);
	virtual void DrawBackground(SDL_Renderer* ren) override;
	virtual void DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards) override;
	virtual void DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards) override;

protected:
	int xPos = 0;
	int yPos = backgroundHeight / 2 - 100;
};

