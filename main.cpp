#include <iostream>
#include <Windows.h>
#include "menu.h"
#include "safe_input.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1)
	{
		std::cout << "� ����� ������� �� ������ ��������?(1 - � �����; 2 - � Int)\n";
		int answer = input<int>(); 

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
			pause_and_cls();
		}
	}

	return 0;
}