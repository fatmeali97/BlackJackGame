#include "Balance.h"
#include "Game.h"
#include "Card.h"
#include <iostream>

Balance::Balance(double balance)
{
    SetBalance(balance);
}

void Balance::SetBalance(double balance)
{
    m_balance = balance;
}

double Balance::GetBalance() const
{
    return m_balance;
}

double Balance::Compare()
{
    if (Game::calculatePlayerPoints() < 21 && Game::calculatePlayerPoints() < Game::calculateDealerPoints())
    {
        double newBalance = m_balance + (2 * m_bet);
        SetBalance(newBalance);
        Win();
    }
    else if (Game::calculatePlayerPoints() == 21)
    {
        double newBalance = m_balance + (1.5 * m_bet) + m_bet;
        SetBalance(newBalance);
        Win();
    }
    else //if ((Game::calculatePlayerPoints() > 21 && Game::calculatePlayerPoints() > Game::calculateDealerPoints())
    {
        double newBalance = m_balance - m_bet;
        SetBalance(newBalance);
        Loose();
    }

    return GetBalance();
}

double Balance::Hit()
{
    double newPoints = Game::calculatePlayerPoints(); //valueOfCard; 

    return 0.0;
}

double Balance::Stay()
{
    return 0.0;
}

void Balance::Win()
{
    std::cout << "You win!" << std::endl;
}

void Balance::Loose()
{
    std::cout << "You loose!" << std::endl;
}


