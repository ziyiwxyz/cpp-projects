#pragma once
#include <iostream>
#include <string>
using namespace std;

// Ա��������
class Worker
{public:
	//���麯�����������������
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ȡ��λ����
	virtual string getJobtName() = 0;

	// Ա�����
	int m_Id;
	// Ա������
	string m_Name;
	//Ա���Ա�
	string m_Gender;
	//Ա������
	string m_Dep;
	//Ա������
	string m_Level;
	// ��λ���
	int m_JobId;
	//����ʱ��
	double m_Days; 
	int m_hours;
	//�ݼ�ʱ��
	double m_LeaveDays;
	//����н��
	double m_wages;


};

// ������
class manager :public Worker
{
public:

	// ���캯��
	manager(int id, string name, string gender, string dep, string level, int jId,double days,double leavedays);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getJobtName();
};

// ������Ա��
class technologist :public Worker
{
public:

	// ���캯��
	technologist(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getJobtName();
};

// ������Ա��
class salesman:public Worker
{
public:

	// ���캯��
	salesman(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getJobtName();
};

// ���۾�����
class salesmanager :public Worker
{
public:

	// ���캯��
	salesmanager(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays);
	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getJobtName();
};