//
// Created by MRV on 20.03.2022.
//

#ifndef MATRIX_SUPPORT_H
#define MATRIX_SUPPORT_H
#include <cmath>
#include <string>
#include <iostream>
long long find_GCD(long long temp_a, long long temp_b);
long long find_LCM(long long temp_a, long long temp_b);
bool is_digit (char ch);
template<class T>
T input(bool (*verifer)(const T &), const std::string& input, const std::string& _error);
template<class T>
T input(const std::string& input, const std::string& _error);
#include "Support.tpp"
#endif
