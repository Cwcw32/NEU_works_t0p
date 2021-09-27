#include"SortStat.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"DA.h"
#include<time.h>
#include"output.h"
#include <stdio.h>
#include <unistd.h>
#include<windows.h>
/*******************************************************
            数
                据
                    维
                        护
                            1录入
                            2添加
                            3删除
                            4加密
                            5登录
 ********************************************************/
/*********************** ***********************************/
/*************************************************************/
/*void input(data *ps, int n)                         //要录入的数量n,
{
    int i;
    data *p;
    for (p=ps, i=0; p<ps+n; p++, i++)
    {
        //scanf
        if(i==n-1)
            p->next=NULL;
        else
            p->next=&p[i+1];
    }
}*/
/*void input_template()
{
    data *header,*moveman;
    moveman->next=NULL;
    header->next=NULL;
    FILE* fp=fopen("datas.txt","a");

    header->next=(data*)malloc(sizeof(data));//建立datas链表，存储数据
    moveman->next=header->next;
    /*while((moveman->next!=NULL))
    {
        //printf输出
        moveman=moveman->next;
    }
    fclose(fp);
}*/
/*void initial(data *it)
{
    it->all=0,
        it->basic=0,
            it->bonus=0,
                it->commonday=0,
                    it->exam_grades=0,
                        //it->five=0,
                        it->fund=0,
                            it->merit=0,
                                it->next=NULL,
                                    it->num=0,
                                        it->overtime=0,
                                            it->salary=0,
                                                it->tax=0,
                                                    it->tyear=0,
                                                        it->tmonth=0;
}*/
//数据初始化
//********************************************************//
/***************************************************************************************

    功能函数列表                                  DEBUG(80/100）

*********************************************************************************/
/*long getbasic(data *it)         //基本工资
{
    return it->basic;
}
long gettime(data *it)          //注册时间
{
    return it->time;
}
long getyear(data *it)          //发工资的时间
{
    return it->tyear;
}
long getmonth(data *it)
{
    return it->tmonth;
}
long getexam_grades(data *it)   //考核成绩
{
    return it->exam_grades;
}
long getovertime(data *it)      //加班时间
{
    return it->overtime;
}*/
double cmerit(data *it)       //全额工资
{
    return (it->basic)*(it->commonday)+(3.0)*(it->overtime)*(it->basic)+(it->bonus)+(it->all);
}
double ctaxrate(data *it)            //公积金标记标记标记标记标记标记标记标记标记标记标记标记标记标记标记
{
    if((it->merit)<=5000)
        return 0;
    else if((it->merit)<=12000)
        return 0.1;
    else if((it->merit)<=25000)
        return 0.2;
    else if((it->merit)<=35000)
        return 0.25;
    else if((it->merit)<=55000)
        return 0.3;
    else if((it->merit)<=80000)
        return 0.35;
    else
        return 0.45;
}
double  ctax(data *it)            //扣税标记标记标记标记标记标记标记标记标记
{
    if(it->merit>5000)
        return (it->merit-5000)*(it->taxrate);
    else
        return 0;
}
double csalary(data *it)        //总工资标记标记标记标记标记标记标记标记标记标记标记标记标记标记
{
    return it->merit-it->tax;
}
void ctimes(data *it)                   //计算注册时间
{
    time_t timeman;
    struct tm *p;
    time (&timeman);
    p=localtime(&timeman);
    it->tim.mday=p->tm_mday,
            it->tim.mon=1+p->tm_mon,
                    it->tim.year=1900+p->tm_year;
    it->tsum=it->tyear*12+it->tmonth;
}
void seta(data *d)                      //内置函数绑定
{
    /*  d->gettime=gettime;
      d->getbasic=getbasic;
      d->getcommonday=getcommonday;
      d->getyear=getyear;
      d->getmonth=getmonth;
      d->getexam_grades=getexam_grades;
      d->getovertime=getovertime;*/
    d->cmerit=cmerit;
    d->csalary=csalary;
    d->ctaxrate=ctaxrate;
    d->ctax=ctax;
}
int setb(data *d)                  //基本信息录入
{
    d->commonday=21;
    char a[200];
    printf("请输入姓名（20字符内）");
    scanf("%21s",d->name);//姓名输入
    int i=0;
    while((d->name[i])!='\0')
    {
        i++;
        if(i>20)
        {
            printf("请在指定字符范围内输入");
            system("pause");
            return 0;
        }
    }

    printf("请输入年份");
    scanf("%d",&d->tyear);

    printf("请输入月份（1~12）");
    scanf("%d",&d->tmonth);
    if(d->tmonth>12||d->tmonth<1)
    {
        printf("请在指定范围内输入月份");
        return 0;
    }

    printf("请输入奖金");
    scanf("%ld",&d->bonus);
    printf("请输入生活津贴");
    scanf("%ld",&d->all);
    printf("请输入基本工资（每天）");
    scanf("%ld",&d->basic);
    printf("请输入考核成绩（100分制，多出100会取余）");
    scanf("%d",&d->exam_grades);
    if(d->exam_grades>100)
        d->exam_grades%=100;

    printf("请输入加班时间");
    scanf("%d",&d->overtime);
    if(d->overtime>30)
    {
        printf("加班时间过多！请正确输入");
        return 0;
    }
    return 1;
}
void setc(data *d)                      //求对应的值
{
    d->merit=d->cmerit(d);
    d->taxrate=d->ctaxrate(d);
    d->tax=d->ctax(d);
    d->salary=d->csalary(d);
    ctimes(d);
}
int set(data *d)
{
    seta(d);
    if(setb(d))
    {
        setc(d);
        printf("数据创建成功");
    }
    else
    {
        printf("数据创建失败");
        system("pause");
        return 0;
    }
    system("pause");
    return 1;
}

//所存数据类构造函数

/////////////////////////////////////////////////////////////////////////////////////////////////



/***********************************************************************************************************
1                   注册                  DEBUG（100/100）

/****************************************************************************************/
void Accreg()
{
    while(1)
    {
        system("cls");
        FILE *fp;
        acc acc_temp;
        int flag=0;
        if((fp=fopen("account.txt","a+"))!=NULL)
        {
            printf("\n\t\t\t\t\t请输入您的注册账号");
            scanf("%s",acc_temp.name);
            FILE *fp2;
            fp2=fopen("account.txt","r");
            acc acc_temp2;
            fread(&acc_temp2,sizeof(acc),1,fp2);
            while(!feof(fp2))
            {
                if(!strcmp(acc_temp2.name,acc_temp.name))
                {
                    printf("\n该账号已被注册，请重新输入");
                    fclose(fp2);
                    flag=1;
                    system("pause");
                    break;
                }
                fread(&acc_temp2,sizeof(acc),1,fp2);
            }
            if(flag)
                return;
            printf("\n\t\t\t\t\t请输入您的注册密码");
            scanf("%s",acc_temp.password);
            printf("\n\t\t\t\t\t请确认您的注册密码");
            char temp[20];
            scanf("%s",temp);
            if(!(strcmp(temp,acc_temp.password)))
            {
                fwrite(&acc_temp,sizeof(acc),1,fp);
                printf("\n注册成功！");
                //printf("返回请按回车");
                system("pause");
                fclose(fp);
                return ;
            }
            else
            {
                printf("\n密码输入不一致，请重新输入");
                system("pause");
                return;
                /* while(1)
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
                         fclose(fp);
                         break;
                     }
                     else if(!(strcmp(choice,"返回")))
                     {
                         fclose(fp);
                         return ;//返回主菜单1
                     }
                     else
                     {
                         printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
                         continue;
                     }
                 }*/
            }
        }
        else
        {
            printf("错误代码03：文件打开失败即将返回");
            system("pause");
            return ;
        }
    }
}
/***********************************************************************************

*2`                 登陆                  DEBUG程度（100/100）

**********************************************************************************/
int login()
{
    while(1)
    {
        system("cls");
        FILE *fp;
        acc acc_temp1,acc_temp2;
        if((fp=fopen("account.txt","r")))
        {
            printf("\n\t\t\t\t\t请输入账号：");
            scanf("%s",acc_temp1.name);
            printf("\n\t\t\t\t\t请输入密码：");
            scanf("%s",acc_temp1.password);
            /*         int i=0;
                     strcmp(acc_temp1.password,"\0");
                     for(;i<20;i++)
                     {
                     acc_temp1.password[i]=getchar();
                     printf("\b*");
                     }*/
            fread(&acc_temp2,sizeof(acc),1,fp);
            while(!feof(fp))
            {
                if(!strcmp(acc_temp1.name,acc_temp2.name))
                {
                    if(!(strcmp(acc_temp1.password,acc_temp2.password)))
                    {
                        fclose(fp);
                        return 1;//进入管理页面
                    }
                    else
                        break;
                }
                fread(&acc_temp2,sizeof(acc),1,fp);
            }
            printf("\n错误代码 02：账号或密码错误，请重新输入");
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
                if(!(strcmp(choice,"重新输入"))||(choice[0]=='1'&&choice[1]=='\0'))
                {
                    fclose(fp);
                    break;
                }
                else if(!(strcmp(choice,"返回"))||(choice[0]=='2'&&choice[1]=='\0'))
                {
                    fclose(fp);
                    return 0;//返回主菜单1
                }
                else
                {
                    printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
                    system("pause");
                    continue;
                }
            }
        }
        else
        {
            printf("无账号菜单！");
            system("pause");
            return 0;
        }
    }
}



/***********************************************************************************

*2`                 数据导入    //需要头指针        DEBUG（90/100）

**********************************************************************************/
int DataIn(data * head)//注意形参是头指针
{
    data *header=(data *)malloc(sizeof(data));
    FILE *fp1;
    fp1=fopen("datas.txt","rb");
    if(!fp1)
    {
        printf("用户菜单不存在");
        fclose(fp1);
        system("pause");
        return 0;
    }
    fread(header,sizeof(data),1,fp1);
    header->next=NULL;
    data *z[200]= {0};
    int i=0;
    while(feof(fp1)==0)                                                   //读取
    {
        data *x=header;
        while(x->next!=NULL)
        {
            x=x->next;
        }
        data *p=(data *)malloc(sizeof(data));
        fread(p,sizeof(data),1,fp1);
        if(feof(fp1)!=0)
        {
            free(p);
           // z[i]=p;
           // i++;
            break;
        }
        //free(p);
        //data *h=p;
        x->next=p;
        p->next=NULL;
        //z[i]=p;
       // i++;
    }
  //  header->next=NULL;
  //  int j=0;
//    for(; j<i; j++)
  //      free(z[j]);
    head->next=header;
    fclose(fp1);    //printlist(head);                  //前
    return 1;
}
void BackaccIn(acc *head)                       //账号密码数据恢复
{
    acc *header=(acc *)malloc(sizeof(acc));
    FILE *fp1;
    fp1=fopen("backupacc.txt","r");
    fread(header,sizeof(acc),1,fp1);
    header->next=NULL;
    while(!feof(fp1))                   //读取
    {
        acc *x=header;
        while(x->next!=NULL)
        {
            x=x->next;
        }
        acc *p=(acc *)malloc(sizeof(acc));
        fread(p,sizeof(acc),1,fp1);
        if(feof(fp1))
            break;
        p->next=NULL;
        x->next=p;
    }
    head->next=header;
    fclose(fp1);
}
void BackupIn(data * head)//注意形头指针
{
    data *header=(data *)malloc(sizeof(data));
    FILE *fp1;
    fp1=fopen("backup.txt","r");
    fread(header,sizeof(data),1,fp1);
    header->next=NULL;
    while(!feof(fp1))                   //读取
    {
        data *x=header;
        while(x->next!=NULL)
        {
            x=x->next;
        }
        data *p=(data *)malloc(sizeof(data));
        fread(p,sizeof(data),1,fp1);
        if(feof(fp1))
            break;
        p->next=NULL;
        x->next=p;
    }
    head->next=header;
    fclose(fp1);
    // printlist(head);                  //前
    printf("\n\n\n");
}
/***********************************************************************************

*2`                 数据导出  //需要头指针（即配合上）  DEBUG(100/100）

**********************************************************************************/
void DataRebuild1(data *head)               //重建data方法1
{
    data *f=head;
    FILE *fp;
    int i=1;
    fp=fopen("datas.txt","wb");
    while(f->next!=NULL)
    {
        f=f->next;
        f->num=i;
        i++;
        fwrite(f,sizeof(data),1,fp);
    }
    fclose(fp);
}

void DataRebuild2(data *head)               //重建data方法2
{
    data *f=head;
    FILE *fp;
    int i=1;
    fp=fopen("temp.txt","wb+");
    while(f->next!=NULL)
    {
        f=f->next;
        f->num=i;
        i++;
        fwrite(f,sizeof(data),1,fp);
    }
    fclose(fp);
    remove("datas.txt");
    rename("temp.txt","datas.txt");
}
void Backupout(data *head)                     //数据恢复导出步骤
{
    data *f=head;
    FILE *fp;
    int i=1;
    fp=fopen("backup.txt","w");
    while(f->next!=NULL)
    {
        f=f->next;
        f->num=i;
        i++;
        fwrite(f,sizeof(data),1,fp);
    }
    fclose(fp);//没有Fclose不行
}
/***********************************************************************************

*2`                 链表释放  //需要头指针（即配合上）  DEBUG(90/100）

**********************************************************************************/
void DataFree(data *header)
{
    data *b=header;
    while(header->next!=NULL)
    {
        data *d;
        d=header;
        header=header->next;
        free(d);
        d=NULL;
    }
    free(b);
}
/***********************************************************************************

*2`                 数据添加 (单项）   //默认时间顺序       DEBUG（100/100）

**********************************************************************************/
void DataSave(data *header){
    FILE *fp1;
    //header->next=NULL;
    fp1=fopen("datas.txt","ab+");
    fwrite(header,sizeof(data),1,fp1);
    printoneall(header);
    system("pause");
    fclose(fp1);
}
void DataSave2(data* header)         //header不是头
{
    FILE* fp1,*fp2,*fp3;
    int flag=0,i=1;
    fp1=fopen("datas.txt","rb");
    fp2=fopen("temp.txt","wb+");
    fp3=fopen("datas.txt","rb");
    data *temp1,*temp2;
    temp1=(data*)malloc(sizeof(data));
    temp2=(data*)malloc(sizeof(data));
    fseek(fp3,sizeof(data),1);
    fread(temp1,sizeof(data),1,fp1);
    fread(temp2,sizeof(data),1,fp3);
    if(!fp1||feof(fp1))
    {
        header->num=i;
        fwrite(header,sizeof(data),1,fp2);
        printoneall(header);
        system("pause");
        free(temp1);
        free(temp2);
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        remove("datas.txt");
        rename("temp.txt","datas.txt");
        return ;
    }
    if(header->tsum<=temp1->tsum)
    {
        header->num=i;
        i++;
        fwrite(header,sizeof(data),1,fp2);
        printoneall(header);
        temp1->num=i;
        i++;
        fwrite(temp1,sizeof(data),1,fp2);
        fread(temp1,sizeof(data),1,fp1);
        flag=1;
    }
    while(!(feof(fp1)))
    {
        //printf("temp1.nym:%d\n",temp1->nym);
        if((flag==0)&&((header->tsum>=temp1->tsum)&&(header->tsum<=temp2->tsum))||((temp1->tsum<=header->tsum)&&(feof(fp3))))
        {
            temp1->num=i;
            i++;
            fwrite(temp1,sizeof(data),1,fp2);
            header->num=i;
            i++;
            fwrite(header,sizeof(data),1,fp2);
            printoneall(header);
            fread(temp1,sizeof(data),1,fp1);
            flag=1;
            continue;
        }
       // if(!feof(fp1)))
        //{
            //  printf("temp2.nym:%d\n",temp2->nym);
          //  fread(temp2,sizeof(data),1,fp1);
            //fwrite(temp2,sizeof(data),1,fp2);
           // continue;
       // }

        temp1->num=i;
        i++;
        fwrite(temp1,sizeof(data),1,fp2);
        fread(temp1,sizeof(data),1,fp1);
    }
    free(temp1);
    free(temp2);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    remove("datas.txt");
    rename("temp.txt","datas.txt");
    system("pause");
}
//***********************员工信息注册
/***********************************************************************************

*2`                 数据修改删除        DEBUG(90/100）

**********************************************************************************/
void DataClear(data *header)
{

    while(1)
    {
        system("cls");
        char choice1[20];
        int flag=0;
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|       修改删除界面：              |");
        printf("\n\t\t\t\t\t|                 （一）删除目标    |");
        printf("\n\t\t\t\t\t|                 （二）清空        |");
        printf("\n\t\t\t\t\t|                 （三）修改        |");
        printf("\n\t\t\t\t\t|                 （四）返回        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
        int d;
        for(d=41; d>0; d--)
            printf("\b");
        scanf("%s",choice1);
        if(!(strcmp(choice1,"清空"))||(choice1[0]=='2'&&choice1[1]=='\0'))
        {
            remove("datas.txt");
            printf("\n清空成功");
        }
        else if(!(strcmp(choice1,"删除"))||(choice1[0]=='1'&&choice1[1]=='\0'))
        {
            char choice[20];
            printf("\n请输入您选择删除的对象");
            scanf("%s",choice);
            data *f=(data*)malloc(sizeof(data));
            DataIn(f);
            data *h=f;
            while(f->next!=NULL)
            {
                if(!strcmp(f->next->name,choice))
                {
                    flag=1;
                    if(f->next->next!=NULL)
                        f->next=f->next->next;
                    else
                        f->next=NULL;
                }
                if(f->next!=NULL)
                    f=f->next;
            }
            DataRebuild2(h);
            DataFree(h);
            free(f);
            if(flag==0)
                printf("\n未查询到目标姓名");
            else
                printf("\n删除成功");
        }
        else if(!(strcmp(choice1,"修改"))||(choice1[0]=='3'&&choice1[1]=='\0'))
        {
            char choice[20];
            printf("\n请输入您选择修改的对象");
            scanf("%s",choice);
            data *f=(data*)malloc(sizeof(data));
            DataIn(f);
            data *h=f;
            while(f->next!=NULL)
            {
                if(!strcmp(f->next->name,choice))
                {
                    flag=1;
                    data *newa=(data *)malloc(sizeof(data));
                    set(newa);
                    if(f->next->next!=NULL)
                        {
                        newa->next=f->next->next;
                        f->next=newa;
                        }
                    else
                        {f->next=newa;
                        newa->next=NULL;}
                }
                if(f->next!=NULL)
                    f=f->next;
            }
            DataRebuild2(h);
            DataFree(h);
            free(f);
            if(flag==0)
                printf("\n未查询到目标姓名");
            else
                printf("\n修改成功");
        }
        else if(!strcmp(choice1,"返回")||(choice1[0]=='4'&&choice1[1]=='\0'))
            return;
        else
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
        system("pause");
    }
}
