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

class SeedMap {
public:
    unsigned long long sourceStart;
    unsigned long long destStart;
    unsigned long long range;

    string getDebug() {
        return "("+ to_string(destStart) + ", " + to_string(sourceStart) + ", " + to_string(range) + ") ";
    }
};

bool compareSeedByValue(const SeedMap& a, const SeedMap& b) {
    return a.sourceStart < b.sourceStart; // Change the comparison condition as needed
}

bool isDig(char ch) {
    return ch >= '0' && ch <= '9';
}

void processLine(string& input, vector<vector<SeedMap>>& seedMaps, int& mapIndex) {
    if (!isDig(input[0])) {
        mapIndex++;
        seedMaps.push_back({});
        return;
    }
    stringstream ss(input);
    SeedMap sm;
    string token;
    getline(ss, token, ' ');
    sm.destStart = stoull(token);
    getline(ss, token, ' ');
    sm.sourceStart = stoull(token);
    getline(ss, token, ' ');
    sm.range = stoull(token);
    seedMaps[mapIndex].push_back(sm);
}

vector<unsigned long long> getSeeds(string& seedLine) {
    stringstream ss(seedLine);
    string token;
    vector<unsigned long long> seeds;
    while(getline(ss, token, ' ')) {
        if (token.empty()) { continue; }
        if (!isDig(token[0])) { continue; }
        seeds.push_back(stoull(token));
    }
    return seeds;
}

void debug(vector<unsigned long long>& seeds, vector<vector<SeedMap>>& seedMaps) {
    cout << "SEEDS: ";
    for (int i = 0; i < seeds.size(); i++) {
        cout << seeds[i] << " ";
    }

    for (int i = 0; i < seedMaps.size(); i++) {
        cout << "\nSeedMap: \n";
        for (int j = 0; j < seedMaps[i].size(); j++) {
            cout << "\t" << seedMaps[i][j].getDebug() << "\n";
        }
    }
}

void sortSeedMaps(vector<vector<SeedMap>>& seedMaps) {
    for (int i = 0; i < seedMaps.size(); i++) {
        sort(seedMaps[i].begin(), seedMaps[i].end(), compareSeedByValue);
    }
}

unsigned long long getLocForSeed(vector<vector<SeedMap>>& seedMaps, unsigned long long seed) {
    unsigned long long dest = seed;
    unsigned long long source;
    bool foundAtLayer = false;
    int grpInd;
    for(int mapInd = 0; mapInd < seedMaps.size(); mapInd++) {
        source = dest;
        vector<SeedMap>& seedMap = seedMaps[mapInd];
        foundAtLayer = false;
        for (grpInd = 0; grpInd < seedMap.size() - 1; grpInd++) {
            if (source < seedMap[grpInd].sourceStart) { break; }
            if (source >= seedMap[grpInd+1].sourceStart) { continue; }
            if (source < seedMap[grpInd].sourceStart + seedMap[grpInd].range) {
                // in the range
                dest = seedMap[grpInd].destStart + (source - seedMap[grpInd].sourceStart);
                foundAtLayer = true;
                break;
            }
            // outside range
            dest = source;
            foundAtLayer = true;
            break;
        }
        
        if (!foundAtLayer) { 
            // check in last level
            if (grpInd < seedMap.size() && source >= seedMap[grpInd].sourceStart && source < (seedMap[grpInd].sourceStart + seedMap[grpInd].range)) {
                dest = seedMap[grpInd].destStart + (source - seedMap[grpInd].sourceStart);
            } else {
                dest = source; 
            }
        }
        // cout << "\t" <<source << " -> " << dest << endl;
    }
    return dest;
}

void processSeeds(vector<vector<SeedMap>>& seedMaps, vector<unsigned long long>& seeds) {
    unsigned long long seedMin = -1, seedLoc;
    for (int i = 0; i < seeds.size(); i++) {
        seedLoc = getLocForSeed(seedMaps, seeds[i]);
        if (seedMin < 0 || seedMin > seedLoc) {
            seedMin = seedLoc;
        }
    }
    cout << seedMin << endl;
}

void sol() {
    string input;
    long cum = 0;
    vector<vector<SeedMap>> seedMaps;
    getline(cin, input);
    vector<unsigned long long> seeds = getSeeds(input);
    int mapIndex = -1;
    while (getline(cin, input)) {
        if (input.empty()) { continue; }
        processLine(input, seedMaps, mapIndex);
    }
    sortSeedMaps(seedMaps);
    processSeeds(seedMaps, seeds);
}

int main() {
    sol();
}