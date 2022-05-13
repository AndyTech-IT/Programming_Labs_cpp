#include "Person_List.h"

Person_List::Person_List(Person* first)
{
    _begin = _end = NULL;
    _count = 0;

    if (first)
        Add(first);
}

Person_List::Person_List(const Person_List& copy): Person_List()
{
    Person_ListItem* curent = copy._begin;
    for (int i = 0; i < copy._count; i++)
    {
        Add(curent->Get_Data());
        curent = curent->Next;
    }
}

Person_List::Person_List(const Person_List* copy) : Person_List()
{
    Person_ListItem* curent = copy->_begin;
    for (int i = 0; i < copy->_count; i++)
    {
        Add(curent->Get_Data());
        curent = curent->Next;
    }
}

Person_List::~Person_List()
{
    if (_count == 0)
        return;
    Person_ListItem* curent = _end;
    Person_ListItem* temp = NULL;
    for (int i = 0; i < _count; i++)
    {
        if (curent)
        {
            temp = curent->Previous;
            delete curent;
            curent = temp;
        }
        else
        {
            cout << "Null data in list!" << endl;
        }
    }
}

void Person_List::Add(Person* p)
{
    if (_count == 0)
    {
        _count = 1;
        _begin = _end = new Person_ListItem(p);
        return;
    }

    _end->Next = new Person_ListItem(p);
    _end->Next->Previous = _end;
    _end = _end->Next;
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

Person* Person_List::Find(string name) const
{
    Person_ListItem* curent = _begin;
    for (int i = 0; i < _count; i++)
    {
        if (curent->Get_Data()->Get_Name().find(name) != -1)
        {
            return curent->Get_Data();
        }
    }
    return NULL;
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
    if (list._count == 0)
    {
        cout << "Список пуст!" << endl;
        return os;
    }

    Person_ListItem* curent = list._begin;
    for (int i = 0; i < list._count; i++)
    {
        os << *curent->Get_Data();
        curent = curent->Next;
    }
    return os;
}

void Save(Person_List& list, string filename)
{
    FILE* f = NULL;
    fopen_s(&f, filename.c_str(), "w");
    if (f == NULL)
    {
        cout << "Save failed!" << endl;
        return;
    }

    int i = list._count;
    fwrite(&i, sizeof(int), 1, f);
    fclose(f);
    Person_ListItem* curent = list._begin;
    for (int i = 0; i < list._count; i++)
    {
        fopen_s(&f, filename.c_str(), "a");
        curent->Get_Data()->WriteData(f);
        curent = curent->Next;
        fclose(f);
    }
    fclose(f);
}

void Load(Person_List& list, string filename)
{
    int i;
    BYTE b;
    FILE* f;
    fopen_s(&f, filename.c_str(), "r");
    if (f == NULL)
    {
        cout << "Cant open the file!" << endl;
        return;
    }

    fread(&i, sizeof(int), 1, f);
    for (int index = 0; index < i; index++)
    {
        fread(&b, sizeof(BYTE), 1, f);
        Person* p;
        if (Person::Is_MyData(b))
        {
            //list.Add(new Person());
            cout << "Data is broken!" << endl;
            break;
        }
        if (Individual_Person::Is_MyData(b))
        {
            p = new Individual_Person();
        }
        else if (Entity_Person::Is_MyData(b))
        {
            p = new Entity_Person();
        }
        else
        {
            cout << "Data is broken!" << endl;
            break;
        }
        p->ReadData(f);
        list.Add(p);
    }
}
