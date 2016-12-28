#include <iostream>  
#include <cstdlib>  

#define M 16  
#define N 16  

using namespace std;

class Bank
{
private:
	int m;                //��Դ����  
	int n;                //��������  
	int available[M];     //��������Դ����  
	int max[M][N];        //����������  
	int allocation[M][N]; //�������  
	int need[M][N];       //�������  
public:
	bool Initilize();     //��ʼ��������  
	bool IsSafe();        //���ϵͳ�Ƿ�ȫ  
	bool Resoure_allocate();//������Դ  
	bool IsFinish();      //���ϵͳ�Ƿ��������  
};

bool Bank::Initilize()
{
	int i, j;
	cout << "������Դ������";
	cin >> m;
	cout << "�������������";
	cin >> n;
	cout << "�������������� " << n << "X" << m << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> max[i][j];
		}
	}
	cout << "���������� " << n << "X" << m << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> allocation[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
			if (need[i][j] < 0)
			{
				return false;
			}
		}
	}
	cout << "�����������Դ���� " << 1 << "X" << m << endl;
	for (i = 0; i < m; i++)
	{
		cin >> available[i];
		if (available[i] < 0)
		{
			return false;
		}
	}
	return true;
}

bool Bank::IsSafe()
{
	int i, j, k, result[N], work[M], finish[N];
	for (i = 0; i < m; i++)
	{
		work[i] = available[i];
	}
	for (i = 0; i < n; i++)                 //��ʶ������ʼ��  
	{
		finish[i] = false;
	}
	for (i = 0, k = 0; i < n; i++)
	{
		if (!finish[i])
		{
			for (j = 0; j < m; j++)
			{
				if (need[i][j] > work[j])      //Ŀǰ�޷�����ý���  
				{
					break;
				}
			}

			if (j == m)                     //��������ý���  
			{
				result[k++] = i;
				for (j = 0; j < m; j++) //�����п�����Դ�����ϵ�i�����Ѿ������˵�  
				{
					work[j] += allocation[i][j];
				}
				finish[i] = true;
				i = -1;                       //��ͷɨ��  
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!finish[i])
		{
			cout << "û�а�ȫ����" << endl;
			return false;
		}
	}
	cout << "��ȫ������" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)            //��������Ѿ�ִ�����,��ȫ�����в������  
		{
			if (need[result[i]][j] != 0)
			{
				break;
			}
		}
		if (j == m)
		{
			continue;
		}
		cout << result[i] << " ";
	}
	cout << endl;
	return true;
}

bool Bank::Resoure_allocate()
{
	int i, process_id, source_id, amount;
	cout << "�������н��̺�:";
	cin >> process_id;
	cout << "������Դ�ţ�";
	cin >> source_id;
	cout << "����������";
	cin >> amount;

	if (amount > need[process_id][source_id])
	{
		cout << "���󲻺Ϸ�����ֹ����" << endl;
		return false;
	}

	if (amount > available[source_id])
	{
		cout << "�����޷����㣬�ȴ�" << endl;
		return false;
	}

	available[source_id] -= amount;                   //�ٶ�������Դ  
	allocation[process_id][source_id] += amount;
	need[process_id][source_id] -= amount;

	if (!IsSafe())                                  //���ϵͳ�Ƿ�ȫ  
	{
		available[source_id] += amount;
		allocation[process_id][source_id] -= amount;
		need[process_id][source_id] += amount;
		cout << "ϵͳ����ȫ���ȴ�" << endl;
		return false;
	}

	for (i = 0; i < m; i++)                        //�鿴�����Ƿ�ִ�����  
	{
		if (allocation[process_id][i] != max[process_id][i])
		{
			break;
		}
	}

	if (i == m)                                     //����ִ�����  
	{
		for (i = 0; i < m; i++)
		{
			available[i] += allocation[process_id][i];
			allocation[process_id][i] = 0;
			need[process_id][i] = 0;
		}
		cout << "����" << process_id << "�������" << endl;
	}
	return true;
}

bool Bank::IsFinish()
{
	int i, j, finish[N];

	for (i = 0; i < n; i++)
	{
		finish[i] = false;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (need[i][j] != 0)
			{
				break;
			}
		}
		if (j == m)
		{
			finish[i] = true;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (finish[i] == false)
		{
			break;
		}
	}
	if (i != n)
	{
		return false;
	}
	return true;
}