#ifndef RATIONAL_H
#define RATIONAL_H
#include "Support.h"
#include <string>
class Rational {
    long long numerator, denominator;
public:
    long long int get_numerator() const;
    long long int get_denominator() const;
    bool operator==(const Rational &rhs) const;
    bool operator!=(const Rational &rhs) const;
    Rational(long long int numerator = 0, long long int denominator = 1);
    Rational(const Rational& another);
    Rational(const Rational&& another);
    std::string to_string() const;
    void simplify();
    Rational operator+(const Rational &right) const;
    Rational operator-(const Rational &right) const;
    Rational operator*(const Rational& right) const;
    Rational operator/(const Rational &right) const;
    Rational& operator=(const Rational& right);
    Rational& operator=(const Rational&& right);
    friend std::istream& operator>>(std::istream& in, Rational& rat);
    friend std::ostream& operator<<(std::ostream& out, Rational& rat);
};
#include "Rational.tpp"

#endif //RATIONAL_H
