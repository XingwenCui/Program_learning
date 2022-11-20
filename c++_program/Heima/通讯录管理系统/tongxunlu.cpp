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
	cout << "5. 修改联系人" << endl;
	cout << "6. 清空联系人" << endl;
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
		system("pause");
		system("cls");
	}
}

//2. 显示所有联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0
	if (abs->m_Size == 0)
	{
		cout << "当前记录为NULL" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "name: " << abs->personArray[i].m_Name << "\t";
			cout << "sex: " << (abs->personArray[i].m_Sex==1?"male":"female") << "\t";
			cout << "age: " << abs->personArray[i].m_Age << "\t";
			cout << "phone: " << abs->personArray[i].m_Phone << "\t";
			cout << "address: " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //enter any key
	system("cls"); //clear screen
}

//检测联系人是否存在，存在返回数组位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1; //如果都没找到
}

//3. 删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "Please input name which you want to delete" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移操作，删除后该后位置的index减一
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新人数
		cout << "delete successfully" << endl;
	}
	else
	{
		cout << "no person " << name << endl;
	}
	system("pause");
	system("cls");
}

//4. 查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "Please input search name" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "name: " << abs->personArray[ret].m_Name << "\t";
		cout << "sex: " << (abs->personArray[ret].m_Sex == 1 ? "male" : "female") << "\t";
		cout << "age: " << abs->personArray[ret].m_Age << "\t";
		cout << "phone: " << abs->personArray[ret].m_Phone << "\t";
		cout << "address: " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout<<"no such person " << name << endl;
	}
	system("pause");
	system("cls");
}

//5. 修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "Please input modified name" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "Please input name:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "Please input sex:" << endl;
		cout << "1---male" << endl;
		cout << "2---female" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex; //abs的array,对应的第size个人的sex
				break;
			}
			cout << "you can only input 1 or 2" << endl;
		}
		//age;
		cout << "Please input age;" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//phone
		cout << "Please input phone number;" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//address
		cout << "Please input address;" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		//update book people
		abs->m_Size++;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "No such person " << name << endl;
	}
	system("pause");
	system("cls");
}

//6. 清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "book has been clean" << endl;
	system("pause");
	system("cls");
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
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
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