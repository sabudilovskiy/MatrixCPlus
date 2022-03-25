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
    std::string to_string(std::string (*toString)(const T &)) const override;
    MathObject<T>* solve_system();
    bool is_homogeneous();
protected:
    virtual Matrix<T>& sum_lines(int to, int from, T cof);
    virtual bool is_null_string(int a);
    virtual Matrix<T>& swap_strings(int a, int b);
    virtual Matrix<T>& div_strings(int a, T k);
    Matrix<T>& reset_augmented();
    Matrix<T>& delete_string(int a) override;
    Matrix<T> substitution(std::vector<T> array);
};




#include "Augmented_matrix.tpp"
#endif //MATRIX_AUGMENTED_MATRIX_H
