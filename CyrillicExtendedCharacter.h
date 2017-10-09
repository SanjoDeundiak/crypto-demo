//
// Created by Oleksandr Deundiak on 10/9/17.
//

#ifndef LAB1_CYRILLICEXTENDEDCHARACTER_H
#define LAB1_CYRILLICEXTENDEDCHARACTER_H


#include <vector>
#include <string>

class CyrillicExtendedCharacter {
public:
    CyrillicExtendedCharacter(std::string ch);
    CyrillicExtendedCharacter(int charNum);
    CyrillicExtendedCharacter(CyrillicExtendedCharacter &&other) noexcept;
    CyrillicExtendedCharacter(const CyrillicExtendedCharacter &other);

    std::string toString() const;
    int getCharNum() const { return this->charNum; }

    CyrillicExtendedCharacter &operator=(const CyrillicExtendedCharacter &other) {
        charNum = other.charNum;
        readableChar = other.readableChar;
        return *this;
    }

    bool operator==(const CyrillicExtendedCharacter &other) const { return this->charNum == other.charNum; }

    friend CyrillicExtendedCharacter operator+(const CyrillicExtendedCharacter &lhs,
                                       const CyrillicExtendedCharacter &rhs) {
        return (int)((lhs.charNum + rhs.charNum) % alphabet.size());
    }

    static std::vector<std::string> alphabet;

private:
    int charNum;
    std::string readableChar;
};


#endif //LAB1_CYRILLICEXTENDEDCHARACTER_H
