/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-30 12:17:44
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-30 13:20:33
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\Tree\HuffmanTree.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<stdlib.h>
void Select(HuffmanTree HT, int end, int *s1, int *s2);
// Noode 结点
typedef struct {
    int weight; //权重
    int parent, left, right; //父，左，右在数组中的下标位置
} HTNode, *HuffmanTree;


//create 哈夫曼树
//HT为地址传递的存储哈夫曼数组，w为存储结点权重的数组， n为结点个数
void CreateHuffmanTree(HuffmanTree* HT, int *w, int n){
    if (n<=1)
        return; //只有一个编码相当于0
    
    int m = 2*n-1; //哈夫曼树总结点数，n是叶子节点
    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    HuffmanTree p = *HT;

    //初始化哈夫曼树中所有节点
    for (int i=1; i<=n; i++){
        (p+i)->weight = *(w+i-1);
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }

    //从数组的下标开始，初始化除了叶子结点以外的结点
    for (int i = n+1; i<=m; i++){
        (p+i)->weight = 0;
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }

    //构建Huffman tree
    for (int i = n+1; i<=m; i++){
        int s1,s2;
        Select(*HT, i-1, &s1,&s2); //查找算法

        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}
//HT数组中存放的哈夫曼树，end表示HT数组中存放结点的最终位置，s1和s2传递的是HT数组中权重值最小的两个结点在数组中的位置
void Select(HuffmanTree HT, int end, int *s1, int *s2) {
    int min1, min2; //记录最小的两个点
    //初始遍历下标
    int i = 1;
    //找到还未构建树的node
    while (HT[i].parent != 0 && i<=end){
        i++;
    }
    min1 = HT[i].weight;
    *s1 = i;//找第一个值
    i++;
    while (HT[i].parent != 0 && i<=end){
        i++;
    }
    //对找到的两个结点比较大小，min2为大的，min1为小的
    if(HT[i].weight < min1) {
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    } else {
        min2 = HT[i].weight;
        *s2 = i;
    }
    //两个结点和后续的所有未构建成树的结点做比较
    for(int j=i+1; j <= end; j++) {
    //如果有父结点，直接跳过，进行下一个
        if(HT[j].parent != 0) {
            continue;
        }
    //如果比最小的还小，将min2=min1，min1赋值新的结点的下标
        if(HT[j].weight < min1) {
            min2 = min1;
            min1 = HT[j].weight;
            *s2 = *s1;
            *s1 = j;
        }
    //如果介于两者之间，min2赋值为新的结点的位置下标
        else if(HT[j].weight >= min1 && HT[j].weight < min2) {
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}

