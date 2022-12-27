#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<int,int> portals;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        portals[a] = b;
        portals[b] = a;
    }
    int steps = 0;
    int pos = 0;
    while(pos != x) {
        pos++;
        steps++;
        if(portals.count(pos) != 0){
            pos = portals[pos];
        }
    }
    cout << steps << endl;
}