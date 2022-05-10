#pragma once
#include "Main.h"
#include "Printed_Edition.h"

#if LR == 6

class Magazine : public Printed_Edition
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Magazines_Count();

protected:
	USHORT _issue;
	BYTE _publish_month;

private:
	string Get_Detail() const override;

public:
	Magazine
	(
		const string title = DEFAULT_STR, const string publisher = DEFAULT_STR, const USHORT publish_year = MIN_PUP_YEAR,
		const USHORT issue = DEFAULT_NUMBER, const BYTE month = DEFAULT_NUMBER
	);
	Magazine(const Magazine& copy);
	Magazine(const Magazine* copy);
	~Magazine() override;

public:
	USHORT Get_Issue() const;
	BYTE Get_Publish_Month() const;

	void Set_Issue(const USHORT issue);
	void Set_Publish_Month(const BYTE month);

public:
	operator const char* () const override;
};

#endif