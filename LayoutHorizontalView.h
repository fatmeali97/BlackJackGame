#pragma once
#include "Interface.h"
#include <vector>

class LayoutHorizontalView : public Interface
{
public:
	LayoutHorizontalView();
	virtual ~LayoutHorizontalView();
	LayoutHorizontalView (int x, int y);
	virtual void SetPosition(int x, int y);
	virtual void DrawBackground(SDL_Renderer* ren) override;
	virtual void DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards) override;
	virtual void DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards) override;

protected:
	int xPos = (backgroundWidht / 2) - 300;
	int yPos = 0;
};

