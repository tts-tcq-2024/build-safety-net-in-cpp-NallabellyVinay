#include "Soundex.h"
#include <cctype>
#include <unordered_map>

// Define a map for soundex code lookup
static const std::unordered_map<char, char> soundexMap {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

// Function to get soundex code for a character
char getSoundexCode(char c) {
    c = toupper(c);
    return soundexMap.count(c) ? soundexMap.at(c) : '0';
}

// Function to generate soundex code for a given name
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    soundex += toupper(name[0]);
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    soundex.append(4 - soundex.length(), '0'); // Pad with '0' to ensure length is 4

    return soundex;
}
