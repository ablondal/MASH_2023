#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

vector<bool> wins(1LL<<32, 0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll state = 0;
    rep(i,0,32){
        auto c = getchar();
        if (c == '!') {
            state ^= (1LL << i);
        }
    }
    

}