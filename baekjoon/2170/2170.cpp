#include <iostream>
#include <limits.h>
#define LINE(x, y) *(lines + x * 2 + y)
#define BIGGER(x, y) (x > y) ? x : y
using namespace std;

int lines[1000000][2];
int container[1000000][2];
int N;

void integrateLines(int* lines, int start, int end) {
    if(start >= end) return;

    int mid = (start + end) / 2;
    integrateLines(lines, start, mid);
    integrateLines(lines, mid + 1, end);

    int i = start, j = mid + 1, k = start;
    if(LINE(i, 0) < LINE(j, 0)) {
        container[k][0] = LINE(i, 0);
        container[k][1] = LINE(i, 1);
        i++;
    } else {
        container[k][0] = LINE(j, 0);
        container[k][1] = LINE(j, 1);
        j++;
    }
    k++;

    while(i <= mid && j <= end) {
        while(LINE(i, 0) == INT_MIN && i <= mid) i++;
        while(LINE(j, 0) == INT_MIN && j <= end) j++;
        if(i > mid || j > end) break;
        if(LINE(i, 0) < LINE(j, 0)) {
            if(container[k-1][1] > LINE(i, 0)) {
                container[k-1][1] = BIGGER(container[k-1][1], LINE(i, 1));
            } else {
                container[k][0] = LINE(i, 0);
                container[k][1] = LINE(i, 1);
                k++;
            }
            i++;
        } else {
            if(container[k-1][1] > LINE(j, 0)) {
                container[k-1][1] = BIGGER(container[k-1][1], LINE(j, 1));
            } else {
                container[k][0] = LINE(j, 0);
                container[k][1] = LINE(j, 1);
                k++;
            }
            j++;
        }
    }

    if(i > mid) {
        for(; j <= end; j++) {
            while(LINE(j, 0) == INT_MIN && j <= end) j++;
            if(j > end) break;
            if(container[k-1][1] > LINE(j, 0)) {
                container[k-1][1] = BIGGER(container[k-1][1], LINE(j, 1));
            } else {
                container[k][0] = LINE(j, 0);
                container[k][1] = LINE(j, 1);
                k++;
            }
        }
    } else if(j > end) {
        for(; i <= mid; i++) {
            while(LINE(i, 0) == INT_MIN && i <= mid) i++;
            if(i > mid) break;
            if(container[k-1][1] > LINE(i, 0)) {
                container[k-1][1] = BIGGER(container[k-1][1], LINE(i, 1));
            } else {
                container[k][0] = LINE(i, 0);
                container[k][1] = LINE(i, 1);
                k++;
            }
        }
    }

    for(i = start; i < start + k; i++) {
        LINE(i , 0) = container[i][0];
        LINE(i , 1) = container[i][1];
    }
    for(i = start + k; i <= end; i++) {
        LINE(i, 0) = INT_MIN;
        LINE(i, 1) = INT_MIN;
    }

    return;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> lines[i][0] >> lines[i][1];
    }

    integrateLines((int*)lines, 0, N-1);

    int i = 0, length = 0;
    while(i < N && lines[i][0] != INT_MIN) {
        length += (lines[i][1] - lines[i][0]);
        i++;
    }
    cout << length;

    return 0;
}