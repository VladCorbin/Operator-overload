#include <iostream>
#include <Windows.h>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    void normalize() 
    {
        if (denominator_ == 0) 
        {
            std::cerr << "Ошибка: знаменатель равен нулю!" << std::endl;
            exit(1);
        }
        if (denominator_ < 0) 
        {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        int gcd = findGCD(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }

public:
    Fraction(int numerator = 1, int denominator = 1)
    {
        numerator_ = numerator;
        denominator_ = denominator;

        normalize();
    }

    int findGCD(int a, int b) 
    {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void print()
    {
        std::cout << numerator_ << "/" << denominator_;
    }

    Fraction operator+(const Fraction& right) {
        int newNumerator = numerator_ * right.denominator_ + right.numerator_ * denominator_;
        int newDenominator = denominator_ * right.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    // Вычитание
    Fraction operator-(const Fraction& right) {
        int newNumerator = numerator_ * right.denominator_ - right.numerator_ * denominator_;
        int newDenominator = denominator_ * right.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    // Умножение
    Fraction operator*(const Fraction& right) {
        int newNumerator = numerator_ * right.numerator_;
        int newDenominator = denominator_ * right.denominator_;
        return Fraction(newNumerator, newDenominator);
    }

    // Деление
    Fraction operator/(const Fraction& right) {
        if (right.numerator_ == 0) {
            std::cerr << "Ошибка: деление на ноль!" << std::endl;
            exit(1);
        }
        int newNumerator = numerator_ * right.denominator_;
        int newDenominator = denominator_ * right.numerator_;
        return Fraction(newNumerator, newDenominator);
    }

    // Унарный минус (изменение знака)
    Fraction operator-() {
        return Fraction(-numerator_, denominator_);
    }

    // Префиксный инкремент (++f)
    Fraction& operator++() {
        numerator_ += denominator_;
        normalize();
        return *this;
    }

    // Префиксный декремент (--f)
    Fraction& operator--() {
        numerator_ -= denominator_;
        normalize();
        return *this;
    }
};




int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите числитель дроби 1: ";
    int num1;
    std::cin >> num1;
    std::cout << std::endl;

    std::cout << "Введите знаменатель дроби 1: ";
    int num2;
    std::cin >> num2;
    std::cout << std::endl;

    std::cout << "Введите числитель дроби 2: ";
    int num_1;
    std::cin >> num_1;
    std::cout << std::endl;

    std::cout << "Введите знаменатель дроби 2: ";
    int num_2;
    std::cin >> num_2;
    std::cout << std::endl;


    Fraction f1(num1, num2);
    Fraction f2(num_1, num_2);
    Fraction f3;
    f3 = f1 + f2;

    f1.print();
    std::cout << " + ";
    f2.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    f3 = f1 - f2;
    f1.print();
    std::cout << " - ";
    f2.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    f3 = f1 * f2;
    f1.print();
    std::cout << " * ";
    f2.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    f3 = f1 / f2;
    f1.print();
    std::cout << " / ";
    f2.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    f3 = -f1;
    std::cout << " - ";
    f1.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    f3 = ++f1;
    std::cout << "++";
    f1.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    f3 = --f1;
    std::cout << "--";
    f1.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;
    return 0;
}