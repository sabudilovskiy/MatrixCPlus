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
Matrix<T>::Matrix(std::vector<std::vector<T>> arr, int m, int n): arr(arr), m(m), n(n) {
    if (arr.size() != m) throw std::invalid_argument("");
    else {
        for (int i = 0; i < m; i++) if (arr[i].size() != n) throw std::invalid_argument("");
    }
}

template<class T>
Matrix<T>::Matrix() : arr(nullptr), m(0), n(0){}

template<class T>
Matrix<T>& Matrix<T>::clear() {
    arr.clear();
    m = 0;
    n = 0;
    return *this;
}

template<class T>
Matrix<T>::~Matrix() {
    clear();
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &right) const {
    if (m == right.m && n == right.n){
        std::vector<std::vector<Rational>> temp_arr;
        temp_arr.resize(m);
        for (int i = 0; i < m; i++){
            temp_arr[i].resize(n);
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
        std::vector<std::vector<Rational>> temp_arr;
        temp_arr.resize(m);
        for (int i = 0; i < m; i++){
            temp_arr[i].resize(n);
            for (int j = 0; j < n; j++){
                temp_arr[i][j] = arr[i][j] - right.arr[i][j];
            }
        }
        return Matrix<T>(temp_arr, m, n);
    }
    else throw std::invalid_argument("матрицы разной размерности");
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &right) const {
    if (n == right.m){
        int p = right.n;
        std::vector<std::vector<Rational>> temp_arr;
        temp_arr.resize(m);
        for (int i = 0; i < m; i++){
            temp_arr[i].resize(p);
            for (int j = 0; j < p; j++){
                temp_arr[i][j] = arr[i][0] * right.arr[0][j];
                for (int k = 1; k < n; k++){
                    temp_arr[i][j] = temp_arr[i][j] + arr[i][k] * right.arr[k][j];
                }
            }
        }
        return Matrix<T>(temp_arr, n, n);
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

template<class T>
Matrix<T> &Matrix<T>::sum_lines(int to, int from, T cof) {
    for (int i = 0; i < n; i++){
        arr[to][i] = arr[to][i] + arr[from][i]*cof;
    }
    return *this;
}

template<class T>
bool Matrix<T>::is_null_string(int a) {
    if (0 <= a && a < m) {
        T zero(0);
        for (int i = 0; i < n; i++) if (arr[a][i] != zero) return false;
        return true;
    } else throw std::invalid_argument("");
}

template<class T>
Matrix<T> &Matrix<T>::move_string_to_end(int a) {
    if (0 <= a && a < m) {
        for (int i = a; i < m - 1; i++) {
            swap_strings(i, i + 1);
        }
        return *this;
    } else throw std::invalid_argument("");
}

template<class T>
Matrix<T> &Matrix<T>::swap_strings(int a, int b) {
    if (0 <= a && a < m && 0 <= b && b < m) {
        for (int i = 0; i < n; i++) {
            std::swap(arr[a][i], arr[b][i]);
        }
        return *this;
    } else throw std::invalid_argument("");
}

template<class T>
Matrix<T> &Matrix<T>::triangular_transformation() {
    int local_m = m;
    int local_n = n;
    int i = 0;
    T zero(0);
    T minus(-1);
    while (i < local_m - 1 && i < local_n - 1) {
        int f = find_non_zero_in_column(i, i + 1);
        if (arr[i][i] != zero && f != -1)
        {
            for (int j = i + 1; j < m; j++) {
                T k = arr[j][i] / arr[i][i] * minus;
                sum_lines(j, i, k);
            }
        }
        else if (f != -1){
            if (is_null_string(i)) {
                move_string_to_end(i);
                //ѕолучилось, что i строка €вл€етс€ нулевой. —мещаем еЄ вниз.
                i--;
                local_m--;
                local_n--;
            } else {
                swap_strings(i, f);
            }
        }
        i++;
    }
    return *this;
}

template<class T>
int Matrix<T>::find_non_zero_in_column(int column, int start) {
    if (0 <= column && column < n) {
        T zero(0);
        for (int i = start; i < m; i++) {
            if (arr[i][column] != zero) return i;
        }
        return -1;
    } else throw std::invalid_argument("");
}

template<class T>
Matrix<T> &Matrix<T>::gauss_transformation() {
    triangular_transformation();
    int i = 0;
    if (m > n) i = n - 1;
    else i = m - 1;
    T zero(0);
    T one(1);
    T minus(-1);
    while (i > 0) {
        int f = find_non_zero_in_column(i, 0);
        if (arr[i][i] != zero && f != i && f != -1) {
            for (int j = i - 1; j >= 0; j--) {
                T k = arr[j][i] / arr[i][i] * minus;
                sum_lines(j, i, k);
            }
        }
        i--;
    }
    //“еперь и над, и под главной диагональю нули. ќсталось добитьс€ того, чтобы на главной диагонали были только единицы
    for (i = 0; i < m; i++) if (arr[i][i] != zero && arr[i][i] != one) {
        //ƒелим i строку на arr[i][i]
        div_strings(i, arr[i][i]);
    }
    return *this;
}

template<class T>
Matrix<T> &Matrix<T>::div_strings(int a, T k) {
    if (0 <= a && a < m) {
        for (int i = 0; i < n; i++) arr[a][i] = arr[a][i] / k;
        return *this;
    } else throw std::invalid_argument("");
}

template<class T>
bool Matrix<T>::is_single() {
    if (m == n){
        T zero(0);
        T one(1);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++) if (i == j && arr[i][j] != one || i!=j && arr[i][j] != zero) return false;
        }
        return true;
    }
    else return false;

}

