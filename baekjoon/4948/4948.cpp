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
    int cases;
    string result = "";

    while(true) {
        cin >> cases;
        if(cases == 0)
            break;
        
        int cnt = 0;
        for(int i = 2; i <= cases * 2; i++) {
            if(i * i <= cases * 2 && !nums[i])
                seize(i);
            if(i > cases && !nums[i])
                cnt++;
        }
        result += to_string(cnt) + "\n";
    }

    cout << result;

    return 0;
}