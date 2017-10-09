//
// Created by Oleksandr Deundiak on 9/26/17.
//

#include <cmath>
#include "SizeGuess.h"
#include "Index.h"
#include "CyrillicCharacter.h"
#include "LatinCharacter.h"

template <typename T>
int SizeGuess::Guess(const std::vector<T> &text, int rmin, int rmax, double idealIndex, double eps) {
    for (int i = rmin; i <= rmax; i++) {
        double avgIndex = 0;
        for (size_t j = 0; j < i; j++) {
            std::vector<T> subText;
            subText.reserve(text.size() / i);

            for (size_t k = j; k < text.size(); k += i) {
                subText.push_back(text[k]);
            }

            double index = Index::Compute<T>(subText);

            avgIndex += index / i;
        }

        if (abs(avgIndex - idealIndex) / idealIndex < eps)
            return i;
    }

    return -1;
}

template int SizeGuess::Guess(const std::vector<CyrillicCharacter> &, int, int, double, double);
template int SizeGuess::Guess(const std::vector<LatinCharacter> &, int, int, double, double);