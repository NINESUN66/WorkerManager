#pragma once

//普通职工文件
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;
class Employee :public Worker
{
public:
	Employee(int id, string name, int deptid);

	virtual void ShowInfo();

	virtual string getDeptName();
};