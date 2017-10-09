//
// Created by Oleksandr Deundiak on 9/26/17.
//

#include <map>
#include <cmath>
#include "TextStats.h"
#include "CyrillicCharacter.h"
#include "LatinCharacter.h"

template <typename T>
std::vector<std::pair<double, T>> TextStats<T>::Stats(const typename std::vector<T> &text, int keyLength, int pos) {
    auto statsMap = StatsRaw(text, keyLength, pos);

    typedef std::pair<double, T> pairType;

    std::vector<pairType> stats;
    for (auto it = statsMap.begin(); it != statsMap.end(); it++) {
        stats.push_back(std::make_pair(it->second, it->first));
    }

    std::sort(stats.begin(), stats.end(), [](const pairType &p1, const pairType &p2) {
        return p1.first > p2.first;
    });

    return stats;
}

template <typename T>
std::map<int, double> TextStats<T>::StatsRaw(const typename std::vector<T> &text, int keyLength, int pos) {
    std::map<int, double> statsMap;

    double sum = 0;
    for (auto i = (size_t)pos; i < text.size(); i += keyLength) {
        statsMap[text[i].getCharNum()]++;
        sum++;
    }

    for (auto it = statsMap.begin(); it != statsMap.end(); it++)
        it->second /= sum;

    return statsMap;
};

template <typename T>
double TextStats<T>::Compare(const std::map<int, double> &actual, const std::map<int, double> &ideal) {
    double res = 0;

    for (auto it = ideal.begin(); it != ideal.end(); it++) {
        double actualVal = 0;
        auto f = actual.find(it->first);

        if (f != actual.end()) {
            actualVal = f->second;
        }

        res += pow(abs(actualVal - it->second), 2);
    }

    return res;
}

template class TextStats<CyrillicCharacter>;
template class TextStats<LatinCharacter>;