#include "Electronic.h"

USHORT Electronic::_objects_count = 0;

USHORT Electronic::Get_Electronic_Count()
{
	return _objects_count;
}

string Electronic::Get_Detail() const
{
	string result = Goods::Get_Detail();
	result += "\t- Катигория: " + _category + '\n';
	return result;
}

Electronic::operator const string() const
{
	return "Электро товар: " + Get_Detail();
}

Electronic::Electronic(const string title, const USHORT weight, string category): Goods(title, weight)
{
	_category = category;
	_objects_count++;
}

Electronic::Electronic(const Electronic& copy): Electronic(copy._title, copy._weight, copy._category)
{ }

Electronic::Electronic(const Electronic * copy) : Electronic(copy->_title, copy->_weight, copy->_category)
{ }

Electronic::~Electronic()
{
	_objects_count--;
}

string Electronic::Get_Category()
{
	return _category;
}
