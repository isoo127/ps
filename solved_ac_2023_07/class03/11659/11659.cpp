#include <iostream>
using namespace std;

int num[100001];
long long int sum[100001];
int range[100001][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
    }
    for(int i = 1; i <= M; i++) {
        cin >> range[i][0] >> range[i][1];
    }

    for(int i = 1; i <= M; i++) {
        long long int n = sum[range[i][1]] - sum[range[i][0] - 1];
        cout << n << "\n";
    }

    return 0;
}