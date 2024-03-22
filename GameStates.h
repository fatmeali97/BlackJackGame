#pragma once
class GameStates
{
public:

	void SetIsReadyToStartGame(bool isReadyToStartGame);
	void SetIsPlayersHaveTwoCards(bool isPlayersHaveTwoCards);
	void SetIsButtonHitClicked(bool isButtonHitClicked);
	void SetIsButtonStayClicked(bool isButtonStayClicked);
	void SetIsGameOver(bool isGameOver);

	bool GetIsReadyToStartGame();
	bool GetIsPlayersHaveTwoCards();
	bool GetIsButtonHitClicked();
	bool GetIsButtonStayClicked();
	bool GetIsGameOver();

	enum GameState
	{
		ReadyToStartGame,
		PlayersHaveTwoCards,
		Hit, 
		Stay,
		GameResult
	};

private:
	bool m_isReadyToStartGame = true;
	bool m_isPlayersHaveTwoCards = false;
	bool m_isButtonHitClicked = false;
	bool m_isButtonStayClicked = false;
	bool m_isGameOver = false;
};

