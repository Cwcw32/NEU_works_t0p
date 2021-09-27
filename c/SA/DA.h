#ifndef DA_H_INCLUDED
#define DA_H_INCLUDED



#define secret "abc123"
struct times
{
    unsigned int mday;
    unsigned int mon;
    unsigned int year;
    unsigned int sum;
};
typedef struct times timess;
struct account
{
    char name[20];//姓名
    char password[20];//密码
    struct account *next;//“员工”，“老板”
    //密码保护
};
typedef struct account acc;
//************************账号信息
/*struct boss
{
   unsigned int workdays;
   unsigned int basic_wage;
};
//************************老板管理*/
typedef struct datas data;
struct datas
{
    unsigned int num;//1用于排序
    char name[40];//2姓名
    unsigned int commonday;//4工作时间
    timess tim;//5注册时间
    unsigned long bonus;//6奖金
    unsigned long all;//7生活津贴
    unsigned long basic;//8基本工资
    unsigned int exam_grades;//9考核成绩
    double merit;//10全额工资
    unsigned int overtime;//12加班时间
    struct datas * next;//13尾指针
    double salary;//14实际工资
    unsigned int tyear;//15年
    unsigned int tmonth;//16月
    unsigned int tsum;
    double tax;//17税钱
    double taxrate;//18税率
    double (*csalary)(data *it);//工资计算
    double (*cmerit)(data *it);//全额工资计算
    double (*ctaxrate)(data *it) ;   //税率计算
    double  (*ctax)(data *it)  ;//税值计算
};
//typedef struct datas data;
//**************************员工数据
void Accreg();
void DataSave();
int login();
#endif // DA_H_INCLUDED
/*******************************************************
            Ъ§
                Он
                    ЮЌ
                        ЛЄ
 ********************************************************/


