#include "Card.h"
#include "TextureManager.h"

void Card::SetFace(std::string face)
{
	this->face = face;
}

void Card::DrawFace(SDL_Renderer* ren)
{
	TextureManager::Instance()->drawTexture(face, { xPos, yPos, 120, 190 }, ren);
}

void Card::DrawBack(SDL_Renderer* ren)
{
	TextureManager::Instance()->drawTexture("cardBack", { xPos, yPos, 120, 190 }, ren);
}

void Card::SetPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}
