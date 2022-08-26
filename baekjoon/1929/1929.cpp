#include <iostream>
#include <string>
using namespace std;

const int SIZE = 1e6 + 1;
bool nums[SIZE] = {true, true};

void seize(int x) {
    if(nums[x])
        return;
    for(int i = 2; i * x < SIZE; i++) {
        nums[i * x] = true;
    }
    return;
}

int main() {
    int M, N;
    cin >> M >> N;

    string str = "";

    for(int i = 2; i <= N; i++) {
        if(i * i <= N)
            seize(i);
        if(i >= M && !nums[i])
            str += to_string(i) + "\n";
    }

    cout << str;

    return 0;
}