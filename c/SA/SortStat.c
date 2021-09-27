/*******************************************************
                排序、统计1、各种排序
                            2、各种统计
 ********************************************************/
#include"SortStat.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"DA.h"
#include<time.h>
/*******************************************************
        排序
 ********************************************************/
data *mergesa(data *head1, data *head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    data *res, *p ;
    if(head1->salary < head2->salary)
    {
        res = head1;
        head1 = head1->next;
    }
    else
    {
        res = head2;
        head2 = head2->next;
    }
    p = res;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->salary < head2->salary)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if(head1 != NULL)
        p->next = head1;
    else if(head2 != NULL)
        p->next = head2;
    return res;
}

data *sortsa(data *header)            //需要头指针
{
    if(header == NULL || header->next == NULL)
        return header;
    else
    {
        //快慢指针找到中间节点
        data *fast = header,*slow = header;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortsa(header);//前半段排序
        slow = sortsa(slow);//后半段排序
        return mergesa(fast,slow);
    }

}
data *mergetime(data *head1, data *head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    data *res, *p ;
    if(head1->tsum < head2->tsum)
    {
        res = head1;
        head1 = head1->next;
    }
    else
    {
        res = head2;
        head2 = head2->next;
    }
    p = res;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->tsum < head2->tsum)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if(head1 != NULL)
        p->next = head1;
    else if(head2 != NULL)
        p->next = head2;
    return res;
}
data *sorttime(data *header)            //需要头指针
{
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //链表归并排序
    if(header == NULL || header->next == NULL)
        return header;
    else
    {
        //快慢指针找到中间节点
        data *fast = header,*slow = header;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sorttime(header);//前半段排序
        slow = sorttime(slow);//后半段排序
        return mergetime(fast,slow);
    }

}
data *mergeov(data *head1, data *head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    data *res, *p ;
    if(head1->overtime < head2->overtime)
    {
        res = head1;
        head1 = head1->next;
    }
    else
    {
        res = head2;
        head2 = head2->next;
    }
    p = res;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->overtime < head2->overtime)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if(head1 != NULL)
        p->next = head1;
    else if(head2 != NULL)
        p->next = head2;
    return res;
}
data *sortov(data *header)            //需要头指针
{
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    //链表归并排序
    if(header == NULL || header->next == NULL)
        return header;
    else
    {
        //快慢指针找到中间节点
        data *fast = header,*slow = header;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        fast = sortov(header);//前半段排序
        slow = sortov(slow);//后半段排序
        return mergeov(fast,slow);
    }

}
void Sort()
{
    while(1)
    {
        system("cls");
        printf("\n\t\t\t\t\t---------------------------------------------");
        printf("\n\t\t\t\t\t|         排序菜单：                        |");
        printf("\n\t\t\t\t\t|                 （一）实际工资            |");
      //  printf("\n\t\t\t\t\t|                 （二）发放时间            |");
       // printf("\n\t\t\t\t\t|                 （三）加班时间            |");
        printf("\n\t\t\t\t\t|                 （二）返回                |");
        printf("\n\t\t\t\t\t---------------------------------—-----------");
        printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
        int d;
        for(d=41; d>0; d--)
            printf("\b");
        char choice[20];
        scanf("%s",choice);
        if(!(strcmp(choice,"实际工资"))||(choice[0]=='1'&&choice[1]=='\0'))
        {
            data *header=(data *)malloc(sizeof(data));
            DataIn(header);
            data *x=sortsa(header);
            DataRebuild1(x);
            DataFree(header);
           // free(x);
            free(header);
            printf("\n按实际工资排序完成");
        }
      /*  else if(!(strcmp(choice,"发放时间"))||(choice[0]=='1'&&choice[1]=='\0'))
        {
            data *header=(data *)malloc(sizeof(data));
            DataIn(header);
            data *x=sorttime(header);
            DataRebuild1(x);
            DataFree(header);
            //free(x);
            free(header);
            printf("\n按发放时间排序完成");
        }
        else if(!strcmp(choice,"加班时间"))
        {
            data *header=(data *)malloc(sizeof(data));
            DataIn(header);
            data *x=sortov(header);
            DataRebuild1(x);
            DataFree(header);
            free(x);
            free(header);
            printf("\n按加班时间排序完成");

        }*/
        else if(!strcmp(choice,"返回")||(choice[0]=='2'&&choice[1]=='\0'))
            return;
        else
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t       ");
        system("pause");
    }



}


/***********************************************************************************

*2`            分析统计                  DEBUG程度（100/100）

**********************************************************************************/

void Analyze(data *f)
{
    while(1)
    {
        system("cls");
        printf("\n\t\t\t\t\t-------------------------------------");
        printf("\n\t\t\t\t\t|         统计菜单：                |");
        printf("\n\t\t\t\t\t|                 （一）时间区间    |");
        //printf("\n\t\t\t\t\t|                 （二）工资区间    |");
        printf("\n\t\t\t\t\t|                 （二）返回        |");
        printf("\n\t\t\t\t\t---------------------------------—---");
        printf("\n\t\t\t\t\t   请选择:[          ]  （输入“返回”等以选择操作）");
        int d;
        for(d=41; d>0; d--)
            printf("\b");
        char choice[20];
        scanf("%s",choice);
        if(!strcmp(choice,"时间区间")||(choice[0]=='1'&&choice[1]=='\0'))
        {
            int flag=0;
            int tempyear,tempmon,num=0;
            printf("\n\t\t\t\t\t请选择起始时间（格式：201902）");
            scanf("%4d%2d",&tempyear,&tempmon);
            unsigned int temsum=tempyear*12+tempmon;
            printf("\n\t\t\t\t\t请选择终止时间（无终止时间输入-1-1）");
            int endyear,endmon;
            scanf("%4d%2d",&endyear,&endmon);
            unsigned int endsum;
            if(endyear==(-1)||endmon==(-1))
            {
                endsum=65535;
                flag=1;
            }
            else
                endsum=endyear*12+endmon;
            data *x=f;
            while(x->next!=NULL)
            {
                x=x->next;
                if(x->tsum>=temsum&&x->tsum<=endsum)
                    num++;
            }
            if(!flag)
                printf("\n\t\t\t\t\t%04d%02d至%04d%02d共发放%d人次工资",tempyear,tempmon,endyear,endmon,num);
            else
                printf("\n\t\t\t\t\t%04d%02d至今共发放%d人次工资",tempyear,tempmon,num);

        }
        /*else if(!strcmp(choice,"工资区间")||(choice[0]=='2'&&choice[1]=='\0'))
        {
            double tempsalary;
            int flag1=0,flag2=0,num=0;
            printf("\n\t\t\t\t\t请选择最低工资（格式：10000无限小输入-1）");
            scanf("%lf",&tempsalary);
            if(tempsalary-(-1)<=1e-5)
            {
                tempsalary=0.0;
                flag1=1;
            }
            printf("\n\t\t\t\t\t请选择最高工资（无限大输入-1）");
            double endsalary;
            scanf("%lf",&endsalary);
            if(endsalary-(-1)<=1e-5)
            {
                endsalary=1e15;
                flag2=1;
            }
            printf("\n\t\t\t\t\t请输入时间（格式201902,无时间输入-1-1）");
            int endyear,endmon;
            scanf("%4d%2d",&endyear,&endmon);
            long int tima=endyear*12+endmon;
            int flag3=0;
            if((endyear==-1)&&(endmon==-1))
                flag3=1;
            data *x=f;
            while(x->next!=NULL)
            {
                x=x->next;
                // printf("\n\n");
                // printf("%d\n",x->tsum);
                if(!flag3)
                {
                    if(x->tsum==tima&&x->salary>=tempsalary&&x->salary<=endsalary)
                        num++;
                }
                else
                {
                    if(x->salary>=tempsalary&&x->salary<=endsalary)
                        num++;
                }
            }

            if(!flag3)
            {
                printf("\n\t\t\t\t\t在%04ld%02ld中",endyear,endmon);
                if(flag1==0||flag2==0)
                    printf("%.2f至%.2f共有%d人次",tempsalary,endsalary,num);
                else if(flag1==0&&flag2==1)
                    printf("%.2f以上共有%d人次",tempsalary,num);
                else if(flag1==1&&flag2==0)
                    printf("%.2f以下共有%d人次",endsalary,num);
                else
                    printf("共有%d人次",num);
            }
            else
            {

                if(flag1==0||flag2==0)
                    printf("至今%.2f至%.2f共有%d人次",tempsalary,endsalary,num);
                else if(flag1==0&&flag2==1)
                    printf("至今%.2f以上共有%d人次",tempsalary,num);
                else if(flag1==1&&flag2==0)
                    printf("%.2f以下共有%d人次",endsalary,num);
                else
                    printf("共有%d人次",num);
            }
        }*/
        else if(!strcmp(choice,"返回")||(choice[0]=='2'&&choice[1]=='\0'))
            return ;
        else
            printf("\n错误代码 01：非法输入，请重新输入\n\t\t\t");
        system("pause");

    }

}
