#include <iostream>
using namespace std;

long long K, N; 
long long ran[10001];

int bs(long long min, long long max) {
    //cout << min << ", " << max << endl;
    if(min >= max) return max;
    long long mid = (max + min) / 2;
    long long tmp = 0;
    for(int i = 1; i <= K; i++) {
        tmp += ran[i] / mid;
    }
    if(tmp < N) return bs(min, mid - 1);
    tmp = 0;
    for(int i = 1; i <= K; i++) {
        tmp += ran[i] / (mid + 1);
    }
    if(tmp < N) return mid;
    else return bs(mid + 1, max);
}

int main() {
    cin >> K >> N;
    long long max = 0;
    for(int i = 1; i <= K; i++) {
        cin >> ran[i];
        max += ran[i];
    }
    max /= K;

    cout << bs(1, max);

    return 0;
}