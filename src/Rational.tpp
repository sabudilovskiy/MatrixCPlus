//
// Created by MRV on 20.03.2022.
//
#include "Rational.h"
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
    long long domnozh = new_denominator / denominator;
    long long new_numerator = numerator * domnozh;
    new_numerator += right.numerator * (new_denominator / right.denominator);
    Rational temp(new_numerator, new_denominator);
    temp.simplify();
    return temp;
}

Rational Rational::operator-(const Rational &right) const {
    long long new_denominator = find_LCM(denominator, right.denominator);
    long long domnozh = new_denominator / denominator;
    long long new_numerator = numerator * domnozh;
    new_numerator -= right.numerator * (new_denominator / right.denominator);
    Rational temp(new_numerator, new_denominator);
    temp.simplify();
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