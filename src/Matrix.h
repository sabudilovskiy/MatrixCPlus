//
// Created by MRV on 20.03.2022.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
template <class T>
class Matrix {
    T** arr;
    int m, n;
public:
    Matrix(Matrix&& another);
    Matrix& operator= (Matrix& another);
    Matrix(Matrix& another);
    Matrix(T** arr, int m, int n);
    Matrix();
    void clear();
    ~Matrix();
    Matrix<T> operator+(const Matrix<T>& right) const;
    Matrix<T> operator-(const Matrix<T>& right) const;
    Matrix<T> operator*(const Matrix<T>& right) const;
    std::string to_string(std::string (*toString)(const T)) const;
};
#include "Matrix.tpp"


#endif //MATRIX_H
