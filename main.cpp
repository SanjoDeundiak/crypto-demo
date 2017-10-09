#include <iostream>
#include "VigenerCryptoAnalysis.h"
#include "VigenerDemo.h"

int main() {
    VigenerDemo demo("gunslinger.txt");

    VigenerCryptoAnalysis analysisLatin(false, "latin.txt");
    VigenerCryptoAnalysis analysisCyrillic(true, "cyrillic.txt");

    std::cout << std::endl << "==================" << std::endl;
    std::cout << std::endl << "==================" << std::endl;

    std::cout << "Latin key: " << analysisLatin.key() << std::endl;
    std::cout << "Latin plaintext: " << analysisLatin.plainText() << std::endl;

    std::cout << std::endl << "==================" << std::endl;

    std::cout << "Cyrillic key: " << analysisCyrillic.key() << std::endl;
    std::cout << "Cyrillic plaintext: " << analysisCyrillic.plainText() << std::endl;


    return 0;
}