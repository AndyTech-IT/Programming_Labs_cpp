#include "Fresh_Food.h"

USHORT Fresh_Food::_objects_count = 0;

USHORT Fresh_Food::Get_Fresh_Food_Count()
{
    return _objects_count;
}

string Fresh_Food::Get_Detail() const
{
    string result = Food::Get_Detail(); 
    result += "\t- Срок годности: " + to_string(Get_ShelfLife_Time()) + '\n';
    return result;
}

Fresh_Food::operator const string() const
{
    return "Свежый " + Get_Detail();
}

Fresh_Food::Fresh_Food(const string title, const USHORT weight, USHORT shelflife_time) : Food(title, weight)
{
    _shelflife_time = shelflife_time;
    _objects_count++;
}

Fresh_Food::Fresh_Food(const Fresh_Food& copy): Fresh_Food(copy._title, copy._weight, copy._shelflife_time)
{ }

Fresh_Food::Fresh_Food(const Fresh_Food * copy) : Fresh_Food(copy->_title, copy->_weight, copy->_shelflife_time)
{ }

Fresh_Food::~Fresh_Food()
{
    _objects_count--;
}

USHORT Fresh_Food::Get_ShelfLife_Time() const
{
    return _shelflife_time;
}
