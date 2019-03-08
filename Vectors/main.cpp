#include <iostream>
#include <fstream>
#include <sstream>
#include "morse.hpp"

int main(void) {
    
    Morse morse;

    // std::string example ("Will proceed to process a file.");
    // morse.textToMorse(&example);

    std::ifstream t("../long.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string longText (buffer.str());
    morse.textToMorse(&longText);

    return EXIT_SUCCESS;
}