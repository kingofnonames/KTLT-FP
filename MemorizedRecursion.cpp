#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int N, S;
long long z = 0;

long long dp[102][1002][1002];
int TRY(int k, int tmpSum, int start){

    ++z;
    if(k == 0){
        return (tmpSum == 0);
    }
    if(dp[k][tmpSum][start] != -1)
        return dp[k][tmpSum][start];

    long long res = 0;

    for(int i = start; i <= S; i += 2){

        if(tmpSum - i >= 0){

            res += TRY(k - 1, tmpSum - i, i);
            res %= MOD;
        }
    }

    return dp[k][tmpSum][start] = res;
}

int main(){

    cin >> N >> S;

    memset(dp, -1, sizeof(dp));
    auto startTime =
        chrono::high_resolution_clock::now();
    cout << TRY(N, S, 1) << endl;
    auto endTime =
        chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << z;
    cout << endl << "Time taken: " << duration.count() << " milliseconds";

}