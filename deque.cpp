#include <iostream>
#include "deque.h"
#include "safe_input.h"

deque::deque(int size_mass = 10)
{
	size = size_mass;
	mass = new float[size] {};
	head = size / 2;
	tail = size / 2;
}

deque::deque(const deque& d1)
{
	size = d1.size;
	mass = new float[size];
	head = d1.head;
	tail = d1.tail;
	for (size_t i = 0; i < size; i++)
	{
		mass[i] = d1.mass[i];
	}
}

deque::~deque()
{
	delete[] mass;
}

bool deque::empty() const
{
	return (head == tail) ? true : false;
}

void deque::display() const
{
	if (empty())
		throw std::string("Дэк пуст!\n");
	std::cout << "Значения дэка: " << std::endl;
	for (int i = 0; i < tail; i++)
	{
		if(mass[i] != 0)
			std::cout << mass[i] << std::endl;
	}
	std::cout << std::endl;
}

void deque::display_size_of_deque() const
{
	std::cout << "Размер дэки: " << size << std::endl << std::endl;
}

void deque::push_back(float var)
{
	if (tail < size)
	{
		mass[tail++] = var;
		std::cout << "\nЧисло " << var << " было добавлено в конец дэка.\n\n";
	}
	else
		throw std::string("\nВ конце дэка нет свободного места!");
}

float deque::pop_back()
{
	float temp = mass[--tail];
	mass[tail] = 0;
	return temp;
}

void deque::push_front(float var)
{
	if (head - 1 >= 0)
	{
		mass[--head] = var;
		std::cout << "\nЧисло " << var << " было добавлено в начало дэка.\n\n";
	}
	else
		throw std::string("\nВ начале дэка нет свободного места!");
}

float deque::pop_front()
{
	float temp = mass[head];
	mass[head++] = 0;
	return temp;
}

deque& deque::operator=(const deque& d1)
{
	if (this == &d1)
		return *this;
	delete[] mass;
	size = d1.size;
	mass = new float[size];
	head = d1.head;
	tail = d1.tail;
	for (size_t i = 0; i < size; i++)
	{
		mass[i] = d1.mass[i];
	}
	return *this;
}

deque deque::operator !() const
{
	deque d1 = *this;
	for (size_t i = 0; i < size; i++)
	{
		if (d1.mass[i] > 0)
			d1.mass[i] = -(d1.mass[i]);
	}
	return d1;
}

deque& deque::operator ++()
{
	if (empty())
		throw std::string("Дэк пуст!\n");
	for (int i = 0; i < size; i++)
	{
		if (mass[i] != 0)
			mass[i] += 0.5;
	}
	std::cout << "Все значения дэки были увеличены на 0.5\n\n";
	return *this;
}

deque& deque::operator --()
{
	if (empty())
		throw std::string("Дэк пуст!\n");
	for (size_t i = 0; i < size; i++)
	{
		if(mass[i] != 0)
			mass[i]--;
	}
	std::cout << "Все значения дэки были уменьшены на единицу\n\n";
	return *this;
}

deque& operator++(deque& d1, int)
{
	std::cout << "Введите добавляемое число\n";
	float var = input<float>();
	system("cls");
	std::cout << "Введите куда нужно добавить число(1 - В начало дэка; 2 - В конец дэка)\n";
	int choice = input<int>();
	switch (choice)
	{
	case 1:
		d1.push_front(var);
		break;
	case 2:
		d1.push_back(var);
		break;
	default:
		std::cout << "\nНекорректная цифра!\n" << std::endl;
	}
	return d1;
}

deque& operator--(deque& d1, int)
{
	if (d1.empty())
		throw std::string("Дэк пуст!\n");
	std::cout << "Введите откуда нужно извлечь число(1 - Из начала дэка; 2 - Из конца дэка)\n";
	int choice = input<int>();
	switch (choice)
	{
	case 1:
		std::cout << "\nИзвлеченное из начала дэка число: " << d1.pop_front() 
			<< std::endl << std::endl;
		break;
	case 2:
		std::cout << "\nИзвлеченное из конца дэка число: " << d1.pop_back() 
			<< std::endl << std::endl;
		break;
	default:
		std::cout << "\nНекорректная цифра!\n" << std::endl;
	}
	return d1;
}