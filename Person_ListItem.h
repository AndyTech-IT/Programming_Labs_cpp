#pragma once
#include "Main.h"
#include "Person.h"

class Person_ListItem
{
protected:
	Person* _data;

public:
	Person_ListItem* Next;
	Person_ListItem* Previous;

public:
	Person_ListItem(Person* data = NULL);
	Person_ListItem(const Person_ListItem& copy);
	Person_ListItem(const Person_ListItem* copy);
	~Person_ListItem();

public:
	Person* Get_Data() const;
	void Set_Data(Person* data);
};

