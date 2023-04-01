#include"WorkManager.h"	
#include"Employee.h"
#include"Boss.h"
#include"Manager.h"
#include<fstream>
#include<algorithm>
WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		ifs.close();
		return;
	}
	//�ж��ļ��Ƿ�������
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = nullptr;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	//����ְ��������������
	this->m_EmpArray = new Worker *[num];
	InputEmpArr();
}
WorkManager::~WorkManager()
{

}
void WorkManager::ShowMenuA()
{	
	cout << "**************************" << endl;
	cout << "******1.�˳��������******" << endl;
	cout << "******2.����ְ����Ϣ******" << endl;
	cout << "******3.��ʾְ����Ϣ******" << endl;
	cout << "******4.ɾ����ְְ��******" << endl;
	cout << "******5.�޸�ְ����Ϣ******" << endl;
	cout << "******6.����ְ����Ϣ******" << endl;
	cout << "******7.���ձ������******" << endl;
	cout << "******8.��������ĵ�******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}
void WorkManager::ShowMenuB()
{
	cout << "**************************" << endl;
	cout << "******1.�˳��������******" << endl;
	cout << "******2.��ʾְ����Ϣ******" << endl;
	cout << "******3.����ְ����Ϣ******" << endl;
	cout << "******4.���ձ������******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}
void WorkManager::exitSystem()
{
	cout << "�����˳�ϵͳ����л����ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}
void WorkManager::addEmp()
{
	cout << "�������������" << endl;
	int num=0;
	cin >> num;
	if (num > 0)
	{
		//���
		//��������µĿռ��С
		int newSize = this->m_EmpNum + num;
		Worker **newSpace = new Worker * [newSize];
		//��ԭ���ռ��µ����ݿ������µĿռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < num; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i+1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i+1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			while(dSelect != 1 && dSelect!= 2 && dSelect != 3)
			{
				cout << "������������������" << endl;
				cin >> dSelect;
			}
			Worker* worker = NULL;
			if (dSelect == 1)
			{
				worker = new Employee(id, name, dSelect);
			}
			else if (dSelect == 2)
			{
				worker = new Manager(id, name, dSelect);
			}
			else if (dSelect == 3)
			{
				worker = new Boss(id, name, dSelect);
			}
			else
			{
				cout << "�����������������" << endl;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//��ָ��ָ���µĿռ�
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//�����ļ�Ϊ�յ�bool
		this->m_FileIsEmpty = false;
		cout << "�ɹ����"<< num << "ְ��" << endl;
		//��������
		this->Save();
	}
	else 
	{
		cout << "������������������" << endl;
		WorkManager::addEmp();
	}
	system("pause");
	system("cls");
	return;
}
void WorkManager::Save()
{
	ofstream fs;
	fs.open(FILENAME, ios::out);
	if (!fs.is_open()) 
	{
		cout << "�ļ���ʧ�ܣ������ļ�λ��!" << endl;
		system("pause");
		exit(0);
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		fs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	fs.close();
}
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}
void WorkManager::InputEmpArr()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[num] = worker;
		num++;
	}
}
void WorkManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else 
	{
		for (int i = 0; i < this->get_EmpNum(); i++)
		{
			this->m_EmpArray[i]->ShowInfo();
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}
bool WorkManager::IsExist(int id = -1, string name = "n", int did = 514)
{
	if (id != -1)
	{
		for (int i = 0; i < this->get_EmpNum(); i++)
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				return true;
			}
		}
	}
	else if (name != "n")
	{
		for (int i = 0; i < this->get_EmpNum(); i++)
		{
			if (this->m_EmpArray[i]->m_Name == name)
			{
				return true;
			}
		}
	}
	return false;
}
int WorkManager::Select()
{
	if (this->get_EmpNum() == 0)
	{
		return -1;
	}
	int Select;
	cout << "��ѡ����ҷ�ʽ��" << endl;
	cout << "1.����ְ����Ų���" << endl;
	cout << "2.����ְ����������" << endl;
	cin >> Select;
	while (Select != 1 && Select != 2)
	{
		cout << "�����������������" << endl;
		cin >> Select;
	}
	return Select;
}
void WorkManager::DeleEmp()
{
	int Select = this->Select();
	if (Select == 1)
	{
		int id;
		cout << "������ְ����ţ�" << endl;
		while (cin >> id)
		{
			if (IsExist(id) == false)
			{
				cout << "��ְ�������ڣ�����������" << endl;
			}
			else
			{
				for (int i = 0; i < this->get_EmpNum(); i++)
				{
					if (this->m_EmpArray[i]->m_Id == id)
					{
						for (int j = i; j < this->get_EmpNum(); j++)
						{
							this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						}
						this->m_EmpNum--;
						this->Save();
						cout << "ɾ���ɹ�" << endl;
						break;
					}
				}
				break;
			}
		}
	}
	else if (Select == 2)
	{
		string name;
		cout << "������ְ��������" << endl;
		while (cin >> name)
		{
			if (IsExist(-1, name) == false)
			{
				cout << "��ְ�������ڣ�����������" << endl;
			}
			else
			{
				for (int i = 0; i < this->get_EmpNum(); i++)
				{
					if (this->m_EmpArray[i]->m_Name == name)
					{
						for (int j = i; j < this->get_EmpNum(); j++)
						{
							this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						}
						this->m_EmpNum--;
						this->Save();
						cout << "ɾ���ɹ�" << endl;
						break;
					}
				}
				break;
			}
		}
	}
	else
	{
		cout << "��ǰû��ְ��" << endl;
		
	}
	system("pause");
	system("cls");
}
void WorkManager::ChangeEmp()
{
	int Select = this->Select();
	int newi, newd;
	string n;
	if (Select == 1)
	{
		int id;
		cout << "������ְ�����" << endl;
		while (cin >> id) 
		{
			if (IsExist(id) == false)
			{
				cout << "��ְ�������ڣ�����������" << endl;
			}
			else
			{
				for (int i = 0; i < this->get_EmpNum(); i++)
				{
					if (this->m_EmpArray[i]->m_Id == id)
					{
						cout << "�������޸ĺ��ְ����ţ�";
						cin >> newi;
						cout << "�������޸ĺ��ְ��������";
						cin >> n;
						cout << "�������޸ĺ��ְ����λ��";
						cout << "1.��ְͨ��" << endl;
						cout << "2.����" << endl;
						cout << "3.�ϰ�" << endl;
						cin >> newd;
						while (newd != 1 && newd != 2 && newd != 3)
						{
							cout << "������������������" << endl;
							cin >> newd;
						}
						delete this->m_EmpArray[i];
						Worker* worker = nullptr;
						if (newd == 1)
						{
							worker = new Employee(newi, n, newd);
						}
						if (newd == 2)
						{
							
							worker = new Manager(newi, n, newd);
						}
						if (newd == 3)
						{
							worker = new Boss(newi, n, newd);
						}
						this->m_EmpArray[i] = worker;
						this->Save();
						cout << "�޸ĳɹ�" << endl;
						system("pause");
						system("cls");
						return;
					}
				}
			}
		}
	}
	else if(Select == 2)
	{
		string name;
		cout << "������ְ������" << endl;
		while (cin >> name) {
			if (IsExist(-1, name) == false)
			{
				cout << "��ְ�������ڣ�����������" << endl;
			}
			else
			{
				for (int i = 0; i < this->get_EmpNum(); i++)
				{
					if (this->m_EmpArray[i]->m_Name == name)
					{
						cout << "�������޸ĺ��ְ����ţ�";
						cin >> newi;
						cout << "�������޸ĺ��ְ��������";
						cin >> n;
						cout << "�������޸ĺ��ְ����λ��";
						cout << "1.��ְͨ��" << endl;
						cout << "2.����" << endl;
						cout << "3.�ϰ�" << endl;
						cin >> newd;
						while (newd != 1 && newd != 2 && newd != 3)
						{
							cout << "������������������" << endl;
							cin >> newd;
						}
						delete this->m_EmpArray[i];
						Worker* worker= nullptr;
						if (newd == 1)
						{
							worker = new Employee(newi, n, newd);
						}
						else if (newd == 2)
						{
							worker = new Manager(newi, n, newd);
						}
						else if (newd == 3)
						{
							worker = new Boss(newi, n, newd);
						}
						this->m_EmpArray[i] = worker;
						this->Save();
						cout << "�޸ĳɹ�" << endl;
						system("pause");
						system("cls");
						return;
					}
				}
			}
		}
	}
	else
	{
		cout << "��ǰû��ְ��" << endl;
		system("pause");
		system("cls");
	}
	return;
}
void WorkManager::SearchEmp()
{
	int Select = this->Select();
	if (Select == -1)
	{
		cout << "��ǰû��ְ��" << endl;
	}
	else if (Select == 1)
	{
		int Sid;
		cout << "������ְ�����";
		cin >> Sid;
		while (IsExist(Sid) == false)
		{
			cout << "��ְ�������ڣ�����������" << endl;
			cin >> Sid;
		}
		for (int i = 0; i < this->get_EmpNum(); i++)
		{
			if (this->m_EmpArray[i]->m_Id == Sid)
			{
				this->m_EmpArray[i]->ShowInfo();
				break;
			}
		}
	}
	else 
	{
		string Sname;
		cout << "������ְ�����";
		cin >> Sname;
		while (IsExist(-1,Sname) == false)
		{
			cout << "��ְ�������ڣ�����������" << endl;
			cin >> Sname;
		}
		for (int i = 0; i < this->get_EmpNum(); i++)
		{
			if (this->m_EmpArray[i]->m_Name == Sname)
			{
				this->m_EmpArray[i]->ShowInfo();
				break;
			}
		}
	}
	system("pause");
	system("cls");
	return;
}
void WorkManager::RankId()
{
	int Select;
	cout << "��ѡ������ʽ��" << endl;
	cout << "1.����ID��������" << endl;
	cout << "2.����ID��������" << endl;
	cin >> Select;
	while (Select != 1 && Select != 2)
	{
		cout << "�����������������" << endl;
		cin >> Select;
	}
	if (Select == 1)
	{
		for (int i = 0; i < this->get_EmpNum() - 1; i++)
		{
			for (int j = 0; j < this->get_EmpNum() - 1 - i; j++)
			{
				if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
				{
					swap(m_EmpArray[j], m_EmpArray[j + 1]);
				}
			}
		}
	}
	else if (Select == 2)
	{
		for (int i = 0; i < this->get_EmpNum() - 1; i++)
		{
			for (int j = 0; j < this->get_EmpNum() - 1 - i; j++)
			{
				if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
				{
					swap(m_EmpArray[j], m_EmpArray[j + 1]);
				}
			}
		}
	}
	this->Save();
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
	return;
}
void WorkManager::CleanAll()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int Select;
	cin >> Select;
	while (Select != 1 && Select != 2)
	{
		cout << "��������,����������" << endl;
		cin >> Select;
	}
	if (Select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->get_EmpNum(); i++)
			{
				if (m_EmpArray[i] != NULL)
				{
					delete m_EmpArray[i];
				}
			}
		}
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		delete[] m_EmpArray;
		this->m_EmpArray = NULL;
		cout << "��ճɹ�" << endl;
	}
	else { cout << "�˳��ɹ�" << endl; }
	system("pause");
	system("cls");
	return;
}