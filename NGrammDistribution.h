//
// Created by Oleksandr Deundiak on 10/9/17.
//

#ifndef LAB1_NGRAMMDISTRIBUTION_H
#define LAB1_NGRAMMDISTRIBUTION_H

#include <vector>

template <typename CharType>
class NGrammDistribution {
public:
    typedef std::pair<std::vector<CharType>, size_t> statRaw;
    typedef std::pair<std::vector<CharType>, double> stat;

    NGrammDistribution(size_t n, size_t step, const std::string &filename);

    const std::vector<stat>& result() const { return res; }
    const double H() const { return H_; }

    void print(const std::string &filename) const;

private:
    void addStat(std::vector<statRaw> &stats, const std::vector<CharType> &text);
    void processStats(const std::vector<statRaw> &stats);

    size_t totalStats = 0;
    double H_ = 0;
    std::vector<stat> res;
};


#endif //LAB1_NGRAMMDISTRIBUTION_H
