#include <iostream>
using namespace std;

int W[101];
int V[101];
int KM[101][100001];
int N;

int main() {
    int K; cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
             if (j - W[i] >= 0) KM[i][j] = max(KM[i - 1][j], KM[i - 1][j - W[i]] + V[i]);
			 else KM[i][j] = KM[i - 1][j];
        }
    }
    cout << KM[N][K];

    return 0;
}