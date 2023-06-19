#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct node {
    int key;
    node* parent;
    node* left;
    node* right;
} typedef node;

node head; node* now;

void insert(int key) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->key = key; tmp->left = NULL; tmp->right = NULL;
    if(now->key > key) {
        now->left = tmp;
        tmp->parent = now;
        now = tmp;
    } else {
        while(now->key < key) now = now->parent;
        now->left->right = tmp;
        tmp->parent = now->left;
        now = tmp;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    head.key = 1000001; head.right = NULL; now = &head;
    int key; while(cin >> key) insert(key);

    stack<node*> s;
    s.push(&head); 
    while(!s.empty()) {
        now = s.top();
        if(now->left == NULL && now->right == NULL) {
            if(now == &head) break;
            cout << now->key << endl; s.pop();
            if(now->parent->right != now) {
                if(now->parent->right != NULL) s.push(now->parent->right);
                now->parent->left = NULL;
            } else now->parent->right = NULL;
            free(now);
        } else {
            if(now->left != NULL) { 
                now = now->left;
                s.push(now);
            } else {
                now = now->right;
                s.push(now);
            }
        }
    } 

    return 0;
}
