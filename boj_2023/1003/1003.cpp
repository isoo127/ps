#include <iostream>
#define MAX_NUM 41
using namespace std;

int N;
int num[1000000];
int fib[MAX_NUM][2];

int main() {
    fib[0][0] = 1; fib[0][1] = 0;
    fib[1][0] = 0; fib[1][1] = 1;
    for(int i = 2; i < MAX_NUM; i++) {
        fib[i][0] = fib[i-1][0] + fib[i-2][0];
        fib[i][1] = fib[i-1][1] + fib[i-2][1];
    }

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < N; i++) {
        cout << fib[num[i]][0] << " " << fib[num[i]][1] << endl;
    }

    return 0;
}