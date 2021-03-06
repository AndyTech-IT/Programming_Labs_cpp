#include "Entity_Person.h"

bool Entity_Person::Is_MyData(BYTE first_byte)
{
	return first_byte == (BYTE)Data_Marker::Is_Entity_Person_Data;
}

Entity_Person::Entity_Person
(
	const string name, const string TIN, const string adress,
	const string MSRN, const string COR, const string BIC
) : Person(name, TIN, adress)
{
	_M_S_R_N = MSRN;
	_C_O_R = COR;
	_B_I_C = BIC;
}

Entity_Person::Entity_Person(const Entity_Person& copy) : Entity_Person(copy._name, copy._T_I_N, copy._registration_adress, copy._M_S_R_N, copy._C_O_R, copy._B_I_C)
{ }

Entity_Person::Entity_Person(const Entity_Person* copy) : Entity_Person(copy->_name, copy->_T_I_N, copy->_registration_adress, copy->_M_S_R_N, copy->_C_O_R, copy->_B_I_C)
{ }

Entity_Person::~Entity_Person()
{ }

string Entity_Person::Get_MSRN() const
{
	return string();
}

string Entity_Person::Get_COR() const
{
	return string();
}

USHORT Entity_Person::Get_BIC() const
{
	return USHORT();
}

void Entity_Person::WriteData(FILE*& f) const
{
	int i;
	BYTE b;
	if (typeid(*this).name() == typeid(Entity_Person).name())
	{
		b = (BYTE)Data_Marker::Is_Entity_Person_Data;
		fwrite(&b, sizeof(BYTE), 1, f);
	}
	Person::WriteData(f);

	Write_String(_M_S_R_N, f);

	Write_String(_C_O_R, f);

	Write_String(_B_I_C, f);
}

void Entity_Person::ReadData(FILE*& f)
{
	int i;
	Person::ReadData(f);

	_M_S_R_N = Read_String(f);

	_C_O_R = Read_String(f);

	_B_I_C = Read_String(f);
}

string Entity_Person::Get_Detail() const
{
	string result;
	result += "??????????? ????:" + string("\n");
	result += "    - ???-?:\t" + _name + '\n';
	result += "    - ????:\t" + _M_S_R_N + '\n';
	result += "    - ???:\t" + _T_I_N + '\n';
	result += "    - ???:\t" + _C_O_R + '\n';
	result += "    - ???:\t" + _B_I_C + '\n';
	result += "    - ?????:\t" + _registration_adress + '\n';
	return result;
}
