#include "Player.h"
#include <iostream>
#include "Game.h"


//
//double Player::Hit()
//{
//	std::cout << "PLAYER HIT" << std::endl;
//    return 0.0;
//}
//
//double Player::Stay()
//{
//	std::cout << "PLAYER STAY" << std::endl;
//    return 0.0;
//}
//
//void Player::Win()
//{
//	std::cout << "You win!" << std::endl;
//}
//
//void Player::Loose()
//{
//	std::cout << "You loose!" << std::endl;
//}

void Player::SetPlayerScore(double points)
{
	m_playerPoints = m_playerPoints + points;
}

void Player::SetDealerScore(double points)
{
	m_dealerPoints = m_dealerPoints + points;
}

double Player::GetPlayerScore()
{
	return m_playerPoints;
}

double Player::GetDealerScore()
{
	return m_dealerPoints;
}

//double Player::Compare()
//{
//	balance.SetBetValue(1000);
//	//Only compare;
//	std::cout << " Balance: " << balance.GetBalance() << std::endl;
//	if (m_playerPoints >= 21 || m_dealerPoints >= 21)
//	{
//		if (m_playerPoints < 21 && m_playerPoints < m_dealerPoints)
//		{
//			double newBalance = balance.GetBalance() + (2 * balance.GetBetValue());
//			balance.SetBalance(newBalance);
//		}
//		else if (m_playerPoints == 21 )
//		{
//			double newBalance = balance.GetBalance() + (1.5 * balance.GetBetValue()) + balance.GetBetValue();
//			balance.SetBalance(newBalance);
//		}
//		//check the logic
//		else if (m_playerPoints > 21 && m_playerPoints > m_dealerPoints)
//		{
//			if (m_playerPoints > m_dealerPoints)
//			{
//				double newBalance = balance.GetBalance() - balance.GetBetValue();
//				balance.SetBalance(newBalance);
//			}
//			if (m_playerPoints < m_dealerPoints)
//			{
//				double newBalance = balance.GetBalance() - balance.GetBetValue();
//				balance.SetBalance(newBalance);
//			}
//		}
//	}
//
//	std::cout << balance.GetBalance() << std::endl;
//	return balance.GetBalance();
//}

bool Player::InitText(SDL_Renderer* ren)
{
	if (TTF_Init() == -1) // return error
	{
		return false;
	}

	m_font = TTF_OpenFont("./fonts/Arcade.ttf", 40);

	SDL_Surface* tempSurfaceText = NULL;
	tempSurfaceText = TTF_RenderText_Blended(m_font, "Hit", { 255,255,255,255 });
	m_hitBtn.hit = SDL_CreateTextureFromSurface(ren, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(m_font, "Stay", { 255,255,255,255 });
	m_stayBtn.stay = SDL_CreateTextureFromSurface(ren, tempSurfaceText);


	int tw, th;
	SDL_QueryTexture(m_stayBtn.stay, 0, 0, &tw, &th);
	SDL_QueryTexture(m_hitBtn.hit, 0, 0, &tw, &th);
	SDL_QueryTexture(m_playerPointsTextTexture, 0, 0, &tw, &th);
	SDL_QueryTexture(m_dealerPointsTextTexture, 0, 0, &tw, &th);

	m_stayBtn.m_stayDestRect = { 
		ButtonCoords::btnStayHorizontalXpos,
		ButtonCoords::btnStayHorizontalYpos,
		60,50 };

	m_hitBtn.m_hitDestRect = {
		ButtonCoords::btnHitHorizontalXpos,
		ButtonCoords::btnHitHorizontalYpos,
		50,50 };

	m_dealerPointsDestRect = { 
		PointsCoords::dealerHorizontalXpos, 
		PointsCoords::dealerHorizontalYpos,
		50, 50 };

	m_playerPointsDestRect = { 
		PointsCoords::playerHorizontalXpos,
		PointsCoords::playerHorizontalYpos,
		50, 50 };

	SDL_FreeSurface(tempSurfaceText);
	return true;
}


void Player::RenderButton(SDL_Renderer* ren)
{
	if (!m_font)
	return;

	SDL_RenderCopy(ren, m_stayBtn.stay, NULL, &m_stayBtn.m_stayDestRect);
	SDL_RenderCopy(ren, m_hitBtn.hit, NULL, &m_hitBtn.m_hitDestRect);
}

bool Player::IsBtnClickable(SDL_Rect& destRect, int mouseXpos, int  mouseYpos)
{
	if (mouseXpos > destRect.x && mouseXpos < destRect.x + destRect.w
		&& mouseYpos > destRect.y && mouseYpos < destRect.y + destRect.y)
	{
		std::cout << "true" << std::endl;
		return true;
	}
	return false;
}


void Player::UpdateScore(SDL_Renderer* ren)
{
	SDL_Surface* tempSurfaceText = NULL;

	tempSurfaceText = TTF_RenderText_Blended(m_font,
		std::to_string(m_playerPoints).data(),
		{ 255,255,255,255 });

	m_playerPointsTextTexture = SDL_CreateTextureFromSurface(ren, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(m_font,
		std::to_string(m_dealerPoints).data(),
		{ 255,255,255,255 });

	m_dealerPointsTextTexture = SDL_CreateTextureFromSurface(ren, tempSurfaceText);
	
	SDL_RenderCopy(ren, m_playerPointsTextTexture, NULL, &m_playerPointsDestRect);
	SDL_RenderCopy(ren, m_dealerPointsTextTexture, NULL, &m_dealerPointsDestRect);

}

void Player::ResetData()
{
	m_playerPoints = 0;
	m_dealerPoints = 0;
}

