#include <stdio.h>
#include <stdlib.h>

/*
    Binary Tree Structure:
          1         
        /   \
       2     3       
      / \   / \
     4   5 6   7     
*/

struct node {
    int val;
    struct node *L;
    struct node *R;
};

// function to create a new node
struct node* build(int d) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->val = d;
    n->L = NULL;
    n->R = NULL;
    return n;
}

// Pre-order traversal: Root -> Left -> Right
void pre_order(struct node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->val);
    pre_order(root->L);
    pre_order(root->R);
}

int main() {
    // Creating the root and branches
    struct node* root = build(1);

    root->L = build(2);
    root->L->L = build(4);
    root->L->R = build(5);

    root->R = build(3);
    root->R->L = build(6);
    root->R->R = build(7);

    printf("Pre-order: ");
    pre_order(root);

    return 0;
}
