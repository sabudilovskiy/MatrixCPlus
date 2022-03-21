//
// Created by MRV on 21.03.2022.
//

#ifndef MATRIX_POINT_H
#define MATRIX_POINT_H
#include "MathObject.h"
template <class T>
class Point : public MathObject<T>{
    std::vector<T> cords;
    int n = 0;
public:
    std::string to_string(std::string (*toString)(const T)) override;
};

template<class T>
std::string Point<T>::to_string(std::string (*toString)(const T)) {
    std::string temp = "(";
    for (int i = 0; i < cords.size() - 1; i++){
        temp+=toString(cords[i]) + ";";
    }
    temp += ")";
    return temp;
}

#include "Point.tpp"

#endif //MATRIX_POINT_H
