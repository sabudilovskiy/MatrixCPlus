//
// Created by MRV on 20.03.2022.
//

#ifndef MATRIX_SUPPORT_H
#define MATRIX_SUPPORT_H
#include <cmath>
long long find_GCD(long long temp_a, long long temp_b){
    temp_a = abs(temp_a);
    temp_b = abs(temp_b);
    while (temp_a != 0 && temp_b != 0)
        if (temp_a > temp_b) temp_a %= temp_b;
        else temp_b %= temp_a;
    return temp_a + temp_b;
};
long long find_LCM(long long temp_a, long long temp_b){
    return temp_a*temp_b/ find_GCD(temp_a, temp_b);
}
#endif //MATRIXFUCK_SUPPORT_H
