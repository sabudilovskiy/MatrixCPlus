//
// Created by MRV on 20.03.2022.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
#include <vector>
template <class T>
class Matrix {
protected:
    std::vector<std::vector<T>> arr;
    int m, n;
public:
    Matrix(Matrix&& another);
    Matrix(const Matrix& another);
    Matrix& operator= (const Matrix& another);
    Matrix& operator= (Matrix&& another);
    Matrix(std::vector<std::vector<T>>& arr);
    Matrix(std::vector<T>& arr);
    Matrix();
    Matrix& clear();
    ~Matrix();
    Matrix<T> operator+(const Matrix<T>& right);
    Matrix<T> operator-(const Matrix<T>& right);
    Matrix<T> operator*(const Matrix<T>& right);
    Matrix<T> operator*(const T& right);
    virtual std::string to_string(std::string (*toString)(const T&)) const;
    virtual Matrix& triangular_transformation();
    virtual Matrix& gauss_transformation();
    bool is_single();
    const std::vector<T>& operator[](int i);
    int get_m() const;
    int get_n() const;

protected:
    virtual Matrix& sum_lines(int to, int from, T cof);
    virtual bool is_null_string(int a);
    virtual Matrix& move_string_to_end(int a);
    virtual Matrix& swap_strings(int a, int b);
    virtual int find_non_zero_in_column(int column, int start);
    virtual Matrix& div_strings(int a, T k);
    virtual Matrix& delete_string(int a);
    Matrix& reduce_null_strings();
};
#include "Matrix.tpp"


#endif //MATRIX_H
