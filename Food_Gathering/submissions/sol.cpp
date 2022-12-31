#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll=long long;

ll tot = 0;
vector<pair<int, ll>> G[1007];
bool fd[1007] = {0};

bool dfs(int c, int p=0){
    bool has_food = fd[c];
    for (auto& [e, d]: G[c]){
        if (e==p) continue;
        if (dfs(e, c)){
            has_food = true;
            tot += 2*d;
        }
    }
    return has_food;
}


int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n-1; ++i){
        int a, b;
        ll d;
        cin >> a >> b >> d;
        G[a].push_back({b, d});
        G[b].push_back({a, d});
    }
    for(int i=0; i<k; ++i){
        int f;
        cin >> f;
        fd[f] = true;
    }
    dfs(1);
    cout << tot << endl;
}