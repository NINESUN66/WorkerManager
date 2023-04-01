#include"Boss.h"
Boss::Boss(int id, string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}
void Boss::ShowInfo()
{
	cout << "职工编号:" << this->m_Id << endl;
	cout << "职工姓名:" << this->m_Name << endl;
	cout << "职位编号:" << this->getDeptName() << endl;
	cout << "岗位职责:享福" << endl;
}
string Boss::getDeptName()
{
	return "老板";
}