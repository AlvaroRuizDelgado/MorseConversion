#pragma once
#ifndef MORSEH
#define MORSEH

#include <iostream>
#include <vector>

class Morse
{
public:
    Morse();
    std::string charToMorse(char *character);
    void textToMorse(std::string *text);

private:
    std::vector<char> alphabet_;
    std::vector<std::string> morse_;
    // std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    //             'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    //             'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
    //             '4', '5', '6', '7', '8', '9', ' '};
    // std::vector<std::string> morse_ = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    //          "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    //          "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--",
    //          "....-", ".....", "-....", "--...", "---..", "----.", " "};
};

#endif