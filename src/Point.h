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
    Point(const std::vector<T> &cords);
    std::string to_string(std::string (*toString)(const T &)) override;
};



#include "Point.tpp"

#endif //MATRIX_POINT_H
