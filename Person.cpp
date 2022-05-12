#include "Person.h"

USHORT Person::_objects_count = 0;

USHORT Person::Get_Person_Count()
{
    return _objects_count;
}

bool Person::Is_MyData(BYTE first_byte)
{
    return first_byte == (BYTE)Data_Marker::Is_Person_Data;
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

void Person::WriteData(FILE*& f) const
{
    int i;
    BYTE b;
    if (typeid(*this).name() == typeid(Person).name())
    {
        b = (BYTE)Data_Marker::Is_Person_Data;
        fwrite(&b, sizeof(BYTE), 1, f);
    }

    i = _name.length();
    fwrite(&i, sizeof(int), 1, f);
    fwrite(&_name, sizeof(char), i, f);

    i = _T_I_N.length();
    fwrite(&i, sizeof(int), 1, f);
    fwrite(&_T_I_N, sizeof(char), i, f);

    i = _registration_adress.length();
    fwrite(&i, sizeof(int), 1, f);
    fwrite(&_registration_adress, sizeof(char), i, f);
}

void Person::ReadData(FILE*& f)
{
    int i;
    fread(&i, sizeof(int), 1, f);
    fread(&_name, sizeof(char), i, f);

    fread(&i, sizeof(int), 1, f);
    fread(&_T_I_N, sizeof(char), i, f);

    fread(&i, sizeof(int), 1, f);
    fread(&_registration_adress, sizeof(char), i, f);
}

ostream& operator<<(ostream& os, Person& p)
{
    os << p.Get_Detail();
    return os;
}