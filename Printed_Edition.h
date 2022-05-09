#pragma once
#include "Main.h"

#if LR == 6

enum class Library_Command
{
	Exit,
	Print_All,
	Add_Magazine,
	Add_Book,
	Add_Textbook,
};

class Printed_Edition
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Editions_Count();

protected:
	string _title;
	string _publisher;
	USHORT _publish_year;

protected:
	virtual string Get_Detail() const;

public:
	Printed_Edition(const string title = DEFAULT_STR, const string publisher = DEFAULT_STR, const USHORT publish_year = MIN_PUP_YEAR);
	Printed_Edition(const Printed_Edition& copy);
	Printed_Edition(const Printed_Edition* copy);
	virtual ~Printed_Edition();

public:
	string Get_Title() const;
	string Get_Publisher() const;
	USHORT Get_Publish_Year() const;

	void Set_Title(const string title);
	void Set_Publisher(const string publisher);
	void Set_Publish_Year(const USHORT publish_year);

public:
	virtual operator const char*() const = 0;
};

#endif