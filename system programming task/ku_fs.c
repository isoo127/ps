#include "ku_fs_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct output {
    struct output* next;
    int data;
} output;

int* makeStates(char* str) {
    int* state = (int*)malloc(sizeof(int) * (strlen(str) + 1));
    state[0] = -1; state[1] = 0;
    int ptr = 0;
    for(int i = 2; i <= strlen(str); i++) {
        while(ptr > 0 && str[ptr] != str[i - 1])
            ptr = state[ptr];
        if(str[ptr] == str[i - 1]) {
            state[i] = ++ptr;
        } else {
            state[i] = 0;
        }
    }
    return state;
}

void findStr(output* head, char* str, int* state, int start, int end) {
    output* last = head;
    int idx = start, s = 0;
    while(idx < end && input[idx] != 0) {
        while(1) {
            if(input[idx] == str[s]) {
                if(++s == strlen(str)) {
                    output* temp = (output *)malloc(sizeof(output));
                    temp->next = NULL;
                    temp->data = idx - strlen(str) + 1;
                    last->next = temp;
                    last = temp;
                } 
                break;
            } else {
                if(state[s] == -1) break;
                else s = state[s];
            }
        }
        idx++;
    }
    if(s != 0) {
        while(input[idx] != 0) {
            if(input[idx] == str[s]) {
                if(++s == strlen(str)) {
                    output* temp = (output *)malloc(sizeof(output));
                    temp->next = NULL;
                    temp->data = idx - strlen(str) + 1;
                    last->next = temp;
                    last = temp;
                }
            } else break;
            idx++;
        }
    }
}

void child(char* str, int* state, int start, int end) {
    output head; head.next = NULL; head.data = -1;
    findStr(&head, str, state, start, end);

    output* ptr = head.next;
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        output* temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    fflush(stdout);
    exit(start);
}

int main(int argc, char* argv[]) {
    char* substring = argv[1];
    int process_cnt = atoi(argv[2]);
    double range = (double)MAXS / process_cnt;
    pid_t* child_pid = (pid_t*)malloc(sizeof(pid_t) * process_cnt);
    int child_status;
    int* state = makeStates(substring);

    for(int i = 0; i < process_cnt; i++) {
        if((child_pid[i] = fork()) == 0) {
            child(substring, state, (int)(range * i), (int)(range * (i + 1)));
        }
    }
    for(int i = 0; i < process_cnt; i++) {
        pid_t wpid = waitpid(child_pid[i], &child_status, 0);
        if (WIFEXITED(child_status))
            printf("Child %d terminated with exit status %d\n", wpid, WEXITSTATUS(child_status));
        else
            printf("Child %d terminated abnormally\n", wpid);
    }

    free(state);
    free(child_pid);
    return 0;
}