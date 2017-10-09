//
// Created by Oleksandr Deundiak on 9/26/17.
//

#ifndef LAB1_INDEX_H
#define LAB1_INDEX_H


#include <vector>

class Index {
public:
    template <typename T>
    static double Compute(const typename std::vector<T> &text);

};


#endif //LAB1_INDEX_H
