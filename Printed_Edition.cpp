#include "Printed_Edition.h"

#if LR == 6

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