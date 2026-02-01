#include <iostream>

class Fraction {
private:
    int num;
    int den;

public:
    Fraction(int n, int d) : num(n), den(d) {}

    Fraction operator+(const Fraction& b) const {
        return Fraction(num * b.den + b.num * den, den * b.den);
    }

    Fraction operator-(const Fraction& b) const {
        return Fraction(num * b.den - b.num * den, den * b.den);
    }

    Fraction operator*(const Fraction& b) const {
        return Fraction(num * b.num, den * b.den);
    }

    Fraction operator/(const Fraction& b) const {
        return Fraction(num * b.den, den * b.num);
    }

    Fraction operator-() const {
        return Fraction(-num, den);
    }

    Fraction& operator++() { 
        num += den;
        return *this;
    }

    Fraction operator++(int) { 
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() {
        num -= den;
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.num << '/' << f.den;
        return os;
    }
};

int main() {
    int n1, d1, n2, d2;
    
    setlocale(LC_ALL, "Rus");
    std::cout << "¬ведите числитель дроби 1: "; std::cin >> n1;
    std::cout << "¬ведите знаменатель дроби 1: "; std::cin >> d1;
    std::cout << "¬ведите числитель дроби 2: "; std::cin >> n2;
    std::cout << "¬ведите знаменатель дроби 2: "; std::cin >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << '\n';
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << '\n';

    Fraction orig = f1;
    ++f1;
    std::cout << "++" << orig << " * " << f2 << " = " << f1 * f2 << '\n';
    std::cout << "«начение дроби 1 = " << f1 << '\n';
    
    Fraction result = f1-- * f2;
    std::cout << f1 << "-- * " << f2 << " = " << result << '\n';
    std::cout << "«начение дроби 1 = " << f1 << '\n';

    return 0;
}