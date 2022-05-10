#pragma once
#include "Main.h"
#include "Goods.h"

#if LR == 7

class Food : public Goods
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Food_Count();

public:
	string Get_Detail() const override;
	operator const string() const override;

public:
	Food(const string title = DEFAULT_STR, const USHORT weight = 0);
	Food(const Food& copy);
	Food(const Food* copy);
	~Food() override;

public:
	virtual USHORT Get_ShelfLife_Time() const = 0;
};

#endif