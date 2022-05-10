#pragma once
#include "Main.h"
#include "Food.h"

#if LR == 7

class Canned_Food : public Food
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Canned_Food_Count();

public:
	string Get_Detail() const override;
	operator const string() const override;

protected:
	USHORT _opened_shelfLife_time;
	USHORT _closed_shelfLife_time;
	bool _is_closed;

public:
	Canned_Food
	(
		const string title = DEFAULT_STR, const USHORT weight = 0, 
		USHORT closed_life_time = 0, USHORT opened_life_time = 0, bool closed = false
	);
	Canned_Food(const Canned_Food& copy);
	Canned_Food(const Canned_Food* copy);
	~Canned_Food() override;

public:
	void Open();

public:
	USHORT Get_ShelfLife_Time() const override;
	bool Is_Opened() const;
};

#endif