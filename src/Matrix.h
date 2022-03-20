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
    Matrix(Matrix&& another) : arr(another.arr), m(another.m), n(another.n)
    {
        another.arr = nullptr;
        another.m = 0;
        another.n = 0;
    }
    Matrix& operator= (Matrix& another) {
        clear();
        m = another.m;
        n = another.n;
        arr = new T*[m];
        for (int i = 0; i < m; i++){
            arr[i] = new T[n];
            for (int j = 0; j < n; j++){
                arr[i][j] = another.arr[i][j];
            }
        }
    }
    Matrix(Matrix& another): m(m), n(n){
        this->arr = new T*[m];
        for (int i = 0; i < m; i++){
            this->arr[i] = new T[n];
            for (int j = 0; j < n; j++){
                this->arr[i][j] = another.arr[i][j];
            }
        }
    }
    Matrix(T** arr, int m, int n): arr(arr), m(m), n(n) {
    }
    Matrix() : arr(nullptr), m(0), n(0){}
    void clear(){
        for (int i = 0; i < m; i++) delete[] arr[i];
        delete[] arr;
        arr = nullptr;
        m = 0;
        n = 0;
    }
    ~Matrix(){
        clear();
    }
    Matrix<T> operator+(const Matrix<T>& right) const{
        if (m == right.m && n == right.n){
            T** temp_arr = new T*[m];
            for (int i = 0; i < m; i++){
                temp_arr[i] = new T[n];
                for (int j = 0; j < n; j++){
                    temp_arr[i][j] = arr[i][j] + right.arr[i][j];
                }
            }
            return Matrix(temp_arr, m, n);
        }
        else throw std::invalid_argument("матрицы разной размерности");
    }
    Matrix<T> operator-(const Matrix<T>& right) const{
        if (m == right.m && n == right.n){
            T** temp_arr = new T*[m];
            for (int i = 0; i < m; i++){
                temp_arr[i] = new T[n];
                for (int j = 0; j < n; j++){
                    temp_arr[i][j] = arr[i][j] - right.arr[i][j];
                }
            }
            return Matrix(temp_arr, m, n);
        }
        else throw std::invalid_argument("матрицы разной размерности");
    }
    Matrix<T> operator*(const Matrix<T>& right) const{
        if (m == right.m && n == right.n){
            T** temp_arr = new T*[m];
            for (int i = 0; i < m; i++){
                temp_arr[i] = new T[n];
                for (int j = 0; j < n; j++){
                    temp_arr[i][j] = arr[i][j] * right.arr[i][j];
                }
            }
            return Matrix(temp_arr, m, n);
        }
        else throw std::invalid_argument("матрицы разной размерности");
    }
    std::string to_string(std::string (*toString)(const T)) const{
        std::string temp;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) temp+= toString(arr[i][j]) + " ";
            temp+='\n';
        }
        return temp;
    }
};

#endif //MATRIX_H
