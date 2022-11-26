#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 10 //队列最大容量

//循环队列设计
typedef struct cir_queue{
    int data[maxsize];
    int rear;
    int front;
} cir_queue;

//1. initialize
cir_queue *init(){
    cir_queue *q = (cir_queue*)malloc(sizeof(cir_queue));
    if (q==NULL){
        exit(0);
    }
    memset(q->data,0,sizeof(q->data));
    q->front=0;
    q->rear=0;
    return q;
}

//2. push
void push(cir_queue *q, int data)
{
    if ((q->rear+1)%maxsize == q->front)
    {
        printf("out of range\n");
        return;
    }
    else
    {
        q->rear=(q->rear+1)%maxsize;
        q->data[q->rear] = data;
    }
}

//3. pop
void pop(cir_queue *q)
{
    if(q->data[q->rear] == 0){
        printf("can't pop empty queue\n");
        return ;
    }
    if(q->rear == q->front){
        q->data[q->rear]=0;

    }
    else{
        q->data[q->front] = 0;
        q->front=(q->front+1)%maxsize;
    }
}

void print(cir_queue *q)
{
    int i=q->front;
    while (i!=q->rear){
        i = (i+1)%maxsize;
        printf("%d\t", q->data[i]);
    }
    printf("\n");
}

int main(){
    cir_queue *q = init();
    ////////////入队操作///////////////
    printf("push\n");
    for(int i=1;i<=6;i++){
        push(q,i);
    }
    print(q);
    ////////////出队操作///////////////
    printf("pop\n");
    for(int i=1;i<=10;i++){
        pop(q);
        print(q);
    }
    return 0;
}