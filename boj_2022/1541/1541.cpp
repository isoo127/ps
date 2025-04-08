#include <iostream>
#include <vector>
using namespace std;

vector<string> parsing(const string& text) {
    vector<string> result;
    string num = "";
    for(int i = 0; i < text.length(); i++) {
        if(text.at(i) == '+' || text.at(i) == '-') {
            result.push_back(num);
            result.push_back(to_string(text.at(i)));
            num = "";
        } else if(i == text.length() - 1) {
            num += text.at(i);
            result.push_back(num);
        } else {
            num += text.at(i);
        }
    }
    return result;
}

int main() {
    string input;
    cin >> input;
    vector<string> elements = parsing(input);

    int result = 0;
    bool isNegative = false;
    for(int i = 0; i < elements.size(); i++) {
        if(i % 2 == 0) {
            if(!isNegative)
                result += stoi(elements.at(i));
            else
                result -= stoi(elements.at(i));
        } else {
            if(elements.at(i) == "-") {
                isNegative = true;
            }
        }
    }
    cout << result;

    return 0;
}