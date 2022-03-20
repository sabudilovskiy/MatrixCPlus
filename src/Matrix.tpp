//
// Created by MRV on 20.03.2022.
//
#include "Matrix.h"
template<class T>
Matrix<T>::Matrix(Matrix &&another) : arr(another.arr), m(another.m), n(another.n)
{
    another.arr = nullptr;
    another.m = 0;
    another.n = 0;
}

template<class T>
Matrix<T> &Matrix<T>::operator=(Matrix &another) {
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

template<class T>
Matrix<T>::Matrix(Matrix &another): m(m), n(n){
    this->arr = new T*[m];
    for (int i = 0; i < m; i++){
        this->arr[i] = new T[n];
        for (int j = 0; j < n; j++){
            this->arr[i][j] = another.arr[i][j];
        }
    }
}

template<class T>
Matrix<T>::Matrix(T **arr, int m, int n): arr(arr), m(m), n(n) {
}

template<class T>
Matrix<T>::Matrix() : arr(nullptr), m(0), n(0){}

template<class T>
void Matrix<T>::clear() {
    for (int i = 0; i < m; i++) delete[] arr[i];
    delete[] arr;
    arr = nullptr;
    m = 0;
    n = 0;
}

template<class T>
Matrix<T>::~Matrix() {
    clear();
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &right) const {
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

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &right) const {
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

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &right) const {
    if (n == right.m){
        int p = right.n;
        T** temp_arr = new T*[m];
        for (int i = 0; i < m; i++){
            temp_arr[i] = new T[p];
            for (int j = 0; j < p; j++){
                temp_arr[i][j] = arr[i][0] * right.arr[0][j];
                for (int k = 1; k < n; k++){
                    temp_arr[i][j] = temp_arr[i][j] + arr[i][k] * right.arr[k][j];
                }
            }
        }
        return Matrix(temp_arr, n, n);
    }
    else throw std::invalid_argument("матрицы разной размерности");
}

template<class T>
std::string Matrix<T>::to_string(std::string (*toString)(const T)) const {
    std::string temp;
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) temp+= toString(arr[i][j]) + " ";
        temp+='\n';
    }
    return temp;
}

