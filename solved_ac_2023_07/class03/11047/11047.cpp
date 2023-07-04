#include <iostream>
using namespace std;

int N, K;
int coin[11];

int main() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> coin[i];

    int ans = 0, tmp = N;
    while(K) {
        if(coin[tmp] <= K) {
            ans++; K -= coin[tmp];
        } else tmp--;
    }
    cout << ans;

    return 0;
}