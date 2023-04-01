#include"SignUp.h"
#define AP "Account.txt"
#include <fstream>
#include<iostream>
#include<conio.h>
using namespace std;
string Password1="";
string Password2="";

void BuildPassword()
{	
	Password1 = "";
	Password2 = "";
	cout << "请输入您的密码:";
	char p;
	while (p = _getch())
	{
		if (p >= 32)
		{
			if (p != 32) Password1 = Password1 + p;
			cout << "*";
		}
		else break;
	}
	cout << endl;
	cout << "请再次确认您的密码:";
	while (p = _getch())
	{
		if (p >= 32)
		{
			if (p != 32) Password2 = Password2 + p;
			cout << "*";
		}
		else break;
	}
}
void AccPass::SignUp()
{
	ofstream ofs;
	ofs.open(AP, ios::out|ios::app);
	cout << "请输入您的账号:" ;
	string Account;
	cin >> m_Account;
	BuildPassword();
	if (Password1 != Password2)
	{
		cout << "两次密码不一致，请重新输入" << endl;
		BuildPassword();
	}
	m_Password = Password1;
	ofs << m_Account << " " << m_Password << endl;
	ofs.close();
	cout << endl;
	cout << "您已成功注册"<<endl;
}