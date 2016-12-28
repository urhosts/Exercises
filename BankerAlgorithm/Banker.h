#include <iostream>  
#include <cstdlib>  

#define M 16  
#define N 16  

using namespace std;

class Bank
{
private:
	int m;                //资源数量  
	int n;                //进程数量  
	int available[M];     //可利用资源向量  
	int max[M][N];        //最大需求矩阵  
	int allocation[M][N]; //分配矩阵  
	int need[M][N];       //需求矩阵  
public:
	bool Initilize();     //初始化各变量  
	bool IsSafe();        //检查系统是否安全  
	bool Resoure_allocate();//分配资源  
	bool IsFinish();      //检查系统是否运行完毕  
};

bool Bank::Initilize()
{
	int i, j;
	cout << "输入资源数量：";
	cin >> m;
	cout << "输入进程数量：";
	cin >> n;
	cout << "输入最大请求矩阵 " << n << "X" << m << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> max[i][j];
		}
	}
	cout << "输入分配矩阵 " << n << "X" << m << endl;
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
	cout << "输入可利用资源向量 " << 1 << "X" << m << endl;
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
	for (i = 0; i < n; i++)                 //标识变量初始化  
	{
		finish[i] = false;
	}
	for (i = 0, k = 0; i < n; i++)
	{
		if (!finish[i])
		{
			for (j = 0; j < m; j++)
			{
				if (need[i][j] > work[j])      //目前无法满足该进程  
				{
					break;
				}
			}

			if (j == m)                     //可以满足该进程  
			{
				result[k++] = i;
				for (j = 0; j < m; j++) //将现有可用资源数加上第i进程已经分配了的  
				{
					work[j] += allocation[i][j];
				}
				finish[i] = true;
				i = -1;                       //从头扫描  
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!finish[i])
		{
			cout << "没有安全序列" << endl;
			return false;
		}
	}
	cout << "安全序列是" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)            //如果进程已经执行完毕,则安全序列中不再输出  
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
	cout << "输入运行进程号:";
	cin >> process_id;
	cout << "请求资源号：";
	cin >> source_id;
	cout << "请求数量：";
	cin >> amount;

	if (amount > need[process_id][source_id])
	{
		cout << "请求不合法，终止运行" << endl;
		return false;
	}

	if (amount > available[source_id])
	{
		cout << "请求无法满足，等待" << endl;
		return false;
	}

	available[source_id] -= amount;                   //假定分配资源  
	allocation[process_id][source_id] += amount;
	need[process_id][source_id] -= amount;

	if (!IsSafe())                                  //检查系统是否安全  
	{
		available[source_id] += amount;
		allocation[process_id][source_id] -= amount;
		need[process_id][source_id] += amount;
		cout << "系统不安全，等待" << endl;
		return false;
	}

	for (i = 0; i < m; i++)                        //查看进程是否执行完毕  
	{
		if (allocation[process_id][i] != max[process_id][i])
		{
			break;
		}
	}

	if (i == m)                                     //进程执行完毕  
	{
		for (i = 0; i < m; i++)
		{
			available[i] += allocation[process_id][i];
			allocation[process_id][i] = 0;
			need[process_id][i] = 0;
		}
		cout << "进程" << process_id << "运行完毕" << endl;
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