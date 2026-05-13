#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    int  N, S;
    cin >> N >> S;
    vector<vector<long long>> A(1007, vector<long long>(1007, 0));
    A[0][0] = 1;
    auto startTime =
        chrono::high_resolution_clock::now();
    for(int i = 1; i <= S; i += 2){
        for(int j = 1; j <= N; ++j){
            for(int sum = i; sum <= S; ++sum){
                A[j][sum] = (A[j][sum] + A[j - 1][sum - i]) % MOD;
            }
        }
    }
    auto endTime =
        chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << A[N][S] % MOD;
    cout << endl << "Time taken: " << duration.count() << " milliseconds";

}