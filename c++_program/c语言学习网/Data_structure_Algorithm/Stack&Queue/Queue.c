#include<stdio.h>
#include<stdlib.h>

//define node
typedef struct node
{
    int data;
    struct node *next;
} node;
//define queue
typedef struct queue
{
    node *front; //首指针
    node *rear; //尾指针
} queue;

//1.1 初始化node
node *init_node()
{
    node *n=(node*)malloc(sizeof(node));
    if (n==NULL){
        printf("Fail to creat node");
        exit(0);
    }
    return n;
}
//1.2 queue
queue *init_queue()
{
    queue *q = (queue*)malloc(sizeof(queue));
    if (q==NULL){
        printf("Fail to creat queue");
        exit(0);
    }
    //首尾均赋值NULL
    q->front=NULL;
    q->rear=NULL;
    return q;
}

//2. queue判断NULL
int empty(queue *q)
{
    return q->front==NULL; //true为空
}

//3. push
void push(queue *q, int data)
{
    //创建新的要push的node
    node *n = init_node();
    n->data = data;
    n->next = NULL; //尾插法
    //如果是空queue，头尾都是这个node
    if (empty(q))
    {
        q->front = n;
        q->rear = n;
    }
    else
    {
        q->rear->next = n; //queue的原尾部节点的下一个是n
        q->rear = n; //queue的尾是n
    }
}

void pop(queue *q)
{
    node *n = q->front;
    if(empty(q))
    {
        return; //直接结束
    }
    //如果 queue中只有1个节点(data)
    if (q->front == q->rear){
        //直接将两个元素的端点指向NULL
        q->front = NULL;
        q->rear = NULL;
        free(n);
    }
    else{
        q->front = q->front->next;//更新front为head的下一个
        free(n);
    }
}

void print_queue(queue *q)
{
    node *n = init_node();
    n=q->front;
    if(empty(q)){
        return ; //queue为空，直接return
    }
    while (n!=NULL)
    {
        printf("%d\t", n->data);
        n=n->next;
    }
    printf("\n");
}

int main(){
    queue *q = init_queue();
    printf("push queue\n");
    for(int i = 1; i<=5; i++){
        push(q,i);
        print_queue(q);
    }
    printf("pop queue\n");
    for (int i=1; i<=5; i++)
    {
        pop(q);
        print_queue(q);
    }
    return 0;
}