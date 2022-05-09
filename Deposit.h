#pragma once
#include "Main.h"

#if LR == 6
enum class Deposit_Command
{
	Exit,
	Income_All,
	Show_All,
};

class Deposit
{
	friend void Print_Deposits_List(const Deposit deposits[], const int count);

private:
	static double _interest_rate;

public:
	static double Get_Interest_Rate();
	static void Set_Interest_Rate(const double rate);

private:
	long double _amount;

public:
	Deposit(const long double start_amount = 0);

public:
	void Add_Profit_To_Amount();
};

#endif