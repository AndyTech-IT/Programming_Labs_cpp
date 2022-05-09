#include "Magazine.h"

#if LR == 6

USHORT Magazine::_objects_count = 0;

USHORT Magazine::Get_Magazines_Count()
{
	return _objects_count;
}

string Magazine::Get_Detail() const
{
	string result = Printed_Edition::Get_Detail();
	result += "Выпуск: №" + to_string(_issue) + '\n';
	result += "Месяц выпуска: " + to_string(_publish_month) + '\n';
	return result;
}

Magazine::Magazine
(
	const string title, const string publisher, const USHORT publish_year,
	const USHORT issue, const BYTE month
) : Printed_Edition(title, publisher, publish_year)
{
	Set_Issue(issue);
	Set_Publish_Month(month);
	_objects_count++;
}

Magazine::Magazine(const Magazine& copy) : Magazine(copy._title, copy._publisher, copy._publish_year, copy._issue, copy._publish_month)
{ }

Magazine::Magazine(const Magazine* copy) : Magazine(copy->_title, copy->_publisher, copy->_publish_year, copy->_issue, copy->_publish_month)
{ }

Magazine::~Magazine()
{
	_objects_count--;
}

USHORT Magazine::Get_Issue() const
{
	return _issue;
}

BYTE Magazine::Get_Publish_Month() const
{
	return _publish_month;
}

void Magazine::Set_Issue(const USHORT issue)
{
	_issue = issue;
}

void Magazine::Set_Publish_Month(const BYTE month)
{
	if (month >= 1 && month <= 12)
		_publish_month = month;
}

Magazine::operator const char* () const
{
	string temp = "Журнал:\n" + Get_Detail();
	int len = temp.length()+1;
	char* result = new char[len];
	for (int i = 0; i < len; i++)
	{
		result[i] = temp[i];
	}
	return result;
}

#endif