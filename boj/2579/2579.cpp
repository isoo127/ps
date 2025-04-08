#include <iostream>
using namespace std;

int stairs[301];
int scores_1[301], scores_2[301];
int N;

int score(int before, int now) {
    if(now > N) return -10000000;
    else if(now == N) return stairs[now];

    int ans = 0;
    if(now - before == 1) {
        if(scores_1[now]) return scores_1[now];
        ans = score(now, now + 2) + stairs[now];
        scores_1[now] = ans;
    }
    else {
        if(scores_2[now]) return scores_2[now];
        ans = score(now, now + 1) + stairs[now];
        int tmp = score(now, now + 2) + stairs[now];
        if(ans < tmp) ans = tmp;
        scores_2[now] = ans;
    }
    return ans;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> stairs[i];

    int a = score(0, 2);
    int b = score(-1, 1);
    if(a < b) cout << b;
    else cout << a;

    return 0;
}