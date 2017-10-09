#include <iostream>
#include <fstream>
#include "VigenerCryptoAnalysis.h"
#include "VigenerDemo.h"
#include "NGrammDistribution.h"
#include "CyrillicExtendedCharacter.h"
#include "CyrillicCharacter.h"

int main() {
    VigenerDemo demo("gunslinger.txt");

    VigenerCryptoAnalysis analysisLatin(false, "latin.txt");
    VigenerCryptoAnalysis analysisCyrillic(true, "cyrillic.txt");

    NGrammDistribution<CyrillicExtendedCharacter> he1(1, 1, "cyrillicExtendedTest.txt");
    he1.print("HE1.txt");

    NGrammDistribution<CyrillicExtendedCharacter> he21(2, 1, "cyrillicExtendedTest.txt");
    he21.print("HE21.txt");

    NGrammDistribution<CyrillicExtendedCharacter> he22(2, 2, "cyrillicExtendedTest.txt");
    he22.print("HE22.txt");

    NGrammDistribution<CyrillicCharacter> h1(1, 1, "cyrillicTest.txt");
    h1.print("H1.txt");

    NGrammDistribution<CyrillicCharacter> h21(2, 1, "cyrillicTest.txt");
    h21.print("H21.txt");

    NGrammDistribution<CyrillicCharacter> h22(2, 2, "cyrillicTest.txt");
    h22.print("H22.txt");

    std::cout << std::endl << "==================" << std::endl;
    std::cout << std::endl << "==================" << std::endl;

    std::cout << "Latin key: " << analysisLatin.key() << std::endl;
    std::cout << "Latin plaintext: " << analysisLatin.plainText() << std::endl;

    std::cout << std::endl << "==================" << std::endl;

    std::cout << "Cyrillic key: " << analysisCyrillic.key() << std::endl;
    std::cout << "Cyrillic plaintext: " << analysisCyrillic.plainText() << std::endl;


    return 0;
}