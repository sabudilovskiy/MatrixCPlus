//
// Created by MRV on 21.03.2022.
//

#include "../includes/Point.h"
template<class T>
std::string Point<T>::to_string(std::string (*toString)(const T &)) {
    std::string temp = "(";
    for (int i = 0; i < cords.size() - 1; i++){
        temp+=toString(cords[i]) + ";";
    }
    temp+=toString(cords[cords.size() - 1]);
    temp += ")";
    return temp;
}

template<class T>
Point<T>::Point(const std::vector<T> &cords):cords(cords), n(cords.size()){}
