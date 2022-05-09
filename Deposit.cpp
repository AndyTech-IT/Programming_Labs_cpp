#include "Deposit.h"

#if LR == 6

double Deposit::_interest_rate = .7;

void Print_Deposits_List(const Deposit deposits[], const int count)
{
	if (count < 0)
		throw exception("Count mast be equals 0 or hier!");

	if (count == 0)
	{
		cout << "Список пуст!" << endl;
		return;
	}
	cout << "Список Депозитов:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i + 1 << ")\t" << deposits[i]._amount << " руб." << endl;
	}
}

double Deposit::Get_Interest_Rate()
{
	return _interest_rate;
}

void Deposit::Set_Interest_Rate(const double rate)
{
	if (rate < 0)
		throw exception("Rate mast be equals 0 or hier!");

	_interest_rate = rate;
}

Deposit::Deposit(const long double start_amount)
{
	if (start_amount < 0)
		throw exception("Amount mast be equals 0 or hier!");

	_amount = start_amount;
}

void Deposit::Add_Profit_To_Amount()
{
	_amount *= 1 + _interest_rate;
}

#endif