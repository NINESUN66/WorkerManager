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
	//判断文件是否有内容
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
	//根据职工人数创建数组
	this->m_EmpArray = new Worker *[num];
	InputEmpArr();
}
WorkManager::~WorkManager()
{

}
void WorkManager::ShowMenuA()
{	
	cout << "**************************" << endl;
	cout << "******1.退出管理程序******" << endl;
	cout << "******2.增加职工信息******" << endl;
	cout << "******3.显示职工信息******" << endl;
	cout << "******4.删除离职职工******" << endl;
	cout << "******5.修改职工信息******" << endl;
	cout << "******6.查找职工信息******" << endl;
	cout << "******7.按照编号排序******" << endl;
	cout << "******8.清空所有文档******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}
void WorkManager::ShowMenuB()
{
	cout << "**************************" << endl;
	cout << "******1.退出管理程序******" << endl;
	cout << "******2.显示职工信息******" << endl;
	cout << "******3.查找职工信息******" << endl;
	cout << "******4.按照编号排序******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}
void WorkManager::exitSystem()
{
	cout << "正在退出系统，感谢您的使用" << endl;
	system("pause");
	exit(0);//退出程序
}
void WorkManager::addEmp()
{
	cout << "请输入添加数量" << endl;
	int num=0;
	cin >> num;
	if (num > 0)
	{
		//添加
		//计算添加新的空间大小
		int newSize = this->m_EmpNum + num;
		Worker **newSpace = new Worker * [newSize];
		//将原来空间下的数据拷贝到新的空间下
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
			cout << "请输入第" << i+1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i+1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			while(dSelect != 1 && dSelect!= 2 && dSelect != 3)
			{
				cout << "输入有误，请重新输入" << endl;
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
				cout << "输入错误，请重新输入" << endl;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//将指针指向新的空间
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新文件为空的bool
		this->m_FileIsEmpty = false;
		cout << "成功添加"<< num << "职工" << endl;
		//保存数据
		this->Save();
	}
	else 
	{
		cout << "输入有误，请重新输入" << endl;
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
		cout << "文件打开失败，请检查文件位置!" << endl;
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
		cout << "文件不存在或记录为空" << endl;
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
	cout << "请选择查找方式：" << endl;
	cout << "1.根据职工编号查找" << endl;
	cout << "2.根据职工姓名查找" << endl;
	cin >> Select;
	while (Select != 1 && Select != 2)
	{
		cout << "输入错误，请重新输入" << endl;
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
		cout << "请输入职工编号：" << endl;
		while (cin >> id)
		{
			if (IsExist(id) == false)
			{
				cout << "该职工不存在，请重新输入" << endl;
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
						cout << "删除成功" << endl;
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
		cout << "请输入职工姓名：" << endl;
		while (cin >> name)
		{
			if (IsExist(-1, name) == false)
			{
				cout << "该职工不存在，请重新输入" << endl;
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
						cout << "删除成功" << endl;
						break;
					}
				}
				break;
			}
		}
	}
	else
	{
		cout << "当前没有职工" << endl;
		
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
		cout << "请输入职工编号" << endl;
		while (cin >> id) 
		{
			if (IsExist(id) == false)
			{
				cout << "该职工不存在，请重新输入" << endl;
			}
			else
			{
				for (int i = 0; i < this->get_EmpNum(); i++)
				{
					if (this->m_EmpArray[i]->m_Id == id)
					{
						cout << "请输入修改后的职工编号：";
						cin >> newi;
						cout << "请输入修改后的职工姓名：";
						cin >> n;
						cout << "请输入修改后的职工岗位：";
						cout << "1.普通职工" << endl;
						cout << "2.经理" << endl;
						cout << "3.老板" << endl;
						cin >> newd;
						while (newd != 1 && newd != 2 && newd != 3)
						{
							cout << "输入有误，请重新输入" << endl;
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
						cout << "修改成功" << endl;
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
		cout << "请输入职工姓名" << endl;
		while (cin >> name) {
			if (IsExist(-1, name) == false)
			{
				cout << "该职工不存在，请重新输入" << endl;
			}
			else
			{
				for (int i = 0; i < this->get_EmpNum(); i++)
				{
					if (this->m_EmpArray[i]->m_Name == name)
					{
						cout << "请输入修改后的职工编号：";
						cin >> newi;
						cout << "请输入修改后的职工姓名：";
						cin >> n;
						cout << "请输入修改后的职工岗位：";
						cout << "1.普通职工" << endl;
						cout << "2.经理" << endl;
						cout << "3.老板" << endl;
						cin >> newd;
						while (newd != 1 && newd != 2 && newd != 3)
						{
							cout << "输入有误，请重新输入" << endl;
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
						cout << "修改成功" << endl;
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
		cout << "当前没有职工" << endl;
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
		cout << "当前没有职工" << endl;
	}
	else if (Select == 1)
	{
		int Sid;
		cout << "请输入职工编号";
		cin >> Sid;
		while (IsExist(Sid) == false)
		{
			cout << "该职工不存在，请重新输入" << endl;
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
		cout << "请输入职工编号";
		cin >> Sname;
		while (IsExist(-1,Sname) == false)
		{
			cout << "该职工不存在，请重新输入" << endl;
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
	cout << "请选择排序方式：" << endl;
	cout << "1.按照ID升序排列" << endl;
	cout << "2.按照ID降序排列" << endl;
	cin >> Select;
	while (Select != 1 && Select != 2)
	{
		cout << "输入错误，请重新输入" << endl;
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
	cout << "排序成功" << endl;
	system("pause");
	system("cls");
	return;
}
void WorkManager::CleanAll()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int Select;
	cin >> Select;
	while (Select != 1 && Select != 2)
	{
		cout << "输入有误,请重新输入" << endl;
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
		cout << "清空成功" << endl;
	}
	else { cout << "退出成功" << endl; }
	system("pause");
	system("cls");
	return;
}