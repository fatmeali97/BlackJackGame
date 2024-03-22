#include "GameStates.h"

void GameStates::SetIsReadyToStartGame(bool isReadyToStartGame)
{
    m_isReadyToStartGame = isReadyToStartGame;
}

void GameStates::SetIsPlayersHaveTwoCards(bool isPlayersHaveTwoCards)
{
    m_isPlayersHaveTwoCards = isPlayersHaveTwoCards;
}

void GameStates::SetIsButtonHitClicked(bool isButtonHitClicked)
{
    m_isButtonHitClicked = isButtonHitClicked;
}

void GameStates::SetIsButtonStayClicked(bool isButtonStayClicked)
{
    m_isButtonStayClicked = isButtonStayClicked;
}

void GameStates::SetIsGameOver(bool isGameOver)
{
    m_isGameOver = isGameOver;
}

bool GameStates::GetIsReadyToStartGame()
{
    return m_isReadyToStartGame;
}

bool GameStates::GetIsPlayersHaveTwoCards()
{
    return m_isPlayersHaveTwoCards;
}

bool GameStates::GetIsButtonHitClicked()
{
    return m_isButtonHitClicked;
}

bool GameStates::GetIsButtonStayClicked()
{
    return m_isButtonStayClicked;
}

bool GameStates::GetIsGameOver()
{
    return m_isGameOver;
}
