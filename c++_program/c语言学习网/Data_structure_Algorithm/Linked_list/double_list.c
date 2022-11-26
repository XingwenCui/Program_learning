#include<stdio.h>
#include<stdlib.h>

//结点设计
typedef struct line{
    int data;
    struct line *pre;
    struct line *next;
} line;

//1. 创建双链表
line* initLine(line * head){
    int number, pos = 1, input_data;
    printf("please enter node size\n");
    scanf("%d",&number);

    if(number<1){return NULL;} //输入非法结束
    ///头结点///
    head=(line*)malloc(sizeof(line));
    head->pre = NULL;
    head->next = NULL;
    printf("please enter the %dth data\n",pos++);
    scanf("%d",&input_data);
    head->data = input_data;

    ///后续结点    
    line * list=head;
    while (pos<=number){
        line * body = (line*)malloc(sizeof(line));
        body->pre = NULL;
        body->next = NULL;
        printf("please enter the %dth data\n",pos++);
        scanf("%d",&input_data);
        body->data = input_data;

        list->next=body;//将现在的list的next指向新的
        body->pre=list;//将新的pre指向list
        list = list->next;//更新list
    }
    return head;
}

//2. 插入
line * insertLine(line * head, int data, int add){
    //新建数据的结点
    line * temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->pre = NULL;
    temp->next = NULL;

    //插入到表头，只需要把head结点更新
    if (add == 1){
        temp->next = head; 
        head->pre = temp;
        head = temp;
    }
    else{
        line * body=head; //起始查找位置
        //找到要插入的前一个node位置
        for (int i = 1; i<add-1; i++){
            body=body->next; //将body更新到 add-1
        }
        //判断是否插入到了链表尾
        if (body->next == NULL){
            body->next = temp;
            temp->pre = body;
        }
        else{
            body->next->pre = temp; //将插入前一个node的next的pre更新为temp
            temp->next = body->next; //更新插入节点的next为原位置的next
            body->next = temp; //更新前一位置next为新节点
            temp->pre = body; //更新插入节点的pre指针
        }
    }
    return head;
}

//3. 删除操作
line * deleteLine(line* head, int data){
    line * list = head;
    while (list) {
        //判断是否找到
        if(list->data == data){
            list->pre->next = list->next; //将前一个node的next改为后一个node
            list->next->pre = list->pre; //同理更新后一个的pre
            free(list);
            printf("--delete-- successfully\n");
            return head;
        }
        list = list->next;
    }
    printf("Error: No such data\n");
    return head;
}

//4. 遍历
void printLine(line * head){
    line *list = head;
    int pos = 1;
    while (list){
        printf("The %dth data is: %d\n",pos++, list->data);
        list = list->next;
    }
}

int main(){
    line *head = NULL;
    printf("creat double linked list\n");
    head = initLine(head);
    printLine(head);
    printf("insert item\n");
    head = insertLine(head,40,2);
    printLine(head);

    printf("delete item\n");
    head = deleteLine(head,2);
    printLine(head);

    return 0;
}