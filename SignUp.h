#pragma once
#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class AccPass
{
public:
	void SignUp();
private:
	string m_Account;
	string m_Password;
};