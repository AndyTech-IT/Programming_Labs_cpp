#include "Person.h"

USHORT Person::_objects_count = 0;

USHORT Person::Get_Person_Count()
{
    return _objects_count;
}

Person::Person(const string name, const string TIN, const string adress)
{
    _name = name;
    _T_I_N = TIN;
    _registration_adress = adress;
    _objects_count++;
}

Person::Person(const Person& copy): Person(copy._name, copy._T_I_N, copy._registration_adress)
{ }

Person::Person(const Person * copy) : Person(copy->_name, copy->_T_I_N, copy->_registration_adress)
{ }

Person::~Person()
{
    _objects_count--;
}

string Person::Get_Name() const
{
    return _name;
}

string Person::Get_TIN() const
{
    return _T_I_N;
}

string Person::Get_RegistrationAdress() const
{
    return _registration_adress;
}

void Person::Chainge_Name(string name)
{
    if (name != "")
        _name = name;
}

void Person::Chainge_RegistrationAdress(string adress)
{
    if (adress != "")
        _registration_adress = adress;
}

ostream& operator<<(ostream& os, Person& p)
{
    os << p.Get_Detail();
    return os;
}