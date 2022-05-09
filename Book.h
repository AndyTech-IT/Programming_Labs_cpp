#pragma once
#include "Main.h"
#include "Printed_Edition.h"

#if LR == 6

class Book : public Printed_Edition
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Books_Count();

protected:
	string _subject_title;
	string _author_name;
	USHORT _pages_count;

protected:
	string Get_Detail() const override;

public:
	Book
	(
		const string title = DEFAULT_STR, const string publisher = DEFAULT_STR, const USHORT publish_year = MIN_PUP_YEAR,
		const string subject = DEFAULT_STR, const string author = DEFAULT_STR, const USHORT pages = DEFAULT_NUMBER
	);
	Book(const Book& copy);	
	Book(const Book* copy);
	~Book() override;

public:
	string Get_Subject_Title() const;
	string Get_Author_Name() const;
	USHORT Get_Pages_Count() const;

	void Set_Subject_Title(const string subject);
	void Set_Author_Name(const string author);
	void Set_Pages_Count(const USHORT pages);

public:
	operator const char* () const override;
};

#endif