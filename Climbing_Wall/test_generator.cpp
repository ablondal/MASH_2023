#include <bits/stdc++.h>
using namespace std;

int randRange(int l, int r) {
    int diff = (r - l + 1);
    return (rand() % diff) + l;
}

string getInputName(int testIndex) {
    return "data/secret/" + to_string(testIndex) + ".in";
}

string getOutputName(int testIndex) {
    return "data/secret/" + to_string(testIndex) + ".out";
}

int main() {
    srand(time(NULL));
    int numTests = 50;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        int h = 1000;
        int w = 100;
        if(z >= 5){
            h = randRange(1, 100);
            w = randRange(1, 100);
        }
        vector<string> grid(h+2);
        for(int i = 0; i < h+2; i++){
            string line = "";
            if(i == 0 || i == h+1) {
                line.push_back('+');
                for(int j = 0; j < w; j++){
                    line.push_back('-');
                }
                line.push_back('+');
            }else{
                line.push_back('|');
                for(int j = 0; j < w; j++){
                    int val = randRange(1, 110);
                    if(val < 10){
                        line.push_back('0' + val);
                    }else{
                        line.push_back('.');
                    }
                }
                line.push_back('|');
            }
            grid[i] = line;
        }
        inFile << h << " " << w << endl;
        for(int i = 0; i < grid.size(); i++){
            inFile << grid[i] << endl;
        }
        inFile.close();
    }
}