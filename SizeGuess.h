//
// Created by Oleksandr Deundiak on 9/26/17.
//

#ifndef LAB1_SIZEGUESS_H
#define LAB1_SIZEGUESS_H


#include <vector>

class SizeGuess {
public:
    template <typename T>
    static int Guess(const std::vector<T> &text, int rmin, int rmax, double idealIndex, double eps);
};


#endif //LAB1_SIZEGUESS_H
