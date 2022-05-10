#pragma once
#include "Main.h"

enum class Goods_Comand
{
	Exit,

	Add_Fresh_Food,
	Add_Canned_Food,
	Add_Electronic,
	Add_Electronic_Component,

	Show_Food,
	Show_Electronic,

	Show_Food_Shelflife_Time,
};

class Goods
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Goods_Count();

public:
	virtual string Get_Detail() const;
	virtual operator const string() const = 0;

protected:
	string _title;
	USHORT _weight;

public:
	Goods(const string title = DEFAULT_STR, const USHORT weight = 0);
	Goods(const Goods& copy);
	Goods(const Goods* copy);
	virtual ~Goods();

public:
	string Get_Title() const;
	USHORT Get_Weight() const;

protected:
	void Set_Title(const string title);
	void Set_Weight(const USHORT weight);
};

