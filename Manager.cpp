#include"Manager.h"
Manager::Manager(int id, string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}

void Manager::ShowInfo()
{
	cout << "职工编号:" << this->m_Id << endl;
	cout << "职工姓名:" << this->m_Name << endl;
	cout << "职位编号:" << this->getDeptName() << endl;
	cout << "岗位职责:完成老板交给的人物，并下发任务给员工"	<< endl;
}
string Manager::getDeptName()
{
	return "经理";
}