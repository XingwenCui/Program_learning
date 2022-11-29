/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-29 22:51:24
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-30 00:14:34
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\Tree\binarytree.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdlib.h>
#include<stdio.h>
// #include<iostream>

//Tree node
typedef struct node{
    int data;
    struct node * left;
    struct node * right;
} Node; //将名称定义为Node

//Root
typedef struct tree{
    Node * root;
} Tree;

//create tree:注意，这不是一个完全二叉树
void insert(Tree * tree, int value){
    //创建node，让其左右不为NULL，数据为value
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    //判断是不是NULL tree，如果是，直接让树根指向这个节点
    if (tree->root == NULL){
        tree->root = node;
    }
    else{//不是NULL tree
        Node* temp = tree->root; //从树根开始
        while (temp != NULL){
            if(value < temp->data){ //小于root就进左边
                if(temp->left == NULL){
                    temp->left = node;//如果左边是NULL，那直接把node赋给左边，这里temp代表树
                    return;
                }
                else{
                    //找不到继续向下搜索,即将temp的left赋给temp
                    temp=temp->left;
                }
            }
            else{//大于root进右边
                if(temp->right == NULL){
                    temp->right = node;
                    return;
                }
                else{
                    //继续向下搜素
                    temp = temp->right;
                }
            }
        }
    }
    return;
}

//遍历 in-order traversal用迭代方法
void inorder(Node * node){
    if (node != NULL){
        inorder(node->left); //先迭代左边
        printf("%d ",node->data); //输出node节点
        inorder(node->right); //最后右边
    }
}

//先序遍历root->left->right
void preorder(Node* node){
    if(node != NULL){
        printf("%d ",node->data); //先node data(root)
        preorder(node->left);
        preorder(node->right);
    }
}

//后序遍历 Post-order traversal
void postorder(Node* node){
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}


//

int main(){
    Tree tree;
    tree.root = NULL;//创建NULL tree
    int n;
    printf("Please enter number of node");
    scanf("%d", &n);

    //输入n个数并创建这个树
    for (int i = 0; i<n; i++){
        int temp;
        printf("please enter the %dth node",i+1);
        scanf("%d",&temp);
        insert(&tree, temp);
    }

    printf("----In order----\n");
    inorder(tree.root);
    printf("\n----Pre order----\n");
    preorder(tree.root);
    printf("\n----Post order----\n");
    postorder(tree.root);

    return 0;
}