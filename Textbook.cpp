#include "Textbook.h"

#if LR == 6

USHORT Textbook::_objects_count = 0;

USHORT Textbook::Get_Textbooks_Count()
{
    return _objects_count;
}

string Textbook::Get_Detail() const
{
    string result = Book::Get_Detail();
    result += "Назначение: " + _objective + '\n';
    return result;
}

Textbook::Textbook
(
    const string title, const string publisher, const USHORT publish_year, 
    const string subject, const string author, const USHORT pages, 
    const string objective
) : Book(title, publisher, publish_year, subject, author, pages)
{
    Set_Objective(objective);
    _objects_count++;
}

Textbook::Textbook(const Textbook& copy) : Textbook(copy._title, copy._publisher, copy._publish_year, copy._subject_title, copy._author_name, copy._pages_count, copy._objective)
{ }

Textbook::Textbook(const Textbook * copy) : Textbook(copy->_title, copy->_publisher, copy->_publish_year, copy->_subject_title, copy->_author_name, copy->_pages_count, copy->_objective)
{ }

Textbook::~Textbook()
{
    _objects_count--;
}

string Textbook::Get_Objective() const
{
    return _objective;
}

void Textbook::Set_Objective(const string objective)
{
    if (objective != "")
        _objective = objective;
}

Textbook::operator const char* () const
{
    string temp = "Учебник: \n" + Get_Detail();
    int len = temp.length() + 1;
    char* result = new char[len];
    for (int i = 0; i < len; i++)
    {
        result[i] = temp[i];
    }
    return result;
}

#endif