#include<iostream>
#include<string>
using namespace std;

#define MAX 1000


//设计联系人struct
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//设计通讯录struct
struct Addressbooks
{
	//保存联系人的数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};
//menu
void showMenu()
{
	cout<<"********************" << endl;
	cout << "1. 添加联系人" << endl;
	cout << "2. 显示联系人" << endl;
	cout << "3. 删除联系人" << endl;
	cout << "4. 查找联系人" << endl;
	cout << "5. 清空联系人" << endl;
	cout << "6. 添加联系人" << endl;
	cout << "0. 退出通讯录" << endl;
	cout << "********************" << endl;
}
//1. add Person, 定义的是结构体指针，且用的地址传递
void addPerson(Addressbooks* abs)
{
	//判断是否满了，如果满了就不能添加了
	if (abs->m_Size == MAX)
	{
		cout << "exceed volume" << endl;
		return;
	}
	else
	{
		//添加具体人
		string name;
		cout << "Please input name:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "Please input sex:" << endl;
		cout << "1---male" << endl;
		cout << "2---female" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{	
				abs->personArray[abs->m_Size].m_Sex = sex; //abs的array,对应的第size个人的sex
				break;
			}
			cout << "you can only input 1 or 2" << endl;
		}
		//age;
		cout << "Please input age;" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//phone
		cout << "Please input phone number;" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//address
		cout << "Please input address;" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//update book people
		abs->m_Size++;
		cout << "添加成功" << endl;
	}
}

//0. quit address book
//根据不同选择，进入不同功能：switch
int main()
{
	Addressbooks abs;
	abs.m_Size = 0; //最初是0人
	int select = 0; //创建用户选择变量
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs); //一定要利用地址传递，可以修饰实参
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0: // quit the book
			cout << "see you next time" << endl;
			system("pause");
			return 0; //quit book
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}