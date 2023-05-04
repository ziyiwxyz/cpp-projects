#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;

#define FILENAME "��˾���ڹ���ϵͳ.txt"

class WorkerManager
{
public:

	// ���캯��
	WorkerManager();

	// չʾ�˵�
	void ShowMenu();

	// ��¼Ա������
	int m_EmpNum;

	// Ա��ָ������
	Worker** m_EmpArray;//Ҳ����д��Worker *m_EmpArray[]

	// ���Ա��
	void Add_Emp();

	// �����ļ�
	void save();

	// �ж��ļ��ͷ�Ϊ�� �ı�־
	bool m_FileIsEmpty;

	// ͳ���ļ��е�����
	int get_EmpNum();

	//ͳ���ļ��и���������
	int get_JobNum(int i);

	//ͳ�ƹ���
	void count_Emp();

	// ��ʼ��Ա�������ļ��ж�ȡ����Ա��
	void init_Emp();

	// ��ʾԱ��
	void show_Emp();

	// �ж�Ա���Ƿ���ڡ������ڣ����������е�λ�ã������ڷ���-1
	int isExist(int id);

	// ɾ��Ա��
	void Del_Emp();

	// �޸�Ա��
	void Mod_Emp();

	// ����Ա��
	void Find_Emp();

	// ����ѡ������
	void Sort_Emp();

	// ��������
	~WorkerManager();
};