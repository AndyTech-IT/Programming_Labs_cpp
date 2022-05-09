#include "Book.h"

#if LR == 6

USHORT Book::_objects_count = 0;

USHORT Book::Get_Books_Count()
{
	return _objects_count;
}

string Book::Get_Detail() const
{
	string result = Printed_Edition::Get_Detail();
	result += "Тематика: " + _subject_title + '\n';
	result += "Автор: " + _author_name + '\n';
	result += "Страниц: " + _pages_count + '\n';
	return result;
}

Book::Book
(
	const string title, const string publisher, const USHORT publish_year, 
	const string subject, const string author, const USHORT pages
) : Printed_Edition(title, publisher, publish_year)
{
	Set_Subject_Title(subject);
	Set_Author_Name(author);
	Set_Pages_Count(pages);
	_objects_count++;
}

Book::Book(const Book& copy) : Book(copy._title, copy._publisher, copy._publish_year, copy._subject_title, copy._author_name, copy._pages_count)
{ }

Book::Book(const Book * copy) : Book(copy->_title, copy->_publisher, copy->_publish_year, copy->_subject_title, copy->_author_name, copy->_pages_count)
{ }

Book::~Book()
{
	_objects_count--;
}

string Book::Get_Subject_Title() const
{
	return _subject_title;
}

string Book::Get_Author_Name() const
{
	return _author_name;
}

USHORT Book::Get_Pages_Count() const
{
	return _pages_count;
}

void Book::Set_Subject_Title(const string subject)
{
	if (subject != "")
		_subject_title = subject;
}

void Book::Set_Author_Name(const string author)
{
	if (author != "")
		_author_name = author;
}

void Book::Set_Pages_Count(const USHORT pages)
{
	_pages_count = pages;
}

Book::operator const char* () const
{
	string temp = "Книга:\n" + Get_Detail();
	int len = temp.length() + 1;
	char* result = new char[len];
	for (int i = 0; i < len; i++)
	{
		result[i] = temp[i];
	}
	return result;
}

#endif