//
// Created by MRV on 21.03.2022.
//

#ifndef MATRIX_AUGMENTED_MATRIX_H
#define MATRIX_AUGMENTED_MATRIX_H
#include "Matrix.h"
#include "MathObject.h"
template<class T>
class Augmented_matrix : public Matrix<T>{
    std::vector<std::vector<T>> augmented_arr;
    int augmented_n = 0;
public:
    Augmented_matrix(std::vector<std::vector<T>>& left, std::vector<std::vector<T>>& right);
    MathObject<T>* solve_system();
    bool is_homogeneous();
    std::string to_string(std::string (*toString)(const T &)) const override;
protected:
    Matrix<T>& sum_lines(int to, int from, T cof) override;
    bool is_null_string(int a) override;
    Matrix<T>& swap_strings(int a, int b) override;
    Matrix<T>& div_strings(int a, T k) override;
    Matrix<T>& delete_string(int a) override;
    Matrix<T>& reset_augmented();
    Matrix<T> substitution(std::vector<T> array);
};




#include "Augmented_matrix.tpp"
#endif //MATRIX_AUGMENTED_MATRIX_H
