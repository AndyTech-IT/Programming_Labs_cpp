#pragma once
#include "Person.h"

class Individual_Person : public Person
{
public:
	static bool Is_MyData(BYTE first_byte);

protected:
	string _secondname;
	bool _has_middlename;
	string _middlename;
	string _personal_phone;

public:
	Individual_Person
	(
		const string name = DEFAULT_STR, const string TIN = DEFAULT_STR, const string adress = DEFAULT_STR,
		const string secondname = DEFAULT_STR, const bool has_middlename = true, const string middlename = DEFAULT_STR, const string phone = DEFAULT_STR
	);
	Individual_Person(const Individual_Person& copy);
	Individual_Person(const Individual_Person* copy);
	~Individual_Person() override;

public:
	string Get_Secondname() const;
	string Get_Middlename() const;
	string Get_Phone() const;

public:
	void Chainge_Phone(string phone);
	void Chainge_Secondname(string secondname);
	void Chainge_Middlename(string middlename);

	void WriteData(FILE*& f) const override;
	void ReadData(FILE*& f) override;

public:
	string Get_Detail() const override;
};

