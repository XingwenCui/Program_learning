#include<stdio.h>
#include<stdlib.h>
/* 1.Define node type,用typedef给struct rename;
 struct 中包含两个成员:1.data 2.Node pointer, -> next Node
 之所以这样定义是为了用Node，和LinkList直接表示 structure Node */
typedef struct Node {
	int data; // data can be any type of data
	struct Node *next;
} Node, *LinkedList; // Node 就是typedef后的struct的新类型, *LinkedList是指向这个类型的指针类型。


/*2.单链表初始化: a function	*/
LinkedList listinit(){
	Node *L;
	//malloc是申请一个大小为size个字节的连续内存空间
	L = (Node*)malloc(sizeof(Node)); //开辟空间，对该节点申请空间
	if (L == NULL){
		printf("fail to request space"); //判断空间是否开辟失败，失败了要提示
		}
	L->next=NULL; //Struct L Point next node to NULL first.(L->next = L.next)
}

/*3.单链表建立1::头插法 */
LinkedList LinkedListCreatH() {
	Node *L; //建立一个Node指针
	L = (Node *)malloc(sizeof(Node)); //申请头部Node空间
	L->next = NULL; //初始化一个空链表
	
	int x; //x为link数据中的data
	while (scanf("%d",&x) != EOF) {
		Node *p; //新的node节点，一会要插到前边
		p = (Node *)malloc(sizeof(Node)); //申请新的空间
		p->data = x; //p的data赋值为x;
		p->next = L->next; //L-->2 -->1 --> NULL
		L->next = p;
	}
	return L;
}

/*4.单链表建立2:尾插法*/
LinkedList LinkedListCreatT() {
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	Node *r; r = L; //建立一个新的r，r始终指向终端节点
	
	int x; //链表数据中的数据
	while (scanf("%d", &x) != EOF) {
		Node *p;
		p = (Node *)malloc(sizeof(Node));
		p->data = x;
		r->next = p; //将节点插到表头，但是插的尾部
		r = p;
	}
	r -> next = NULL;
	return L;
}

/*5.遍历单链表 */
void printList(LinkedList L) {
	Node *p=L->next;
	int i=0;
	// p的指针不为NULL就继续遍历
	while(p){
		printf("The %d element value is %d\n", ++i, p->data);
		p= p->next;
	}
}

/*6.修改元素,对L，修改x的值为k*/
LinkedList LinkedListReplace(LinkedList L, int x, int k) {
	Node *p=L->next;
	int i=0;
	while(p){
		if(p->data==x){
			p->data=k;
		}
		p=p->next;//往下指
	}
	return L; //return 一个replaced linkedlist
}

/*7. 插入元素，在第i个位置插入x的元素*/
LinkedList LinkedListInsert(LinkedList L, int i,int x) {
	Node *pre; //前节点
	pre = L;
	int tempi = 0;
	for (tempi = 1;tempi < i; tempi++) {
		pre = pre->next; //查找第i个位置的pre节点
	}
	//插入过程
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->data = x; //插入的值为x
	p->next = pre->next; //插入节点的next是刚才pre的next,这样完成了p-->pre's next
	pre->next = p; //更新pre的next是p，这样完成了pre-->p
	
	return L;
}

/*8. 删除元素*/
LinkedList LinkedListDelete(LinkedList L, int x) {
	Node *p,*pre; //pre为前一个节点，p为查找的节点
	p = L->next;
	//找值为x的元素的node，不对就过到下一个
	while(p->data != x){
		pre = p;
		p = p->next;
	}
	pre->next = p->next; //remove p: pre-->p的next，不连p了
	free(p);//释放空间
	
	return L;
}

int main() {
    //创建 
    LinkedList list;
    printf("请输入单链表的数据：以EOF结尾\n");
    list = LinkedListCreatT();
    //list=LinkedListCreatT();
    printList(list);
     
    //插入 
    int i;
    int x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //修改
    printf("请输入修改的数据：");
    scanf("%d",&i);
    printf("请输入修改后的值：");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //删除 
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
}