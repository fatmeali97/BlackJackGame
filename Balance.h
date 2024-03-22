#pragma once
class Balance
{
public:
	Balance();
	Balance (double balance);
	void SetBalance(double balance);
	double GetBalance() const;

	void SetBetValue(double bet);
	double GetBetValue();

private:
	double m_balance = 100000.00;
	double m_bet; 
};

