#include <bits/stdc++.h>
#define unsigned long long
using namespace std;

int N, banyak1 = 30, C[62][62], ans = 0;
string biner;
int mod = 1111111111111111111;

signed main () {
    cin >> N;
    for (int i = 0; i <= 60; i++) {
        C[i][0] = 1;
        for (int j = 1; j < min(i, 30); j++) {
            C[i][j] = (C[i-1][j-1]%mod + C[i-1][j]%mod) % mod;
            //cout << C[i][j] << " ";
        }
        C[i][i] = 1;
    } //cout << endl;
    for (int i = 1; i <= 30; i++) {
        biner += "1";
    }
    for (int i = 1; i <= 30;  i++) {
        biner += "0";
    }
    for (int i = banyak1-1; i >= 0; i--) {
        int idx = i, nilai = 0;
        while (N > nilai) {
            nilai += C[idx][i];
            if (nilai >= N) {
                nilai -= C[idx][i];
                break;
            }
            idx++;
        }
        N -= nilai;
        swap(biner[i], biner[idx]);
    }
    //cout << biner << endl;
    for (int i=0; i<biner.length(); i++) {
        if (biner[i] == '1') ans += 1ULL << i;
    }
    cout << ans << endl;
}