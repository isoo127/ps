#include <iostream>
#include <string>
using namespace std;

const int SIZE = 123456 * 2 + 1;
bool nums[SIZE] = {true, true};
int p[SIZE] = {2, 2};

int main() {
    int idx = 2;
    for(int i = 2; i < SIZE; i++) {
        if(!nums[i]) {
            for(int j = 2; j * i < SIZE; j++) {
                nums[j * i] = true;
            }
            p[idx] = i;
            idx = i;
        }
    }

    int input;
    string result = "";
    while(true) {
        cin >> input;
        if(input == 0)
            break;

        int cnt = 0;
        int pos = 2;
        while(pos <= input * 2) {
            if(pos > input) 
                cnt ++;
            pos = p[pos];
        }
        result += to_string(cnt) + "\n";
    }
    cout << result;

    return 0;
}