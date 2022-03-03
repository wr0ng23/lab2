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
		std::cout << "С каким классом вы хотите работать?(1 - С дэком; 2 - С Int): ";
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
			std::cout << "Введена неверная цифра!" << std::endl;
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
	cout << "Введите размер дэки, с которой хотите работать: "; 
	int size; cin >> size;
	deque* d1 = new deque(size);
	while (1)
	{
		system("cls");
		cout << "1) Показать элементы дэка\n"
			<< "2) Добавить элемент в дэк\n"
			<< "3) Извлечь элемент из дэка\n"
			<< "4) Получить текущий дэк с отрицательными значениями\n"
			<< "5) Уменьшить значения каждого элемента дэка на 1\n"
			<< "6) Увеличить значения каждого элемента дэка на 0.5\n"
			<< "7) Выход из программы\n";
		int answer;
		cout << "Введите действие: "; cin >> answer;

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
			<< "6) Выход из программы\n";
		int answer; 
		cout << "Введите действие: "; cin >> answer;

		switch (answer)
		{
		case 1:
			system("cls");
			int number;
			cout << "Введите число 1: "; cin >> number;
			*Int1 = number;
			cout << "Введите число 2: "; cin >> number;
			*Int2 = number;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Результат сложения: " << *Int1 + *Int2 << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "Результат вычитания: " << *Int1 - *Int2 << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Результат умножения: " << *Int1 * (*Int2) << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			cout << "Результат деления: " << *Int1 / *Int2 << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "Выход из программы..." << endl;
			delete Int1;
			delete Int2;
			exit(1);
			break;
		default:
			system("cls");
			cout << "Введена неверная цифра!" << endl;
			system("pause");
		}
	}
}