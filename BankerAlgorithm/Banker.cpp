#include "Banker.h"

using namespace std;

int main()
{
	Bank process;

	if (!process.Initilize())   //��ʼ��  
	{
		cout << "�������" << endl;
	}

	if (!process.IsSafe())      //���ϵͳ���г��Ƿ�ȫ  
	{
		return 0;
	}

	while (true)
	{
		process.Resoure_allocate();     //���ݸ�������Ҫ������Դ  
		if (process.IsFinish())         //���ϵͳ�Ƿ�ִ�����  
		{
			cout << "���н���ִ�����" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}