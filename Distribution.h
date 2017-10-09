//
// Created by Oleksandr Deundiak on 9/26/17.
//

#ifndef LAB1_DISTRIBUTION_H
#define LAB1_DISTRIBUTION_H


#include <map>

template <typename T>
class Distribution {
public:
    Distribution();

    const std::map<int, double> &getIdeal() { return ideal; };

private:
    std::map<int, double> ideal;
};


#endif //LAB1_DISTRIBUTION_H
