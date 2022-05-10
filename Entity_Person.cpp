#include "Entity_Person.h"

Entity_Person::Entity_Person
(
	const string name, const string TIN, const string adress, 
	const string MSRN, const string COR, const string BIC
)
{
	_M_S_R_N = MSRN;
	_C_O_R = COR;
	_B_I_C = BIC;
}

Entity_Person::Entity_Person(const Entity_Person& copy)
{
}

Entity_Person::Entity_Person(const Entity_Person* copy)
{
}

Entity_Person::~Entity_Person()
{
}

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

string Entity_Person::Get_Detail() const
{
	string result;
	result += "Şğèäè÷åñêîå Ëèöî:" + string("\n");
	result += "    - Îğã-èÿ:\t"	+ _name + '\n';
	result += "    - ÎÃĞÍ:\t"	+ _M_S_R_N + '\n';
	result += "    - ÈÍÍ:\t"	+ _T_I_N + '\n';
	result += "    - ÊÏÏ:\t"	+ _C_O_R + '\n';
	result += "    - ÁÈÊ:\t"	+ _B_I_C + '\n';
	return result;
}
