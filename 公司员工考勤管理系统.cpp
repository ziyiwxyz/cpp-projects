#include <iostream>
using namespace std;
#include <string>
#include "workerManager.h"
#include "worker.h"

int main()
{
	int choice = 0;	// �洢�û�ѡ��
	WorkerManager wm;

	while (true)
	{

		// ��ʾ�˵�
		wm.ShowMenu();

		// ��ȡ�û�����Ĺ���
		cout << "��������ѡ��Ĺ��ܣ�" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:	// �˳�ϵͳ
			cout << "��ӭ���´�ʹ�ã�";
			return 0;
		case 1:	// ���Ա��
			wm.Add_Emp();
			break;
		case 2:	// ��ʾԱ��
			wm.show_Emp();
			break;
		case 3:	// ɾ��Ա��
			wm.Del_Emp();
			break;
		case 4:	// �޸�Ա��
			wm.Mod_Emp();
			break;
		case 5:	// ����Ա��
			wm.Find_Emp();
			break;
		case 6:	// ����Ա��
			wm.Sort_Emp();
			break;
		case 7:	// ͳ�ƹ���
			wm.count_Emp();
			break;
		//case 8��//Ա��
		
		default:
			cout << "��������ȷ������ѡ�" << endl;	
			break;
		}
	}

	system("pause");
	return 0;
}