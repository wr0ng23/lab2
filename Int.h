#include <iostream>

class Int
{
private:
	int number;
public:
	Int()
	{
		number = 0;
	}

	Int(int a)
	{
		number = a;
	}

	Int(const Int& i1)
	{
		number = i1.number;
	}

	Int operator + (Int& i1) const
	{
		return	Int(number + i1.number);
	}

	Int operator - (Int& i1) const
	{
		return	Int(number - i1.number);
	}

	Int operator * (Int& i1) const
	{
		return	Int(number * i1.number);
	}

	Int operator / (Int& i1) const
	{
		return	Int(number / i1.number);
	}

	operator int() const
	{
		return number;
	}
};