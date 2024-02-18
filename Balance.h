#pragma once
class Balance
{
public:

	Balance(double balance);

	void SetBalance(double balance);
	double GetBalance() const;
	double Compare();

	double Hit();
	double Stay();

	void Win(); 
	void Loose(); 

private:
	double m_balance = 100000.00;
	double m_bet; 
};

