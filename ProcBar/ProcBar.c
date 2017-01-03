/*************************************************************************
	> File Name: ProcBar.c
	> Author: hosts
	> Mail: hosts@gsxio.com
	> Created Time: Sun 01 Jan 2017 10:30:40 AM EST
 ************************************************************************/

#include"ProcBar.h"
void ProcBar()
{
    int rate = 0;
    char str[102]={ 0 };
    const char* sta = "-\\|/";
    str[0]='\0';
    while(rate <= 100)
    {
        str[rate] = '-';
        printf("[%-100s],%d%%,[%c]\r",str,rate,sta[rate%4]);
        fflush(stdout);
        if(rate!=0);
            str[rate-1];
        str[rate]='=';
        str[++rate]='\0';
        usleep(100000);
    }
}

