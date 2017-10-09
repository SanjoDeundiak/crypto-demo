//
// Created by Oleksandr Deundiak on 9/26/17.
//

#ifndef LAB1_TEXTSTATS_H
#define LAB1_TEXTSTATS_H


#include <utility>
#include <vector>
#include <map>

template <typename T>
class TextStats {
public:
    static std::vector<std::pair<double, T>> Stats(const typename std::vector<T> &text, int keyLength, int pos);
    static std::map<int, double> StatsRaw(const typename std::vector<T> &text, int keyLength, int pos);
    static double Compare(const std::map<int, double> &actual, const std::map<int, double> &ideal);
};


#endif //LAB1_TEXTSTATS_H
