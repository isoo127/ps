#include <stdio.h>
#include <string.h>
using namespace std;

int M;
int S[21];

int main() {
    scanf("%d", &M);

    char cmd[10]; int x;
    for(int i = 0; i < M; i++) {
        scanf("%s", cmd);
        scanf("%d", &x);
        if(!strcmp(cmd, "add")) {
            S[x] = 1;
        } else if(!strcmp(cmd, "remove")) {
            S[x] = 0;
        } else if(!strcmp(cmd, "check")) {
            if(S[x]) printf("1\n");
            else printf("0\n");
        } else if(!strcmp(cmd, "toggle")) {
            if(S[x]) S[x] = 0;
            else S[x] = 1;
        } else if(!strcmp(cmd, "all")) {
            for(int j = 1; j <= 20; j++) S[j] = 1;
        } else if(!strcmp(cmd, "empty")) {
            for(int j = 1; j <= 20; j++) S[j] = 0;
        }
    }

    return 0;
}