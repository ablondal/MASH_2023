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

int main() {
    srand(time(NULL));
    vector<int> primes;
    for(int i = 2; i < 100; i++){
        bool isPrime = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0) {
                isPrime = false;
            }
        }
        if(isPrime){
            primes.push_back(i);
        }
    }
    int numTests = 50;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        int p = primes[randRange(0, primes.size() - 1)]; 
        int n = randRange(1, 1000);
        int m = randRange(1, 1000);
        if(z % 4 == 0){
            n = p * randRange(1, 1000 / p);
        }else if(z % 2 == 0){
            m = p * randRange(1, 1000 / p);
        }
        inFile << n << " " << m << " " << p << endl;
        inFile.close();
        ofstream outFile(getOutputName(z + 1));
        if(n % p == 0 || m % p == 0){
            outFile << "YES" << endl;
        }else{
            outFile << "NO" << endl;
        }
        outFile.close();
    }

}