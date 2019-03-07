#include "morse.hpp"

void Morse::textToMorse(std::string *text) {
    int i = 0;
    for (char& c : *text) {
        if ('a' <= c && c <= 'z') {     // Alternative: store capital letters in dictionary --> more often out of cache.
            c = c^0x20;
        }
        i = charToMorse(&c);
        // std::cout << c << ": " << morse_[i] << "\n";
    }
}

int Morse::charToMorse(char *c) {
    int i = 0;
    while (alphabet_[i] != *c) {
        i++;
        if (i == ALPHABET_SIZE) {
            return ALPHABET_SIZE-1;
        }
    }
    return i;
}