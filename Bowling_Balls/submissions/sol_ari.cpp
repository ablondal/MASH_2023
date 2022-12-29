#include <cmath> // fmod
#include <vector> // vector
#include <complex> // complex numbers as 2d points
#include <utility> // pair
#include <iostream> // cin, cout
#include <unordered_map> // Unordered map (hash map)
using namespace std;
// using cd = complex<double>;
// using ll = long long;
const double eps = 1e-3; // 0 but with some breathing room

pair<int, int> solve(double r, int n, vector<complex<double> > &pts){
    // Store the bowling balls in a grid, check only for collisions
    // within the 9 grid spaces adjascent.
    // Make the grid size large enough so that only the 3x3 around
    // each ball needs to be checked.
    double g_siz = (2.5 * r);

    // Since C++ unordered_maps don't like tuples, we'll translate the
    // grid point (x, y) into x + y * 1e9.
    // Each coordinate cannot exceed 1e5 due to bowling ball radius
    // restrictions, so this mapping should be unique.
    // Note also that no balls overlap, so we should have at most about 2 or 3
    // balls per grid position.
    long long P = 1e9;
    unordered_map<long long, vector<int> > M;

    // For each ball, check for collisions with previous balls.
    // There are only 9 positions, so at most about 20 collision checks.
    // Gives an O(n) solution!
    for(int j=1; j<=n; j++){
        // Make sure to use floor to account for negative numbers
        long long x = floor(pts[j].real() / g_siz);
        long long y = floor(pts[j].imag() / g_siz);

        // Check collisions with all previous balls (smaller index)
        vector<int> possible_collisions;
        for(int dx=-1; dx<2; dx++){
            for(int dy=-1; dy<2; dy++){
                auto it = M.find((x+dx) + P*(y+dy));
                // If there are any balls in this space, check all of them.
                if (it != M.end()){
                    for(auto index: it->second){ // auto is my friend
                        possible_collisions.push_back(index);
                    }
                }
            }
        }
        // Add point to its grid box
        M[x + P*y].push_back(j);

        // Check collisions
        for(auto i: possible_collisions){
            // Why I like complex numbers for points: makes simple things simple
            double dist_sq = norm(pts[i]-pts[j]);
            // cout << i << " " << j << " " << dist_sq << endl;
            if (dist_sq - (4*r*r) < eps){
                return {i, j};
            }
        }
    }

    return {0, 0};
}

int main(){
    double r;
    int n;
    cin >> r >> n;
    vector<complex<double> > pts(n+1);
    for(int i=1; i<=n; i++){
        double x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    auto [i1, i2] = solve(r, n, pts); // Ever wanted to do Python unpacking in c++?
    cout << i1 << " " << i2 << endl;
}