#pragma once
#include "Person.h"

class Individual_Person : public Person
{
protected:
	string _secondname;
	bool _has_middlename;
	string _middlename;
	USHORT _age;
	string _personal_phone;

public:
	Individual_Person
	(
		const string name = DEFAULT_STR, const string TIN = DEFAULT_STR, const string adress = DEFAULT_STR,
		const string secondname = DEFAULT_STR, const bool has_middlename = true, const string middlename = DEFAULT_STR, const USHORT age = 0, const string phone = DEFAULT_STR
	);
	Individual_Person(const Individual_Person& copy);
	Individual_Person(const Individual_Person* copy);
	~Individual_Person() override;

public:
	string Get_Secondname() const;
	string Get_Middlename() const;
	USHORT Get_Age() const;
	string Get_Phone() const;

public:
	string Get_Detail() const override;
};

