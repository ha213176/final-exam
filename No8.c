#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct bst{
    char *key;
    struct bst *r_next, *l_next;
}BST;


BST * add(BST *root, char *buf, int len);
BST *makeNoed(char *buf, int len);
void inorder(BST *node);
void nodeFree(BST *node);

int main(){
    BST *root = NULL;
    char buf[1024];
    int len;
    while(fgets(buf, 1024, stdin) != NULL){
        len = strlen(buf);
        if(buf[len-1] == '\n'){
            buf[len-1] = '\0';
            len--;
        }
        root = add(root, buf, len);
    }
    inorder(root);
    nodeFree(root);
    return 0;
}


BST *add(BST *root, char *buf, int len){
    BST *ptr = root, *qtr = root;
    int d = 0;
    if(root == NULL){
        root = makeNoed(buf, len);
        return root;
    }
    else{
        while(ptr != NULL){
            if(strcmp(ptr->key, buf) > 0){
                qtr = ptr;
                ptr = ptr->l_next;
                d = 0;
            }
            else if(strcmp(ptr->key, buf) < 0){
                qtr = ptr;
                ptr = ptr->r_next;
                d = 1;
            }
            else{
                return root;
            }
        }
    }
    if(d == 0){
        qtr->l_next = makeNoed(buf, len);
    }
    else{
        qtr->r_next = makeNoed(buf, len);
    }
    return root;
}

BST *makeNoed(char *buf, int len){
    BST *node = malloc(sizeof(BST));
    node->r_next = NULL;
    node->l_next = NULL;
    node->key = malloc((len+1)*sizeof(char));
    strncpy(node->key, buf, len+1);
    return node;
}

void inorder(BST *node){
    if(node != NULL){
        inorder(node->l_next);
        printf("%s\n", node->key);
        inorder(node->r_next);
    }
    return;
}

void nodeFree(BST *node){
    if(node != NULL){
        nodeFree(node->l_next);
        nodeFree(node->r_next);
        free(node->key);
        free(node);
    }
    return;
}
