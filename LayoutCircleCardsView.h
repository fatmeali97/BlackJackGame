#pragma once
#include <SDL.h>
#include "Interface.h"
#include "TextureManager.h"

class LayoutCircleCardsView : public Interface
{
public:
	LayoutCircleCardsView();
	virtual ~LayoutCircleCardsView();
	virtual void SetPosition(int x, int y);
	virtual void DrawBackground(SDL_Renderer* ren) override;
	virtual void DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards) override;
	virtual void DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards) override;

private:
	int xPos = (backgroundWidht / 2) - 300;
	int yPos = 0; 
};

