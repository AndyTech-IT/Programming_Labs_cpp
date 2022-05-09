#include "LR_6.h"

#if LR == 6

#include "Deposit.h"
void General_1()
{
	int count;
	cout << "������� ����� ���������: ";
	cin >> count;
	Deposit* deposits = new Deposit[count];
	cout << "������� ��������� ����� ���������:" << endl;
	for (int i = 0; i < count; i++)
	{
		int amount;
		cout << i + 1 << ") ";
		cin >> amount;
		deposits[i] = Deposit(amount);
	}

	bool work = true;
	int k;
	double rate;

	rate = double(rand() % 2000) / 100;
	Deposit::Set_Interest_Rate(rate / 100);

	while (work)
	{
		system("cls");
		// Randomly chainging of rate
		k = rand() % 100;
		if (k > 75)
		{
			rate = double(rand() % 2000) / 100;
			Deposit::Set_Interest_Rate(rate / 100);
			cout << "��-�� �������������� �� ����� ���������� ������ ����������." << endl;
			cout << "����� ������ ����������: " << rate << '%' << endl;
			system("pause");
		}

		system("cls");
		cout << "������ �� ������ ����������: " << Deposit::Get_Interest_Rate() << '%' << endl;

		int i;
		cout << "0) �����" << endl;
		cout << "1) ������ �������" << endl;
		cout << "2) ������� ��������" << endl;
		cout << "������� �������: ";
		cin >> i;
		switch ((Deposit_Command)i)
		{
		case Deposit_Command::Income_All:
			for (int i = 0; i < count; i++)
			{
				deposits[i].Add_Profit_To_Amount();
			}
			break;
		case Deposit_Command::Show_All:
			Print_Deposits_List(deposits, count);
			system("pause");
			break;

		case Deposit_Command::Exit:
			cout << "�������.." << endl;
			work = false;
			break;
		default:
			cout << "�������� �������!" << endl;
			system("pause");
			break;
		}
	}

	delete[] deposits;
}

#include "Printed_Edition.h"
#include "Magazine.h"
#include "Book.h"
#include "Textbook.h"

void Print_All(Magazine magazines[], Book books[], Textbook textbooks[])
{
	int count = Printed_Edition::Get_Editions_Count();
	cout << "�������� ������� (�����): " << count << endl;

	count = Magazine::Get_Magazines_Count();
	cout << endl << "�������: " << count << endl;
	for (int i = 0; i < count; i++)
		cout << magazines[i] << endl;

	count = Book::Get_Books_Count() - Textbook::Get_Textbooks_Count();
	cout << endl << "�����: " << count << endl;
	for (int i = 0; i < count; i++)
		cout << books[i] << endl;

	count = Textbook::Get_Textbooks_Count();
	cout << endl << "��������: " << count << endl;
	for (int i = 0; i < count; i++)
		cout << textbooks[i] << endl;
}

void General_2()
{
	int c;
	int count;
	bool work = true;

	string title, publisher;
	USHORT year;

	Magazine* magazines = NULL;
	Magazine* m_copy = NULL;
	USHORT issue;
	BYTE mounth;

	Book* books = NULL;
	Book* b_copy = NULL;
	string subject, author;
	USHORT pages;

	Textbook* tb_copy = NULL;
	Textbook* textbooks = NULL;
	string objective;

	while (work)
	{
		system("cls");

		cout << "0) �����" << endl;
		cout << "1) ������� �� �����" << endl;
		cout << "2) �������� ������" << endl;
		cout << "3) �������� �����" << endl;
		cout << "4) �������� �������" << endl;
		cout << "�������� �������: ";
		cin >> c;
		switch ((Library_Command)c)
		{

		case Library_Command::Exit:
		{
			work = false;
			cout << "�������.." << endl;
			system("pause");
			break;
		}

		default:
		{
			cout << "�������� �������!" << endl;
			system("pause");
			break;
		}

		case Library_Command::Print_All:
		{
			Print_All(magazines, books, textbooks);
			system("pause");
			break;
		}
		case Library_Command::Add_Magazine:
		{

			// new Printed_Edition data
			cout << "��������: ";
			cin >> title;
			cout << "������������: ";
			cin >> publisher;
			cout << "��� �������: ";
			cin >> year;

			cout << "�������: ";
			cin >> issue;
			cout << "����� �������: ";
			cin >> year;

			if (magazines == NULL)
			{
				count = 1;
				magazines = new Magazine[count--]{ Magazine(title, publisher, year, issue, year) };
			}
			else
			{
				count = Magazine::Get_Magazines_Count();
				m_copy = new Magazine[count + 1];
				for (int i = 0; i < count; i++)
				{
					m_copy[i] = magazines[i];
				}
				delete[] magazines;
				magazines = m_copy;
				magazines[count] = Magazine(title, publisher, year, issue, year);
			}

			cout << endl  << "�������� " << magazines[count];
			system("pause");
			break;
		}

		case Library_Command::Add_Book:
		{

			// new Printed_Edition data
			cout << "��������: ";
			cin >> title;
			cout << "������������: ";
			cin >> publisher;
			cout << "��� �������: ";
			cin >> year;

			cout << "��������: ";
			cin >> subject;
			cout << "�����: ";
			cin >> author;
			cout << "����� �������: ";
			cin >> pages;

			if (books == NULL)
			{
				count = 1;
				books = new Book[count--]{ Book(title, publisher, year, subject, author, pages) };
			}
			else
			{
				count = Book::Get_Books_Count();
				b_copy = new Book[count + 1];
				for (int i = 0; i < count; i++)
				{
					b_copy[i] = books[i];
				}
				delete[] books;
				books = b_copy;
				books[count] = Book(title, publisher, year, subject, author, pages);
			}

			cout << endl << "��������� " << books[count];
			system("pause");
			break;
		}

		case Library_Command::Add_Textbook:
		{

			// new Printed_Edition data
			cout << "��������: ";
			cin >> title;
			cout << "������������: ";
			cin >> publisher;
			cout << "��� �������: ";
			cin >> year;

			cout << "��������: ";
			cin >> subject;
			cout << "�����: ";
			cin >> author;
			cout << "����� �������: ";
			cin >> pages;


			cout << "����������: ";
			cin >> objective;

			if (textbooks == NULL)
			{
				count = 1;
				textbooks = new Textbook[count--]{ Textbook(title, publisher, year, subject, author, pages, objective) };
			}
			else
			{
				count = Textbook::Get_Textbooks_Count();
				tb_copy = new Textbook[count + 1];
				for (int i = 0; i < count; i++)
				{
					tb_copy[i] = textbooks[i];
				}
				delete[] textbooks;
				textbooks = tb_copy;
				textbooks[count] = Textbook(title, publisher, year, subject, author, pages, objective);
			}

			cout << endl << "�������� " << books[count];
			system("pause");
			break;
		}
		}
	}

	if (magazines)
		delete[] magazines;
	if (books)
		delete[] books;
	if (textbooks)
		delete[] textbooks;
}

void ALL()
{
#if REPORT == false
	cout << "����� ������� 1" << endl;
	General_1();

	system("pause");
	system("cls");

	cout << "����� ������� 2" << endl;
	General_2();
#endif
}

#endif