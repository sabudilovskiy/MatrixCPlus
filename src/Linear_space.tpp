//
// Created by MRV on 21.03.2022.
//

#include "Linear_space.h"
template<class T>
Linear_space<T>::Linear_space(std::vector<Matrix<T>> arr) {
    int m = arr[0].get_m();
    for (Matrix<T> vector : arr) {
        if (vector.get_m() != m || vector.get_m() != 1) throw std::invalid_argument("");
    }
    base = arr;
}

template<class T>
std::string Linear_space<T>::to_string(std::string (*toString)(const T)) {
    std::string answer = "Линейное пространство: \n";
    int i = 1;
    for (Matrix<T>& vector : base) {
        std::string temp = vector.to_string(toString);
        answer += "v" + std::to_string(i) + " = (" + temp.substr(0, temp.length() - 2) + ")\n";
        i++;
    }
    return answer;
}
