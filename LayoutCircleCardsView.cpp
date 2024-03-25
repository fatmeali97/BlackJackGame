#include "LayoutCircleCardsView.h"


LayoutCircleCardsView::LayoutCircleCardsView()
{
}

LayoutCircleCardsView::~LayoutCircleCardsView()
{
}

void LayoutCircleCardsView::SetPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}

void LayoutCircleCardsView::DrawBackground(SDL_Renderer* ren)
{
	TextureManager::Instance()->drawTexture("background3", { 0, 0, backgroundWidht, backgroundHeight }, ren);

}

void LayoutCircleCardsView::DrawDirectionDealer(SDL_Renderer* ren, std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		cards.at(i).SetPosition(xPos + (i * (constant::cardOffset /2)),
			yPos + (i * (constant::cardOffset / 4)) + constant::dealerDealerYpos);
		cards.at(i).DrawFace(ren, constant::circleAngle);
	}
}

void LayoutCircleCardsView::DrawDirectionPlayer(SDL_Renderer* ren, std::vector<Card>& cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		cards.at(i).SetPosition(xPos + (i * (constant::cardOffset / 2)),
			 yPos + (i * (constant::cardOffset / 4)) + constant::playerDealerYpos);
		cards.at(i).DrawFace(ren, constant::circleAngle);
	}
}
