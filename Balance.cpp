#include "Balance.h"
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <iostream>

Balance::Balance()
{}

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

void Balance::SetBetValue(double bet)
{
    m_bet = bet;
}

double Balance::GetBetValue()
{
    return m_bet;
}




