#include"Employee.h"


Employee::Employee(int id,string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}

void Employee::ShowInfo()
{
	cout << "ְ�����:" << this->m_Id << endl;
	cout << "ְ������:" << this->m_Name << endl;
	cout << "ְλ���:" << this->getDeptName() << endl;
	cout << "��λְ��:��ɾ�����������" << endl;
}
string Employee::getDeptName()
{
	return "Ա��";
}