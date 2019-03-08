#pragma once
#ifndef MORSEH
#define MORSEH

#include <iostream>
#include <unordered_map>

class Morse
{
public:
    Morse();
    std::string charToMorse(char *character);
    void textToMorse(std::string *text);

private:
    std::unordered_map<char, std::string> morseDict_;
};

#endif