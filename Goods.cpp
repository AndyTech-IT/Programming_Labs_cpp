#include "Goods.h"

USHORT Goods::_objects_count = 0;

USHORT Goods::Get_Goods_Count()
{
    return _objects_count;
}

string Goods::Get_Detail() const
{
    return _title + ' ' + to_string(_weight) + " êã.\n";
}

Goods::Goods(const string title, const USHORT weight)
{
    _title = DEFAULT_STR;
    Set_Title(title);
    Set_Weight(weight);
    _objects_count++;
}

Goods::Goods(const Goods& copy) : Goods(copy._title, copy._weight)
{ }

Goods::Goods(const Goods* copy) : Goods(copy->_title, copy->_weight)
{ }

Goods::~Goods()
{
    _objects_count--;
}

string Goods::Get_Title() const
{
    return _title;
}

USHORT Goods::Get_Weight() const
{
    return _weight;
}

void Goods::Set_Title(const string title)
{
    if (title != "")
        _title = title;
}

void Goods::Set_Weight(const USHORT weight)
{
    _weight = weight;
}
