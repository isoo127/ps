#include <iostream>
#include <string>
using namespace std;

bool isGroup(string word) {
    string target = "#" + word;
    string set = "";
    for(int i = 1; i <= word.size(); i++) {
        if(target.at(i) != target.at(i - 1)) {
            if(set.find(target.at(i)) == string::npos)
                set += target.at(i);
            else
                return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if(isGroup(input))
            cnt++;
    }
    cout << cnt;
    
    return 0;
}