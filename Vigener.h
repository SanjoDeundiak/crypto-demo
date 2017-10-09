//
// Created by Oleksandr Deundiak on 9/25/17.
//

#ifndef LAB1_VIGENER_H
#define LAB1_VIGENER_H

#include <vector>

template <typename T>
class Vigener {
public:
    Vigener(std::vector<T> key);

    typename std::vector<T> encrypt(const std::vector<T> &plainText) const;
    typename std::vector<T> decrypt(const std::vector<T> &cipherText) const;
private:
    std::vector<T> key;
};


#endif //LAB1_VIGENER_H
