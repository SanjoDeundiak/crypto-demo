//
// Created by Oleksandr Deundiak on 10/10/17.
//

#include <iostream>
#include "DrCalculator.h"
#include "LatinCharacter.h"
#include "CyrillicCharacter.h"


template <typename T>
void DrCalculator::Calculate(const std::vector<T> &text, int rmin, int rmax) {
    std::cout << std::endl << std::endl << "====DrCalculator====" << std::endl;

    for (int r = rmin; r <= rmax; r++) {
        size_t val = 0;

        for (size_t i = 0; i + r < text.size(); i++) {
            if (text[i] == text[i + r])
                val++;
        }

        std::cout << "D for r=" << r << ": " << val << std::endl;
    }

    std::cout << "====DrCalculator====" << std::endl << std::endl;
}

template void DrCalculator::Calculate<LatinCharacter>(const std::vector<LatinCharacter> &text, int rmin, int rmax);
template void DrCalculator::Calculate<CyrillicCharacter>(const std::vector<CyrillicCharacter> &text, int rmin, int rmax);