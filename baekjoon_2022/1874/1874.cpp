#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int> s;
    s.push(0);

    vector<int> nums;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }

    string result = "";
    for(int i = 0, j = 1; i < N; i++) {
        for(; j <= N * 2; j++) {
            if(s.top() == nums.at(i)) {
                result += "-\n"; s.pop();
                break;
            } else if(s.top() < nums.at(i)) {
                result += "+\n"; s.push(j);
            } else {
                cout << "NO"; return 0;
            }
        }
    }
    cout << result;

    return 0;
}