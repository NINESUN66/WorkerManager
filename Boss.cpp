#include"Boss.h"
Boss::Boss(int id, string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}
void Boss::ShowInfo()
{
	cout << "ְ�����:" << this->m_Id << endl;
	cout << "ְ������:" << this->m_Name << endl;
	cout << "ְλ���:" << this->getDeptName() << endl;
	cout << "��λְ��:��" << endl;
}
string Boss::getDeptName()
{
	return "�ϰ�";
}