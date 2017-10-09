//
// Created by Oleksandr Deundiak on 10/9/17.
//

#ifndef LAB1_VIGENERCRYPTOANALYSIS_H
#define LAB1_VIGENERCRYPTOANALYSIS_H

#include <string>

class VigenerCryptoAnalysis {
public:
    VigenerCryptoAnalysis(bool isCyrillic, std::string filename);

    const std::string& key() const { return key_; }
    const std::string& plainText() const { return plainText_; }

private:
    void analyse(bool isCyrillic, std::string filename);

    template <typename T>
    void analyse_(std::string filename, double idealIndex, int rmin, int rmax);

    std::string key_;
    std::string plainText_;
};


#endif //LAB1_VIGENERCRYPTOANALYSIS_H
