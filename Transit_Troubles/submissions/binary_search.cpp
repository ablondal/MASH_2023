#include <bits/stdc++.h>
using namespace std;

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
    cin >> n >> w1 >> w2;
    for(int i = 0; i < n; i++){
        int frequency, length;
        cin >> frequency >> length;
        busses.push_back({frequency, length});
    }
    initialTime = getArrivalTime(0);
    cout << binarySearch(0, 1e9) << endl;
}