#include "Main.h"

int main()
{
	SetConsoleCP(RusCharset);
	SetConsoleOutputCP(RusCharset);
	setlocale(LC_ALL, "rus");

	cout << "������������ ������ �" << LR << endl;

	ALL();

	system("pause");
	return 0;
}