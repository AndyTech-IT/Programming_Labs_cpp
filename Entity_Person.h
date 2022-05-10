#pragma once
#include "Main.h"
#include "Person.h"

class Entity_Person : public Person
{
protected:
	string _M_S_R_N;
	string _C_O_R;
	string _B_I_C;

public:
	Entity_Person
	(
		const string name = DEFAULT_STR, const string TIN = DEFAULT_STR, const string adress = DEFAULT_STR,
		const string MSRN = DEFAULT_STR, const string COR = DEFAULT_STR, const string BIC = DEFAULT_STR
	);
	Entity_Person(const Entity_Person& copy);
	Entity_Person(const Entity_Person* copy);
	~Entity_Person() override;

public:
	string Get_MSRN() const;
	string Get_COR() const;
	USHORT Get_BIC() const;

public:
	string Get_Detail() const override;
};

