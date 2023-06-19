#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int now, click;
int btn[10];

int dim(int num) {
    if(num == 0) return 1;
    int cnt = 0;
    int tmp = num;
    while(tmp) {
        cnt++; tmp /= 10;
    }
    return cnt;
}

int ans(int num) {
    return abs(N - num) + dim(num);
}

bool available(int num) {
    int tmp = num;
    while(tmp) {
        int rest = tmp % 10;
        if(btn[rest]) return false;
        tmp /= 10;
    }
    return true;
}

int pos(int dim) {
    if(dim == 1 || dim == 0) return 0;
    int tmp = 1;
    for(int i = 1; i < dim; i++) {
        tmp *= 10;
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        btn[tmp] = 1;
    }
    now = 100; click = abs(N - now);

    int s = pos(dim(N) - 2);
    int e = pos(dim(N) + 3);
    for(int i = s; i <= e; i++) {
        if(available(i)) {
            if(click > ans(i)) click = ans(i);
        }
    }

    cout << click;

    return 0;
}