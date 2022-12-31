#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> cards(n);
    for(int i = 0; i < n; i++){
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
    ll answer = 0;
    for(int i = 0; i < k; i++){
        ll diff = cards[n - k + i] - cards[i];
        answer += diff * diff;
    }
    cout << answer << endl;
}