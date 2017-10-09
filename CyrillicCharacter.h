//
// Created by Oleksandr Deundiak on 9/25/17.
//

#ifndef LAB1_CYRILLICCHARACTER_H
#define LAB1_CYRILLICCHARACTER_H


#include <vector>
#include <string>

class CyrillicCharacter {
public:
    CyrillicCharacter(std::string ch);
    CyrillicCharacter(int charNum);
    CyrillicCharacter(CyrillicCharacter &&other) noexcept;
    CyrillicCharacter(const CyrillicCharacter &other);

    std::string toString() const;
    int getCharNum() const { return this->charNum; }

    CyrillicCharacter &operator=(const CyrillicCharacter &other) {
        charNum = other.charNum;
        readableChar = other.readableChar;
        return *this;
    }

    bool operator==(const CyrillicCharacter &other) const { return this->charNum == other.charNum; }

    friend CyrillicCharacter operator+(const CyrillicCharacter &lhs,
                                       const CyrillicCharacter &rhs) {
        return (int)((lhs.charNum + rhs.charNum) % alphabet.size());
    }

    static std::vector<std::string> alphabet;

private:
    int charNum;
    std::string readableChar;
};


#endif //LAB1_CYRILLICCHARACTER_H
