cmake_minimum_required(VERSION 3.6)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vigener.cxx Vigener.h CyrillicCharacter.cxx CyrillicCharacter.h TextConverter.cxx TextConverter.h Index.cxx Index.h SizeGuess.cxx SizeGuess.h TextStats.cxx TextStats.h Distribution.cxx Distribution.h LatinCharacter.cxx LatinCharacter.h VigenerCryptoAnalysis.cxx VigenerCryptoAnalysis.h VigenerDemo.cxx VigenerDemo.h NGrammDistribution.cxx NGrammDistribution.h CyrillicExtendedCharacter.cxx CyrillicExtendedCharacter.h DrCalculator.cxx DrCalculator.h)
add_executable(lab1 ${SOURCE_FILES})

configure_file(cyrillic.txt cyrillic.txt COPYONLY)
configure_file(latin.txt latin.txt COPYONLY)
configure_file(cyrillicTest.txt cyrillicTest.txt COPYONLY)
configure_file(cyrillicExtendedTest.txt cyrillicExtendedTest.txt COPYONLY)
configure_file(gunslinger.txt gunslinger.txt COPYONLY)