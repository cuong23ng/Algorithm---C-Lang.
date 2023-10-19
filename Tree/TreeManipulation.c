#include <stdio.h>
#include <string.h>

typedef struct TreeNode{
    int id;
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
}TreeNode;
TreeNode* root;

TreeNode* MakeNode(int u){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->id = u;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void MakeRoot(int u){
    root = MakeNode(u);
}

TreeNode* Find(int v, TreeNode* root){
    if(root == NULL) return NULL;
    if(root->id == v) return root;

    TreeNode* p = Find(v, root->firstChild);
    if(p != NULL) return p;

    p = Find(v, root->nextSibling);
    return p;
}


void Insert(int u, int v){
    TreeNode* Parent = Find(v, root);

    if(Parent == NULL){
        printf("1");
        return;
    }

    TreeNode* newNode = MakeNode(u);
    if(Parent->firstChild == NULL)Parent->firstChild = newNode;
    else{
        TreeNode* rightmost = Parent->firstChild;
        while(rightmost->nextSibling != NULL)rightmost = rightmost->nextSibling;
        rightmost->nextSibling = newNode;
    }
}

void PreOrder(TreeNode* root){
    if(root == NULL) return;

    printf("%d ", root->id);

    TreeNode* p = root->firstChild;
    while(p != NULL){
        PreOrder(p);
        p = p->nextSibling;
    }
}

void PostOrder(TreeNode* root){
    if(root == NULL) return;
    TreeNode* p = root->firstChild;
    while(p != NULL){
        PostOrder(p);
        p = p->nextSibling;
    }
    printf("%d ", root->id);
}

void InOrder(TreeNode* root){
    if(root == NULL) return;
    TreeNode* p = root;
    if(p->firstChild == NULL){
        printf("%d ", p->id);
        return;
    }

    InOrder(p->firstChild);
    printf("%d ", p->id);
    p = p->firstChild->nextSibling;
    while(p != NULL){
        InOrder(p);
        p = p->nextSibling;
    }
}

int main(){
    char cmd[20];
    do{
        fflush(stdin);
        scanf("%s", &cmd);
        if(!strcmp(cmd, "MakeRoot")){
            int id;
            scanf("%d", &id);
            MakeRoot(id);
        }
        else if(!strcmp(cmd, "Insert")){
            int id, pa;
            scanf("%d%d", &id, &pa);
            Insert(id, pa);
        }
        else if(!strcmp(cmd, "InOrder")){
            InOrder(root);
            printf("\n");
        }
        else if(!strcmp(cmd, "PreOrder")){
            PreOrder(root);
            printf("\n");
        }
        else if(!strcmp(cmd, "PostOrder")){
            PostOrder(root);
            printf("\n");
        }
    }while(strcmp(cmd, "*"));
    return 0;
}
