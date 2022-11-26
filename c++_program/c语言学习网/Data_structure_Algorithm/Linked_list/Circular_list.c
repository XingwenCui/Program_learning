#include<stdio.h>
#include<stdlib.h>

// define list node
typedef struct list
{
    int data;
    struct list *next;
} list ;

//1. 初始结点
list *initlist(){
    list *head = (list*)malloc(sizeof(list));
    if (head==NULL){
        printf("Fail to create");
        exit(0);
    }
    else{
        head->next = NULL;
        return head;
    }
}

//2. 创建list
int create_list(list *head){
    int data; // 插入的数据类型可以改
    printf("Please enter insert data\n");
    scanf("%d",&data);
    //初始化新node，准备链接
    list *node=initlist();
    node->data=data;

    if (head!=NULL){
        list *p = head;
        //找到最后一个data
        while (p->next!=head){
            p = p->next;
        }
        p->next = node;
        node->next = head;
        return 1;
    }
    else{
        printf("head node has no element\n");
        return 0;
    }
}

//3. 插入元素
list * insert_list(list * head, int pos, int data){
    list *node = initlist(); //新建要插入的节点
    list *p = head; //新的链表
    list *t;
    t = p;
    node->data = data;

    if(head!=NULL){
        for (int i=1; i<=pos; i++){
            t = t->next; //找到插入位置
        }
        node->next = t->next; //现将插入的nodenext更新
        t->next=node; //将上一个位置的next更新为查入的node
        return p;
    }
    return p;
}

//4. 删除
int delete_list(list *head){
    if (head==NULL){
        printf("Empty list\n");
        return 0;
    }
    //建立临时node存储head的信息，记住退出点
    list *temp = head;
    list *ptr = head->next;

    int del;
    printf("please enter delete data: ");
    scanf("%d",&del);

    while(ptr != head){
        if (ptr->data == del){
            //如果删除的是最后一个节点，那直接将next设为head
            if(ptr->next == head){
                temp->next = head;
                free(ptr);
                return 1;
            }
            temp->next = ptr->next;
            free(ptr);
            printf("delete successfully\n");
            return 1;
        }
        temp = temp->next;
        ptr = ptr->next;
    }
    printf("NO such element\n");
    return 0;
}

//5. 遍历
int display(list *head){
    if(head != NULL){
        list *p = head;
        while(p->next != head){
            printf("%d\n",p->next->data);
            p = p->next;
        }
        return 1;
    }
    else{
        printf("NULL list\n");
        return 0;
    }
}

int main(){
    list *head = initlist();
    head->next =head;

    for (int i = 0; i < 5; i++)
    {
        create_list(head);
    }
    display(head);
    head = insert_list(head,1,10);
    display(head);
    delete_list(head);
    display(head);
    return 0;
    
}