//Game.cpp
#include "Game.h"
#include "TextureManager.h"
//#include "LayoutHorizontalView.h"
//#include "LayoutVerticalView.h"
//#include "LayoutCircleCardsView.h"
#include <iostream>
#include <vector>
#include "Factory.h"



bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				time_t t;
				srand((unsigned)time(&t)); // разбъркваме картите от самото начало

				state = ReadyToStartGame;
				loadTextures();
				initPlayerCards();
				initDealerCards();
				player.InitText(renderer);
				
				//layout = Factory::CreateLayout(Layouts::LayoutHorizontal);
				ChangeLayout();
			}
			else
			{
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else
		{
			std::cout << "window init failed\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	layout->DrawBackground(renderer);

	if (state == PlayersHaveTwoCards || state == Playing)
	{
		player.RenderButton(renderer);

		for (int i = 0; i < dealerCards.size(); ++i)
		{
			layout->DrawDirectionDealer(renderer, dealerCards);
		}

		for (int i = 0; i < playerCards.size(); ++i)
		{
			layout->DrawDirectionPlayer(renderer, playerCards);
		}
	}

	else if (state == GameResult)
	{
		if (isLosingGame)
		{
			TextureManager::Instance()->drawTexture("YouLose", { 0,0,600,300 }, renderer, 0);
		}
		else 
		{
			TextureManager::Instance()->drawTexture("YouWin", { 0,0,600,300 }, renderer, 0);
		}
	}
	
	if (state == ReadyToStartGame)
	{
		TextureManager::Instance()->drawTexture("Start", { 0,0,600,300 }, renderer, 0);
	}
	
	player.UpdateScore(renderer);
	SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT: running = false; break;

		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				std::cout << "the state is: " << state << std::endl;
				if (state == ReadyToStartGame)
				{
					state = PlayersHaveTwoCards;

				}
				else if (state == GameResult)
				{
					ResetGame();
					state = ReadyToStartGame;
				}
			}

			if (event.key.keysym.sym == SDLK_7)
			{
				ChangeLayout();
			}
		}break;

		case SDL_MOUSEBUTTONDOWN:
		{
			if (SDL_BUTTON_LEFT == event.button.button)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&x, &y);

				if (player.IsBtnClickable(player.m_hitBtn.m_hitDestRect, x, y) 
					&& state == PlayersHaveTwoCards || state == Playing)
				{
					state = Playing;
					std::cout << "you clicked HIT btn" << std::endl;
					GivePlayerCard(1, playerCards);
					Compare();
				}
				      
				if (player.IsBtnClickable(player.m_stayBtn.m_stayDestRect, x, y) 
					&& state == PlayersHaveTwoCards || state == Playing)
				{
					state = Playing;
					std::cout << "you clicked STAY btn" << std::endl;
					GiveDealerCard(1, dealerCards);
					Compare();
				}
			}
		}break;

		default: break;
		}
	}
}

void Game::update()
{}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning()
{
	return Game::running;
}

void Game::loadTextures()
{
	TextureManager::Instance()->loadTexture("./assets/10013144.jpg",
		"background",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/linen-texture-green-tones.jpg",
		"background1",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/layout3.jpg",
		"background3",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardBackBlue.png",
		"cardBack",
		renderer);

	//	Clubs
	TextureManager::Instance()->loadTexture("./assets/cardClubs2.png",
		"Clubs2",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs3.png",
		"Clubs3",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs4.png",
		"Clubs4",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs5.png",
		"Clubs5",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs6.png",
		"Clubs6",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs7.png",
		"Clubs7",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs8.png",
		"Clubs8",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs9.png",
		"Clubs9",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubs10.png",
		"Clubs0",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubsA.png",
		"ClubsA",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubsJ.png",
		"ClubsJ",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubsK.png",
		"ClubsK",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardClubsQ.png",
		"ClubsQ",
		renderer);

	//	Diamonds
	TextureManager::Instance()->loadTexture("./assets/cardDiamonds2.png",
		"Diamonds2",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds3.png",
		"Diamonds3",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds4.png",
		"Diamonds4",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds5.png",
		"Diamonds5",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds6.png",
		"Diamonds6",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds7.png",
		"Diamonds7",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds8.png",
		"Diamonds8",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds9.png",
		"Diamonds9",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamonds10.png",
		"Diamonds0",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamondsA.png",
		"DiamondsA",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamondsJ.png",
		"DiamondsJ",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamondsK.png",
		"DiamondsK",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamondsQ.png",
		"DiamondsQ",
		renderer);

	//Hearts
	TextureManager::Instance()->loadTexture("./assets/cardHearts2.png",
		"Hearts2",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts3.png",
		"Hearts3",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts4.png",
		"Hearts4",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts5.png",
		"Hearts5",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts6.png",
		"Hearts6",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts7.png",
		"Hearts7",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts8.png",
		"Hearts8",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts9.png",
		"Hearts9",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHearts10.png",
		"Hearts0",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHeartsA.png",
		"HeartsA",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHeartsJ.png",
		"HeartsJ",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHeartsK.png",
		"HeartsK",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardHeartsQ.png",
		"HeartsQ",
		renderer);

	//Spades
	TextureManager::Instance()->loadTexture("./assets/cardSpades2.png",
		"Spades2",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades3.png",
		"Spades3",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades4.png",
		"Spades4",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades5.png",
		"Spades5",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades6.png",
		"Spades6",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades7.png",
		"Spades7",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades8.png",
		"Spades8",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades9.png",
		"Spades9",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpades10.png",
		"Spades0",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpadesA.png",
		"SpadesA",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpadesJ.png",
		"SpadesJ",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpadesK.png",
		"SpadesK",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardSpadesQ.png",
		"SpadesQ",
		renderer);

	//states
	TextureManager::Instance()->loadTexture("./assets/states/3.png",
		"Start",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/states/2.png",
		"Play",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/states/1.png",
		"GameOver",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/states/4.png",
		"YouWin",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/states/5.png",
		"YouLose",
		renderer);

}

void Game::initPlayerCards()
{
	for (int i = 0; i < 2; ++i)
	{
		Card tempCard;
		tempCard.SetPosition(cardPosX + (i * constant::cardOffset), cardPosY + constant::playerDealerYpos);
		std::string cardValue = getRandomFace();
		tempCard.SetFace(cardValue);
		playerCards.push_back(tempCard);
		std::cout << "Player cards are " << cardValue <<
			" the value is: " << m_power << std::endl;
		player.SetPlayerScore(m_power);
	}
}

void Game::initDealerCards()
{
	for (int i = 0; i < 2; ++i)
	{
		Card tempCard;
		tempCard.SetPosition(cardPosX + (i * constant::cardOffset), cardPosY + constant::dealerDealerYpos);
		std::string cardValue = getRandomFace();
		tempCard.SetFace(cardValue);
		dealerCards.push_back(tempCard);
		std::cout << "Dealer cards are " << cardValue <<
			" the value is: " << m_power << std::endl;
		player.SetDealerScore(m_power);
	}
}

void Game::ChangeLayout()
{
	m_layoutId++;
	std::cout << static_cast<int>(Layouts::MaxLayoutCount) << std::endl;
	layout = Factory::CreateLayout(Layouts::LayoutCircleCards);
	if (m_layoutId == 0)
	{
		layout = Factory::CreateLayout(Layouts::LayoutHorizontal);
		std::cout << m_layoutId << std::endl;
		return;
	}

	else if (m_layoutId == 1)
	{
		layout = Factory::CreateLayout(Layouts::LayoutCircleCards);
		std::cout << m_layoutId << std::endl;
		return;
	}

	else if (m_layoutId == 2)
	{
		layout = Factory::CreateLayout(Layouts::LayoutVertical);
		std::cout << m_layoutId << std::endl;
		return;
	}

	if (m_layoutId > 2)
	{
		m_layoutId = 0;
	}

	//for (m_layoutId = 0; m_layoutId < static_cast<int>(Layouts::MaxLayoutCount); ++m_layoutId)
	//{
	//	std::cout << m_layoutId << std::endl;
	//	switch (m_layoutId)
	//	{
	//	case 0:
	//	{
	//		layout = Factory::CreateLayout(Layouts::LayoutHorizontal);
	//		//std::cout << "Layouts::LayoutHorizontal " << std::endl;
	//	} break;
	//	case 1:
	//	{
	//		layout = Factory::CreateLayout(Layouts::LayoutCircleCards);
	//		//std::cout << "Layouts::LayoutCircleCards" << std::endl;
	//	} break;
	//	case 2:
	//	{
	//		layout = Factory::CreateLayout(Layouts::LayoutVertical);
	//		//std::cout << "Layouts::LayoutVertical" << std::endl;
	//	} break;
	//	default: break;
	//	}
	//}

	std::cout << m_layoutId << std::endl;
}

void Game::IncreasedId(int increaseValue)
{
	m_layoutId = m_layoutId + increaseValue;

}

void Game::ResetGame()
{
	IsStartingNewGame = true;
	player.ResetData();
	dealerCards.clear();
	playerCards.clear();
	initDealerCards();
	initPlayerCards();
}

void Game::GameOver()
{
	state = GameResult;
	IsGameOver = true;
	IsStartingNewGame = false;
	isLosingGame = false;
	isWiningGame = false;
}

void Game::Win()
{
	state = GameResult;
	isWiningGame = true;
	IsStartingNewGame = false;
	IsGameOver = false;
	isLosingGame = false;
}

void Game::Lose()
{
	state = GameResult;
	isLosingGame = true;
	IsStartingNewGame = false;
	IsGameOver = false;
	isWiningGame = false;
}

void Game::Compare()
{
	balance.SetBetValue(1000);
	//Only compare;
	std::cout << " Balance: " << balance.GetBalance() << std::endl;
	//if (player.GetPlayerScore() >= 21 || player.GetDealerScore() >= 21)
	//{
	//	if (player.GetPlayerScore() < 21 && player.GetPlayerScore() < player.GetDealerScore())
	//	{
	//		double newBalance = balance.GetBalance() + (2 * balance.GetBetValue());
	//		balance.SetBalance(newBalance);
	//		Win();
	//	}
	//	else if (player.GetPlayerScore() == 21 )
	//	{
	//		double newBalance = balance.GetBalance() + (1.5 * balance.GetBetValue()) + balance.GetBetValue();
	//		balance.SetBalance(newBalance);
	//		Win();
	//	}
	//	//check the logic
	//	else if (player.GetPlayerScore() > 21 && player.GetPlayerScore() > player.GetDealerScore())
	//	{
	//		if (player.GetPlayerScore() > player.GetDealerScore())
	//		{
	//			double newBalance = balance.GetBalance() - balance.GetBetValue();
	//			balance.SetBalance(newBalance);
	//			Lose();
	//		}
	//		if (player.GetPlayerScore() < player.GetDealerScore())
	//		{
	//			double newBalance = balance.GetBalance() - balance.GetBetValue();
	//			balance.SetBalance(newBalance);
	//			Lose();
	//		}
	//	}
	//}

	if (player.GetPlayerScore() >= 21 && player.GetPlayerScore() > player.GetDealerScore())
	{
		double newBalance = balance.GetBalance() - balance.GetBetValue();
		balance.SetBalance(newBalance);
		Lose();
	}

	else if (player.GetPlayerScore() < 21 && player.GetDealerScore() > 21)
	{
		double newBalance = balance.GetBalance() - balance.GetBetValue();
		balance.SetBalance(newBalance);
		Win();
	}

	else if (player.GetPlayerScore() == 21 && player.GetPlayerScore() == player.GetDealerScore())
	{
		if (player.GetPlayerScore() < player.GetDealerScore())
		{
			double newBalance = balance.GetBalance() - balance.GetBetValue();
			balance.SetBalance(newBalance);
			Win();
		}
		else if (player.GetPlayerScore() > player.GetDealerScore())
		{
			double newBalance = balance.GetBalance() - balance.GetBetValue();
			balance.SetBalance(newBalance);
			Lose();
		}
	}

	std::cout << balance.GetBalance() << std::endl;
}


void Game::GiveDealerCard(int cardToBeGiven, std::vector <Card>& cards)
{
	for (int i = 0; i < cardToBeGiven; ++i)
	{
		Card tempCard;
		std::string cardValue = getRandomFace();
		tempCard.SetFace(cardValue);
		cards.push_back(tempCard);
		/*std::cout << "Player cards are " << cardValue <<
			" the value is: " << m_power << std::endl;*/
		player.SetDealerScore(m_power);
	}
}

void Game::GivePlayerCard(int cardToBeGiven, std::vector <Card> &cards)
{
	for (int i = 0; i < cardToBeGiven; ++i)
	{
		Card tempCard;
		std::string cardValue = getRandomFace();
		tempCard.SetFace(cardValue);
		cards.push_back(tempCard);
		/*std::cout << "Dealer cards are " << cardValue <<
			" the value is: " << m_power << std::endl;*/
		player.SetPlayerScore(m_power);
	}
}

std::string Game::getRandomFace()
{
	std::vector<std::string> allCards
	{
		"Clubs2","Clubs3",
		"Clubs4","Clubs5",
		"Clubs6","Clubs7",
		"Clubs8","Clubs9",
		"Clubs0","ClubsA",
		"ClubsJ","ClubsK",
		"ClubsQ",

		"Diamonds2","Diamonds3",
		"Diamonds4","Diamonds5",
		"Diamonds6","Diamonds7",
		"Diamonds8","Diamonds9",
		"Diamonds0","DiamondsA",
		"DiamondsJ","DiamondsK",
		"DiamondsQ",

		"Hearts2","Hearts3",
		"Hearts4","Hearts5",
		"Hearts6","Hearts7",
		"Hearts8","Hearts9",
		"Hearts0","HeartsA",
		"HeartsJ","HeartsK",
		"HeartsQ",

		"Spades2","Spades3",
		"Spades4","Spades5",
		"Spades6","Spades7",
		"Spades8","Spades9",
		"Spades0","SpadesA",
		"SpadesJ","SpadesK",
		"SpadesQ"
	};

	int cardsCount = allCards.size(); // how much cards we have
	int firstCardIndex = rand() % cardsCount; // the card index that is randed
	std::string firstCardValue = allCards[firstCardIndex];

	for (int i = 0; i < 1; ++i)
	{
		int lastNum = firstCardValue.back() - '0';
		
		//set the power
		if (lastNum > 0 && lastNum <= 9)
		{
			int power = lastNum;
			m_power = power;
		}
		if (lastNum == 0)
		{
			int power = 10;
			m_power = power;
		}
		if (firstCardValue.back() == 'A')
		{
			int power = 11;
			m_power = power;
		}
		if (firstCardValue.back() == 'J')
		{
			int power = 12;
			m_power = power;
		}
		if (firstCardValue.back() == 'Q')
		{
			int power = 13;
			m_power = power;
		}
		if (firstCardValue.back() == 'K')
		{
			int power = 14;
			m_power = power;
		}
	}
	return firstCardValue;
}

Game::Game()
{
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	Game::state = ReadyToStartGame;
}

Game::~Game()
{
	delete window;
	delete renderer;
}