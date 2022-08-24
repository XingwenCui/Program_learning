#include<iostream>
#include<cstdlib>
#include<unistd.h> //延时函数
#include<stdio.h> //getchar()
#include<ctime>
#include<termios.h> //终端设置

using namespace std;

// global variables
#define MAX_X 20 // maze width X aex
#define MAX_Y 30 // maze height Y aex

bool flag = false; //true -> game created
bool slow = false; //speed of game
bool autogame = true; //mode of game
int maze[MAX_X][MAX_Y]; //2d array represent maze

class stack_of_maze
{
	private:
		//define a struct contain index and move info
		struct node
		{
			int x;
			int y;
			char direction; //last path(how to come)
			node* next; //next node
		};
		node* head;//clare first
	public:
		stack_of_maze()
		{
			//construct object
			head = NULL;
		}
		
		//obj life over call it
		~stack_of_maze()
		{
			node* p = head;
			//delete sequentially
			while (head!=NULL){
				head = head->next;
				delete p;
				p = head;
			}
		}

		void push(int xx, int yy, char ddirection)
		{
			//define a new node first
			node* new_node = new node;
			//push operate
			if(new_node != NULL){
				new_node->x == xx;
				new_node->y == yy;
				new_node->direction = ddirection;
				new_node->next = NULL;
				//judge stack is empty
				if(head==NULL)
					head = new_node; //empty stack
				else{
					new_node->next = head; //add new to head(top)
					head = new_node;
				}
			}
			else
				cout<<"fail to allocte memory"<<endl;
			
		}

		// pop stack
		//int& x:x=a->a and x use same memory
		node* pop(int& xx, int& yy) 	
		{
			if (head!=NULL)
			{
				node* p = head;
				head = head->next;
				xx = p->x;
				yy = p->y;
				delete p;
			}
			return head;
		}

		//print maze
		void print()
		{
			if(head!=NULL){
				node* p = head;
				while(p!=NULL){
					cout<<" "<<p->x<<" "<<p->y<<" "<<p->direction<<endl;
					p = p->next;
				}
			}
			else
				cout<<"stack is empty"<<endl;
		}

};


//create MAZE
void createMaze()
{
	int maxway = MAX_X * MAX_Y; //max path
	int x,y;

	//fill maze
	for (x=0;x<MAX_X;x++)
		for (y=0;y<MAX_Y;y++)
			maze[x][y] = 1;
	//random seed function
	srand((unsigned)time(NULL));
	//random construct maze route
	for (int i=0;i<maxway;i++)
	{
		x = rand()%(MAX_X-2) + 1;
		y = rand()%(MAX_Y-2) + 1;
		maze[x][y] = 0;
	}

	//entry
	maze[1][1] = 0;
	//exit
	maze[MAX_X-2][MAX_Y-2] = 0;

	maze[0][1] = 3;
	maze[MAX_X-1][MAX_Y-2] = 0;
}

//print MAZE
void printMaze()
{
	int x,y;
	//clear screen
	system("clear");
	//system("cls") //windows command
	//print maze
	for(x=0;x<MAX_X;x++)
	{
		for(y=0;y<MAX_Y;y++)
		{
			if(maze[x][y]==0){cout<<"  ";continue;}
			if(maze[x][y]==1){cout<<"■ ";continue;}
			if(maze[x][y]==2){cout<<"× ";continue;}
			if(maze[x][y]==3){cout<<"↓ ";continue;}
			if(maze[x][y]==4){cout<<"→ ";continue;}
			if(maze[x][y]==5){cout<<"← ";continue;}
			if(maze[x][y]==6){cout<<"↑ ";continue;}
			if(maze[x][y]==7){cout<<"※ ";continue;} //now position
		}
		cout<<endl; //next line
	}
	//slow game?
	if(slow){
		sleep(1);
	}
}



int main()
{
	stack_of_maze x;
	x.print();

	return 0;
}


