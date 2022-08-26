#include <iostream>
#include <string>
using namespace std;

const int SIZE = 123456 * 2 + 1;
bool nums[SIZE] = {true, true};
int p[SIZE];

int main() {
    int idx = 0;
    for(int i = 2; i < SIZE; i++) {
        if(!nums[i]) {
            for(int j = 2; j * i < SIZE; j++) {
                nums[j * i] = true;
            }
            p[idx] = i;
            idx++;
        }
    }

    int input;
    string result = "";
    while(true) {
        cin >> input;
        if(input == 0)
            break;

        int cnt = 0;
        int pos = 0;
        while(p[pos] <= input * 2) {
            if(p[pos] > input) 
                cnt ++;
            pos++;
        }
        result += to_string(cnt) + "\n";
    }
    cout << result;

    return 0;
}