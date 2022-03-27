#include "../includes/Augmented_matrix.h"
#include "../includes/Affine_space.h"
#include "../includes/Linear_space.h"
#include "../includes/Point.h"

template<class T>
Augmented_matrix<T>::Augmented_matrix(std::vector<std::vector<T>>& left, std::vector<std::vector<T>>& right) :  Matrix<T>(left), augmented_arr(right){
    if (right.size() != left.size()) throw std::invalid_argument("");
    augmented_n = augmented_arr[0].size();
    for (int i = 1; i < this->m; i++){
        if (augmented_arr[i].size() != augmented_n) throw std::invalid_argument("");
    }
}

template<class T>
std::string Augmented_matrix<T>::to_string(std::string (*toString)(const T &)) const {
    std::string temp;
    for (int i = 0; i < this->m; i++) {
        for(int j = 0; j < this->n; j++) temp+= toString(this->arr[i][j]) + " ";
        temp[temp.length() - 1] = '|';
        for (int j = 0; j < augmented_n; j++) temp+= toString(augmented_arr[i][j]) + " ";
        temp+='\n';
    }
    return temp;
}

template<class T>
Matrix<T> &Augmented_matrix<T>::sum_lines(int to, int from, T cof) {
    Matrix<T>::sum_lines(to, from, cof);
    for (int i = 0; i < augmented_n; i++) augmented_arr[to][i] = augmented_arr[to][i] + augmented_arr[from][i] * cof;
    return *this;
}

template<class T>
bool Augmented_matrix<T>::is_null_string(int a) {
    T zero(0);
    for (int i = 0; i < augmented_n; i++){
        if (augmented_arr[a][i] != zero){
            return false;
        }
    }
    return Matrix<T>::is_null_string(a);
}

template<class T>
Matrix<T> &Augmented_matrix<T>::swap_strings(int a, int b) {
    for (int i = 0; i < augmented_n; i++) {
        std::swap(augmented_arr[a][i], augmented_arr[b][i]);
    }
    return Matrix<T>::swap_strings(a, b);
}

template<class T>
Matrix<T> &Augmented_matrix<T>::div_strings(int a, T k) {
    for (int i = 0; i < this->augmented_n; i++)  augmented_arr[a][i] = augmented_arr[a][i] / k;
    return Matrix<T>::div_strings(a, k);
}

template<class T>
MathObject<T> *Augmented_matrix<T>::solve_system() {
    if (augmented_n == 1) {
        Augmented_matrix<T> copy(this->arr, augmented_arr);
        copy.gauss_transformation();
        copy.reduce_null_strings();
        if (copy.m == copy.n) {
            T one = T(1);
            std::vector<T> answer;
            answer.resize(copy.n);
            for (int i = 0;  i < copy.n; i++)
                if (copy.arr[i][i] == one)
                    answer[i] = copy.augmented_arr[i][0];
                else return nullptr;
            return new Point<T>(answer);
        }
        else if (copy.m < copy.n){
            std::vector<Matrix<T>> base;
            T one(1);
            T zero(0);
            base.resize(copy.n - copy.m);
            if (is_homogeneous()){
                // Так как СЛАУ является однородной и прямоугольной, то она задаёт линейное подпространство(оболочку). Найдём базис.
                for (int i = 0; i < base.size(); i++){
                    std::vector<T> cords_vector;
                    cords_vector.resize(base.size(), zero);
                    cords_vector[i] = one;
                    for (int j = 0; j < copy.m; j++){
                        base[i] = copy.substitution(cords_vector);
                    }
                }
                return new Linear_space<T>(base);
            }
            else{
                //Так как СЛАУ является неоднородной и прямоугольной, то она задаёт линейное многообразие. Найдём базис.
                //Найдём частное решение
                T zero(0);
                std::vector<T> cords_vector;
                cords_vector.resize(copy.n - copy.m, zero);
                //Это вектор, на который перенесёно линейное подпространство
                auto v = copy.substitution(cords_vector);
                //Найдём базис соответствующего пространства. Для этого обнулим столбец свободных членов.
                copy.reset_augmented();
                for (int i = 0; i < base.size(); i++){
                    cords_vector.resize(base.size(), zero);
                    cords_vector[i] = one;
                    for (int j = 0; j < copy.m; j++){
                        base[i] = copy.substitution(cords_vector);
                    }
                }
                return new Affine_space<T>(v, base);
            }
        }
        else return nullptr;
    }
    else throw std::invalid_argument("");
}

template<class T>
bool Augmented_matrix<T>::is_homogeneous() {
    T zero(0);
    if (augmented_n > 1) return false;
    for (int i = 0; i < this->m; i++) if (augmented_arr[i][0] != zero) return false;
    return true;
}

template<class T>
Matrix<T> Augmented_matrix<T>::substitution(std::vector<T> array) {
    if (this->n - this->m == array.size() && augmented_n == 1) {
        if (this->is_single()) {
            T zero(0);
            T minus(-1);
            std::vector<T> cof;
            cof.resize(this->n, zero);
            for (int i = this->m; i < this->n; i++) cof[i] = array[i - this->m];
            for (int i = 0; i < this->m; i++) {
                for (int j =  this->m; j < this->n; j++) {
                    //если и коэффициент в матрице ненулевой и подставляется не ноль у соответствующей переменной
                    if (this->arr[i][j] != zero && cof[j]!= zero) {
                        cof[i] = cof[i] + this->arr[i][j] * cof[j] * minus;
                    }
                }
                if (augmented_arr[i][0]!=zero) {
                    cof[i] = cof[i] + augmented_arr[i][0];
                }
            }
            Matrix<T> answer(cof);
            return answer;
        } else throw  std::invalid_argument("");
    } else throw std::invalid_argument("");
}

template<class T>
Matrix<T> &Augmented_matrix<T>::reset_augmented() {
    for (int i = 0; i < this->m; i++) for (int j = 0; j < augmented_n; j++) augmented_arr[i][j] = 0;
    return *this;
}

template<class T>
Matrix<T> &Augmented_matrix<T>::delete_string(int a) {
    augmented_arr.erase(augmented_arr.begin() + a);
    return Matrix<T>::delete_string(a);
}
