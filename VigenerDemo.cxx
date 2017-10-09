//
// Created by Oleksandr Deundiak on 10/9/17.
//

#include "VigenerDemo.h"
#include "LatinCharacter.h"
#include "TextConverter.h"
#include "Vigener.h"
#include "Index.h"
#include <fstream>
#include <iostream>

VigenerDemo::VigenerDemo(std::string filename) {
    auto input = std::ifstream(filename);

    std::string textStr;
    std::string line;
    while (std::getline(input, line)) {
        textStr += line;
    }

    auto plainText = TextConverter<LatinCharacter>::Convert(textStr);

    std::vector<std::string> keysStr = {
        "ab",
        "abc",
        "abcd",
        "abcde",
        "stephenking"
    };

    std::vector<std::vector<LatinCharacter>> keys;

    for (auto &keyStr: keysStr)
        keys.push_back(TextConverter<LatinCharacter>::Convert(keyStr));

    std::vector<double> indexes;

    std::cout << "Plaintext index: " << Index::Compute(plainText) << std::endl;

    for (int i = 0; i < keys.size(); i++) {
        Vigener<LatinCharacter> vigener(keys[i]);

        auto cipherText = vigener.encrypt(plainText);

        std::cout << std::endl << "==================" << std::endl;
        std::cout << "Key index: " << keysStr[i] << std::endl;
        std::cout << "Ciphertext index: " << Index::Compute(cipherText) << std::endl;
    }
}