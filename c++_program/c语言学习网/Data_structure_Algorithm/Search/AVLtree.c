/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-01 19:49:43
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-01 20:29:16
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\Search\AVLtree.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<stdlib.h>
#define max(a,b) a>b ? a:b

//AVL tree node设计
typedef struct Node{
    int key; //data
    struct Node *left;
    struct Node *right; 
    int height; // AVL树的深度
} BTNode;

//返回结点的深度
int height(BTNode *N){
    if (N == NULL)
        return 0;
    return N->height;
}

//新建Node
BTNode* newNode(int key){
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

 //LL调整
 BTNode* ll_rotate(BTNode* y){
    BTNode *x = y->left; //新建x赋值为y的L
    y->left = x->right; //y的L变为x的R
    x->right = y; //x的R变为y
    
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
 }

 //RR调整
 BTNode* rr_rotate(BTNode* y){
    BTNode *x = y->right;
    y->right = x->left;
    x->left = y;

    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
 }

 //判断平衡
 int getBalance(BTNode *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
 }

 //插入node
 BTNode* insert(BTNode* node, int key){
    if (node == NULL){
        return newNode(key); //如果是空的树，直接新建一个node当做数
    }
    if (key < node->key){
        node->left = insert(node->left,key);
    }
    else if (key >= node->key){
        node->right = insert(node->right, key);
    }
    else{
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key){ //LL
        return ll_rotate(node);
    }
    if (balance < -1 && key < node->right->key){ //RR
        return rr_rotate(node);
    }
    if (balance > 1 && key > node->left->key){ //LR
        node->left = rr_rotate(node->left);
        return ll_rotate(node);
    }
    if (balance < -1 && key > node->right->key){ // RL
        node->right = ll_rotate(node->right);
        return rr_rotate(node);
    }
    return node;
 }

 //遍历
void preOrder(BTNode *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(BTNode * root) {
    if (root != NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
  
int main() {
    BTNode *root = NULL;
  
    root = insert(root, 90);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
  
    printf("pre order: ");
    preOrder(root);
    printf("\n");
    inOrder(root);
    return 0;
}