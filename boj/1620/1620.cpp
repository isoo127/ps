#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<int, string> m1;
map<string, int> m2;
string str[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    
    string name; 
    for(int i = 1; i <= N; i++) {
        cin >> name;
        m1.insert(make_pair(i, name));
        m2.insert(make_pair(name, i));
    }

    int num;
    for(int i = 0; i < M; i++) {
        cin >> str[i];
    }
    for(int i = 0; i < M; i++) {
        try {
            num = stoi(str[i]);
            cout << m1.find(num)->second << "\n";
        } catch(invalid_argument) {
            cout << m2.find(str[i])->second << "\n";
        }
    }

    return 0;
}