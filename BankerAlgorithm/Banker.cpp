#include "Banker.h"

using namespace std;

int main()
{
	Bank process;

	if (!process.Initilize())   //初始化  
	{
		cout << "输入错误" << endl;
	}

	if (!process.IsSafe())      //检查系统运行初是否安全  
	{
		return 0;
	}

	while (true)
	{
		process.Resoure_allocate();     //根据各进程需要分配资源  
		if (process.IsFinish())         //检查系统是否执行完毕  
		{
			cout << "所有进程执行完毕" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}