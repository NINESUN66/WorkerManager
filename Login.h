#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
#include"SignUp.h"
using namespace std;
class AP
{
public:
	AP(string ac, string pa)
	{
		m_Ac = ac;
		m_Pa = pa;
	}

	string m_Ac;
	string m_Pa;
};
int MAX_TRY_TIMES = 5;
int Login()
{
	cout << "1.µÇÂ¼" << endl;
	cout << "2.×¢²á" << endl;
	int n;
	cin >> n;
	if (n == 2)
	{
		AccPass temp;
		temp.SignUp();
		system("pause");
		system("cls");
		Login();
	}
	string account;
	char a;
	cout << "ÇëÊäÈëÕËºÅ£º";
	while (a = _getch())
	{
		if (a >= 32)
		{
			if (a != 32)account = account + a;
			cout << a;
		}
		else break;
	}
	cout << endl;

	string password;
	char p;
	cout << "ÇëÊäÈëÃÜÂë£º";
	while (p = _getch())
	{
		if (p >= 32)
		{
			if (p != 32) password = password + p;
			cout << "*";
		}
		else break;
	}
	cout << endl;

	string Acc, Pass;
	int num = 0;
	vector<AP> Aparr;
	ifstream ifs;
	ifs.open("Account.txt", ios::in);
	while (ifs >> Acc && ifs >> Pass)
	{
		AP temp(Acc, Pass);
		Aparr.push_back(temp);
		num++;
	}
	ifs.close();
	bool IsLogin = false;
	for (int i = 0; i < num; i++)
	{
		if (Aparr[i].m_Pa == password && Aparr[i].m_Ac == account)
		{	
			IsLogin = true;
			cout << "µÇÂ½³É¹¦£¡" << endl;
			if (account == "123") 
			{ 
				system("pause");
				system("cls");
				return 1; 
			}
			else 
			{ 
				system("pause");
				system("cls");
				return 0; 
			}
		}
		else IsLogin = false;
	}
	if (IsLogin == false)
	{
		cout << "ÕËºÅ»òÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£¡" << endl;
		system("pause");
		system("cls");
		MAX_TRY_TIMES--;
		if (MAX_TRY_TIMES <= 0) {
			cout << "³¢ÊÔµÇÂ¼´ÎÊý¹ý¶à£¬³ÌÐòÍË³ö£¡" << endl;
			exit(0);
		}
		Login();
	}
}