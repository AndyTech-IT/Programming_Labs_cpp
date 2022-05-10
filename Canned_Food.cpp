#include "Canned_Food.h"

#if LR == 7

USHORT Canned_Food::_objects_count = 0;

USHORT Canned_Food::Get_Canned_Food_Count()
{
    return _objects_count;
}

string Canned_Food::Get_Detail() const
{
    string result = Food::Get_Detail();
    result += "\t- Срок годности (" + string(_is_closed ? "закрыто" : "открыто") + "): " + to_string(Get_ShelfLife_Time()) + '\n';
    return result;
}

Canned_Food::operator const string() const
{
    return "Консервы: " + Get_Detail();
}

Canned_Food::Canned_Food
(
    const string title, const USHORT weight, 
    USHORT closed_life_time, USHORT opened_life_time, bool closed
) : Food(title, weight)
{
    _closed_shelfLife_time = closed_life_time;
    _opened_shelfLife_time = opened_life_time;
    _is_closed = closed;
    _objects_count++;
}

Canned_Food::Canned_Food(const Canned_Food& copy): Canned_Food(copy._title, copy._weight, copy._closed_shelfLife_time, copy._opened_shelfLife_time, copy._is_closed)
{ }

Canned_Food::Canned_Food(const Canned_Food* copy) : Canned_Food(copy->_title, copy->_weight, copy->_closed_shelfLife_time, copy->_opened_shelfLife_time, copy->_is_closed)
{ }

Canned_Food::~Canned_Food()
{
    _objects_count--;
}

void Canned_Food::Open()
{
    if (_is_closed)
        _is_closed = false;
}

USHORT Canned_Food::Get_ShelfLife_Time() const
{
    return _is_closed ? _closed_shelfLife_time : _opened_shelfLife_time;
}

bool Canned_Food::Is_Opened() const
{
    return _is_closed == false;
}

#endif