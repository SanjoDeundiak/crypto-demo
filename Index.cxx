//
// Created by Oleksandr Deundiak on 9/26/17.
//

#include <iostream>
#include "Index.h"
#include "CyrillicCharacter.h"
#include "LatinCharacter.h"

template <typename T>
double Index::Compute(const typename std::vector<T> &text) {
    const std::vector<std::string> alphabet = T::alphabet;
    auto size = (double)text.size();

    double sum = 0;
    for (size_t i = 0; i < alphabet.size(); i++) {
        auto count = (double)std::count(text.begin(), text.end(), T(alphabet[i]));

        sum += count / size * (count - 1) / (size - 1);
    }

    return sum;
}

template double Index::Compute<CyrillicCharacter>(const typename std::vector<CyrillicCharacter> &);
template double Index::Compute<LatinCharacter>(const typename std::vector<LatinCharacter> &);