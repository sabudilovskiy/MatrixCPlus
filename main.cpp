#include "DEBUG.h"
#ifndef DEBUG
#include "includes/Augmented_matrix.h"
#include <iostream>
#include "includes/Rational.h"
#include "includes/MathObject.h"
int main() {
    setlocale(LC_ALL, "Russian");
    std::string error = "Допущена ошибка при вводе. Повторите ввод: ";
    std::string actions = "Введите действие, которые вы хотите совершить:\n0) закончить работу\n1) сложить матрицы\n2) вычесть матрицы\n3) перемножить матрицы\n4) решить СЛАУ: ";
    int number_action = 1;
    while (number_action!=0){
        number_action = input<int>([](const int& n){return 0 <= n && n <= 4;}, actions, error);
        if (1 <= number_action && number_action <= 3){
            int m1, m2, n1, n2;
            m1 = input<int>([](const int& n){return n >= 1;}, "Введите первую размерность первой матрицы: ", error);
            n1 = input<int>([](const int& n){return n >= 1;}, "Введите вторую размерность первой матрицы: ", error);
            m2 = input<int>([](const int& n){return n >= 1;}, "Введите первую размерность второй матрицы: ", error);
            n2 = input<int>([](const int& n){return n >= 1;}, "Введите вторую размерность второй матрицы: ", error);
            std::vector<std::vector<Rational>> vector_matrix_1, vector_matrix_2;
            std::cout << "Ввод первой матрицы: \n";
            vector_matrix_1.resize(m1);
            vector_matrix_2.resize(m2);
            for (int i = 0; i < m1; i++) {
                vector_matrix_1[i].resize(n1);
                for (int j = 0; j < n1; j++) vector_matrix_1[i][j] = input<Rational>("", error);
            }
            std::cout << "Ввод второй матрицы: \n";
            for (int i = 0; i < m2; i++) {
                vector_matrix_2[i].resize(n2);
                for (int j = 0; j < n2; j++) vector_matrix_2[i][j] = input<Rational>("", error);
            }
            Matrix<Rational> matrix1(vector_matrix_1), matrix2(vector_matrix_2);
            Matrix<Rational> answer;
            try{
                switch (number_action) {
                    case 1:
                    {
                        answer = matrix1 + matrix2;
                    }
                    break;
                    case 2:{
                        answer = matrix1 - matrix2;
                    }
                    break;
                    case 3: {
                        answer = matrix1 * matrix2;
                    }
                    break;
                }
                std::cout << "Ответ:\n";
                std::cout << answer.to_string([](const Rational& rational){
                    return rational.to_string();
                });
            }
            catch (std::invalid_argument){
                std::cout << "Для данной операции матрицы таких размеров не совместимы\n";
            }
        }
        else if (number_action == 4){
            int m = input<int>([](const int& n){return n >= 1;}, "Введите первую размерность основной матрицы: ", error);
            int n = input<int>([](const int& n){return n >= 1;}, "Введите вторую размерность основной матрицы: ", error);
            std::vector<std::vector<Rational>> main, aug;
            main.resize(m);
            aug.resize(m);
            std::cout << "Введите основную матрицу: \n";
            for (int i = 0; i < m; i++) {
                main[i].resize(n);
                for (int j = 0; j < n; j++) main[i][j] = input<Rational>("", error);
            }
            std::cout << "Введите столбец свободных членов: \n";
            for (int i = 0; i < m; i++) {
                aug[i].resize(1);
                aug[i][0] = input<Rational>("", error);
            }
            MathObject<Rational>* answer = Augmented_matrix<Rational> (main, aug).solve_system();
            if (answer == nullptr){
                std::cout << "Нет корней.\n";
            }
            else {
                std::cout << answer->to_string([](const Rational &rat) { return rat.to_string(); });
                delete answer;
            }
        }
    }
}
#endif