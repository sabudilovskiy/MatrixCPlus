//
// Created by MRV on 21.03.2022.
//

#include "Affine_space.h"
template<class T>
std::string Affine_space<T>::to_string(std::string (*toString)(const T &)) {
    std::string answer = "??????? ????????????: \n v0 = (";
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
Affine_space<T>::Affine_space(Matrix<T> _v0, std::vector<Matrix<T>> arr) :v0(_v0){
    int m = arr[0].get_m();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].get_m() != m || arr[i].get_m() != 1) throw std::invalid_argument("");
    }
    base.resize(arr.size());
    for (int i = 0; i < arr.size(); i++) base[i] = arr[i];
}
