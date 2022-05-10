#include "Electronic_Component.h"

USHORT Electronic_Component::_objects_count = 0;

USHORT Electronic_Component::Get_Electronic_Component_Count()
{
    return _objects_count;
}

string Electronic_Component::Get_Detail() const
{
    string result = Electronic::Get_Detail();
    result += "\t- Совместимо с: " + _component_of + '\n';
    return result;
}

Electronic_Component::operator const string() const
{
    return "Комплектующая: " + Get_Detail();
}

Electronic_Component::Electronic_Component(const string title, const USHORT weight, string category, string component_of): Electronic(title, weight, category)
{
    _component_of = component_of;
    _objects_count++;
}

Electronic_Component::Electronic_Component(const Electronic_Component& copy): Electronic_Component(copy._title, copy._weight, copy._category, copy._component_of)
{ }

Electronic_Component::Electronic_Component(const Electronic_Component * copy) : Electronic_Component(copy->_title, copy->_weight, copy->_category, copy->_component_of)
{ }

Electronic_Component::~Electronic_Component()
{
    _objects_count--;
}

string Electronic_Component::Get_Component_Of()
{
    return _component_of;
}
