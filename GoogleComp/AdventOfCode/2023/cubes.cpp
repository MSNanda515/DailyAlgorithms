#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <sstream>


using namespace std;

vector<string> breakIntoTokens(string& input) {
    vector<string> tokens;
    int colIndex = input.find(':');
    tokens.push_back(input.substr(0, colIndex));
    int lastBound = colIndex + 2;
    for (int i = lastBound; i < input.size(); i++) {
        if (input[i] == ';') {
            tokens.push_back(input.substr(lastBound, i - lastBound));
            lastBound = i + 2;
        }
    }
    tokens.push_back(input.substr(lastBound));
    return tokens;
}

const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

void processGame(string& game, int& red, int& green, int& blue) {
    red = green = blue = 0;
    int ptr = 0;
    while (ptr < game.size()) {
        int spaceInd = game.find(' ', ptr);
        int colorCount = stoi(game.substr(ptr, spaceInd - ptr));
        int commaInd = game.find(',', ptr);
        if (commaInd < 0) {
            commaInd = game.size();
        }
        string colorName = game.substr(spaceInd + 1, commaInd - spaceInd - 1);
        if ( colorName == "red") { red = colorCount; }
        else if (colorName == "blue") { blue = colorCount; }
        else green = colorCount;

        ptr = commaInd + 2;
    }
}

int getGameId(string& gameIdStr) {
    return stoi(gameIdStr.substr(5));
}

void processLine(string& input, long& cum) {
    vector<string> tokens = breakIntoTokens(input);
    int red, green, blue;
    for (int i = 1; i < tokens.size(); i++) {
        processGame(tokens[i], red, green, blue);
        if (red > MAX_RED || green > MAX_GREEN || blue > MAX_BLUE) {
            return;
        } 
    }
    cum += getGameId(tokens[0]);
}

void processLine2(string& input, long& cum) {
    vector<string> tokens = breakIntoTokens(input);
    int red, green, blue;
    int redMax = 0, greenMax = 0, blueMax = 0;
    for (int i = 1; i < tokens.size(); i++) {
        processGame(tokens[i], red, green, blue);
        redMax = max(red, redMax);
        greenMax = max(green, greenMax);
        blueMax = max(blue, blueMax);
    }
    cum += 1l * redMax * blueMax * greenMax;
}

void sol() {
    string input;
    long cum = 0;
    string token;
    while (getline(cin, input)) {
        processLine2(input, cum);
    }
    cout << cum << endl;
}

int main() {
    sol();
}