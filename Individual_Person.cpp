#include "Individual_Person.h"

Individual_Person::Individual_Person
(
	const string name, const string TIN, const string adress, 
	const string secondname, const bool has_middlename, const string middlename, const string phone
): Person(name, TIN, adress)
{
	_secondname = secondname;
	_has_middlename = has_middlename;
	_middlename = middlename;
	_personal_phone = phone;
}

Individual_Person::Individual_Person(const Individual_Person& copy)
	:Individual_Person(copy._name, copy._T_I_N, copy._registration_adress, copy._secondname, copy._has_middlename, copy._middlename, copy._personal_phone)
{ }

Individual_Person::Individual_Person(const Individual_Person * copy)
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

string Individual_Person::Get_Detail() const
{
	string result;
	result += "Физическое Лицо:" + string("\n");
	result += "    - ФИО:\t" + _secondname + ' ' + _name + ' ' + Get_Middlename() + '\n';
	result += "    - Телефон:\t" + _personal_phone + '\n';
	result += "    - ИНН:\t" + _T_I_N + '\n';
	return result;
}
