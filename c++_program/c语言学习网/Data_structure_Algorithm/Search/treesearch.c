/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-12-01 17:21:54
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-12-01 18:12:17
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\Search\treesearch.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<stdlib.h>

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 
  
/* 二叉树的二叉链表结点结构定义 */
typedef  struct BiTNode /* 结点结构 */
{
    int data;   /* 结点数据 */
    struct BiTNode *lchild, *rchild;    /* 左右孩子指针 */
} BiTNode, *BiTree;

Status Delete(BiTree *p); 
/* 递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBST(BiTree t, int key, BiTree f, BiTree *p) 
{  
    if (!t) /*  查找不成功 */
    { 
        *p = f;  
        return -1; 
    }
    else if (key == t->data) /*  查找成功 */
    { 
        *p = t;  
        return 1;  
    } 
    else if (key < t->data) 
        return SearchBST(t->lchild, key, t, p);  /*  在左子树中继续查找 */
    else  
        return SearchBST(t->rchild, key, t, p);  /*  在右子树中继续查找 */
}

//插入
BiTree InsertBST(BiTree t, int key){
    //如果树中什么都没，直接当成root
    if(t == NULL){
        t->lchild = t->rchild = NULL;
        t->data = key;
        return t; 
    }
    //如果不为NULL，按照左小右大迭代插入
    if (key < t->data)
    {
        t->lchild = InsertBST(t->lchild,key);
    }
    else
    {
        t->rchild = InsertBST(t->rchild, key);
    }
    return t;
}
// n个data在数组d中， tree为二叉排序root
BiTree CreatBiTree(BiTree tree, int d[], int n)
{
    for (int i = 0; i<n; i++){
        tree = InsertBST(tree,d[i]);
    }
}

//删除结点，这事不像插入这么容易，因为删除结点后，可能会影响其他树的结构

/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE。 */
Status DeleteBST(BiTree *T,int key)
{ 
    if(!*T) /* 不存在关键字等于key的数据元素 */ 
        return -1;
    else
    {
        if (key==(*T)->data) /* 找到关键字等于key的数据元素 */ 
            return Delete(T);
        else if (key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
  
    }
}
/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
Status Delete(BiTree *p)
{
    BiTree q,s;
    if((*p)->rchild==NULL) /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
    {
        q=*p; *p=(*p)->lchild; free(q);
    }
    else if((*p)->lchild==NULL) /* 只需重接它的右子树 */
    {
        q=*p; *p=(*p)->rchild; free(q);
    }
    else /* 左右子树均不空 */
    {
        q=*p; s=(*p)->lchild;
        while(s->rchild) /* 转左，然后向右到尽头（找待删结点的前驱） */
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
        if(q!=*p)
            q->rchild=s->lchild; /*  重接q的右子树 */ 
        else
            q->lchild=s->lchild; /*  重接q的左子树 */
        free(s);
    }
    return 1;
}

int main(){
    BiTree t;
    int d[] = {1,2,3,4,5,6};
    CreatBiTree(t,d, 5);
    return 0;
}
