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
	cout << "��������������:";
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
	cout << "���ٴ�ȷ����������:";
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
	cout << "�����������˺�:" ;
	string Account;
	cin >> m_Account;
	BuildPassword();
	if (Password1 != Password2)
	{
		cout << "�������벻һ�£�����������" << endl;
		BuildPassword();
	}
	m_Password = Password1;
	ofs << m_Account << " " << m_Password << endl;
	ofs.close();
	cout << endl;
	cout << "���ѳɹ�ע��"<<endl;
}