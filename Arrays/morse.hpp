#pragma once
#ifndef MORSEH
#define MORSEH

#include <iostream>

class Morse
{
public:
    Morse() {};
    int charToMorse(char *character);
    void textToMorse(std::string *text);

private:
    static const int ALPHABET_SIZE {44};    // 37 without dummy characters
    char alphabet_[ALPHABET_SIZE] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                   ':', ';', '>', '=', '<', '?', '@',   // dummy characters
                                   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                   'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                   'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
    std::string morse_[ALPHABET_SIZE] {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                                       " ", " ", " ", " ", " ", " ", " ", // dummy characters
                                       ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                       "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                       "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
};

#endif