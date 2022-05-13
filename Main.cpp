#include "Main.h"

int main()
{
	SetConsoleCP(RusCharset);
	SetConsoleOutputCP(RusCharset);
	setlocale(LC_ALL, "rus");

	cout << "Лабораторная работа №" << LR << endl;

	ALL();

	system("pause");
	return 0;
}

void Write_String(string data, FILE*& f)
{
    int size = data.length();
    fwrite(&size, sizeof(int), 1, f);
    for (int i = 0; i < size; i++)
    {
        fwrite(&data[i], sizeof(char), 1, f);
    }
}

string Read_String(FILE*& f)
{
    int size;
    char* temp;
    fread(&size, sizeof(int), 1, f);
    temp = new char[size + 1];
    for (int i = 0; i < size; i++)
        fread_s(&temp[i], sizeof(char)*(size+1), sizeof(char), 1, f);
    temp[size] = '\0';
    return temp;
}
