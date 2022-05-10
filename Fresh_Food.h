#pragma once
#include "Main.h"
#include "Food.h"

class Fresh_Food : public Food
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Fresh_Food_Count();

public:
	string Get_Detail() const override;
	operator const string() const override;

protected:
	USHORT _shelflife_time;

public:
	Fresh_Food(const string title = DEFAULT_STR, const USHORT weight = 0, USHORT shelflife_time = 0);
	Fresh_Food(const Fresh_Food& copy);
	Fresh_Food(const Fresh_Food* copy);
	~Fresh_Food() override;

public:
	USHORT Get_ShelfLife_Time() const override;
};

