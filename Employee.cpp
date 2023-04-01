#include"Employee.h"


Employee::Employee(int id,string name, int deptid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = deptid;
}

void Employee::ShowInfo()
{
	cout << "职工编号:" << this->m_Id << endl;
	cout << "职工姓名:" << this->m_Name << endl;
	cout << "职位编号:" << this->getDeptName() << endl;
	cout << "岗位职责:完成经理交给的任务" << endl;
}
string Employee::getDeptName()
{
	return "员工";
}