#include "Individual_Person.h"

bool Individual_Person::Is_MyData(BYTE first_byte)
{
	return first_byte == (BYTE)Data_Marker::Is_Individual_Person_Data;
}

Individual_Person::Individual_Person
(
	const string name, const string TIN, const string adress,
	const string secondname, const bool has_middlename, const string middlename, const string phone
) : Person(name, TIN, adress)
{
	_secondname = secondname;
	_has_middlename = has_middlename;
	_middlename = middlename;
	_personal_phone = phone;
}

Individual_Person::Individual_Person(const Individual_Person& copy)
	:Individual_Person(copy._name, copy._T_I_N, copy._registration_adress, copy._secondname, copy._has_middlename, copy._middlename, copy._personal_phone)
{ }

Individual_Person::Individual_Person(const Individual_Person* copy)
	: Individual_Person(copy->_name, copy->_T_I_N, copy->_registration_adress, copy->_secondname, copy->_has_middlename, copy->_middlename, copy->_personal_phone)
{ }

Individual_Person::~Individual_Person()
{ }

string Individual_Person::Get_Secondname() const
{
	return _secondname;
}

string Individual_Person::Get_Middlename() const
{
	return _has_middlename ? _middlename : "";
}

string Individual_Person::Get_Phone() const
{
	return _personal_phone;
}

void Individual_Person::Chainge_Phone(string phone)
{
	_personal_phone = phone;
}

void Individual_Person::Chainge_Secondname(string secondname)
{
	_secondname = secondname;
}

void Individual_Person::Chainge_Middlename(string middlename)
{
	_middlename = middlename;
}

void Individual_Person::WriteData(FILE*& f) const
{
	int i;
	BYTE b;
	if (typeid(*this).name() == typeid(Individual_Person).name())
	{
		b = (BYTE)Data_Marker::Is_Individual_Person_Data;
		fwrite(&b, sizeof(BYTE), 1, f);
	}
	Person::WriteData(f);

	Write_String(_secondname, f);

	fwrite(&_has_middlename, sizeof(bool), 1, f);
	if (_has_middlename)
	{
		Write_String(_middlename, f);
	}

	Write_String(_personal_phone, f);
}

void Individual_Person::ReadData(FILE*& f)
{
	int i;
	Person::ReadData(f);

	_secondname = Read_String(f);

	fread(&_has_middlename, sizeof(bool), 1, f);
	if (_has_middlename)
	{
		_middlename = Read_String(f);
	}

	_personal_phone = Read_String(f);
}

string Individual_Person::Get_Detail() const
{
	string result;
	result += "Физическое Лицо:" + string("\n");
	result += "    - ФИО:\t" + _secondname + ' ' + _name + ' ' + Get_Middlename() + '\n';
	result += "    - Телефон:\t" + _personal_phone + '\n';
	result += "    - ИНН:\t" + _T_I_N + '\n';
	result += "    - Адрес:\t" + _registration_adress + '\n';
	return result;
}
