#include <iostream>
#include <string>
using namespace std;

enum chord {c, d, e, f, g, a, b, C, D, E, F, G, A, B};

int main(){
    int n;
    cin >> n;
    
    bool chordc[10] = {false, true, true, true, false, false, true, true, true, true};
    bool chordd[10] = {false, true, true, true, false, false, true, true, true, false};
    bool chorde[10] = {false, true, true, true, false, false, true, true, false, false};
    bool chordf[10] = {false, true, true, true, false, false, true, false, false, false};
    bool chordg[10] = {false, true, true, true, false, false, false, false, false, false};
    bool chorda[10] = {false, true, true, false, false, false, false, false, false, false};
    bool chordb[10] = {false, true, false, false, false, false, false, false, false, false};
    bool chordC[10] = {false, false, true, false, false, false, false, false, false, false};
    bool chordD[10] = {true, true, true, true, false, false, true, true, true, false};
    bool chordE[10] = {true, true, true, true, false, false, true, true, false, false};
    bool chordF[10] = {true, true, true, true, false, false, true, false, false, false};
    bool chordG[10] = {true, true, true, true, false, false, false, false, false, false};
    bool chordA[10] = {true, true, true, false, false, false, false, false, false, false};
    bool chordB[10] = {true, true, false, false, false, false, false, false, false, false};
    bool* mask[14] = {chorda, chordb, chordc, chordd, chorde, chordf, chordg, chordA, chordB, chordC, chordD, chordE, chordF, chordG};
    bool stat[10] = {false, false, false, false, false, false, false, false, false, false};
    int ans[10] = {0};
    string song;
    char note;
    int c;
    for(int i = 0; i < n; i++){
        cin >> song;
        for (int j = 0; j < song.size(); j++){
            // cout << song[j];
            // cout << "Here";}
            note = song[j];
            // cout << note << endl;
            if (note >= 'a'){
                c = note - 'a';
            }
            else {
                c = note - 'A' + 7;
            }
            // cout << c << endl;
            // cout << note << endl;
            // for (int aa = 0; aa < 10; aa ++){
            //             cout << mask[c][aa] << ' ';
            //         }
            //         cout << endl;
            //     for (int aa = 0; aa < 10; aa ++){
            //             cout << stat[aa] << ' ';
            //         }
            //         cout << endl;
            for (int k = 0; k < 10; k++){
                // cout << c << mask[c][k] << stat[k] << endl;
                if (mask[c][k] != stat[k]){
                    stat[k] = mask[c][k];
                    if (mask[c][k] == true)
                        ans[k]++;
                }
            }
        }
        for (int j = 0; j < 10; j++){
            cout << ans[j];
            ans[j] = 0;
            stat[j] = false;
            if (j == 9)
                continue;
            cout << ' ';
        }
        cout << endl;
    }
}