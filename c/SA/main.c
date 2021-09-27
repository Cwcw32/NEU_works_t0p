#include"DA.h"
#include"DI.h"
#include"En.h"
#include"exit.h"
#include"help.h"
#include"output.h"
#include"SA.h"
#include"SortStat.h"
#include"SS.h"
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

int main()
{
    system("color 1e");
    int flagm1=0,//登录选择支管理
        flagm2=0;//用户主菜单管理
    /////////////////////////////////////////////////////////////////////////////////////主菜单
    printf("\n\t\t\t加载中");
    int i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|12);
    for(i=1; i<=10; i++)
    {
        printf(".");
    }                                         //模拟加载程序
    fflush(stdout);
    for (i = 1; i <= 10; ++i)
    {
        printf("\b");
    }
    for (i = 1; i <= 10; ++i)
    {
        printf(">");
        fflush(stdout);
        Sleep(100);
    }
    putchar('\n');
    gotoxy(30,0);
    float x, y, a = 1.0, f;
    int d=0;
    for(y = a + 0.3; y >= -a - 0.3; y -= 0.1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|d%15+1);
        for(x = -a - 0.3; x <= a + 0.3; x += 0.05)
        {
            f = pow(x*x + y*y, 3) - a*a * pow(x*x - y*y, 2);		                                //图像界面
            //fputc(f <= 1E-5 ? '*' : ' ', fp);
            putchar(f <= 1E-5 ? '*' : ' ');
        }
        //fputc('\n', fp);
        d++;
        gotoxy(30,0+d);
    }
    gotoxy(30,++d);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|10);
    printf("========================================================");
    gotoxy(30,++d);
    printf("||                                                    ||");
    gotoxy(30,++d);
    printf("||                    工资管理系统                    ||");
    gotoxy(30,++d);
    printf("||                                                    ||");
    gotoxy(30,++d);
    printf("========================================================");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|14);
    system("pause");
    printf("\n\t\t\t\t\t按任意键继续");
    while(1)
    {
        //主菜单
        system("cls");
        char choice[20];
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|         主界面：                  |");
        printf("\n\t\t\t\t\t|                 （一）登录        |");
        printf("\n\t\t\t\t\t|                 （二）帮助        |");
        printf("\n\t\t\t\t\t|                 （三）退出        |");
        printf("\n\t\t\t\t\t|                 （四）注册        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[    ]  （输入“登录”等以选择操作）");
        for(d=35; d>0; d--)
            printf("\b");
        scanf("%s",choice);
        //  getchar();
        if (!(strcmp(choice,"登录"))||(choice[0]=='1'&&choice[1]=='\0'))      //拥有功能：查询，管理维护及员工所拥有的大部分功能，有员工意见时能够接收并取消状态
        {
            while(1)
            {
                //登录
                if(login())
                {
                    for(i=1; i<=10; i++)
                    {
                        printf("...");
                        Sleep(100);
                    }
                    printf("\n登录成功！");
                    flagm1=1;
                    break;
                }
                else
                    break;
            }
        }
        else if(!(strcmp(choice,"退出"))||(choice[0]=='3'&&choice[1]=='\0'))
            exit(1);                                    //退出
        else if(!(strcmp(choice,"帮助"))||(choice[0]=='2'&&choice[1]=='\0'))
            question();
        else if(!(strcmp(choice,"注册"))||(choice[0]=='4'&&choice[1]=='\0'))//仅能查询自己的工资项目，可提交意见
            flagm1=3;
        else
        {
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
            continue;
        }                                               //非法操作
        //登录界面
        if(flagm1==1)
        {
            while(1)
            {
                flagm2=Menu2();
                //           1查询系统2管理系统3设置0返回
                // int flagmm=0;
                // data tempdata;
                switch(flagm2)
                {
                case 1:             //查询系统
                    menu21();
                    break;
                case 2:             //管理系统
                    menu22();
                    break;
                case 3:             //设置
                    menu23();
                    break;
                }
                if (!flagm2)
                {
                    flagm1=0;
                    break;
                }
            }
        }
        else if(flagm1==3)
            Menu3();                //
        else if(flagm1==2)
            ;//;                 help();                   //帮助菜单
    }
}

