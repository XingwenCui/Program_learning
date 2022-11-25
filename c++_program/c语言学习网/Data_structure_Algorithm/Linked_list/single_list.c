#include<stdio.h>
#include<stdlib.h>

//1. 定义一个链表节点
typedef struct Node
{
    int data; //数据类型，可以是其他类型
    struct Node *next; //单向list的指针
} Node, *LinkedList; //对 struct Node重命名为Node,和指针LinkedList

//2. 对链表初始化
LinkedList listinit(){
    Node *L;
    L = (Node*)malloc(sizeof(Node)); //申请空间，return地址指针
    if (L==NULL){
        printf("Fail to allocate space");
    }
    L->next=NULL; //如果空间开成功，next指向NULL(结构体指针用->)
    return L;
}

//3.1 Head insert创建LinkedList
// 从空表开始生成新节点
LinkedList LinkedListCreatH(){
    Node *L;
    L = (Node *)malloc(sizeof(Node)); //头结点空间
    L->next = NULL; //初始化

    int x; //链表data的数据
    while(scanf("%d",&x)!=EOF){
        Node *p;
        p = (Node*)malloc(sizeof(Node)); //申请插入的空间
        p->data = x; //节点data赋值
        p->next = L->next;//将结点插入到表头L-->|2|-->|1|-->NULL
        L->next = p;
    }
    return L;
}
//3.2 Tail insert创建LinkedList
LinkedList LinkedListCreatT(){
    Node *L;
    L = (Node*)malloc(sizeof(Node)); //头结点空间
    L->next = NULL;
    //建立tail pointer始终代表当前链表的尾结点
    Node *r;
    r = L;

    int x; //插入的数据
    while(scanf("%d",&x) != EOF){
        Node *p;
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        r->next = p; //在原本的tail r后插入p
        r = p; //tail变成p
    }
    r->next=NULL; //最后让tail指向NULL
    return L;
}

//4. print所有信息
void printList(LinkedList L){
    Node *p = L->next;//初始指针
    int i = 0;
    while (p){
        printf("The %d element is %d\n",++i,p->data);
        p=p->next; //下一个节点
    }
}

//5. 修改,注意返回的是地址，即对那个对象永久修改，而不是值传递
LinkedList LinkedListReplace(LinkedList L, int x, int k){
    Node *p = L->next;
    //最简单的查找，顺序查找
    int i = 0;
    while (p){
        if (p->data == x){
            p->data = k;
        }
        p = p->next;
    }
    return L;
}

//6. 插入，找到第i个位置，将next指针指向新的节点，新节点next指向i+1
LinkedList LinkedListInsert(LinkedList L, int i, int x){
    Node *pre; //前节点
    pre = L;

    for (int tempi = 1; tempi<i; tempi++){
        pre = pre->next; //找到第i个位置的前结点 i-1
    }

    Node *p;
    p = (Node*)malloc(sizeof(Node)); //申请空间
    p->data = x;
    p->next = pre->next; //把新建节点的next设为i+1
    pre->next = p; // 把pre的next即i设成插入的

    return L;
}

//7. delete把删除位置的前一个next设成i+1即可
LinkedList LinkedListDelete(LinkedList L, int x){
    Node *p, *pre; 
    p = L->next;
    //查找x的位置，顺便将p的前一个node更新
    while(p->data != x){
        if (p->next == NULL){
            printf("There is no %d\n",p->data);
            return NULL;
        }
        pre = p;
        p = p->next;
    }
    pre->next = p->next; //删除
    free(p);

    return L;
}

int main(){
    //创建 
    LinkedList list;
    printf("Please input data of linkedlist and end with EOF\n");
    list = LinkedListCreatT();
    //list=LinkedListCreatT();
    printList(list);
     
    //插入 
    int i;
    int x;
    printf("Please enter insert location");
    scanf("%d",&i);
    printf("Pleas enter insert date");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //修改
    printf("Please enter modified data");
    scanf("%d",&i);
    printf("Please enter new data");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //删除 
    printf("Please enter deleted data");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
}