#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int ROW = 102;
const int COL = 102;
int arr[ROW][COL];
int visit[ROW][COL];

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = atoi(&tmp);
            visit[i][j] = atoi(&tmp);
        }
    }

    vector<pair<int, int>> nodes;
    pair<int, int> tmp; tmp.first = 1; tmp.second = 1;
    visit[1][1] = 0;
    nodes.push_back(tmp);
    
    int count = 1;
    while(true) {
        int size = nodes.size();
        int flag = 0;
        for(int i = 0; i < size; i++) {
            if(arr[nodes.at(i).first - 1][nodes.at(i).second] && visit[nodes.at(i).first - 1][nodes.at(i).second]) { // up
                visit[nodes.at(i).first - 1][nodes.at(i).second] = 0;
                nodes.push_back(make_pair(nodes.at(i).first - 1, nodes.at(i).second));
            } 
            if(arr[nodes.at(i).first + 1][nodes.at(i).second] && visit[nodes.at(i).first + 1][nodes.at(i).second]) { // down
                if(nodes.at(i).first + 1 == N && nodes.at(i).second == M) {
                    flag = 1;
                    break;
                }
                visit[nodes.at(i).first + 1][nodes.at(i).second] = 0;
                nodes.push_back(make_pair(nodes.at(i).first + 1, nodes.at(i).second));
            } 
            if(arr[nodes.at(i).first][nodes.at(i).second + 1] && visit[nodes.at(i).first][nodes.at(i).second + 1]) { // right
                if(nodes.at(i).first == N && nodes.at(i).second + 1 == M) {
                    flag = 1;
                    break;
                }
                visit[nodes.at(i).first][nodes.at(i).second + 1] = 0;
                nodes.push_back(make_pair(nodes.at(i).first, nodes.at(i).second + 1));
            } 
            if(arr[nodes.at(i).first][nodes.at(i).second - 1] && visit[nodes.at(i).first][nodes.at(i).second - 1]) { // left
                visit[nodes.at(i).first][nodes.at(i).second - 1] = 0;
                nodes.push_back(make_pair(nodes.at(i).first, nodes.at(i).second - 1));
            }
        }
        count++;
        if(flag) break;
        nodes.erase(nodes.begin(), nodes.begin() + size);
    }

    printf("%d", count);

    return 0;
}