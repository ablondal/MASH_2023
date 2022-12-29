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
const double range = 1e5;
const int n = 100000;
const double pi = acos(-1);
const double eps = 5e-2; // 0 but with some breathing room

unordered_map<long long, vector<int> > M;
vector<cd> pts;
double g_siz;
int r;

int try_add(cd n_pt, int j, bool override=0){
    // Since C++ unordered_maps don't like tuples, we'll translate the
    // grid point (x, y) into x + y * 1e9.
    // Each coordinate cannot exceed 1e5 due to bowling ball radius
    // restrictions, so this mapping should be unique.
    // Note also that no balls overlap, so we should have at most about 2 or 3
    // balls per grid position.
    const long long P = 1e9;

    // For each ball, check for collisions with previous balls.
    // There are only 9 positions, so at most about 20 collision checks.
    // Gives an O(n) solution!
    // Make sure to use floor to account for negative numbers
    long long x = floor(n_pt.real() / g_siz);
    long long y = floor(n_pt.imag() / g_siz);

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
    // Check collisions
    if (!override){
        for(auto i: possible_collisions){
            // Why I like complex numbers for points: makes simple things simple
            double dist_sq = norm(pts[i]-n_pt);
            // cout << i << " " << j << " " << dist_sq << endl;
            double dist = sqrt(dist_sq);
            if (dist - 2*r <= r/100){
                return 0;
            }
        }
    }
    // If no collisions:
    // Add point to its grid box
    M[x + P*y].push_back(j);
    return 1;
}

int main() {
    random_device rd;
    mt19937 e2(rd());
    // uniform_real_distribution<> dist(0, 10);
    uniform_real_distribution<double> distrib(-range, range);
    uniform_real_distribution<double> distribang(-pi, pi);
    uniform_int_distribution<> d3(0, int(range)/1000);
    r = d3(e2);
    g_siz = 2.5*r;
    auto rand = bind(distrib, e2);
    auto randang = bind(distribang, e2);


    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// vector<cd> pts;
    cd p1 = {rand(), rand()};
    cd p2 = p1 + polar<double>(2*r, randang());
    pts.push_back(p1); pts.push_back(p2);
    try_add(p1, 0, 1);
    try_add(p2, 1, 1);

    int tt = 0;

    while(sz(pts) < n && tt < n){
        cd npt = {rand(), rand()};
        if (try_add(npt, sz(pts))) {
            pts.push_back(npt);
        }
        tt++;
    }
    cout << r << " " << sz(pts) << endl;
    uniform_int_distribution<> d2(0, sz(pts)-1);

    rep(i,0,2*n){
        int a = d2(e2);
        int b = d2(e2);
        swap(pts[a], pts[b]);
    }
    for(auto pt: pts){
        printf("%.6lf %.6lf\n", real(pt), imag(pt));
        // cout << real(pt) << " " << imag(pt) << endl;
    }
}