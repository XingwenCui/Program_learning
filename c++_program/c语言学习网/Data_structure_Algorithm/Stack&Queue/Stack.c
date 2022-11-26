#include<stdio.h>
#include<stdlib.h>

//Stack node设计
typedef struct node
{
    int data;
    struct node *next;
} Node;
//利用上边的node创建stack，分为指向head的top指针和计数
typedef struct stack
{
    Node *top; //指向head，最上层
    int count; //计数
} Link_Stack;

//创建stack
Link_Stack *init()
{
    Link_Stack *s = (Link_Stack*)malloc(sizeof(Link_Stack));
    if (s==NULL)
    {
        printf("Fail to Assign allocation");
        exit(0);
    }
    s->top=NULL;
    s->count=0;
    return s;
}

//入栈 push
Link_Stack *Push_stack(Link_Stack *p, int elem)
{
    //判断stack是否为空
    if (p == NULL)
    {
        printf("Empty stack");
        return NULL;
    }
    //创建新的stack node，为temp node赋值，并将next指向stack p的top
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = elem;
    temp->next = p->top;
    p->top = temp; //对stack的p的top更新
    p->count++; //计数加一位
    return p;
}
//出栈
Link_Stack * Pop_stack(Link_Stack *p)
{
    Node *temp;
    temp = p->top; //要出的数据转给temp
    if (p->top == NULL)
    {
        printf("Error: Empty stack");
        return p;
    }
    else
    {
        p->top = p->top->next; //把stack的top位置转为pop的下一个
        free(temp);

        p->count--;
        return p;
    }
}

//遍历
int show_stack(Link_Stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("Error: Empty stack");
        return 0;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    return 0;
}

int main(){
    Link_Stack *s = init();
    //push stack
    Push_stack(s,1);
    show_stack(s);
    Push_stack(s,4);
    show_stack(s);
    Pop_stack(s);
    printf("The stack has %d elements\n",(s->count));    

    Link_Stack *p;
    p = init();
    int n = 5;
    int input[6] = {10,20,30,40,50,60};
    /////////////以依次入栈的方式创建整个栈//////////////
    for(int i=0;i<=n;i++){
        Push_stack(p, input[i]);
    }
    show_stack(p);
    ////////////////////出栈///////////////////////
    Pop_stack(p);
    show_stack(p);

    return 0;
}