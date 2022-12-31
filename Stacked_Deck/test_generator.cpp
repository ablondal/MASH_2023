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
        int n = randRange(1, 1e3);
        int k = randRange(1, n/2);
        if(z < 5) {
            n = 1e5;
            k = n / 2;
        }
        inFile << n << " " << k << endl;
        for(int i = 0; i < n; i++){
            inFile << randRange(1, 1e5) << " ";
        }
        inFile << endl;
        inFile.close();
    }

}