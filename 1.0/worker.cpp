#include "worker.h"
#include<iomanip>

// ���캯��
manager::manager(int id, string name, string gender, string dep, string level, int jId,double days,double leavedays)
{	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}

// ��ʾ������Ϣ
void manager::showInfo()
{
	cout << "��ţ� " << this->m_Id
		<< "\t������ " << this->m_Name
		<< setw(15) << "\t�Ա� " << this->m_Gender
		<< setw(10) << "\t���ţ� " << this->m_Dep
		<< setw(10) << "\t����" << this->m_Level
		<< setw(10) << "\t��λ�� " << this->getJobtName()
		<< setw(10) << "\t����ʱ�䣺 " << this->m_Days
		<< setw(10) << "\t�ݼ�ʱ�䣺 " << this->m_LeaveDays << endl;
}

// ��ȡ��λ����
string manager::getJobtName()
{
	return string("����");//����ת��Ϊstring
}





// ���캯��
technologist::technologist(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}
// ��ʾ������Ϣ
void technologist::showInfo()
{
	cout << "��ţ� " << this->m_Id
		<< "\t������ " << this->m_Name
		<< setw(15) << "\t�Ա� " << this->m_Gender
		<< setw(10) << "\t���ţ� " << this->m_Dep
		<< setw(10) << "\t����" << this->m_Level
		<< setw(10) << "\t��λ�� " << this->getJobtName()
		<< setw(10) << "\t����ʱ�䣺 " << this->m_Days
		<< setw(10) << "\t�ݼ�ʱ�䣺 " << this->m_LeaveDays << endl;
}
// ��ȡ��λ����
string technologist::getJobtName()
{
	return string("������Ա");//����ת��Ϊstring
}





// ���캯��
salesman::salesman(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}
// ��ʾ������Ϣ
void salesman::showInfo()
{
	cout << "��ţ� " << this->m_Id
		<< "\t������ " << this->m_Name
		<< setw(15) << "\t�Ա� " << this->m_Gender
		<< setw(10) << "\t���ţ� " << this->m_Dep
		<< setw(10) << "\t����" << this->m_Level
		<< setw(10) << "\t��λ�� " << this->getJobtName()
		<< setw(10) << "\t����ʱ�䣺 " << this->m_Days
		<< setw(10) << "\t�ݼ�ʱ�䣺 " << this->m_LeaveDays << endl;
		
}
// ��ȡ��λ����
string salesman::getJobtName()
{
	return string("������Ա");//����ת��Ϊstring
}





// ���캯��
salesmanager::salesmanager(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}

// ��ʾ������Ϣ
void salesmanager::showInfo()
{
	cout << "��ţ� " << this->m_Id
		<< "\t������ " << this->m_Name
		<< setw(15) << "\t�Ա� " << this->m_Gender
		<< setw(10) << "\t���ţ� " << this->m_Dep
		<< setw(10) << "\t����" << this->m_Level
		<< setw(10) << "\t��λ�� " << this->getJobtName()
		<< setw(10) << "\t����ʱ�䣺 " << this->m_Days
		<< setw(10) << "\t�ݼ�ʱ�䣺 " <<this->m_LeaveDays<< endl;
}

// ��ȡ��λ����
string salesmanager::getJobtName()
{
	return string("���۾���");//����ת��Ϊstring
}



