#include <iostream>
using namespace std;

int N, M;
int p[51];
int party_num[51];
int party[51][51];

int findSet(int a) {
    if(p[a] == a) return a;
    return p[a] = findSet(p[a]);
}

void merge(int a, int b) {
    int sa = findSet(a), sb = findSet(b);
    if(a > b) p[sa] = sb;
    else p[sb] = sa;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) p[i] = i;
    int pn; cin >> pn; 
    int ls;
    if(pn == 0) {
        cout << M; return 0;
    }
    cin >> ls;
    for(int i = 2; i <= pn; i++) {
        int tmp; cin >> tmp;
        merge(ls, tmp);
    }

    for(int i = 1; i <= M; i++) {
        cin >> party_num[i];
        int x; cin >> party[i][1];
        for(int j = 2; j <= party_num[i]; j++) {
            cin >> party[i][j];
            merge(party[i][1], party[i][j]);
        }
    }

    int ans = M;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= party_num[i]; j++) {
            if(findSet(ls) == findSet(party[i][j])) {
                ans--;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}