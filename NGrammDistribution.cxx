//
// Created by Oleksandr Deundiak on 10/9/17.
//

#include <cmath>
#include <fstream>
#include "NGrammDistribution.h"
#include "TextConverter.h"
#include "CyrillicExtendedCharacter.h"
#include "CyrillicCharacter.h"

template <typename CharType>
NGrammDistribution<CharType>::NGrammDistribution(size_t n, size_t step, const std::string &filename) {
    auto input = std::ifstream(filename);

    std::string textStr;
    std::string line;
    while (std::getline(input, line)) {
        textStr += line;
    }

    auto text = TextConverter<CharType>::Convert(textStr);

    std::vector<statRaw> stats;
    stats.reserve(size_t(pow(CharType::alphabet.size(), n)));

    std::vector<int> counters(n, 0);

    bool exit = false;
    while (!exit) {
        std::vector<CharType> newGramm;
        newGramm.reserve(n);
        for (auto counter: counters) {
            newGramm.emplace_back(CharType::alphabet[counter]);
        }

        stats.emplace_back(newGramm, 0);

        counters[counters.size() - 1]++;
        size_t i = counters.size() - 1;
        while (counters[i] == CharType::alphabet.size()) {
            counters[i] = 0;
            if (i == 0) {
                exit = true;
                break;
            }
            i--;
            counters[i]++;
        }
    }

    for (size_t i = 0; i + n <= text.size(); i += step) {
        addStat(stats, std::vector<CharType>(text.cbegin() + i, text.cbegin() + i + n));
    }

    processStats(n, stats);
}

template <typename CharType>
void NGrammDistribution<CharType>::processStats(size_t n, const std::vector<statRaw> &stats) {
    res.reserve(stats.size());

    for (auto &s: stats) {
        double val = double(s.second) / totalStats;
        if (val != 0)
            H_ += -val * log2(val);
        res.emplace_back(s.first, val);
    }

    H_ /= n;
}

template <typename CharType>
void NGrammDistribution<CharType>::addStat(std::vector<statRaw> &stats, const std::vector<CharType> &text) {
    size_t n = text.size();
    std::vector<int> counters(n, 0);

    size_t index = 0;
    for (size_t i = 0, k = 1; i < n; i++, k *= CharType::alphabet.size()) {
        index += text[n - i - 1].getCharNum() * k;
    }

    // ASSERT(stats[index].first == text)
    stats[index].second++;

    totalStats++;
}

template <typename CharType>
void NGrammDistribution<CharType>::print(const std::string &filename) const {
    std::ofstream output(filename);

    output << "H=" << H_ << std::endl;

    for (auto &stat: res) {
        auto text = TextConverter<CharType>::Convert(stat.first);
        output << text << " " << stat.second << std::endl;
    }
}

template class NGrammDistribution<CyrillicExtendedCharacter>;
template class NGrammDistribution<CyrillicCharacter>;