#pragma once
#ifndef MORSEH
#define MORSEH

#include <iostream>
#include <map>

class Morse
{
public:
    Morse();
    std::string charToMorse(char *character);
    void textToMorse(std::string *text);

private:
    std::map<char, std::string> morseDict_;
};

#endif