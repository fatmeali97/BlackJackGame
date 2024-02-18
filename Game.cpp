//Game.cpp
#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>

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

				loadTextures();
				initPlayerCards();
				initDealerCards();

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

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	//Background Image upload
	TextureManager::Instance()->drawTexture("background", { 0, 0, backgroundWidht, backgroundHeight }, renderer);

	if (state == ReadyToStartGame)
	{
		//nothing to draw;
	}
	else if (state == PlayerHaveTwoCards)
	{
		//Dealer Cards
		dealerCard1.DrawBack(renderer);
		dealerCard2.DrawBack(renderer);
		//Open cards
		playerCard1.DrawFace(renderer);
		playerCard2.DrawFace(renderer);
	}
	else if (state == PlayerHaveThreeCards)
	{
		//Dealer Cards
		dealerCard1.DrawBack(renderer);
		dealerCard2.DrawBack(renderer);

		//Open cards
		playerCard1.DrawFace(renderer);
		playerCard2.DrawFace(renderer);
		playerCard3.DrawFace(renderer);
	}
	else if (state == GameResult)
	{
		//Dealer Cards
		dealerCard1.DrawFace(renderer);
		dealerCard2.DrawFace(renderer);

		//Open cards
		playerCard1.DrawFace(renderer);
		playerCard2.DrawFace(renderer);
		playerCard3.DrawFace(renderer);
	}
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
			if (event.key.keysym.sym == SDLK_1)
			{
				state = ReadyToStartGame;
			}
			else if (event.key.keysym.sym == SDLK_2)
			{
				state = PlayerHaveTwoCards;
			}
			else if (event.key.keysym.sym == SDLK_3)
			{
				state = PlayerHaveThreeCards;
			}
			else if (event.key.keysym.sym == SDLK_4)
			{
				state = GameResult;
			}
			else if (event.key.keysym.sym == SDLK_5)
			{
				playerCard1.SetFace("DiamondsQ");
			}
		}

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
		"Clubs10",
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
		"Diamonds10",
		renderer);

	TextureManager::Instance()->loadTexture("./assets/cardDiamondsA.png",
		"ClubsA",
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
		"Hearts10",
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
		"Spades10",
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

}

void Game::initPlayerCards()
{

	playerCard1.SetPosition(cardPosX + 350, cardPosY + 450);
	playerCard2.SetPosition(cardPosX + 550, cardPosY + 450);
	playerCard3.SetPosition(cardPosX + 750, cardPosY + 450);

	std::string card1Value = getRandomFace();
	playerCard1.SetFace(card1Value);

	std::string card2Value = getRandomFace();
	playerCard2.SetFace(card2Value);

	std::string card3Value = getRandomFace();
	playerCard3.SetFace(card3Value);
}

std::string Game::getRandomFace()
{
	std::vector<std::string> allCards
	{
		"Clubs2","Clubs3",
		"Clubs4","Clubs5",
		"Clubs6","Clubs7",
		"Clubs8","Clubs9",
		"Clubs10","ClubsA",
		"ClubsJ","ClubsK",
		"ClubsQ",

		"Diamonds2","Diamonds3",
		"Diamonds4","Diamonds5",
		"Diamonds6","Diamonds7",
		"Diamonds8","Diamonds9",
		"Diamonds10","DiamondsA",
		"DiamondsJ","DiamondsK",
		"DiamondsQ",

		"Hearts2","Hearts3",
		"Hearts4","Hearts5",
		"Hearts6","Hearts7",
		"Hearts8","Hearts9",
		"Hearts10","HeartsA",
		"HeartsJ","HeartsK",
		"HeartsQ",

		"Spades2","Spades3",
		"Spades4","Spades5",
		"Spades6","Spades7",
		"Spades8","Spades9",
		"Spades10","SpadesA",
		"SpadesJ","SpadesK",
		"SpadesQ"
	};


	int cardsCount = allCards.size();
	int firstCardIndex = rand() % cardsCount;
	std::string firstCardValue = allCards[firstCardIndex];
	std::cout << firstCardIndex << std::endl;
	return firstCardValue;



}

double Game::calculatePlayerPoints()
{
	return 0.0;
}

double Game::calculateDealerPoints()
{
	return 0.0;
}


void Game::initDealerCards()
{
	dealerCard1.SetPosition(cardPosX +350, cardPosY + 50 );
	dealerCard2.SetPosition(cardPosX + 750, cardPosY + 50);

	std::string card1Value = getRandomFace();
	dealerCard1.SetFace(card1Value);

	std::string card2Value = getRandomFace();
	dealerCard2.SetFace(card2Value);
}

void Game::initCardsValue()
{
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