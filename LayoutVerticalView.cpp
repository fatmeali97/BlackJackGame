#include "LayoutVerticalView.h"
#include "TextureManager.h"
#include <iostream>

LayoutVerticalView::LayoutVerticalView()
{
	std::cout << "construcrtor LayoutVerticalView" << std::endl;
}

LayoutVerticalView::~LayoutVerticalView()
{
	std::cout << "destructor LayoutVerticalView" << std::endl;
}

LayoutVerticalView::LayoutVerticalView(int x, int y): Interface(x,y)
{}

void LayoutVerticalView::SetPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}

void LayoutVerticalView::DrawBackground(SDL_Renderer* ren)
{
	TextureManager::Instance()->drawTexture("background1", { 0, 0, backgroundWidht, backgroundHeight }, ren);
}

void LayoutVerticalView::DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		cards.at(i).SetPosition(xPos + constant::dealerXpos, yPos + (i * constant::cardOffset));
		cards.at(i).DrawFace(ren, constant::horizontalAngleDealer);
	}
}

void LayoutVerticalView::DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		cards.at(i).SetPosition(xPos + constant::playerXpos, yPos + (i * constant::cardOffset));
		cards.at(i).DrawFace(ren, constant::horizontalAnglePlayer);
	}
}

