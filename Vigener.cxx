//
// Created by Oleksandr Deundiak on 9/25/17.
//

#include "Vigener.h"
#include "CyrillicCharacter.h"
#include "LatinCharacter.h"

template <typename T>
Vigener<T>::Vigener(std::vector<T> key)
    : key(std::move(key)) {

}

template <typename T>
typename std::vector<T> Vigener<T>::encrypt(const std::vector<T> &plainText) const {
    std::vector<T> result;
    result.reserve(plainText.size());

    for (size_t i = 0, j = 0; i < plainText.size(); i++, j = (j + 1) % key.size()) {
        result.push_back(T((plainText[i].getCharNum() + key[j].getCharNum()) % T::alphabet.size()));
    }

    return result;
}

template <typename T>
typename std::vector<T> Vigener<T>::decrypt(const std::vector<T> &cipherText) const {
    std::vector<T> result;
    result.reserve(cipherText.size());

    for (size_t i = 0, j = 0; i < cipherText.size(); i++, j = (j + 1) % key.size()) {
        result.push_back(T((T::alphabet.size() + cipherText[i].getCharNum() - key[j].getCharNum()) % T::alphabet.size()));
    }

    return result;
}

template class Vigener<CyrillicCharacter>;
template class Vigener<LatinCharacter>;