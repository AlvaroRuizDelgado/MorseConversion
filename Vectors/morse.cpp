#include <algorithm>
#include <fstream>
#include "morse.hpp"


Morse::Morse() {
    std::ifstream file("morse.dat");
    char alphabet;
    std::string morse;
    if (file.is_open()) {

        int nElements = std::count(std::istreambuf_iterator<char>(file), 
                                   std::istreambuf_iterator<char>(), '\n');
        alphabet_.reserve(nElements);
        morse_.reserve(nElements);
        file.seekg(0, file.beg);    // Reset the file position

        while (file >> alphabet >> morse) {
            alphabet_.push_back(alphabet);
            morse_.push_back(morse);
        }
        alphabet_.push_back(' ');
        morse_.push_back(" ");
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
    std::vector<char>::iterator it;
    int index;
    it = std::find(alphabet_.begin(), alphabet_.end(), *c);
    if (it == alphabet_.end()) {
        return morse_.back();
    }
    index = std::distance( alphabet_.begin(), it );
    return morse_.at(index);
}