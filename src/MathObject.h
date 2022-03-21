//
// Created by MRV on 21.03.2022.
//

#ifndef MATRIX_MATHOBJECT_H
#define MATRIX_MATHOBJECT_H

template<class T>
class MathObject {
public:
    virtual std::string to_string(std::string (*toString)(const T)) = 0;
};

#endif //MATRIX_MATHOBJECT_H
