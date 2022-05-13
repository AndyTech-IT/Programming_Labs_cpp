#include "LR_7.h"

#if LR == 7

#include "SetArray.h"
void General_1()
{
	SetArray<int> arr1(1), arr2(2), arr3;
	arr1 += (arr2 += SetArray<int>(3) += arr3 = SetArray<int>(4) + 5) - 4;
	SetArray<int> arr4 = arr1 - arr2 - arr3;

	for (int i = 0; i < arr1; i++)
		cout << *arr1[i] << ' ';
	cout << endl;

	for (int i = 0; i < arr2; i++)
		cout << *arr2[i] << ' ';
	cout << endl;

	for (int i = 0; i < arr3; i++)
		cout << *arr3[i] << ' ';
	cout << endl;

	for (int i = 0; i < arr4; i++)
		cout << *arr4[i] << ' ';
	cout << endl;

	system("pause");
}

#include "Goods.h"
#include "Food.h"
#include "Canned_Food.h"
#include "Fresh_Food.h"
#include "Electronic.h"
#include "Electronic_Component.h"

void Show_Shalflife_Time(Food** food)
{
	if (food == NULL)
	{
		cout << "������ ����!" << endl;
		return;
	}

	for (int i = 0; i < Food::Get_Food_Count(); i++)
	{
		cout << food[i]->Get_Title() << " - " << food[i]->Get_ShelfLife_Time() << " ��." << endl;
	}
}

void Show_Goods(Goods** goods)
{
	USHORT count = 0;
	if (goods == NULL)
	{
		cout << "������ ����!" << endl;
		return;
	}
	string geted_type = typeid(**goods).name();
	if (geted_type == typeid(Canned_Food).name() || geted_type == typeid(Fresh_Food).name())
	{
		count = Food::Get_Food_Count();
	}
	else if (geted_type == typeid(Electronic).name() || geted_type == typeid(Electronic_Component).name())
	{
		count = Electronic::Get_Electronic_Count();
	}
	else
	{
		cout << "������!" << endl;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		cout << string(*goods[i]) << endl;
	}
}

void Add_Food(Food**& food, Food* adding)
{
	if (food == NULL)
	{
		food = new Food * [1]{ adding };
	}
	else
	{
		int count = Food::Get_Food_Count() - 1;
		Food** temp = new Food * [count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = food[i];
		}

		delete[] food;
		temp[count] = adding;
		food = temp;
	}

	cout << endl << "�������� ����� �������:" << endl;
	cout << string(*adding)<< endl;
}


void Add_Electronic(Electronic**& electronic, Electronic* adding)
{
	if (electronic == NULL)
	{
		electronic = new Electronic * [1]{ adding };
	}
	else
	{
		int count = Electronic::Get_Electronic_Count() - 1;
		Electronic** temp = new Electronic * [count + 1];
		for (int i = 0; i < count; i++)
		{
			temp[i] = electronic[i];
		}

		delete[] electronic;
		temp[count] = adding;
		electronic = temp;
	}

	cout << endl << "�������� ����� �������:" << endl;
	cout << string(*adding) << endl;
}

void General_2()
{
	Food** food = NULL;
	Electronic** electronic = NULL;
	int c;
	bool work = true;

	string title;
	USHORT weight;

	USHORT shelflife_time;
	USHORT shelflife_time1;

	string category;
	string componet_of;

	while (work)
	{
		system("cls");

		cout << "0) �����." << endl;
		cout << "1) �������� ������." << endl;
		cout << "2) �������� ��������." << endl;
		cout << "3) �������� �����������." << endl;
		cout << "4) �������� ���������." << endl;
		cout << "5) ������� ���." << endl;
		cout << "6) ������� �����������." << endl;
		cout << "7) ������� ���� �������� ���." << endl;
		cin >> c;
		switch ((Goods_Comand)c)
		{
		case Goods_Comand::Add_Fresh_Food:
			cout << "��������: ";
			cin >> title;
			cout << "���: ";
			cin >> weight;
			cout << "���� ��������: ";
			cin >> shelflife_time;
			Add_Food(food, new Fresh_Food(title, weight, shelflife_time));
			break;
		case Goods_Comand::Add_Canned_Food:
			cout << "��������: ";
			cin >> title;
			cout << "���: ";
			cin >> weight;
			cout << "���� �������� (�������): ";
			cin >> shelflife_time;
			cout << "���� �������� (�������): ";
			cin >> shelflife_time1;
			Add_Food(food, new Canned_Food(title, weight, shelflife_time1, shelflife_time));
			break;
		case Goods_Comand::Add_Electronic:
			cout << "��������: ";
			cin >> title;
			cout << "���: ";
			cin >> weight;
			cout << "���������: ";
			cin >> category;
			Add_Electronic(electronic, new Electronic(title, weight, category));
			break;
		case Goods_Comand::Add_Electronic_Component:
			cout << "��������: ";
			cin >> title;
			cout << "���: ";
			cin >> weight;
			cout << "���������: ";
			cin >> category;
			cout << "��������� �: ";
			cin >> componet_of;
			Add_Electronic(electronic, new Electronic_Component(title, weight, category, componet_of));
			break;
		case Goods_Comand::Show_Food:
			Show_Goods((Goods**)food);
			break;
		case Goods_Comand::Show_Electronic:
			Show_Goods((Goods**)electronic);
			break;
		case Goods_Comand::Show_Food_Shelflife_Time:
			Show_Shalflife_Time(food);
			break;

		case Goods_Comand::Exit:
			work = false;
			cout << "�������.." << endl;
			break;
		default:
			cout << "�������� ������!" << endl;
			break;
		}

		system("pause");
	}

	if (food)
	{
		for (int i = 0; i < Food::Get_Food_Count(); i++)
			delete food[i];
		delete[] food;
	}

	if (electronic)
	{
		for (int i = 0; i < Food::Get_Food_Count(); i++)
			delete electronic[i];
		delete[] electronic;
	}

}

#include "Person.h"
#include "Individual_Person.h"
#include "Entity_Person.h"
#include "Person_List.h"
#include "Person_ListItem.h"

void Individual()
{
	Person_List list;
	cout << list << endl << endl;
	list.Add(new Individual_Person("����", "123145151355", "����� ��� 3 �������� 2", "������", true, "��������", "89146359804"));
	list.Add(new Entity_Person("��� ��������", "43562351", "����� ��� 5 �������� �", "124124", "34254625", "567324254"));
	cout << list << endl << endl;

	Save(list, "test.txt");
	Load(list, "test.txt");
	cout << list << endl << endl;

	list.Add(new Individual_Person("1", "1", "1", "1", true, "1", "1"));
	list.Add(new Individual_Person("2", "2", "2", "2", true, "2", "2"));
	list.Add(new Individual_Person("�", "�", "�", "�", true, "�", "�"));
	list.Sort();
	cout << list << endl << endl;

	list.Remove(0);
	cout << list << endl << endl;

	list[0]->Chainge_Name("1");
	((Individual_Person*)list[0])->Chainge_Middlename("1");
	((Individual_Person*)list[0])->Chainge_Secondname("1");
	cout << *list[0] << *list[-1] << endl;
}

void ALL()
{
#	if REPORT == false

	cout << "����� ������� 1" << endl;
	General_1();

	system("cls");

	cout << "����� ������� 2" << endl;
	General_2();

	system("cls");

#	endif

	cout << "�������������� �������" << endl;
	Individual();
}

#endif