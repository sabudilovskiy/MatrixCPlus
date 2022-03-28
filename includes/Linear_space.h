//
// Created by MRV on 21.03.2022.
//

#ifndef MATRIX_LINEAR_SPACE_H
#define MATRIX_LINEAR_SPACE_H
#include "MathObject.h"
template<class T>
class Linear_space : public MathObject<T>{
     std::vector<Matrix<T>> base;
public:
    Linear_space(const std::vector<Matrix<T>>& arr);
    std::string to_string(std::string (*toString)(const T &)) override;
};

#include "Linear_space.tpp"


#endif //MATRIX_LINEAR_SPACE_H
