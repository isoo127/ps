#include <iostream>
using namespace std;

int nums[1001];
int mins[1001];

void min(int x) {
    int tmp = nums[x];
    mins[x] = nums[x];
    for(int i = 0; i <= x/2; i++) {
        if(tmp > mins[i] + mins[x - i])
            tmp = mins[i] + mins[x - i];
    }
    mins[x] = tmp;
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> nums[i];
    for(int i = 1; i <= N; i++) min(i);
    cout << mins[N];

    return 0;
}