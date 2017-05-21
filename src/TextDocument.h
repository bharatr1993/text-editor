#ifndef TextDocument_H
#define TextDocument_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <locale>

#include <string>
#include <algorithm>

using std::string;
using std::vector;

class TextDocument {
    public:
        bool init(string &filename);
        bool saveFile(string &filename);

        sf::String getLine(int lineNumber);
        int charsInLine(int line) const;
        int getLineCount() const;

        void addTextToPos(sf::String text, int line, int charN);
        void removeTextFromPos(int amount, int line, int charN);

        std::string convertSpecialChar(sf::Uint32 c, std::ofstream &outputFile);

        int charAmountContained(int startLineN, int startCharN, int endLineN, int endCharN);

    private:
        bool initLinebuffer();
        sf::String buffer;
        int length;
        vector<int> lineBuffer;

        int getBufferPos(int line, int charN);

        sf::String toUtf32(const std::string& inString);
};

#endif