//
// Created by Oleksandr Deundiak on 9/26/17.
//

#ifndef LAB1_TEXTCONVERTER_H
#define LAB1_TEXTCONVERTER_H


#include <vector>
#include <string>

template <typename T>
class TextConverter {
public:
    static std::vector<T> Convert(const std::string &str);
    static std::string Convert(const std::vector<T> &text, int breakInterval = -1, int limit = -1);
};


#endif //LAB1_TEXTCONVERTER_H
