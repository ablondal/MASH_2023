#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    if(n % p == 0 || m % p == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}