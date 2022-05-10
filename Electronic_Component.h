#pragma once
#include "Electronic.h"
class Electronic_Component : public Electronic
{
private:
	static USHORT _objects_count;

public:
	static USHORT Get_Electronic_Component_Count();

public:
	string Get_Detail() const override;
	operator const string() const override;

protected:
	string _component_of;

public:
	Electronic_Component(const string title = DEFAULT_STR, const USHORT weight = 0, string category = DEFAULT_STR, string component_of = DEFAULT_STR);
	Electronic_Component(const Electronic_Component& copy);
	Electronic_Component(const Electronic_Component* copy);
	~Electronic_Component() override;

public:
	string Get_Component_Of();
};

