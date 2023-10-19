#include <stdio.h>
#include <string.h>

typedef struct TreeNode{
    int id;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
}TreeNode;
TreeNode* root = NULL;

TreeNode* MakeNode(int u){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->id = u;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void Insert(int id){
    if(root == NULL) {
        root = MakeNode(id);
        return;
    }
    TreeNode* p = root;
    while(1){
        if(p->id > id){
            if(p->leftChild == NULL){
                p->leftChild = MakeNode(id);
                return;
            }
            p = p->leftChild;
        }
        else if(p->id < id){
            if(p->rightChild == NULL){
                p->rightChild = MakeNode(id);
                return;
            }
            p = p->rightChild;
        }
        else return;
    }
}

void PreOrder(TreeNode* root){
    if(root == NULL)return;

    printf("%d ", root->id);

    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}

int main(){
    char cmd[20];
    int id;
    while(1){
        fflush(stdin);
        scanf("%s", cmd);
        if(!strcmp(cmd, "#"))break;

        scanf("%d", &id);
        Insert(id);
    }
    PreOrder(root);
    return 0;
}
