//
// Created by Oleksandr Deundiak on 9/26/17.
//

#include "TextConverter.h"
#include "CyrillicCharacter.h"
#include "LatinCharacter.h"
#include "CyrillicExtendedCharacter.h"

template <typename T>
std::vector<T> TextConverter<T>::Convert(const std::string &str) {
    std::vector<T> result;
    result.reserve(str.size());
    for (size_t i = 0; i < str.size(); i++) {
        result.push_back(T(std::string { str[i] }));
    }

    return result;
}

template <>
std::vector<CyrillicCharacter> TextConverter<CyrillicCharacter>::Convert(const std::string &str) {
    std::vector<CyrillicCharacter> result;
    result.reserve(str.size() / 2);
    for (size_t i = 0; i < str.size(); i += 2) {
        result.emplace_back(std::string{str[i], str[i+1]});
    }

    return result;
}

template <>
std::vector<CyrillicExtendedCharacter> TextConverter<CyrillicExtendedCharacter>::Convert(const std::string &str) {
    std::vector<CyrillicExtendedCharacter> result;
    result.reserve(str.size() / 2);
    for (size_t i = 0; i < str.size(); i += 2) {
        result.emplace_back(std::string{str[i], str[i+1]});
    }

    return result;
}

template <typename T>
std::string TextConverter<T>::Convert(const std::vector<T> &text, int breakInterval, int limit) {
    std::string str;

    for (size_t i = 0, breakCounter = 1, limitCounter = 0; i < text.size(); i++, breakCounter++) {
        str += text[i].toString();

        if ((int)breakCounter == breakInterval) {
            breakCounter = 0;
            limitCounter++;
            str += "\n";

            if (limitCounter == limit)
                return str;
        }
    }

    return str;
}

template class TextConverter<CyrillicCharacter>;
template class TextConverter<CyrillicExtendedCharacter>;
template class TextConverter<LatinCharacter>;