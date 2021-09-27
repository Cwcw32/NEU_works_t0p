/*******************************************************
        数
                据
                        查
                                询
                                1、单元查询
                                2、多元查询
 ********************************************************/
#include"SortStat.h"
#include"DA.h"
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
/***************************************************************************************

          查询行输出       （文件操作)               DEBUG(70/100）

*********************************************************************************/
void  findname()            //包含界面                         //姓名为索引       //************查询并输出***********//1姓名2时间//
{
    FILE *fp;
    char choice[20];
    int flag=0;//,num=0;
    if((fp=fopen("datas.txt","rb"))!=NULL)
    {
        //位运算采用lowbit待优化标记标记标记标记标记标记标记标记标记标记标记标记标记标记
        while(1)//标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记查询模板
        {
            printf("请输入查询姓名");
            scanf("%s",choice);
            data *tempdata;
            tempdata=(data *)malloc(sizeof(data));
            fread(tempdata,sizeof(data),1,fp);
            while(!feof(fp))
            {
                if(!(strcmp(choice,tempdata->name)))
                {
                    flag=1;
                    printoneall(tempdata);//标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记
                }
                fread(tempdata,sizeof(data),1,fp);
            }
            if((!flag)&&(feof(fp)!=0 ))
            {
                printf("未查询到目标姓名");
                while(1)
                {
                    printf("\n\t\t\t（一）重新输入（二）返回");
                    scanf("%s",choice);
                    if(!(strcmp(choice,"重新输入")))
                    {
                        flag=0;
                        rewind(fp);//文件指针需要回到起始
                        break;
                    }
                    else if(!(strcmp(choice,"返回")))
                    {
                        return;
                    }
                    else
                    {
                        printf("\n\t\t\t错误代码 01：非法输入，请重新输入\n\t\t\t       ");
                        continue;
                    }
                }
            }
            if((flag==1)&&(feof(fp)!=0))                  //查找成功
            {
                free(tempdata);
                printf("完成");
                break;
            }//printf tempdata all;
        }//case 1结束
    }
}
/***************************************************************************************

            查询列输出       //链表操作                           DEBUG(100/100）

*********************************************************************************/
void findy(data *head,int j)
/*j 为fchoice
//0姓名
//1年月
//2奖金
//3生活津贴
//4基本工资
//5考核成绩
//6加班时间
//7实际工资*/
{
    data *f=head;
    char **a;
    a=(char **)malloc(500);
    a[0]="序号";
    a[1]="姓名";
    a[2]="日期";
    a[3]="奖金";
    a[4]="生活津贴";
    a[5]="基本工资";
    a[6]="考核成绩";
    a[7]="加班时间";
    a[8]="工资";
    printf("\n|%-5s|",a[0]);
    if(j&(1<<0))
    {
        printf("|%-10s|",a[1]);
    }
    if(j&(1<<1))
    {
        printf("|%-10s|",a[2]);
    }
    if(j&(1<<2))
    {
        printf("|%-10s|",a[3]);
    }
    if(j&(1<<3))
    {
        printf("|%-10s|",a[4]);
    }
    if(j&(1<<4))
    {
        printf("|%-10s|",a[5]);
    }
    if(j&(1<<5))
    {
        printf("|%-10s|",a[6]);
    }
    if(j&(1<<6))
    {
        printf("|%-10s|",a[7]);
    }
    // printf("到过这里1");
    if(j&128)
    {
        printf("|%-10s|\n",a[8]);
    }
    //printf("到过这里2");*/
    free(a);
    int x=1;
    while(f->next!=NULL)
    {
        f=f->next;
        printf("\n|%-5d|",x++);
        if(j&(1<<0))
        {
            printf("|%-10s |",f->name);
        }
        if(j&(1<<1))
        {
            printf("|%-04d %02d   |",f->tyear,f->tmonth);
        }
        if(j&(1<<2))
        {
            printf("|%-10d|",f->bonus);
        }
        if(j&(1<<3))
        {
            printf("|%-10d|",f->all);
        }
        if(j&(1<<4))
        {
            printf("|%-10d|",f->basic);
        }
        if(j&(1<<5))
        {
            printf("|%-10d|",f->exam_grades);
        }
        if(j&(1<<6))
        {
            printf("|%-10d|",f->overtime);
        }
        if(j&128)//(j&(1<<7））会出bug?????
        {
            printf("|%-10.2f|",f->salary);
        }
    }
    return;
}
/***************************************************************************************

            信息行列筛选输出        //包含界面                            DEBUG(100/100）

*********************************************************************************/

void    findx(data *head,int j)
/*j 为fchoice
0姓名1年月2奖金3生活津贴4基本工资5考核成绩6加班时间7实际工资
姓名选择
时间选择
考核成绩划分选择*/
{
    data *f=head;
    int flag=0;
    while(1)
    {
        char choice[20];
        printf("\n\t\t\t\t\t请输入查询姓名");
        scanf("%s",choice);
        int x=1;
        while(f->next!=NULL)
        {
            f=f->next;
            if(!strcmp(choice,f->name))
            {
                char **a;
                a=(char **)malloc(200);
                a[0]="序号";
                a[1]="姓名";
                a[2]="日期";
                a[3]="奖金";
                a[4]="生活津贴";
                a[5]="基本工资";
                a[6]="考核成绩";
                a[7]="加班时间";
                a[8]="工资";
                // printf("%5s",a[0]);
                printf("\n|%-5s|",a[0]);
                if(j&(1<<0))
                {
                    printf("|%-10s|",a[1]);
                }
                if(j&(1<<1))
                {
                    printf("|%-10s|",a[2]);
                }
                if(j&(1<<2))
                {
                    printf("|%-10s|",a[3]);
                }
                if(j&(1<<3))
                {
                    printf("|%-10s|",a[4]);
                }
                if(j&(1<<4))
                {
                    printf("|%-10s|",a[5]);
                }
                if(j&(1<<5))
                {
                    printf("|%-10s|",a[6]);
                }
                if(j&(64))
                {
                    printf("|%-10s|",a[7]);
                }
                // printf("到过这里1");
                if(j&128)
                {
                    printf("|%-10s|\n",a[8]);
                }
                //printf("到过这里2");*/
                free(a);
                flag=1;
                //printf("%5d",x++);

                printf("\n|%-5d|",x++);
                if(j&(1<<0))
                {
                    printf("|%-10s |",f->name);
                }
                if(j&(1<<1))
                {
                    printf("|%-04d %02d   |",f->tyear,f->tmonth);
                }
                if(j&(1<<2))
                {
                    printf("|%-10I32d|",f->bonus);
                }
                if(j&(1<<3))
                {
                    printf("|%-10d|",f->all);
                }
                if(j&(1<<4))
                {
                    printf("|%-10d|",f->basic);
                }
                if(j&(1<<5))
                {
                    printf("|%-10d|",f->exam_grades);
                }
                if(j&(64))
                {
                    printf("|%-10d|",f->overtime);
                }
                if(j&128)
                {
                    printf("|%-10.2f|",f->salary);
                }
                printf("\n");
                printf("\n");
            }
        }
        while(flag==0)
        {
            printf("\n未查询到目标姓名");
            printf("\n\t\t\t\t\t-------------------------------------");
            printf("\n\t\t\t\t\t|             出错：                |");
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
                return;//返回主菜单1
            }
            else
            {
                printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
                continue;
            }
        }
        if(flag==1)
            return;
    }
}
/**************************************************************************************

            信息选择                              DEBUG(100/100）

*********************************************************************************/
int fchoice()
{
    while(1)
    {
        int x=0,j=0,temp[10]= {0},flag=0;
        while(1)
        {
            system("cls");
            printf("\n\t\t\t\t\t-----------------------------------------------");
            printf("\n\t\t\t\t\t|               选择列标准：                  |");
            printf("\n\t\t\t\t\t|（一）姓名    （二）发放时间  （三）奖金     |");
            printf("\n\t\t\t\t\t|（四）生活津贴（五）基本工资  （六）考核成绩 |");
            printf("\n\t\t\t\t\t|（七）加班时间（八）实际工资  （九）全选     |");
            printf("\n\t\t\t\t\t---------------------------------—-------------");
            printf("\n\t\t\t\t\t                       **返回请输入返回或-1***");
            printf("\n\t\t\t\t\t                    选择完成后请输入完成或0***");
            printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
            int d;
            for(d=41; d>0; d--)
                printf("\b");
            char choice[20];
            scanf("%s",choice);
            if(!(strcmp(choice,"姓名" ))||(choice[0]=='1'&&choice[1]=='\0'))
            {
                j|=(1<<0);
                temp[0]=1;
            }
            if(!(strcmp(choice,"发放时间" ))||(choice[0]=='2'&&choice[1]=='\0'))
            {
                j|=(1<<1);
                temp[1]=1;
            }
            if(!(strcmp(choice,"奖金" ))||(choice[0]=='3'&&choice[1]=='\0'))
            {
                j|=(1<<2);
                temp[2]=1;
            }
            if(!(strcmp(choice,"生活津贴" ))||(choice[0]=='4'&&choice[1]=='\0'))
            {
                j|=(1<<3);
                temp[3]=1;
            }
            if(!(strcmp(choice,"基本工资" ))||(choice[0]=='5'&&choice[1]=='\0'))
            {
                j|=(1<<4);
                temp[4]=1;
            }
            if(!(strcmp(choice,"考核成绩" ))||(choice[0]=='6'&&choice[1]=='\0'))
            {
                j|=(1<<5);
                temp[5]=1;
            }
            if(!(strcmp(choice,"加班时间" ))||(choice[0]=='7'&&choice[1]=='\0'))
            {
                j|=(1<<6);
                temp[6]=1;
            }
            if(!(strcmp(choice,"实际工资" ))||(choice[0]=='8'&&choice[1]=='\0'))
            {
                j|=(128);
                temp[7]=1;
            }
            if(!(strcmp(choice,"全选" ))||(choice[0]=='9'&&choice[1]=='\0'))
            {
                j=(256)-1;
                temp[8]=1;
            }
            if(!(strcmp(choice,"返回" ))||(choice[0]=='-'&&choice[1]=='1'&&choice[2]=='\0'))
                return 0;
            if(!(temp[0]||temp[1]||temp[2]||temp[3]||temp[4]||temp[5]||temp[6]||temp[7]||temp[8]))
            {
                printf("\n错误代码 01：非法输入，请重新输入");
                system("pause");
                continue;
            }
            if(!(strcmp(choice,"完成"))||(choice[0]=='0'&&choice[1]=='\0'))
            {
                int i=0;
                printf("\n\t\t\t\t\t您的选择列标准数字是：");
                for(; i<=8; i++)
                {
                    if(temp[i]==1)
                    {
                        printf("%d ",i+1);
                    }
                }
                return j;
            }
            system("pause");
        }
    }
}

/////////////////////////菜单栏
