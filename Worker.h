#pragma once
#include<string>
#include<iostream>
using namespace std;
//职工抽象类
class Worker
{
public:
	int m_Id;
	string m_Name;
	int m_DeptId;
	virtual void ShowInfo()=0;
	virtual string getDeptName()=0;
};