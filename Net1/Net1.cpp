#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(const Fraction& num2) const {
		return numerator_ * num2.denominator_ == num2.numerator_ * denominator_;
	}
	bool operator<(const Fraction& num2) const {
		return numerator_ * num2.denominator_ < num2.numerator_ * denominator_;
	}
	bool operator!=(const Fraction& num2) const {
		return !(*this == num2);
	}

	bool operator>(const Fraction& num2) const {
		return num2 < *this;
	}

	bool operator<=(const Fraction& num2) const {
		return (*this < num2) || (*this == num2);
	}

	bool operator>=(const Fraction& num2) const {
		return (*this > num2) || (*this == num2);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}