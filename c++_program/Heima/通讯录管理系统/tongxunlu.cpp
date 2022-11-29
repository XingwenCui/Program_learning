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
	cout << "1. ������ϵ��" << endl;
	cout << "2. ��ʾ��ϵ��" << endl;
	cout << "3. ɾ����ϵ��" << endl;
	cout << "4. ������ϵ��" << endl;
	cout << "5. �޸���ϵ��" << endl;
	cout << "6. �����ϵ��" << endl;
	cout << "0. �˳�ͨѶ¼" << endl;
	cout << "********************" << endl;
}
//1. add Person, ������ǽṹ��ָ�룬���õĵ�ַ����
void addPerson(Addressbooks* abs)
{
	//�ж��Ƿ����ˣ�������˾Ͳ���������
	if (abs->m_Size == MAX)
	{
		cout << "exceed volume" << endl;
		return;
	}
	else
	{
		//���Ӿ�����
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
		cout << "���ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//2. ��ʾ������ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼ΪNULL" << endl;
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

//�����ϵ���Ƿ���ڣ����ڷ�������λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1; //�����û�ҵ�
}

//3. ɾ��ָ����ϵ��
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
			//����ǰ�Ʋ�����ɾ����ú�λ�õ�index��һ
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //��������
		cout << "delete successfully" << endl;
	}
	else
	{
		cout << "no person " << name << endl;
	}
	system("pause");
	system("cls");
}

//4. ����ָ����ϵ����Ϣ
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

//5. �޸�ָ����ϵ����Ϣ
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
				abs->personArray[ret].m_Sex = sex; //abs��array,��Ӧ�ĵ�size���˵�sex
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
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "No such person " << name << endl;
	}
	system("pause");
	system("cls");
}

//6. �����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "book has been clean" << endl;
	system("pause");
	system("cls");
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