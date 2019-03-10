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
    int i = (int) (*c - '0');
    if (0 < i && i < ALPHABET_SIZE) {
        return i;
    }
    return ALPHABET_SIZE-1;

    // BINARY SEARCH (~ twice as slow)
    // int low = 0;
    // int high = ALPHABET_SIZE-1;
    // while (low <= high) {
    //     int middle = (low + high) / 2;
    //     if (alphabet_[middle] == *c) {
    //         return middle;
    //     }
    //     if (alphabet_[middle] < *c) { // In the upper half
    //         low = middle + 1;
    //     }
    //     else {
    //         high = middle - 1;
    //     }
    // }
    // return ALPHABET_SIZE-1;
}