#include<iostream>
#include<string>
#include<fstream>
#include"WorkManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Login.h"
using namespace std;
int main()
{
	if (Login() == 1)
	{
		cout << "欢迎您管理员" << endl;
		WorkManager Ad;
		int Choose;
		while (true)
		{
			Ad.ShowMenuA();//展示菜单
			cout << "请输入您的选择" << endl;
			cin >> Choose;
			switch (Choose)
			{
				case(1):
				{
					Ad.exitSystem();
					break;
				}
				case(2):
				{	
					Ad.addEmp();	
					break;
				}
				case(3):
				{
					Ad.ShowEmp();
					break;
				}
				case(4):
				{
					Ad.DeleEmp();
					break;
				}
				case(5):
				{
					Ad.ChangeEmp();
					break;
				}
				case(6):
				{
					Ad.SearchEmp();
					break;
				}
				case(7):
				{
					Ad.RankId();
					break;
				}
				case(8):
				{
					Ad.CleanAll();
					break;
				}
				default:
				{
					system("cls");
					break;
				}
			}
		}

	}
	else 
	{
		WorkManager wm;//实例化管理者对象
		int Choose;
	while (true)
	{
		wm.ShowMenuB();//展示菜单
		cout << "请输入您的选择" << endl;
		cin >> Choose;
		switch (Choose)
		{
		case(1):
		{
			wm.exitSystem();
			break;
		}
		case(2):
		{	wm.ShowEmp();
			break;
		}
		case(3):
		{
			wm.SearchEmp();
			break;
		}
		case(4):
		{wm.RankId();
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
	}
	system("pause");
	return 0;
}