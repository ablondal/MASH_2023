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

int n, w1, w2;
vector<pair<int,int>> busses;
int initialTime;

int getArrivalTime(int startTime) {
    int curTime = startTime + w1;
    for(int i = 0; i < n; i++){
        int frequency = busses[i].first;
        int length = busses[i].second;
        int start;
        if(curTime % frequency == 0){
            start = curTime;
        }else{
            start = frequency * (curTime / frequency + 1);
        }
        curTime = start + length;
    }
    return curTime + w2;
}

int binarySearch(int l, int r) {
    if(l == r){
        return l;
    }
    int mid = (l + r + 1) / 2;
    if(getArrivalTime(mid) > initialTime) {
        return binarySearch(l, mid-1);
    }
    return binarySearch(mid, r);
}

int main() {
    srand(time(NULL));
    int numTests = 50;
    for(int z = 0; z < numTests; z++){
        busses.clear();
        ofstream inFile(getInputName(z + 1));
        if(z < numTests - 3) {
            n = randRange(1, 1e3);
        }else{
            n = 1e5;
        }
        w1 = randRange(1, 1e3);
        w2 = randRange(1, 1e3);
        inFile << n << " " << w1 << " " << w2 << endl;
        for(int i = 0; i < n; i++){
            int a = randRange(1, 1e3);
            int b = randRange(1, 1e3);
            busses.push_back({a, b});
            inFile << a << " " << b << endl;
        }
        inFile.close();
        initialTime = getArrivalTime(0);
        ofstream outFile(getOutputName(z + 1));
        outFile << binarySearch(0, 1e9) << endl;
        outFile.close();
    }

}