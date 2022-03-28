//
// Created by MRV on 20.03.2022.
//
#include "Rational.h"
#include "Support.h"
long long int Rational::get_numerator() const {
    return numerator;
}

long long int Rational::get_denominator() const {
    return denominator;
}

bool Rational::operator==(const Rational &rhs) const {
    return numerator == rhs.numerator &&
           denominator == rhs.denominator;
}

bool Rational::operator!=(const Rational &rhs) const {
    return !(rhs == *this);
}

Rational::Rational(long long int numerator, long long int denominator) : numerator(numerator), denominator(denominator){
    if (denominator == 0) throw std::invalid_argument("");
    simplify();
}

Rational::Rational(const Rational &another) : numerator(another.numerator), denominator(another.denominator){
}

Rational::Rational(const Rational &&another) : numerator(another.numerator), denominator(another.denominator){
}

std::string Rational::to_string() const {
    if (denominator != 1) return std::to_string(numerator) + "/" + std::to_string(denominator);
    else return std::to_string(numerator);
}

void Rational::simplify() {
    long long gcd = find_GCD(numerator, denominator);
    if (gcd != 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
    if (denominator < 0){
        numerator*=-1;
        denominator*=-1;
    }
}

Rational Rational::operator+(const Rational &right) const {
    long long new_denominator = find_LCM(denominator, right.denominator);
    long long cof = new_denominator / denominator;
    long long right_cof = new_denominator / right.denominator;
    long long new_numerator = numerator * cof + right.numerator * right_cof;
    Rational temp(new_numerator, new_denominator);
    return temp;
}

Rational Rational::operator-(const Rational &right) const {
    long long new_denominator = find_LCM(denominator, right.denominator);
    long long cof = new_denominator / denominator;
    long long right_cof = new_denominator / right.denominator;
    long long new_numerator = numerator * cof - right.numerator * right_cof;
    Rational temp(new_numerator, new_denominator);
    return temp;
}

Rational Rational::operator*(const Rational &right) const {
    long long leftNumerator = numerator;
    long long leftDenominator = denominator;
    long long rightNumerator = right.numerator;
    long long rightDenominator = right.denominator;
    long long GCD = find_GCD(leftNumerator, rightDenominator);
    if (GCD != 1) {
        leftNumerator /= GCD;
        rightDenominator /= GCD;
    }
    GCD = find_GCD(rightNumerator, leftDenominator);
    if (GCD != 1) {
        leftDenominator /= GCD;
        rightNumerator /= GCD;
    }
    long long newNumerator = leftNumerator * rightNumerator;
    long long newDenominator = leftDenominator * rightDenominator;
    Rational temp(newNumerator, newDenominator);
    temp.simplify();
    return temp;
}

Rational Rational::operator/(const Rational &right) const {
    return *this * Rational(right.denominator, right.numerator);
}

Rational &Rational::operator=(const Rational &right) {
    numerator = right.numerator;
    denominator = right.denominator;
    return *this;
}

Rational &Rational::operator=(const Rational &&right) {
    numerator = right.numerator;
    denominator = right.denominator;
    return *this;
}

std::istream & operator>>(std::istream &in, Rational &rat) {
    std::string buffer;
    in >> buffer;
    int i = 0;
    int sep = 0;
    if (buffer[i] == '-') i++;
    while (i < buffer.size() && is_digit(buffer[i])){
        i++;
    }
    if (i == buffer.size()){
        rat.numerator = std::stoll(buffer);
        rat.denominator = 1;
    }
    else if (buffer[i] == '/' && i != 0){
        rat.numerator = std::stoll(buffer.substr(0, i));
        rat.denominator = std::stoll (buffer.substr(i+1));
    }
    else throw std::invalid_argument("");
    return in;
}

std::ostream &operator<<(std::ostream &out, Rational &rat) {
    out << rat.to_string();
    return out;
}
