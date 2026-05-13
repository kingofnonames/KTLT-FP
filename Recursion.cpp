#include <bits/stdc++.h>
using namespace std;
int N, S;
int z = 0;
const int MOD = 1e9 + 7;
long long TRY(long long k, long long tmpSum, long long start){
    ++z;
    if(k == 0) return (tmpSum == 0) ? 1 : 0;
    long long res = 0;
    for(long long i = start; i <= S; i += 2){
        if(k > 0 && tmpSum - i >= 0) res =  (res + TRY(k - 1, tmpSum - i, i)) % MOD;
    }
    return res;
}

int main(){
    cin >> N >> S;
    auto startTime =
        chrono::high_resolution_clock::now();
    cout << TRY(N, S, 1);
    auto endTime =
        chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << endl << z;
    cout << endl << "Time taken: " << duration.count() << " milliseconds";
}