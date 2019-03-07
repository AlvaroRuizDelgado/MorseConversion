#include <iostream>
#include <fstream>
#include "morse.hpp"

Morse::Morse() {
    std::ifstream file("morse.dat");
    char alphabet;
    std::string morse;
    if (file.is_open()) {
        while (file >> alphabet >> morse) {
            morseDict_.insert( std::pair<char,  std::string>(alphabet, morse) );
        }
        morseDict_.insert( std::pair<char, std::string>(' ', " ") );
    }
    else {
        std::cout << "Unable to open file.\n";
    }
}

void Morse::textToMorse(std::string *text) {
    int i = 0;
    for (char& c : *text) {
        if ('a' <= c && c <= 'z') {     // Alternative: store capital letters in dictionary --> more often out of cache.
            c = c^0x20;
        }
        std::string morse = charToMorse(&c);
        // std::cout << c << ": " << morse << "\n";
    }
}

std::string Morse::charToMorse(char *c) {
    auto search = morseDict_.find(*c);
    if (search != morseDict_.end()) {
        return search->second;
    }
    else {
        return std::string("NOT FOUND");
    }
}