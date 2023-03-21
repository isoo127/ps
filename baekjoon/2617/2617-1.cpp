#include <iostream>
#include <malloc.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _Node {
    int n;
    struct _Node* next;
} Node;

typedef struct {
    Node* lighter;
    Node* heavier;
} Weight;

Weight w[100];
int cnt_l[100];
int cnt_h[100];

void link(int a, int b) {
    Node* temp = w[a].lighter;
    Node* node = (Node*)malloc(sizeof(Node));
    node->n = b; node->next = temp;
    w[a].lighter = node;

    temp = w[b].heavier;
    node = (Node*)malloc(sizeof(Node));
    node->n = a; node->next = temp;
    w[b].heavier = node;
}

int DFS(int n, bool compLighter) {
    int cnt = 0; Node* tmp;
    if(compLighter) tmp = w[n].lighter;
    else tmp = w[n].heavier;

    if(tmp == NULL) return cnt;
    while(tmp != NULL) {
        cnt++;
        if(compLighter) {
            if(!cnt_l[tmp->n]) cnt += DFS(tmp->n, compLighter);
            else cnt += cnt_l[tmp->n];
        } else {
            if(!cnt_h[tmp->n]) cnt += DFS(tmp->n, compLighter);
            else cnt += cnt_h[tmp->n];
        }
        tmp = tmp->next;
    }
    if(compLighter) cnt_l[n] = cnt;
    else cnt_h[n] = cnt;

    return cnt;
}

bool check(int n, int comp) {
    int l = DFS(n, true); 
    int h = DFS(n, false);
    return l > comp || h > comp;
}

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> v;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < v.size(); i++) {
        link(v.at(i).first, v.at(i).second);
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(check(i, (N - 1) / 2)) cnt++;
    }
    cout << cnt;

    return 0;
}