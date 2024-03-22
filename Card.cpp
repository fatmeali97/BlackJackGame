#include "Card.h"
#include "TextureManager.h"

void Card::SetFace(std::string face)
{
	this->face = face;
}

std::string Card::GetFace()
{
	return face;
}

void Card::DrawFace(SDL_Renderer* ren, int angle)
{
	TextureManager::Instance()->drawTexture(face, { xPos, yPos, 120, 190 }, ren, angle);
}

void Card::DrawFaceVertical(SDL_Renderer* ren)
{
	TextureManager::Instance()->drawTexture(face, { xPos, yPos, 120, 190 }, ren, 90);
}

void Card::DrawBack(SDL_Renderer* ren, int angle)
{
	TextureManager::Instance()->drawTexture("cardBack", { xPos, yPos, 120, 190 }, ren, angle);
}

void Card::SetPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}
