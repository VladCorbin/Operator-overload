#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator = 1, int denominator = 1)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    void print()
    {
        std::cout << numerator_ << "/" << denominator_;
    }

    Fraction operator+(Fraction right)
    {
        int nNumerator_ = numerator_ + right.numerator_;
        int nDenominator_ = denominator_ + right.denominator_;
        return Fraction(nNumerator_, nDenominator_);
    }

    Fraction operator--()
    {
        int nNumerator_ = numerator_ - 1;
        int nDenominator_ = denominator_ - 1;
        return Fraction(nNumerator_, nDenominator_);
    }

    Fraction operator++()
    {
        int nNumerator_ = numerator_ + 1;
        int nDenominator_ = denominator_ + 1;
        return Fraction(nNumerator_, nDenominator_);
    }

    Fraction operator-() 
    {
        int nNumerator_ = numerator_ - numerator_;
        int nDenominator_ = denominator_ - denominator_;
        return Fraction(nNumerator_, nDenominator_);
    }

    Fraction operator-(Fraction right)
    {
        int nNumerator_ = numerator_ - right.numerator_;
        int nDenominator_ = denominator_ - right.denominator_;
        return Fraction(nNumerator_, nDenominator_);
    }

    Fraction operator*(Fraction right)
    {
        int nNumerator_ = numerator_ * right.numerator_;
        int nDenominator_ = denominator_ * right.denominator_;
        return Fraction(nNumerator_, nDenominator_);
    }

    Fraction operator/(Fraction right)
    {
        int nNumerator_ = numerator_ / right.numerator_;
        int nDenominator_ = denominator_ / right.denominator_;
        return Fraction(nNumerator_, nDenominator_);
    }
};




int main()
{
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
    f1.print();
    std::cout << " - ";
    f2.print();
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