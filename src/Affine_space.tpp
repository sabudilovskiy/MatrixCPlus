//
// Created by MRV on 21.03.2022.
//

#include "Affine_space.h"
template<class T>
std::string Affine_space<T>::to_string(std::string (*toString)(const T)) {
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
