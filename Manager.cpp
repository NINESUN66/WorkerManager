#include"Manager.h"
Manager::Manager(int id, string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}

void Manager::ShowInfo()
{
	cout << "ְ�����:" << this->m_Id << endl;
	cout << "ְ������:" << this->m_Name << endl;
	cout << "ְλ���:" << this->getDeptName() << endl;
	cout << "��λְ��:����ϰ彻����������·������Ա��"	<< endl;
}
string Manager::getDeptName()
{
	return "����";
}