//
// Created by MRV on 20.03.2022.
//
#include "Support.h"
long long find_GCD(long long int temp_a, long long int temp_b) {
    temp_a = abs(temp_a);
    temp_b = abs(temp_b);
    while (temp_a != 0 && temp_b != 0)
        if (temp_a > temp_b) temp_a %= temp_b;
        else temp_b %= temp_a;
    return temp_a + temp_b;
}

long long find_LCM(long long int temp_a, long long int temp_b) {
    return temp_a*temp_b/ find_GCD(temp_a, temp_b);
}

bool is_digit(char ch) {
    return '0' <= ch && ch <= '9';
}


template<class T>
T input(bool (*verifer)(const T &), const std::string &input, const std::string &_error) {
    T temp;
    std::cout << input;
    try {
        std::cin >> temp;
        if (verifer(temp)) return temp;
        else throw std::exception("");
    }
    catch (std::exception) {
        while (true) {
            std::cout << _error;
            try {
                std::cin >> temp;
                if (verifer(temp)) return temp;
                else throw std::exception("");
            }
            catch (std::exception) {
            }
        }
    }
}

template<class T>
T input(const std::string &input, const std::string &_error) {
    T temp;
    std::cout << input;
    try {
        std::cin >> temp;
        return temp;
    }
    catch (std::exception) {
        while (true) {
            std::cout << _error;
            try {
                std::cin >> temp;
                return temp;
            }
            catch (std::exception) {
            }
        }
    }
}
