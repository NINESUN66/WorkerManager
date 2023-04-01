#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"Worker.h"
using namespace std;
#define FILENAME "WorkerManager.txt" 
//�����������
class WorkManager
{
public:
	WorkManager();
	~WorkManager();
	void ShowMenuA();
	void ShowMenuB();
	void exitSystem();
	//��¼ְ������
	int m_EmpNum;
	//ְ�������ָ��
	Worker** m_EmpArray;
	//���ְ��
	void addEmp();
	//�����ļ�
	void Save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//��¼�ļ��е�ְ����
	int get_EmpNum();
	//�����ļ��е�ְ����Ϣ
	void InputEmpArr();
	//��ʾְ������
	void ShowEmp();
	//���ְ���Ƿ����
	bool IsExist(int, string, int);
	//ʵ��ɾ��ְ��
	void DeleEmp();
	int Select();
	//ʵ���޸�ְ��
	void ChangeEmp();
	//ʵ�ֲ���Ա��
	void SearchEmp();
	//���ձ������
	void RankId();
	//ʵ����������ĵ�
	void CleanAll();
};
