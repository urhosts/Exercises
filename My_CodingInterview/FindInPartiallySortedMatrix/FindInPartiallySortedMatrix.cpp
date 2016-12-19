
bool Find(int* matrix, int rows, int columns, int number)	//rows 行	columns 列
{
	bool found = false;				//定义一个bool变量储存，以便统一返回

	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;			//选取第一行最后一个数作为查找起点
		while (row < rows && column >= 0)	//如果当前行小于总行，当前列只要不为零就进入循环
		{
			if (matrix[row * columns + column] == number)//这个地方一定要仔细想一想为什么是
														 //row*columns 后面这个为什么是带s的？
			{
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				--column;
			else
				++row;
		}
	}
//
//	return found;
//}
//
//// ====================测试代码====================
//void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
//{
//	if (testName != nullptr)
//		printf("%s begins: ", testName);
//
//	bool result = Find(matrix, rows, columns, number);
//	if (result == expected)
//		printf("Passed.\n");
//	else
//		printf("Failed.\n");
//}
//
////  1   2   8   9
////  2   4   9   12
////  4   7   10  13
////  6   8   11  15
//// 要查找的数在数组中
//void Test1()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test1", (int*)matrix, 4, 4, 7, true);
//}
//
////  1   2   8   9
////  2   4   9   12
////  4   7   10  13
////  6   8   11  15
//// 要查找的数不在数组中
//void Test2()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test2", (int*)matrix, 4, 4, 5, false);
//}
//
////  1   2   8   9
////  2   4   9   12
////  4   7   10  13
////  6   8   11  15
//// 要查找的数是数组中最小的数字
//void Test3()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test3", (int*)matrix, 4, 4, 1, true);
//}
//
////  1   2   8   9
////  2   4   9   12
////  4   7   10  13
////  6   8   11  15
//// 要查找的数是数组中最大的数字
//void Test4()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test4", (int*)matrix, 4, 4, 15, true);
//}
//
////  1   2   8   9
////  2   4   9   12
////  4   7   10  13
////  6   8   11  15
//// 要查找的数比数组中最小的数字还小
//void Test5()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test5", (int*)matrix, 4, 4, 0, false);
//}
//
////  1   2   8   9
////  2   4   9   12
////  4   7   10  13
////  6   8   11  15
//// 要查找的数比数组中最大的数字还大
//void Test6()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test6", (int*)matrix, 4, 4, 16, false);
//}
//
//// 鲁棒性测试，输入空指针
//void Test7()
//{
//	Test("Test7", nullptr, 0, 0, 16, false);
//}
//
//int main(int argc, char* argv[])
//{
//	Test1();
//	Test2();
//	Test3();
//	Test4();
//	Test5();
//	Test6();
//	Test7();
//
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//using namespace std;
//
//bool Find(int* matrix, int rows, int columns, int number)	//rows 行	columns 列
//{ 
//	bool found = false;
//
//	if (matrix != NULL && rows > 0 && columns > 0)
//	{
//		int row = 0;
//		int column = columns - 1;
//		
//		while (row<rows && column>0)
//		{
//			if (matrix[row*columns + column] == number)
//			{
//				found = true;
//				break;
//			}
//			else if (matrix[row*columns + column] > number)
//				--column;
//			else
//				++row;
//		}
//	}
//	return found;
//}
//
void test()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	bool ret = Find((int *)matrix, 4, 4, 12); //如果找到就返回1,找不到就返回0
	printf("%d\n", ret);					  //偷懒只写了一组，其他的都是这个样子的，领悟思想，嗯！
}

int main()
{
	test();
	system("pause");
	return 0;
}

#include <stdio.h>

bool Find(int* matrix, int rows, int columns, int number)	//rows 行	columns 列
{
	bool found = false;

	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row<rows && column>0)
		{
			if (matrix[row*column + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row*column + column] > number)
				--column;
			else
				++row;
		}
	}
}