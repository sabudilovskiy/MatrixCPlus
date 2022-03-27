//
// Created by MRV on 21.03.2022.
//

#include "../includes/Affine_space.h"
template<class T>
std::string Affine_space<T>::to_string(std::string (*toString)(const T &)) {
    std::string answer = "Афинное пространство: \n v0 = (";
    std::string temp = v0.to_string(toString);
    answer += temp.substr(0, temp.length() - 2) + ")\n";
    int i = 1;
    for (Matrix<T>& vector : base) {
        temp = vector.to_string(toString);
        answer += "v" + std::to_string(i) + " = (" + temp.substr(0, temp.length() - 2) + ")\n";
        i++;
    }
    return answer;
}

template<class T>
Affine_space<T>::Affine_space(Matrix<T> _v0, std::vector<Matrix<T>> arr) :v0(_v0), base(arr) {
    int m = arr[0].get_m();
    for (Matrix<T> vector : arr) {
        //матрица - это вектор. Если там записано больше одной строки необходимо вернуть ошибку
        if (vector.get_m() != m || vector.get_m() != 1) throw std::invalid_argument("");
    }
}
