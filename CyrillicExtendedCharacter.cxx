//
// Created by Oleksandr Deundiak on 10/9/17.
//

#include "CyrillicExtendedCharacter.h"

std::vector<std::string> CyrillicExtendedCharacter::alphabet = { "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я", "  "};

CyrillicExtendedCharacter::CyrillicExtendedCharacter(std::string ch)
        : readableChar(std::move(ch)) {
    auto findIt = std::find(alphabet.begin(), alphabet.end(), this->readableChar);

    if (findIt == alphabet.end())
        throw -1;

    charNum = (int)std::distance(alphabet.begin(), findIt);
}

CyrillicExtendedCharacter::CyrillicExtendedCharacter(int charNum) {
    if (charNum >= alphabet.size())
        throw -1;

    this->charNum = charNum;
    this->readableChar = alphabet[charNum];
}

CyrillicExtendedCharacter::CyrillicExtendedCharacter(CyrillicExtendedCharacter &&other) noexcept
        : readableChar(std::move(other.readableChar)), charNum(other.charNum) {
}

CyrillicExtendedCharacter::CyrillicExtendedCharacter(const CyrillicExtendedCharacter &other)
        : readableChar(other.readableChar), charNum(other.charNum) {
}

std::string CyrillicExtendedCharacter::toString() const {
    return this->readableChar;
}