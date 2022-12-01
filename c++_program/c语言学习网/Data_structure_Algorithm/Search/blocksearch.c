/*
 * @Author: XingwenCui cxw1997n@gmail.com
 * @Date: 2022-11-30 22:06:26
 * @LastEditors: XingwenCui cxw1997n@gmail.com
 * @LastEditTime: 2022-11-30 23:10:19
 * @FilePath: \Program_learning\c++_program\c语言学习网\Data_structure_Algorithm\Search\blocksearch.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<stdlib.h>

//block
struct index
{
    int key;
    int start;
} newIndex[3]; // 结构体数组

int search(int key, int a[]);

// const void *a 表示，定义了指针a，他可以指向任意类型的值，这个值必须是常量
int cmp(const void *a, const void *b)
{
    return (*(struct index*)a).key > (*(struct index*)b).key?1:-1;
}

int main()
{
    int i, j=-1, k, key;
    int a[] = {33,42,44,38,24,48, 22,12,13,8,9,20, 60,58,74,49,86,53};
    //确认模块起始值和最大值
    for (i=0; i<3; i++){
        newIndex[i].start = j+1; //确定每个块起始
        j += 6; //下个块的起始

        for (int k=newIndex[i].start; k<=j; k++){
            if (newIndex[i].key<a[k])
            {
                newIndex[i].key = a[k]; //更新key，最大值
            }
        }
    }
    //对结构体按照key值进行排序
    qsort(newIndex, 3, sizeof(newIndex[0]), cmp);
    //进行查找
    printf("Please enter the number which you want: \n");
    scanf("%d", &key);

    k = search(key,a);
    
    if (k>0){
        printf("The number in %d\n", k+1);
    }
    else{
        printf("There is no such number\n");
    }
    return 0;
}

int search(int key, int a[]){
    int i, startValue;
    i = 0; //块
    while (i<3 && key>newIndex[i].key){
        i++; // 确定在那个块中
    }
    if (i>=3)
    {
        //大于块的数，没找到
        return -1;
    }
    startValue = newIndex[i].start;
    int up = startValue+5;
    while (startValue <= up && a[startValue] != key)
    {
        startValue++;
    }
    if (startValue>up)
    {
        return -1;
    }
    return startValue; //索引位置
}