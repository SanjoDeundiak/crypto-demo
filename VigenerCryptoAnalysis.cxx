//
// Created by Oleksandr Deundiak on 10/9/17.
//

#include <fstream>
#include "VigenerCryptoAnalysis.h"
#include "LatinCharacter.h"
#include "CyrillicCharacter.h"
#include "TextConverter.h"
#include "SizeGuess.h"
#include "Distribution.h"
#include "Vigener.h"
#include "TextStats.h"

VigenerCryptoAnalysis::VigenerCryptoAnalysis(bool isCyrillic, std::string filename) {
    analyse(isCyrillic, std::move(filename));
}

void VigenerCryptoAnalysis::analyse(bool isCyrillic, std::string filename) {
    if (isCyrillic) {
        analyse_<CyrillicCharacter>(std::move(filename), 0.0553, 2, 30);
    }
    else {
        analyse_<LatinCharacter>(std::move(filename), 0.06555, 2, 26);
    }
}

template <typename CharType>
void VigenerCryptoAnalysis::analyse_(std::string filename, double idealIndex, int rmin, int rmax) {
    auto input = std::ifstream(filename);

    std::string textStr;
    std::string line;
    while (std::getline(input, line)) {
        textStr += line;
    }

    auto text = TextConverter<CharType>::Convert(textStr);

    auto keyLength = SizeGuess::Guess(text, rmin, rmax, idealIndex, 0.1);

    std::vector<CharType> key(keyLength, CharType(0));

    auto distribution = Distribution<CharType>();

    for (int pos = 0; pos < keyLength; pos++) {
        std::vector<CharType> keyCopy = key;
        CharType keyVal = keyCopy[pos];
        double min = std::numeric_limits<double>::max();
        for (int i = 0; i < CharType::alphabet.size(); i++) {
            keyCopy[pos] = keyCopy[pos] + 1;

            auto vigener = Vigener<CharType>(keyCopy);

            auto statsRaw = TextStats<CharType>::StatsRaw(vigener.decrypt(text), keyLength, pos);

            double val = TextStats<CharType>::Compare(statsRaw, distribution.getIdeal());

            if (val < min) {
                min = val;
                keyVal = keyCopy[pos];
            }
        }

        key[pos] = keyVal;
    }

    auto vigener = Vigener<CharType>(key);

    auto decryptedText = vigener.decrypt(text);

    key_ = TextConverter<CharType>::Convert(key);
    plainText_ = TextConverter<CharType>::Convert(decryptedText);
}