
bool Find(int* matrix, int rows, int columns, int number)	//rows ��	columns ��
{
	bool found = false;				//����һ��bool�������棬�Ա�ͳһ����

	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;			//ѡȡ��һ�����һ������Ϊ�������
		while (row < rows && column >= 0)	//�����ǰ��С�����У���ǰ��ֻҪ��Ϊ��ͽ���ѭ��
		{
			if (matrix[row * columns + column] == number)//����ط�һ��Ҫ��ϸ��һ��Ϊʲô��
														 //row*columns �������Ϊʲô�Ǵ�s�ģ�
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
//// ====================���Դ���====================
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
//// Ҫ���ҵ�����������
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
//// Ҫ���ҵ�������������
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
//// Ҫ���ҵ�������������С������
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
//// Ҫ���ҵ�������������������
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
//// Ҫ���ҵ�������������С�����ֻ�С
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
//// Ҫ���ҵ������������������ֻ���
//void Test6()
//{
//	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	Test("Test6", (int*)matrix, 4, 4, 16, false);
//}
//
//// ³���Բ��ԣ������ָ��
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
//bool Find(int* matrix, int rows, int columns, int number)	//rows ��	columns ��
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
	bool ret = Find((int *)matrix, 4, 4, 12); //����ҵ��ͷ���1,�Ҳ����ͷ���0
	printf("%d\n", ret);					  //͵��ֻд��һ�飬�����Ķ���������ӵģ�����˼�룬�ţ�
}

int main()
{
	test();
	system("pause");
	return 0;
}

#include <stdio.h>

bool Find(int* matrix, int rows, int columns, int number)	//rows ��	columns ��
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