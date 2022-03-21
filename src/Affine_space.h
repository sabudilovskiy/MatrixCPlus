//
// Created by MRV on 21.03.2022.
//

#ifndef MATRIX_AFFINE_SPACE_H
#define MATRIX_AFFINE_SPACE_H

#include "MathObject.h"
#include "Matrix.h"
template<class T>
class Affine_space : public MathObject<T>{
    Matrix<T> v0;
    std::vector<Matrix<T>> base;
public:
    Affine_space(Matrix<T> _v0 , std::vector<Matrix<T>> arr);
     std::string to_string(std::string (*toString)(const T));
};


#include "Affine_space.tpp"
#endif //MATRIX_AFFINE_SPACE_H
