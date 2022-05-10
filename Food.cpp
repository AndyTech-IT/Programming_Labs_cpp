#include "Food.h"

USHORT Food::_objects_count = 0;

USHORT Food::Get_Food_Count()
{
    return _objects_count;
}

string Food::Get_Detail() const
{
    return Goods::Get_Detail();
}

Food::operator const string() const
{
    return "Åäà " + Get_Detail();
}

Food::Food(const string title, const USHORT weight) : Goods(title, weight)
{
    _objects_count++;
}

Food::Food(const Food& copy) : Food(copy._title, copy._weight)
{ }

Food::Food(const Food * copy) : Food(copy->_title, copy->_weight)
{ }

Food::~Food()
{
    _objects_count--;
}
