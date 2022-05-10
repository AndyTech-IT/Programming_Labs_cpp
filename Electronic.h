#pragma once
#include "Main.h"
#include "Goods.h"

class Electronic : public Goods
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Electronic_Count();

public:
	string Get_Detail() const override;
	operator const string() const override;

protected:
	string _category;

public:
	Electronic(const string title = DEFAULT_STR, const USHORT weight = 0, string category = DEFAULT_STR);
	Electronic(const Electronic& copy);
	Electronic(const Electronic* copy);
	~Electronic() override;

public:
	string Get_Category();
};

