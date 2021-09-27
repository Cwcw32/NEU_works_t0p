#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include"DA.h"
#include"SS.h"
#include"SortStat.h"
#include"DI.h"
#include <math.h>

/*******************************************************
            环境1、菜单
                2、分支
                3、联系方式
 ******************************************************/
/***************************************************************************************

   WINDOWS界面                                 DEBUG(100/100）

*********************************************************************************/

void gotoxy(int x,int y)
{
    COORD Pos;
    Pos.X=x;//横坐标
    Pos.Y=y;//纵坐标
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
void draw()//美丽的画卷~
{
    double y,x,f;
    for(y = 4; y >= -4; y -=1)
    {
        for(x = -12; x <= 12; x += 0.75)
        {
            f = 16*x*x + 144*y*y - 144*16;	//函数方程
            //fputc(f > 1E-5 ? '*' : ' ', fp);
            if(x<-(1e-5))
                putchar(f > 1E-15 ? '<' : ' ');
            else if(x>1e-5)
                putchar(f>1E-15?'>':' ');
        }
        //fputc('\n', fp);
        putchar('\n');
    }
}
/***************************************************************************************

   注册界面                                 DEBUG(100/100）

*********************************************************************************/
void Menu3()                                                       //注册界面
{
    while(1)
    {
        system("cls");
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|         注册界面：                |");
        printf("\n\t\t\t\t\t|                 （一）注册        |");
        printf("\n\t\t\t\t\t|                 （二）返回        |");
        //  printf("\n\t\t\t\t\t|                 （三）退出        |");
        //printf("\n\t\t\t\t\t|                 （四）注册        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[    ]  （输入“返回”等以选择操作）");
        int d;
        for(d=35; d>0; d--)
            printf("\b");
        char choice[20];
        scanf("%s",choice);
        if(!(strcmp(choice,"注册" ))||(choice[0]=='1'&&choice[1]=='\0'))
            Accreg();
        else if(!(strcmp(choice,"返回"))||(choice[0]=='2'&&choice[1]=='\0'))
            return ;
        else
        {
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
            system("pause");
        }
    }
}
//注册老板账号界面
/***************************************************************************************

    用户菜单                                 DEBUG(100/100）

*********************************************************************************/
int Menu2()                                //次主菜单
{
    while(1)
    {
        system("cls");
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|         用户菜单：                |");
        printf("\n\t\t\t\t\t|                 （一）查询系统    |");
        printf("\n\t\t\t\t\t|                 （二）管理系统    |");
        printf("\n\t\t\t\t\t|                 （三）设置        |");
        printf("\n\t\t\t\t\t|                 （四）返回        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
        int d;
        for(d=41; d>0; d--)
            printf("\b");
        char choice[20];
        scanf("%s",choice);
        if(!(strcmp(choice,"查询系统" ))||(choice[0]=='1'&&choice[1]=='\0'))
            return 1;
        else if(!(strcmp(choice,"管理系统"))||(choice[0]=='2'&&choice[1]=='\0'))
            return 2;
        else if(!(strcmp(choice,"设置"))||(choice[0]=='3'&&choice[1]=='\0'))
            return 3;
        else if(!(strcmp(choice,"返回"))||(choice[0]=='4'&&choice[1]=='\0'))
            return 0;
        else
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
    }
}
/*int menu21()
{
    char choice[20];
    printf("\n\t\t\t次主菜单：\n\t\t\t（一）单项查找");
    printf("\n\t\t\t（二）组合查找（格式：20XX.XX.XX，如2018.01.01");
    printf("\n\t\t\t（三）返回");
    printf("\n\t\t\t请选择：\n\t\t\t");
    scanf("%s",choice);
    if (!(strcmp(choice,"单项查找")))
    {
        return 1;
    }
    else if(!(strcmp(choice,"组合查找")))
        return 2;
    else if(!(strcmp(choice,"返回")))
        return 0;
    else
        {
            printf("错误代码 01：非法输入，请重新输入\n\t\t\t       ");
            continue;
        }

}*/
/*
int menu211()                                                       ///单项查找
{
    while(1)
    {
        char choice[20];
        printf("\n\t\t\t次主菜单：\n\t\t\t（一）姓名查找");
        printf("\n\t\t\t（二）时间查找（格式：20XX.XX.XX，如2018.01.01");
        printf("\n\t\t\t（三）返回");
        printf("\n\t\t\t请选择：\n\t\t\t");
        scanf("%s",choice);
        if (!(strcmp(choice,"姓名")))
        {
            return 1;
        }
        else if(!(strcmp(choice,"时间查找")))
            return 2;                                    //退出
        else if(!(strcmp(choice,"返回")))
            return 0;
        else
        {
            printf("错误代码 01：非法输入，请重新输入\n\t\t\t       ");
            continue;
        }
    }
}
*/
/***************************************************************************************

    查询菜单                                  DEBUG(100/100）

*********************************************************************************/
void menu21()
{
    while(1)
    {
        system("cls");
        char choice[20];
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|        查询界面：                 |");
        printf("\n\t\t\t\t\t|                 （一）组合全体查询|");
        printf("\n\t\t\t\t\t|                 （二）目标单独查询|");
        printf("\n\t\t\t\t\t|                 （三）数据统计    |");
        printf("\n\t\t\t\t\t|                 （四）返回        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
        int d;
        for(d=41; d>0; d--)
            printf("\b");
        scanf("%s",choice);
        if(!strcmp(choice,"组合全体查询")||(choice[0]=='1'&&choice[1]=='\0'))
        {
            data *he=(data*)malloc(sizeof(data));
            he->next=NULL;
            if(!DataIn(he))
                continue;
            int j=fchoice();
            if(j==0)
                continue;
            findy(he,j);
            DataFree(he);
        }
        else if(!strcmp(choice,"目标单独查询")||(choice[0]=='2'&&choice[1]=='\0'))
        {
            data *he=(data*)malloc(sizeof(data));
            DataIn(he);
            int j=fchoice();
            if(j==0)
                continue;
            findx(he,j);
            DataFree(he);
        }
        else if(!strcmp(choice,"统计")||(choice[0]=='3'&&choice[1]=='\0'))
        {
            data *he=(data *)malloc(sizeof(data));
            DataIn(he);
            Analyze(he);
            DataFree(he);
        }
        else if(!strcmp(choice,"返回")||(choice[0]=='4'&&choice[1]=='\0'))
        {

            return;
        }
        else
        {
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
            system("pause");
            printf("按任意键继续");
            continue;
        }
        system("pause");
        printf("按任意键继续");
    }
}
/***************************************************************************************

    管理菜单
                                      DEBUG(60/100）

*********************************************************************************/

int menu22()                                        //管理系统1数据维护系统（添加，删除，加密）
{
    while(1)
    {
        system("cls");
        char choice[20];
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|         管理界面：                |");
        printf("\n\t\t\t\t\t|                 （一）添加        |");
        printf("\n\t\t\t\t\t|                 （二）删除        |");
        printf("\n\t\t\t\t\t|                 （三）排序        |");
        printf("\n\t\t\t\t\t|                 （四）返回        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[    ]  （输入“登录”或输入“1”、“2”等以选择操作）");
        int d;
        for(d=35; d>0; d--)
            printf("\b");
        scanf("%s",choice);
        if (!(strcmp(choice,"添加"))||(choice[0]=='1'&&choice[1]=='\0'))                                 //添加(默认发放时间排序)
        {
            printf("\n请按提示输入\n");
            data *header=(data*)malloc(sizeof(data));
            //header->next=NULL;
            if(set(header))
                DataSave(header);       //输入正确保存，输入失败不保存
            else
            {
                free(header);
                continue;
            }
            free(header);
        }
        else if(!(strcmp(choice,"删除"))||(choice[0]=='2'&&choice[1]=='\0'))                             //删除/清空
        {
            DataClear();
        }
        else if(!(strcmp(choice,"排序"))||(choice[0]=='3'&&choice[1]=='\0'))
        {
            Sort();
        }
        else if(!(strcmp(choice,"返回"))||(choice[0]=='4'&&choice[1]=='\0'))                         //正常返回
        {
            return 0;
        }
        else                                                    //非法重输
        {
            printf("错误代码 01：非法输入，请重新输入\n\t\t\t       ");
            system("pause");
            printf("按任意键继续");
            continue;
        }
    }
}
/***************************************************************************************

    设置菜单
                                     DEBUG(0/100）

*********************************************************************************/
int menu23()
{
    while(1)
    {
        system("cls");
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|        设置界面：                 |");
        printf("\n\t\t\t\t\t|                 （一）数据备份    |");
        printf("\n\t\t\t\t\t|                 （二）数据恢复    |");
        printf("\n\t\t\t\t\t|                 （三）背景音乐    |");
        printf("\n\t\t\t\t\t|                 （四）系统还原    |");
        printf("\n\t\t\t\t\t|                 （五）返回        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
        int d;
        for(d=41; d>0; d--)
            printf("\b");
        char choice[20];
        scanf("%s",choice);
        if(!strcmp(choice,"数据备份")||(choice[0]=='1'&&choice[1]=='\0'))
            DataBackup();
        else if(!strcmp(choice,"数据恢复")||(choice[0]=='2'&&choice[1]=='\0'))
            DataRecover();
        else if(!strcmp(choice,"背景音乐")||(choice[0]=='3'&&choice[1]=='\0'))
            Soundset();
        else if(!strcmp(choice,"系统还原")||(choice[0]=='4'&&choice[1]=='\0'))
            reevery();
        else if(!strcmp(choice,"返回")||(choice[0]=='5'&&choice[1]=='\0'))
            return 0;
        else
            printf("错误代码 01：非法输入，请重新输入\n\t\t\t");
        system("pause");
    }
}
void question()
{
    while(1)
    {
        system("cls");
        char choice[20];
        printf("\n\t\t\t\t\t请选择（一）税率计算\n\t\t\t\t\t（二）返回\n");
        scanf("%s",choice);
        if(!strcmp(choice,"税率计算")||(choice[0]=='1'&&choice[1]=='\0'))
        {
            printf("不大于5000不收\n12000以下0.1\n25000以下0.2\n35000以下0.25\n55000以下0.3\n80000以下0.35\n80000以上0.45\n");
        }

        else if(!strcmp(choice,"返回")||(choice[0]=='2'&&choice[1]=='\0'))
            return ;
        else
            printf("错误代码 01：非法输入，请重新输入\n\t\t\t");
        system("pause");
    }
}
