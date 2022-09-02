#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    string result = "";
    for(int i = 0; i < N; i++) {
        string text;
        cin >> text;

        int stack = 0;
        for(int j = 0; j < text.length(); j++) {
            if(text.at(j) == '(') stack++;
            else if(text.at(j) == ')')
                if(stack > 0) stack--;
                else { stack = - 1; break; }
        }
        if(stack == 0) result += "YES\n";
        else result += "NO\n";
    }
    cout << result;

    return 0;
}