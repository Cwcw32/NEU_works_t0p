/*******************************************************
                    系统相关1、时间设置                          ->注册时间使用
                            2、时间校正
                            3、主题颜色                           ->用户设置使用
                            4、语言
                            5、自定义设置背景、文字颜色
                            6、恢复出厂设置                        ->仅供测试

 ********************************************************/
#include"SortStat.h"
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>//PlaySound函数的头文件
#pragma comment(lib, "winmm.lib")//链接库，PlaySound函数必须使用
#include<stdio.h>
#include"DA.h"
void EnvironmentColorChange(int i)//标记标记标记
{
    system("color ab");//黑白状态
    system("color F0");//亮白黑
    system("color FD");//亮白淡紫(本系统默认）
    system("color F9");
};
void Soundset()//后台播放
{
    printf("散月");
    PlaySound("1.wav",NULL,SND_ASYNC);
}
void reevery()
{
    while(1)
    {
        printf("\n\t\t\t\t\t请输入管理员口令");
        char choice[20];
        scanf("%s",choice);
        if(!strcmp(choice,secret))
        {
            FILE *fp1,*fp2,*fp3;
            fp1=fopen("datas.txt","w");
            fp2=fopen("backup.txt","w");
            fp3=fopen("account.txt","w");
            fclose(fp1);
            fclose(fp2);
            fclose(fp3);
            printf("\n系统还原成功");
            return;
        }
        else
        {
            printf("\n口令错误，无法打开该项目");
            while(1)
            {
                printf("\n\t\t\t\t\t-------------------------------------");
                printf("\n\t\t\t\t\t|         登录出错：                |");
                printf("\n\t\t\t\t\t|                 （一）重新输入    |");
                printf("\n\t\t\t\t\t|                 （二）返回        |");
                printf("\n\t\t\t\t\t---------------------------------—---");
                printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
                int d;
                for(d=41; d>0; d--)
                    printf("\b");
                char choice[20];
                scanf("%s",choice);
                if(!(strcmp(choice,"重新输入")))
                {
                    break;
                }
                else if(!(strcmp(choice,"返回")))
                {
                    return ;
                }
                else
                {
                    printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
                    continue;
                }
            }
        }

    }
}


