//
// Created by Oleksandr Deundiak on 9/26/17.
//

#ifndef LAB1_LATINCHARACTER_H
#define LAB1_LATINCHARACTER_H


#include <string>
#include <vector>

class LatinCharacter {
public:
    LatinCharacter(std::string ch);
    LatinCharacter(int charNum);
    LatinCharacter(LatinCharacter &&other) noexcept;
    LatinCharacter(const LatinCharacter &other);

    std::string toString() const;
    int getCharNum() const { return this->charNum; }

    LatinCharacter &operator=(const LatinCharacter &other) {
        charNum = other.charNum;
        readableChar = other.readableChar;
        return *this;
    }

    bool operator==(const LatinCharacter &other) const { return this->charNum == other.charNum; }

    friend LatinCharacter operator+(const LatinCharacter &lhs,
                                    const LatinCharacter &rhs) {
        return (int)((lhs.charNum + rhs.charNum) % alphabet.size());
    }

    static std::vector<std::string> alphabet;

private:
    int charNum;
    std::string readableChar;
};


#endif //LAB1_LATINCHARACTER_H
