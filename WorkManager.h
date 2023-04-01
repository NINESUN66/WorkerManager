#pragma once//防止头文件重复包含
#include<iostream>
#include"Worker.h"
using namespace std;
#define FILENAME "WorkerManager.txt" 
//建立程序大类
class WorkManager
{
public:
	WorkManager();
	~WorkManager();
	void ShowMenuA();
	void ShowMenuB();
	void exitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组的指针
	Worker** m_EmpArray;
	//添加职工
	void addEmp();
	//保存文件
	void Save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//记录文件中的职工数
	int get_EmpNum();
	//读入文件中的职工信息
	void InputEmpArr();
	//显示职工功能
	void ShowEmp();
	//检查职工是否存在
	bool IsExist(int, string, int);
	//实现删除职工
	void DeleEmp();
	int Select();
	//实现修改职工
	void ChangeEmp();
	//实现查找员工
	void SearchEmp();
	//按照编号排序
	void RankId();
	//实现清空所有文档
	void CleanAll();
};
