#include "workerManager.h"
using namespace std;
// ���캯��
WorkerManager::WorkerManager():m_EmpNum(0)
{
	// �жϴ洢�ļ�״̬

	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ�

	// 1���ļ������ڵ����
	if (!ifs.is_open())//is_open()������������ж��ļ��Ƿ�ɹ���
	{
		cout << "�ļ�������" << endl;
		// ��ʼ������
		// ��ʼ������
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	// 2���ļ����ڣ�����Ϊ�գ�û�м�¼�κ�Ա����Ϣ
	// �ж��ļ��Ƿ�Ϊ��
	string ch;
	ifs >> ch;
	if (ifs.eof()) // end of file���ļ���β
	{
		cout << "�ļ�Ϊ��" << endl;
		// ��ʼ������
		// ��ʼ������
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	// 3���ļ����ڣ���������Ա����Ϣ
	int num = this->get_EmpNum();
	// ���Դ���
	/*cout << "Ա������Ϊ��" << num << endl;*/
	this->m_EmpNum = num;

	// ����ռ䣬��Ÿ���Ա��ָ�������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ���ļ��е�Ա������,�浽������
	this->init_Emp();

}

// չʾ�˵�
void WorkerManager::ShowMenu()
{
	cout << "============[��ӭ������˾Ա�����ڹ���ϵͳ��]============" << endl;
	cout << "========================[���˵�]========================" << endl;
	cout << "====================[0.�˳�����ϵͳ]====================" << endl;
	cout << "====================[1.����Ա����Ϣ]====================" << endl;
	cout << "====================[2.��ʾԱ����Ϣ]====================" << endl;
	cout << "====================[3.ɾ��Ա����Ϣ]====================" << endl;
	cout << "====================[4.�޸�Ա����Ϣ]====================" << endl;
	cout << "====================[5.����Ա����Ϣ]====================" << endl;
	cout << "====================[6.����Ա����Ϣ]====================" << endl;
	cout << "====================[7.ͳ��Ա����Ϣ]====================" << endl;
	cout << endl;
}

// ���Ա��
void WorkerManager::Add_Emp()
{
	cout << "���������Ա����������" << endl;
	int addNum = 0; // �����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		// ��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum+8; // �¿ռ����� = ԭ����¼������ + ��������

		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];//Worker** m_EmpArray ==Worker *m_EmpArray[]

		// ��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) // �ж�ԭ�����Ƿ�Ϊ��
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		// �������������
		for (int i = 0; i < addNum; i++)
		{
			int id; // Ա�����
			string name; // Ա������
			string gender;
			string dep;
			string level;
			double days;
			double leavedays;
			int dSelect; // ѡ��

			cout << "�������" << i + 1 << "����Ա����ţ�" << endl;
			cin >> id;
			if (isExist(id) == -1)
			{
				cout << "�������" << i + 1 << "����Ա��������" << endl;
				cin >> name;
				cout << "�������" << i + 1 << "����Ա���Ա�" << endl;
				cin >> gender;
				cout << "�������" << i + 1 << "����Ա�����ţ�" << endl;
				cin >> dep;
				cout << "�������" << i + 1 << "����Ա������" << endl;
				cin >> level;
				cout << "�������" << i + 1 << "����Ա������ʱ�䣺" << endl;
				cin >> days;
				cout << "�������" << i + 1 << "����Ա���ݼ�ʱ�䣺" << endl;
				cin >> leavedays;
				cout << "��ѡ���Ա���ĸ�λ��" << endl;
				cout << "1������" << endl;
				cout << "2��������Ա" << endl;
				cout << "3��������Ա" << endl;
				cout << "4�����۾���" << endl;
				cin >> dSelect;

				
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new manager(id,name, gender, dep,level,1,days,leavedays);
					break;
				case 2:
					worker = new technologist(id, name, gender, dep, level, 1, days, leavedays);
					break;
				case 3:
					worker = new salesman(id, name, gender, dep, level, 1, days, leavedays);
					break;
				case 4:
					worker = new salesmanager(id, name, gender, dep, level, 1, days, leavedays);
					break;
				default:
					cout << "��������ȷ������ѡ�";
					return;
				}
				// ������Ա����ָ�룬������������
				if (this->m_EmpNum + i <= newSize)
				{
					newSpace[this->m_EmpNum + i] = worker;
				}
			
				
			}
			else
			{
				cout << "����ı��["<<id<<"]�Ѵ��ڣ����������룡" << endl;
	
				system("pause");
				system("cls");
				return;
			}
		}
		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		// �����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		// �����µ�ְ������
		this->m_EmpNum = newSize;

		// ��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��!" << endl;

		// ����Ա����ϢΪ�ļ�
		this->save();

		// ����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "������������" << endl;
	}

	// ��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

// �����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// ��д�ļ��ķ�ʽ���ļ�
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;	// ʧ�ܽ���
	}

	// ��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Gender << " "
			<< this->m_EmpArray[i]->m_Dep << " "
			<< this->m_EmpArray[i]->m_Level << " "
			<< this->m_EmpArray[i]->m_JobId
			<< this->m_EmpArray[i]->m_Days 
			<< this->m_EmpArray[i]->m_LeaveDays << endl;
	}

	// �ر��ļ�
	ofs.close();
}

// ͳ���ļ��������� �������ж��ļ�����Ա�Ĵ洢���
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ� ��

	int id;
	string name;
	string gender;
	string dep;
	string level;
	int jId;
	double days;
	double leavedays;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> dep &&ifs>>level&& ifs >> jId&&ifs>>days && ifs >> leavedays)
	{
		num++;
	}

	return num;
}

int WorkerManager::get_JobNum(int i)
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ� ��

	int id;
	string name;
	string gender;
	string dep;
	string level;
	int jId;
	double days;
	double leavedays;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> dep && ifs >>level&&ifs>> jId && ifs >> days && ifs >> leavedays)
	{
			if(jId==i)
			num++;
	}
	return num;
}

//ͳ�ƹ���
void WorkerManager::count_Emp()
{
	cout << "1.ͳ��������Ա����������" << endl;
	cout << "2.ͳ����һԱ�����ݼ�����"<<endl;
	cout << "��ѡ����Ҫʹ�õ�ͳ�ƹ���:" << endl;
	int temp; cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "������Ա����Ϊ��" <<get_EmpNum()<< endl;
		cout << "������Ա�������ֱ�Ϊ��" << endl;
		cout << "���������Ϊ��" <<get_JobNum(1)<< endl;
		cout << "������Ա������Ϊ��" << get_JobNum(2) << endl;
		cout << "������Ա������Ϊ��" << get_JobNum(3) << endl;
		cout << "���۾��������Ϊ��" << get_JobNum(4) << endl;
		break;

	case 2:
		Find_Emp();//ʹ�ò��Һ���
		break;
	
	default:
		cout << "��������ȷ������ѡ�" << endl;
		break;
	}

}

// ��ʼ��Ա�������ļ��ж�ȡ����Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string gender;
	string dep;
	string level;
	int jId;
	double days;
	double leavedays;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> gender&&ifs>>dep&&ifs>>level&&ifs>>jId && ifs >> days&& ifs >> leavedays)
	{
		Worker* worker = NULL;

		if (jId == 1) // ����
		{
			worker = new manager(id, name,gender,dep,level,jId,days,leavedays);
		}
		else if (jId == 2) // ������Ա
		{
			worker = new technologist(id, name, gender, dep, level, jId, days, leavedays);
		}
		else if (jId == 3) // ������Ա
		{
			worker = new salesman(id, name, gender, dep, level, jId, days, leavedays);
		}
		else // ���۾���
		{
			worker = new salesmanager(id, name, gender, dep, level, jId, days, leavedays);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	// �ر��ļ�
	ifs.close();
}

// ��ʾԱ��
void WorkerManager::show_Emp()
{
	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// ���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	// �����������
	system("pause");
	system("cls");
}

// �ж�Ա���Ƿ���ڡ������ڣ����������е�λ�ã������ڷ���-1
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			// �ҵ�Ա��
			index = i;
			break;
		}
	}
	return index;
}

// ɾ��Ա��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������ɾ����Ա�����(����֪��������ʹ��5.���ҹ��ܲ���Ա�����)��" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) // ˵��Ա�����ڣ�����Ҫɾ��indexλ�������ϵ�Ա��
		{
			cout << "Ҫɾ��Ա������Ϣ��" << endl;
			// ���ö�̬���ó���ӿ���ʾԱ����Ϣ
			this->m_EmpArray[index]->showInfo();
			//ȷ���Ƿ�Ҫ�޸�
			cout << "ȷ���Ƿ�Ҫɾ��Ա������Ϣ���ǣ�\"1\"���߷�\"2\"��" << endl;
			int temp; cin >> temp;
			if (temp == 1)
			{
				// �ͷ�ɾ������Ա�����ڴ�
				delete this->m_EmpArray[index];
				// ����ǰ��
				for (int i = index; i < this->m_EmpNum; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--; // ���������м�¼��Ա����
				// ����ͬ�����µ��ļ���
				this->save();
				cout << "ɾ���ɹ���" << endl;
			}
			else if (temp == 2)
			{
				return;
			}
			else
				cout << "�������ǣ�\"1\"���߷�\"2\"��" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ�Ա��" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");
}

// �޸�Ա��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			

			// ����Ϣ ��ʼ��
			int newId = 0;
			string newName = "";
			string newGender ="";
			string newDep="";
			string newLevel = "";
			int newjId = 0;
			double newDays=0;
			double newLeaveDays = 0;

			cout << "Ҫ�޸ĵ�Ա��ԭ������Ϣ��" << endl ;
			// ���ö�̬���ó���ӿ���ʾԱ����Ϣ
			this->m_EmpArray[index]->showInfo();
			//ȷ���Ƿ�Ҫ�޸�
			cout << "ȷ���Ƿ�Ҫ�޸ĸ�Ա������Ϣ���ǣ�\"1\"���߷�\"2\"��"<<endl;
			int temp; cin >> temp;
			if (temp == 1)
			{ 	// ���ҵ�Ա�����
				// �ͷ�ɾ������Ա�����ڴ�
				delete this->m_EmpArray[index];
				cout << "�������±�ţ�";
				cin >> newId;
				if(this->isExist(newId)==-1)
				{
				cout << "������������" << endl;
				cin >> newName;
				cout << "�������Ա�" << endl;
				cin >> newGender; 
				cout << "�����벿�ţ�" << endl;
				cin >> newDep;
				cout << "�����뼶��" << endl;
				cin >> newLevel;
				cout << "�����빤��ʱ�䣺" << endl;
				cin >> newDays;
				cout << "�������ݼ�ʱ�䣺" << endl;
				cin >> newLeaveDays;
				cout << "��ѡ���Ա���ĸ�λ��" << endl;
				cout << "1������" << endl;
				cout << "2��������Ա" << endl;
				cout << "3��������Ա" << endl;
				cout << "4�����۾���" << endl;
				cin >> newjId;

				Worker* worker = NULL;
				switch (newjId)
				{
				case 1:
					worker = new manager(newId, newName,newGender,newDep,newLevel,newjId,newDays,newLeaveDays);
					break;
				case 2:
					worker = new technologist(newId, newName, newGender, newDep, newLevel, newjId, newDays, newLeaveDays);
					break;
				case 3:
					worker = new salesman(newId, newName, newGender, newDep, newLevel, newjId, newDays, newLeaveDays);
					break;
				case 4:
					worker = new salesmanager(newId, newName, newGender, newDep, newLevel, newjId, newDays, newLeaveDays);
					break;
				default:
					cout << "��������ȷ������ѡ�";
					return;
				}

				// �������ݵ�������
				this->m_EmpArray[index] = worker;

				cout << "�޸ĳɹ���" << endl;

				// ���ݱ��浽�ļ���
				this->save();
				}
				else if (this->isExist(newId) != -1)
				{
					cout << "��id�Ѵ���,�����²�����" << endl;
					return; 
				}
			}
			else if (temp ==2)
				return;
			else
				cout << "�������ǣ�\"1\"���߷�\"2\"��"<<endl;
			
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");
}

// ����Ա��
// �ṩ���ֲ��ҷ�ʽ��һ�ְ���Ա����ţ�һ�ְ���Ա����������Ų���������������������
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������Ա����Ų���" << endl;
		cout << "2������Ա����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// ����Ų���
			int id;
			cout << "������Ա����ţ�" << endl;
			cin >> id;

			int index = isExist(id);
			if (index != -1)
			{
				// �ҵ�Ա��
				cout << "���ҳɹ�����Ա����Ϣ���£�" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			// ����������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false; // ���ҵ���־��0-δ�ҵ���1-���ҵ�
							   // û����breakȥ��i����ķ�������Ϊ���������ظ�ʱҲ��ȫ����ʾ
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���Ա�����Ϊ��"
						<< this->m_EmpArray[i]->m_Id
						<< " ����Ϣ���£�" << endl;

					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			// �������
			cout << "����ѡ������" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");
}

// ����ѡ������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		// �����������
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����Ա���������" << endl;
		cout << "2����Ա����Ž���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) // ����
				{
					if (m_EmpArray[minOrmax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
				else // ����
				{
					if (m_EmpArray[minOrmax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
			}

			if (i != minOrmax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrmax];
				m_EmpArray[minOrmax] = temp;
			}
		}

		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->show_Emp();
	}

}

// ��������
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
	//
	// ��Ϊ���� �����¿ռ�ָ�������ͷ� this->m_EmpArray �����ͷ� newSpace��
}