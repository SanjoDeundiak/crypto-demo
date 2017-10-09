//
// Created by Oleksandr Deundiak on 9/25/17.
//

#include <iostream>
#include "CyrillicCharacter.h"

std::vector<std::string> CyrillicCharacter::alphabet = { "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я" };

CyrillicCharacter::CyrillicCharacter(std::string ch)
    : readableChar(std::move(ch)) {
    auto findIt = std::find(alphabet.begin(), alphabet.end(), this->readableChar);

    if (findIt == alphabet.end()) {
        std::cout << this->readableChar << std::endl;
        throw -1;
    }

    charNum = (int)std::distance(alphabet.begin(), findIt);
}

CyrillicCharacter::CyrillicCharacter(int charNum) {
    if (charNum >= alphabet.size()) {
        std::cout << "HERE" << std::endl;
        throw -1;
    }

    this->charNum = charNum;
    this->readableChar = alphabet[charNum];
}

CyrillicCharacter::CyrillicCharacter(CyrillicCharacter &&other) noexcept
    : readableChar(std::move(other.readableChar)), charNum(other.charNum) {
}

CyrillicCharacter::CyrillicCharacter(const CyrillicCharacter &other)
    : readableChar(other.readableChar), charNum(other.charNum) {
}

std::string CyrillicCharacter::toString() const {
    return this->readableChar;
}