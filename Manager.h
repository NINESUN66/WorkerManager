#pragma once
#include"Worker.h"
#include<iostream>
#include<string>
using namespace std;
class Manager :public Worker
{
public:
	Manager(int id, string name, int deptid);
	virtual void ShowInfo();
	virtual string getDeptName();
};