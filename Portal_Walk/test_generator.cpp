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
        int n = randRange(0, 1e3);
        int x = randRange(2 * n + 1, 1e5);
        inFile << n << " " << x << endl;
        vector<int> potentialLocations;
        for(int i = 1; i < x; i++){
            potentialLocations.push_back(i);
        }
        random_shuffle(potentialLocations.begin(), potentialLocations.end());
        map<int,int> portals;
        for(int i = 0; i < n; i++){
            int a = potentialLocations[2 * i];
            int b = potentialLocations[2 * i + 1];
            inFile << a << " " << b << endl;
            portals[a] = b;
            portals[b] = a;
        }
        inFile.close();
        int steps = 0;
        int pos = 0;
        while(pos != x) {
            pos++;
            steps++;
            if(portals.count(pos) != 0){
                pos = portals[pos];
            }
        }
        ofstream outFile(getOutputName(z + 1));
        outFile << steps << endl;
        outFile.close();
    }

}