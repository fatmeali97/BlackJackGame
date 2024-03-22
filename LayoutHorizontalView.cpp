#include "LayoutHorizontalView.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

LayoutHorizontalView::LayoutHorizontalView()
{
	std::cout << "constructor LayoutHorizontalView" << std::endl;
}

LayoutHorizontalView::~LayoutHorizontalView()
{
	std::cout << "destructor LayoutHorizontalView" << std::endl;
}

LayoutHorizontalView::LayoutHorizontalView(int x, int y) : Interface(x,y)
{}

void LayoutHorizontalView::SetPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}

void LayoutHorizontalView::DrawBackground(SDL_Renderer* ren)
{
	TextureManager::Instance()->drawTexture("background", { 0, 0, backgroundWidht, backgroundHeight }, ren);
}

void LayoutHorizontalView::DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		cards.at(i).SetPosition(xPos + (i * constant::cardOffset), yPos + constant::dealerDealerYpos);
		cards.at(i).DrawFace(ren, constant::verticalAngle);
	}
}

void LayoutHorizontalView::DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		cards.at(i).SetPosition(xPos + (i * constant::cardOffset), yPos + constant::playerDealerYpos);
		cards.at(i).DrawFace(ren, constant::verticalAngle);
	}
}

