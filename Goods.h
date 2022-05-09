#pragma once
#include "Main.h"

class Goods
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Goods_Count();

protected:
	virtual string Get_Detail() const;
	virtual operator const string() const = 0;

protected:
	string _title;
	USHORT _weight;

public:
	Goods(const string title = DEFAULT_STR, const USHORT weight = 0);
	Goods(const Goods& copy);
	Goods(const Goods* copy);
	~Goods();

public:
	string Get_Title() const;
	USHORT Get_Weight() const;

public:
	void Set_Title(const string title);
	void Set_Weight(const USHORT weight);
};

