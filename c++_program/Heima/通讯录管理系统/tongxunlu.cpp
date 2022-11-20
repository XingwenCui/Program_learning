#include<iostream>
#include<string>
using namespace std;

#define MAX 1000


//�����ϵ��struct
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//���ͨѶ¼struct
struct Addressbooks
{
	//������ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};
//menu
void showMenu()
{
	cout<<"********************" << endl;
	cout << "1. �����ϵ��" << endl;
	cout << "2. ��ʾ��ϵ��" << endl;
	cout << "3. ɾ����ϵ��" << endl;
	cout << "4. ������ϵ��" << endl;
	cout << "5. �����ϵ��" << endl;
	cout << "6. �����ϵ��" << endl;
	cout << "0. �˳�ͨѶ¼" << endl;
	cout << "********************" << endl;
}
//1. add Person, ������ǽṹ��ָ�룬���õĵ�ַ����
void addPerson(Addressbooks* abs)
{
	//�ж��Ƿ����ˣ�������˾Ͳ��������
	if (abs->m_Size == MAX)
	{
		cout << "exceed volume" << endl;
		return;
	}
	else
	{
		//��Ӿ�����
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
				abs->personArray[abs->m_Size].m_Sex = sex; //abs��array,��Ӧ�ĵ�size���˵�sex
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
		cout << "��ӳɹ�" << endl;
	}
}

//0. quit address book
//���ݲ�ͬѡ�񣬽��벻ͬ���ܣ�switch
int main()
{
	Addressbooks abs;
	abs.m_Size = 0; //�����0��
	int select = 0; //�����û�ѡ�����
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs); //һ��Ҫ���õ�ַ���ݣ���������ʵ��
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