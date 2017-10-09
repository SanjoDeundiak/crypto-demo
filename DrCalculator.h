//
// Created by Oleksandr Deundiak on 10/10/17.
//

#ifndef LAB1_DRCALCULATOR_H
#define LAB1_DRCALCULATOR_H


#include <vector>

class DrCalculator {
public:
    template <typename T>
    static void Calculate(const std::vector<T> &text, int rmin, int rmax);
};


#endif //LAB1_DRCALCULATOR_H
