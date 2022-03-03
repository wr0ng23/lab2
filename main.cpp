#include <iostream>
#include <Windows.h>
#include "deque.h"
#include "Int.h"

void menu_Int();
void menu_deque();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1)
	{
		system("cls");
		std::cout << "� ����� ������� �� ������ ��������?(1 - � �����; 2 - � Int): ";
		int answer; std::cin >> answer;

		switch (answer)
		{
		case 1:
			menu_deque();
			break;
		case 2:
			menu_Int();
			break;
		default:
			system("cls");
			std::cout << "������� �������� �����!" << std::endl;
			system("pause");
		}
	}

	return 0;
}

void menu_deque()
{
	using std::cout;
	using std::cin;
	using std::endl;
	system("cls");
	cout << "������� ������ ����, � ������� ������ ��������: "; 
	int size; cin >> size;
	deque* d1 = new deque(size);
	while (1)
	{
		system("cls");
		cout << "1) �������� �������� ����\n"
			<< "2) �������� ������� � ���\n"
			<< "3) ������� ������� �� ����\n"
			<< "4) �������� ������� ��� � �������������� ����������\n"
			<< "5) ��������� �������� ������� �������� ���� �� 1\n"
			<< "6) ��������� �������� ������� �������� ���� �� 0.5\n"
			<< "7) ����� �� ���������\n";
		int answer;
		cout << "������� ��������: "; cin >> answer;

		try
		{
			switch (answer)
			{
			case 1:
				system("cls");
				d1->display();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				(*d1)++;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				(*d1)--;
				system("pause");
				system("cls");
				break;
			case 4:
			{
				system("cls");
				deque d2 = !(*d1);
				d2.display();
				system("pause");
				system("cls");
				break;
			}
			case 5:
				system("cls");
				--(*d1);
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				++(*d1);
				system("pause");
				system("cls");
				break;
			case 7:
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
			<< "6) ����� �� ���������\n";
		int answer; 
		cout << "������� ��������: "; cin >> answer;

		switch (answer)
		{
		case 1:
			system("cls");
			int number;
			cout << "������� ����� 1: "; cin >> number;
			*Int1 = number;
			cout << "������� ����� 2: "; cin >> number;
			*Int2 = number;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "��������� ��������: " << *Int1 + *Int2 << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "��������� ���������: " << *Int1 - *Int2 << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "��������� ���������: " << *Int1 * (*Int2) << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "��������� �������: " << *Int1 / *Int2 << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "����� �� ���������..." << endl;
			delete Int1;
			delete Int2;
			exit(1);
			break;
		default:
			system("cls");
			cout << "������� �������� �����!" << endl;
			system("pause");
		}
	}
}