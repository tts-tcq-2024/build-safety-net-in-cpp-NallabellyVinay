#include "Soundex.h"
#include <cctype>
#include <string>

// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    static const std::string codes = "01230120022455012623010202";
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? codes[c - 'A'] : '0';
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(soundex[0]);
    size_t i = 1;
    while (i < name.length() && soundex.length() < 4) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
        ++i;
    }

    soundex.resize(4, '0');
    return soundex;
}
