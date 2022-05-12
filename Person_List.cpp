#include "Person_List.h"

void Person_List::Add(Person* p)
{
    if (_count == 0)
    {
        _count = 1;
        _begin = _end = new Person_ListItem[_count]{ p };
        return;
    }

    _end = _end->Next = new Person_ListItem(p);
    _count++;
}

void Person_List::Remove(USHORT index)
{
    if (index >= _count)
        return;

    _count--;
    delete this->operator [](index);
    if (_count == 0)
        _begin = _end = NULL;
}

void Person_List::Sort()
{
    if (_count <= 1)
        return;

    for (int loop = 0; loop < _count; loop++)
    {
        Person_ListItem* curent = _begin;
        for (int i = 0; i < _count - loop - 1; i++)
        {
            Person_ListItem* p1, * p2;
            Person* temp;
            p1 = curent;
            p2 = curent->Next;
            if (p1->Get_Data()->Get_Name() > p2->Get_Data()->Get_Name())
            {
                Person* temp = p1->Get_Data();
                p1->Set_Data(p2->Get_Data());
                p2->Set_Data(temp);
            }
        }
    }
}

Person_ListItem* Person_List::Find(string name)
{
    Person_ListItem* curent = _begin;
    for (int i = 0; i < _count; i++)
    {
        if (curent->Get_Data()->Get_Name().find(name) != -1)
        {
            return curent;
        }
    }
}

Person* Person_List::operator[](USHORT index) const
{
    if (index >= _count)
        return NULL;

    Person_ListItem* curent = _begin;
    for (int i = 0; i < index; i++)
        curent = curent->Next;
    return curent->Get_Data();
}

Person_List::operator int() const
{
    return _count;
}

ostream& operator<<(ostream& os, const Person_List& list)
{
    Person_ListItem* curent = list._begin;
    for (int i = 0; i < list._count; i++)
    {
        os << curent;
        curent = curent->Next;
    }
    return os;
}

void Save(Person_List list, string filename)
{
    FILE* f;
    fopen_s(&f, filename.c_str(), "w");
    if (f == NULL)
    {
        cout << "Save failed!" << endl;
        return;
    }
    int i = list._count;
    fwrite(&i, sizeof(int), 1, f);
    for (Person_ListItem* curent = list._begin, int i = 0; i < list._count; i++, curent = curent->Next)
    {
        curent->Get_Data()->WriteData(f);
    }
    fclose(f);
}

void Load(Person_List& list, string filename)
{
}
