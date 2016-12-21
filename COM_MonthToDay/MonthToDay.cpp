//#include <iostream>
//
//using namespace std;
//
//int ReturnWeekDay(unsigned int iYear, unsigned int iMonth, unsigned int iDay)
//{
//	int iWeek = 0;
//	unsigned int y = 0, c = 0, m = 0, d = 0;
//
//	if (iMonth == 1 || iMonth == 2)
//	{
//		c = (iYear - 1) / 100;
//		y = (iYear - 1) % 100;
//		m = iMonth + 12;
//		d = iDay;
//	}
//	else
//	{
//		c = iYear / 100;
//		y = iYear % 100;
//		m = iMonth;
//		d = iDay;
//	}
//
//	iWeek = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;    //蔡勒公式  
//	iWeek = iWeek >= 0 ? (iWeek % 7) : (iWeek % 7 + 7);    //iWeek为负时取模  
//	if (iWeek == 0)    //星期日不作为一周的第一天  
//	{
//		iWeek = 7;
//	}
//
//	return iWeek;
//}
//
//int main()
//{
//	int year, month, day = 0;
//	cin << year << "-" << month << "-" << day;
//	ReturnWeekDay(year, month, day);
//	cout<<
//}
//
//#include <cstdio>
//
//void CaculateWeekDay(int y, int m, int d)
//{
//	if (m == 1 || m == 2) {
//		m += 12;
//		y--;
//	}
//	int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
//	switch (iWeek)
//	{
//	case 0: printf("星期一\n"); break;
//	case 1: printf("星期二\n"); break;
//	case 2: printf("星期三\n"); break;
//	case 3: printf("星期四\n"); break;
//	case 4: printf("星期五\n"); break;
//	case 5: printf("星期六\n"); break;
//	case 6: printf("星期日\n"); break;
//	}
//}
//void main()
//{
//	int year = 0, month = 0, day = 0;
//	printf("请输入日期：\n格式为：1900,1,1\n");
//	char temp = '1';
//	while (temp != '0')
//	{
//		scanf("%d,%d,%d", &year, &month, &day);
//		scanf("%c", &temp);
//		CaculateWeekDay(year, month, day);
//		printf("输入0退出,其他继续:");
//		scanf("%c", &temp);
//	}
//}

#include<iostream>

using namespace std;

struct time
{
	int year;
	int month;
	int day;
	unsigned int weekday;
};

void initialtime(time & t);//输入初始化时间
void Show(time & t);//显示时间信息
int Weekdaycount(time & t);//计算当日是星期几
int Daycount(time & t);//计算当日是第公元多少天
int Daysyearcount(time & t);//计算当日是该年的第多少天
bool isleapyear(time & t);//判断该年是不是闰年
bool check(time &t);//检查时间格式是否正确

int main()
{
	time t;
	initialtime(t);
	Show(t);
	system("pause");
	return 0;
}

bool check(time &t)
{
	if (t.year <= 0 || (t.month <= 0 || t.month > 12) || t.day <= 0)
		return false;
	else
	{
		if ((t.month == 1 || t.month == 3 || t.month == 5 || t.month == 7
			|| t.month == 8 || t.month == 10 || t.month == 12) && t.day > 31)
			return false;
		else
		{
			if ((t.month == 4 || t.month == 6 || t.month == 9 || t.month == 11
				) && t.day > 30)return false;
			else
			{
				if (t.month == 2)
				{
					if (isleapyear(t))
					{
						if (t.day > 29)
							return false;
						else return true;
					}
					else
					{
						if (t.day > 28)
							return false;
						else
							return true;
					}
				}
			}
		}
	}
}
void initialtime(time & t)
{
	cout << "Enter the time (year,month,day):\n";
	cin >> t.year;
	cin.get();
	cin >> t.month;
	cin.get();
	cin >> t.day;
	cin.get();
	if (!check(t)){ cout << "Try again:\n"; initialtime(t); }
	else
		t.weekday = Weekdaycount(t);
}
void Show(time & t)
{
	cout << "Year: " << t.year << "\t";
	cout << "Month: " << t.month << "\t";
	cout << "Day: " << t.day << "\t";
	cout << "Weekday: " << t.weekday << endl;
	cout << "This is a ";
	if (isleapyear(t))cout << "leap"; else cout << "nonleap";
	cout << " year.\n";
	cout << "Today is the " << Daysyearcount(t) << " days of the year.\n";
}
int Weekdaycount(time & t)
{
	return Daycount(t) % 7;
}
int Daycount(time & t)
{
	int days = 0;
	days = (t.year - 1) * 365 + (t.year - 1) / 4 - (t.year - 1) / 100
		+ (t.year - 1) / 400 + Daysyearcount(t);
	return days;
}
bool isleapyear(time & t)
{
	if (t.year % 4 == 0 && t.year % 100 != 0) return true;//年是四的倍数而且不是100的倍数，是闰年
	if (t.year % 400 == 0)return true;
	else return false;
}
int Daysyearcount(time & t)
{
	int days = 0;
	int mtemp = t.month - 1;
	while (mtemp > 0)
	{
		switch (mtemp)
		{
		case(1) :
		case(3) :
		case(5) :
		case(7) :
		case(8) :
		case(10) :
		case(12) :
				 days += 31; break;
		case(4) :
		case(6) :
		case(9) :
		case(11) :
				 days += 30; break;
		case(2) :
			days += 28; break;
		default:
			break;
		}
		--mtemp;
	}
	if (isleapyear(t))++days;//如果是闰年，再加上一天
	return days + t.day;//返回计算的天数加上当月的天数
}
