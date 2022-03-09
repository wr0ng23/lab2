#include <process.h>
#include <iostream>
#include "deque.h"
#include "Int.h"
#include "safe_input.h"

void pause_and_cls()
{
	system("pause");
	system("cls");
}

void menu_deque()
{
	using std::cout;
	using std::cin;
	using std::endl;
	system("cls");
	cout << "������� ������ ����, � ������� ������ ��������\n";
	int size = input<int>();
	deque* d1 = new deque(size);
	while (1)
	{
		system("cls");
		std::cout << "1) �������� �������� ����\n"
			<< "2) �������� ������� � ���\n"
			<< "3) ������� ������� �� ����\n"
			<< "4) �������� ������� ��� � �������������� ����������\n"
			<< "5) ��������� �������� ������� �������� ���� �� 1\n"
			<< "6) ��������� �������� ������� �������� ���� �� 0.5\n"
			<< "7) �������� ������ ����\n"
			<< "8) ����� �� ���������\n";
		int answer = input<int>();
		try
		{
			switch (answer)
			{
			case 1:
				system("cls");
				d1->display();
				pause_and_cls();
				break;
			case 2:
				system("cls");
				(*d1)++;
				pause_and_cls();
				break;
			case 3:
				system("cls");
				(*d1)--;
				pause_and_cls();
				break;
			case 4:
			{
				system("cls");
				deque d2 = !(*d1);
				d2.display();
				pause_and_cls();
				break;
			}
			case 5:
				system("cls");
				--(*d1);
				pause_and_cls();
				break;
			case 6:
				system("cls");
				++(*d1);
				pause_and_cls();
				break;
			case 7:
				system("cls");
				d1->display_size_of_deque();
				pause_and_cls();
				break;
			case 8:
				system("cls");
				cout << "����� �� ���������..." << endl;
				delete d1;
				exit(1);
				break;
			default:
				system("cls");
				cout << "������� �������� �����!" << endl;
				system("pause");
			}
		}
		catch (std::string& ex)
		{
			std::cout << ex << std::endl;
			system("pause");
		}
	}
}

void menu_Int()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Int* Int1 = new Int;
	Int* Int2 = new Int;
	while (1)
	{
		system("cls");
		cout << "1) ������ ��� ����� ������ Int\n"
			<< "2) ������� ��� ����� ����� ������ Int\n"
			<< "3) ������� ��� ����� ����� ������ Int\n"
			<< "4) �������� ��� ����� ����� ������ Int\n"
			<< "5) ��������� ��� ����� ����� ������ Int\n"
			<< "6) �������� ������� �����\n"
			<< "7) ����� �� ���������\n";
		int answer = input<int>();

		switch (answer)
		{
		case 1:
		{
			system("cls");
			cout << "������� ����� 1\n";
			int number = input<int>();
			*Int1 = number;
			cout << "������� ����� 2\n"; number = input<int>();
			*Int2 = number; cout << endl;
			pause_and_cls();
			break;
		}
		case 2:
			system("cls");
			cout << "��������� ��������: " << *Int1 + *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 3:
			system("cls");
			cout << "��������� ���������: " << *Int1 - *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 4:
			system("cls");
			cout << "��������� ���������: " << *Int1 * (*Int2) << endl << endl;
			pause_and_cls();
			break;
		case 5:
			system("cls");
			cout << "��������� �������: " << *Int1 / *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 6:
			system("cls");
			cout << "����� 1: " << *Int1 << endl;
			cout << "�����2 2: " << *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 7:
			system("cls");
			cout << "����� �� ���������...\n";
			delete Int1;
			delete Int2;
			exit(1);
			break;
		default:
			system("cls");
			cout << "������� �������� �����!\n";
			system("pause");
		}
	}
}