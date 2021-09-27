/*******************************************************
                        输出1、端口直接输出
                            2、文件输出
                            3、输出格式设定
 ********************************************************/
#include"SortStat.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"DA.h"
#include<time.h>
void printoneall(data *header)
{
    printf("姓名%s 写入时间%d%d工作时间%ld 加班时间%d 奖金%ld 生活津贴%ld 基本工资%ld 考核成绩%d 全额工资%.2f 税钱%.2f 税率%.2f 实际工资%.2f 年%d 月%d  "
           ,
           header->name,
           header->tim.year,
           header->tim.mon,
           header->commonday,
           header->overtime,
           header->bonus,
           header->all,
           header->basic,
           header->exam_grades,
           header->merit,
           header->tax,
           header->taxrate,
           header->salary,
           header->tyear,
           header->tmonth);
}

void printone(data *header,int choice[20])
{


    /*
    序号%d 姓名%s 写入时间%d%d%d工作时间%ld 加班时间%d 奖金%ld 生活津贴%ld 基本工资%ld 考核成绩%d 全额工资%.2f 税钱%.2f 税率%.2f 实际工资%.2f 年%d 月%d   "
     1       2           3 4 5         6         7        8           9          10          11         12       13      14            15    16	  17
    */
    int i=0;
    for(; i<20; i++)
    {
        switch(choice[i])
        {
        case 1:
            printf("序号%d",header->num);
            break;
        case 2:
            printf("姓名%s",header->name);
            break;
        case 3:
            printf("写入时间%d",header->tim.year);
            break;
        case 4:
            printf("%0d",header->tim.mon);
            break;
        case 5:
            printf("%0d",header->tim.mday);
            break;
        case 6:
            printf("工作时间%ld",header->commonday);
            break;
        case 7:
            printf("加班时间%d",header->overtime);
            break;
        case 8:
            printf("奖金%ld",header->bonus);
            break;
        case 9:
            printf("生活津贴%ld",header->all);
            break;
        case 10:
            printf("基本工资%ld",header->basic);
            break;
        case 11:
            printf("考核成绩%d",header->exam_grades);
            break;
        case 12:
            printf("全额工资%.2f",header->merit);
            break;
        case 13:
            printf("税钱%.2f",header->tax);
            break;
        case 14:
            printf("税率%.2f",header->taxrate);
            break;
        case 15:
            printf("实际工资%.2f",header->salary);
            break;
        case 16:
            printf("年%d",header->tyear);
            break;
        case 17:
            printf("月%d",header->tmonth);
            break;
        }
    }
}

void printlist(data *header)            //有头辣
{
    while(header->next!=NULL)
    {
        header=header->next;
        printoneall(header);
    }
}
