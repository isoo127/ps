#include <iostream>
#include <vector>
using namespace std;

int p[201], parent[201];
int N, M;

int findSet(int a) {
    if(parent[a] == a) return a;
    return parent[a] = findSet(parent[a]);
}

void merge(int a, int b) {
    int sa = findSet(a), sb = findSet(b);
    if(a > b) parent[sa] = sb;
    else parent[sb] = sa;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i <= 200; i++) parent[i] = i;
	for (int tmp, i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1) merge(i, j);
		}
	}

	int past, now;
	bool canTrip = true;
	cin >> past;

	for (int i = 1; i < M; i++) {
		cin >> now;
		if (!canTrip) continue;
		if (findSet(past) != findSet(now)) canTrip = false;
		past = now;
	}

	if (canTrip) cout << "YES";
	else cout << "NO";
}