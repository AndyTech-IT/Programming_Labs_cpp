#pragma once
#include "Main.h"
#include "Person.h"
#include "Person_ListItem.h"
#include "Individual_Person.h"
#include "Entity_Person.h"

class Person_List
{
	friend void Save(Person_List& list, string filename);
	friend void Load(Person_List& list, string filename);
	friend ostream& operator << (ostream& os, const Person_List& list);

private:
	Person_ListItem* _begin, * _end;
	USHORT _count;

public:
	Person_List(Person* first = NULL);
	Person_List(const Person_List& copy);
	Person_List(const Person_List* copy);
	~Person_List();

private:
	Person_ListItem* Get_Item(USHORT index) const;

public:
	void Add(Person* p);
	void Remove(USHORT index);

	void Sort();
	Person* Find(string name) const;

public:
	Person* operator [](int index) const;
	operator int() const;
};

ostream& operator << (ostream& os, const Person_List& list);
void Save(Person_List& list, string filename);
void Load(Person_List& list, string filename);

