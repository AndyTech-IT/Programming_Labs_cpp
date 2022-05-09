#include "Printed_Edition.h"

#if LR == 6

USHORT Printed_Edition::_objects_count = 0;

USHORT Printed_Edition::Get_Editions_Count()
{
	return _objects_count;
}

string Printed_Edition::Get_Detail() const
{
	string result;
	result += "Название: " + _title + '\n';
	result += "Издатель: " + _publisher + '\n';
	result += "Год издания: " + to_string(_publish_year) + '\n';
	return result;
}

Printed_Edition::Printed_Edition(const string title, const string publisher, const USHORT publish_year)
{
	_publish_year = MIN_PUP_YEAR;
	Set_Title(title);
	Set_Publisher(publisher);
	Set_Publish_Year(publish_year);
	_objects_count++;
}

Printed_Edition::Printed_Edition(const Printed_Edition& copy): Printed_Edition(copy._title, copy._publisher, copy._publish_year)
{ }

Printed_Edition::Printed_Edition(const Printed_Edition* copy) : Printed_Edition(copy->_title, copy->_publisher, copy->_publish_year)
{ }

Printed_Edition::~Printed_Edition()
{
	_objects_count--;
}

string Printed_Edition::Get_Title() const
{
	return _title;
}

string Printed_Edition::Get_Publisher() const
{
	return _publisher;
}

USHORT Printed_Edition::Get_Publish_Year() const
{
	return _publish_year;
}

void Printed_Edition::Set_Title(const string title)
{
	if (title != "")
		_title = title;
}

void Printed_Edition::Set_Publisher(const string publisher)
{
	if (publisher != "")
		_publisher = publisher;
}

void Printed_Edition::Set_Publish_Year(const USHORT publish_year)
{
	if (publish_year >= MIN_PUP_YEAR)
		_publish_year = publish_year;
}

#endif