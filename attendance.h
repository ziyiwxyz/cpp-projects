/*#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class hoursconverttodays:public Worker
{public:
	
	void converttohours(double days);
	void converttodays(int hours);
	int gethours();
	double getdays();
};

class sickandleave:public hoursconverttodays
{public:
	double sickleave;//Ա������û����������
	double sickleaveMax=2;//�������Բ����������� 16Сʱ
	double paidleave;//Ա���Ѿ���н�ݼٵ����� 
	double paidleaveMax=3;//Ա�����Դ�н�ݼٵ����� 24Сʱ
	double paiddays;//Ա�������㹤�ʵ����� paiddays=sickleave+paidleave
};*/