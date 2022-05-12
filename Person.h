#pragma once
#include "Main.h"

enum class Data_Marker 
{
	Is_Person_Data,
	Is_Individual_Person_Data,
	Is_Entity_Person_Data,
};

class Person
{
private:
	static USHORT _objects_count;
public:
	static USHORT Get_Person_Count();
	static bool Is_MyData(BYTE first_byte);

protected:
	string _name;
	string _T_I_N;
	string _registration_adress;

public:
	Person(const string name = DEFAULT_STR, const string TIN = DEFAULT_STR, const string adress = DEFAULT_STR);
	Person(const Person& copy);
	Person(const Person* copy);
	virtual ~Person();

public:
	string Get_Name() const;
	string Get_TIN() const;
	string Get_RegistrationAdress() const;

public:
	void Chainge_Name(string name);
	void Chainge_RegistrationAdress(string adress);

public:
	virtual string Get_Detail() const = 0;
	virtual void WriteData(FILE*& f) const;
	virtual void ReadData(FILE*& f);
};

ostream& operator<<(ostream& os, Person& p);