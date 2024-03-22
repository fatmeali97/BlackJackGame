#pragma once
#include "Card.h"
#include "Balance.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace ButtonCoords
{
	const int btnStayHorizontalXpos = 50;
	const int btnStayHorizontalYpos = 50;
	const int btnStayVerticalXpos = 50;
	const int btnStayVerticalYpos = 50;

	const int btnHitHorizontalXpos = 50;
	const int btnHitHorizontalYpos = 600;
	const int btnHitVerticalXpos = 50;
	const int btnHitVerticalYpos = 600;
}

namespace PointsCoords
{
	const int dealerHorizontalXpos = 1150;
	const int dealerHorizontalYpos = 50;
	const int dealerVerticalXpos = 1150;
	const int dealerVerticalYpos = 50;

	const int playerHorizontalXpos = 1150;
	const int playerHorizontalYpos = 600;
	const int playerVerticalXpos = 1150;
	const int playerVerticalYpos = 600;
}

struct HitBtn
{
	SDL_Texture* hit;
	SDL_Rect m_hitDestRect;
};

struct StayBtn
{
	SDL_Texture* stay;
	SDL_Rect m_stayDestRect;
};

class Player
{
public:

	void UpdateScore(SDL_Renderer* ren);
	void ResetData();
	void SetPlayerScore(double points);
	void SetDealerScore(double points);

	double GetPlayerScore();
	double GetDealerScore();
	//double Compare();

	bool InitText(SDL_Renderer* ren);
	void RenderButton(SDL_Renderer* ren);

	bool IsBtnClickable(
		SDL_Rect& destRect,
		int mouseXpos,
		int mouseYpos);

	HitBtn m_hitBtn;
	StayBtn m_stayBtn;

	//void GiveCard(int givenCard, std::vector <Card>& cards); //player
private:
	int m_playerPoints;
	int m_dealerPoints; 

	//Balance balance;
	TTF_Font* m_font;
	SDL_Texture* m_playerPointsTextTexture;
	SDL_Texture* m_dealerPointsTextTexture;
	
	SDL_Rect m_playerPointsDestRect;
	SDL_Rect m_dealerPointsDestRect;


	bool m_isbtnHitClicable = false;
	bool m_isbtnStayClicable = false;
};

