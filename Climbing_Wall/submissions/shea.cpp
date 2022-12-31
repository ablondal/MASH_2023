#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h+2);
    for(int i = 0; i < h+2; i++){
        cin >> grid[i];
    }
    vector<vector<int>> dp(h+2, vector<int>(w + 2, 1e9));
    int answer = 1e9;
    for(int i = h+1; i >= 0; i--){
        for(int j = 0; j < w+2; j++){
            if(j == 0 || j == w + 1){
                continue;
            }
            if(i == h+1){
                dp[i][j] = 0;
            }
            if(dp[i][j] == 1e9){
                continue;
            }
            for(int k = -5; k <= 5; k++){
                for(int l = 1; l <= 5; l++){
                    if(k * k + l * l > 25){
                        continue;
                    }
                    if(j + k < 1 || j + k >= w + 1 || i - l < 0){
                        continue;
                    }
                    if(isdigit(grid[i-l][j+k])) {
                        dp[i-l][j+k] = min(dp[i-l][j+k], dp[i][j] + (grid[i-l][j+k] - '0'));
                    }
                    if(i - l == 0){
                        answer = min(answer, dp[i][j]);
                    }
                }
            }
        }
    }
    if(answer == 1e9){
        cout << -1 << endl;
    }else{
        cout << answer << endl;
    }
}