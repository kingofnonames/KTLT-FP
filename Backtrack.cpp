#include <bits/stdc++.h>
using namespace std;

int N, S;
int cnt = 0;
int tmpSum = 0;
const int MOD = 1e9 + 7;
int a[107];

void print() {
    for (int i = 1; i <= N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void backtrack(int k, int start) {
    if (k > N) {
        if (tmpSum == S) {
            // print();
            cnt = (cnt + 1) % MOD;
        }
        return;
    }
    for (int i = start; i <= S; i += 2) {
        if (tmpSum + i > S)
            break;
        a[k] = i;
        tmpSum += i;
        backtrack(k + 1, i);
        tmpSum -= i;
    }
}

int main() {
    cin >> N >> S;
    auto startTime =
        chrono::high_resolution_clock::now();
    backtrack(1, 1);
    auto endTime =
        chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    cout << cnt << endl;
    cout << "Time taken: " << duration.count() << " milliseconds";
}