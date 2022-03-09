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
	cout << "Введите размер дэки, с которой хотите работать\n";
	int size = input<int>();
	deque* d1 = new deque(size);
	while (1)
	{
		system("cls");
		std::cout << "1) Показать элементы дэка\n"
			<< "2) Добавить элемент в дэк\n"
			<< "3) Извлечь элемент из дэка\n"
			<< "4) Получить текущий дэк с отрицательными значениями\n"
			<< "5) Уменьшить значения каждого элемента дэка на 1\n"
			<< "6) Увеличить значения каждого элемента дэка на 0.5\n"
			<< "7) Показать размер дэки\n"
			<< "8) Выход из программы\n";
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
				cout << "Выход из программы..." << endl;
				delete d1;
				exit(1);
				break;
			default:
				system("cls");
				cout << "Введена неверная цифра!" << endl;
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
		cout << "1) Задать два числа класса Int\n"
			<< "2) Сложить два целых числа класса Int\n"
			<< "3) Вычесть два целых числа класса Int\n"
			<< "4) Умножить два целых числа класса Int\n"
			<< "5) Разделить два целых числа класса Int\n"
			<< "6) Показать текущие числа\n"
			<< "7) Выход из программы\n";
		int answer = input<int>();

		switch (answer)
		{
		case 1:
		{
			system("cls");
			cout << "Введите число 1\n";
			int number = input<int>();
			*Int1 = number;
			cout << "Введите число 2\n"; number = input<int>();
			*Int2 = number; cout << endl;
			pause_and_cls();
			break;
		}
		case 2:
			system("cls");
			cout << "Результат сложения: " << *Int1 + *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 3:
			system("cls");
			cout << "Результат вычитания: " << *Int1 - *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 4:
			system("cls");
			cout << "Результат умножения: " << *Int1 * (*Int2) << endl << endl;
			pause_and_cls();
			break;
		case 5:
			system("cls");
			cout << "Результат деления: " << *Int1 / *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 6:
			system("cls");
			cout << "Число 1: " << *Int1 << endl;
			cout << "Число2 2: " << *Int2 << endl << endl;
			pause_and_cls();
			break;
		case 7:
			system("cls");
			cout << "Выход из программы...\n";
			delete Int1;
			delete Int2;
			exit(1);
			break;
		default:
			system("cls");
			cout << "Введена неверная цифра!\n";
			system("pause");
		}
	}
}