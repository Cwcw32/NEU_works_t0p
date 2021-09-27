/*******************************************************
                系统维护1、时间检查
                        2、数据备份
                        3、文件检查
                        4、预防性检查
                        5、校正性检查
                        6、数据检查
                        7、数据恢复
 ********************************************************/
#include"SortStat.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"DA.h"
#include<time.h>
#include"output.h"
#include<windows.h>
/***************************************************************************************

    时间检查
                                      DEBUG(50/100）

*********************************************************************************/
void print_time()
{
    time_t timeman;
    struct tm *p;
    time (&timeman);
    p=localtime(&timeman);
    int mday=p->tm_mday,
        mon=1+p->tm_mon,
        year=1900+p->tm_year
             ;
    printf("%04d%02d%02d"
           ,year
           ,mon
           ,mday
          );
}

void DataBackup()                   //数据备份
{
    data *he=(data *)malloc((sizeof(data)));
    DataIn(he);                 //读
    Backupout(he);                 //创建+导入datas
    DataFree(he);                   //释放
    printf("\n数据备份完成");
}
void DataRecover()                  //数据恢复
{
    while(1)
    {
        printf("\n\t\t\t\t\t请输入管理员口令");
        char choice[20];
        scanf("%s",choice);
        if(!strcmp(choice,secret))
        {
            data *he=(data *)malloc((sizeof(data)));
            BackupIn(he);         //读取
            DataRebuild1(he);             //导出到datas;
            DataFree(he);
            printf("\n数据恢复完成，按任意键返回");
            getchar();
            getchar();
            return;               //释放
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
                //   printf("\n\t\t\t\t\t|                                   |");
                // printf("\n\t\t\t\t\t|                                   |");
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
        // printf("完成");
    }
}




