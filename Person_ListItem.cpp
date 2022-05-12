#include "Person_ListItem.h"

Person_ListItem::Person_ListItem(Person* data)
{
	_data = data;
	Next = Previous = NULL;
}

Person_ListItem::Person_ListItem(const Person_ListItem& copy): Person_ListItem(copy._data)
{ }

Person_ListItem::Person_ListItem(const Person_ListItem * copy) : Person_ListItem(copy->_data)
{ }

Person_ListItem::~Person_ListItem()
{
	if (Next)
		Next->Previous = Previous;
	if (Previous)
		Previous->Next = Next;
	delete _data;
}

Person* Person_ListItem::Get_Data() const
{
	return _data;
}

void Person_ListItem::Set_Data(Person* data)
{
	_data = data;
}
