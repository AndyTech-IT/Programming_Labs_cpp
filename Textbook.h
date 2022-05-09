#pragma once
#include "Main.h"
#include "Book.h"

#if LR == 6

class Textbook :  public Book
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Textbooks_Count();

protected:
	string _objective;

protected:
	string Get_Detail() const override;

public:
	Textbook
	(
		const string title = DEFAULT_STR, const string publisher = DEFAULT_STR, const USHORT publish_year = MIN_PUP_YEAR,
		const string subject = DEFAULT_STR, const string author = DEFAULT_STR, const USHORT pages = DEFAULT_NUMBER,
		const string objective = DEFAULT_STR
	);
	Textbook(const Textbook& copy);
	Textbook(const Textbook* copy);
	~Textbook() override;

public:
	string Get_Objective() const;


	void Set_Objective(const string objective);

public:
	operator const char* () const override;
};

#endif