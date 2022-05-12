#pragma once
#include "Main.h"
#include "Person.h"
#include "Person_ListItem.h"

class Person_List
{
	friend void Save(Person_List list, string filename);
	friend void Load(Person_List& list, string filename);
	friend ostream& operator << (ostream& os, const Person_List& list);
private:
	Person_ListItem* _begin, * _end;
	USHORT _count;

public:
	void Add(Person* p);
	void Remove(USHORT index);

	void Sort();
	Person_ListItem* Find(string name);

public:
	Person* operator [](USHORT index) const;
	operator int() const;
};

ostream& operator << (ostream& os, const Person_List& list);
void Save(Person_List list, string filename);
void Load(Person_List& list, string filename);

