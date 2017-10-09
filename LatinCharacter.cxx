//
// Created by Oleksandr Deundiak on 9/26/17.
//

#include "LatinCharacter.h"

std::vector<std::string> LatinCharacter::alphabet = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

LatinCharacter::LatinCharacter(std::string ch)
        : readableChar(std::move(ch)) {
    auto findIt = std::find(alphabet.begin(), alphabet.end(), this->readableChar);

    if (findIt == alphabet.end())
        throw -1;

    charNum = (int)std::distance(alphabet.begin(), findIt);
}

LatinCharacter::LatinCharacter(int charNum) {
    if (charNum >= alphabet.size())
        throw -1;

    this->charNum = charNum;
    this->readableChar = alphabet[charNum];
}

LatinCharacter::LatinCharacter(LatinCharacter &&other) noexcept
        : readableChar(std::move(other.readableChar)), charNum(other.charNum) {
}

LatinCharacter::LatinCharacter(const LatinCharacter &other)
        : readableChar(other.readableChar), charNum(other.charNum) {
}

std::string LatinCharacter::toString() const {
    return this->readableChar;
}