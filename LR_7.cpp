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

void General_2()
{

}

void Individual()
{

}

void ALL()
{
#	if REPORT == false

	cout << "Общее задание 1" << endl;
	General_1();

	system("pause");
	system("cls");

	cout << "Общее задание 2" << endl;
	General_2();

	system("pause");
	system("cls");

#	endif

	cout << "Индивидуальное задание" << endl;
	Individual();
}

#endif