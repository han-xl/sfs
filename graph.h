#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <time.h> 

#define len 20
#define MAX 100

////////////////////////////////////////////////
typedef struct Date                 //定义时间结构体
{
	int year;              //年
	int month;             //月
	int day;               //日
}Date;
typedef struct ifo                      //成员信息结构体
{	char        Name[len];              //记录这个人的姓名
	Date        Birthday;               //记录这个人的出生日期
	char        SW[len];                //记录这个人是否死亡
	Date        Dieday;                 //记录这个人的死亡日期
	char        Kind[len];              //记录这个人的性别
	char        Marital[len];           //记录这个人是否结婚
	char        Brothadd[len];          //记录这个人的出生地址
	char        Address[len];           //记录这个人的家庭住址
	char        Vocation[len];          //记录这个人的职业
	char        Degree[len];            //记录这个人的简历
	char        Father[len];            //记录这个人的父亲姓名
	int         Degress;                //记录这个人的辈分
	int         Height;                 //记录这个人身高
	int         Age;                    //记录这个人年龄
	int         Num;                    //记录这个人拥有几个儿女
}ifo;
typedef struct BinNode                //定义树
{	
	ifo    data;                      //成员信息
	struct BinNode *child;                  //定义孩子指针
	struct BinNode *brother;                //定义兄弟指针
	struct BinNode *parent;                 //定义父亲指针
}BinNode,*BinTree;
///////////////////////////////////////////////////////////////////////
typedef BinTree QElemType;
typedef struct QNode                          //队列
{
	QElemType Data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front,rear;
}LinkQueue;
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
void MainMenue1(BinTree T);                            //子菜单选择
void MainMenue(BinTree T);                             //菜单选择
int Inspect1(Date B,Date D);                           //判断日期大小--B大于D
int Inspect(Date D);                                   //判断时间的正确性
BinTree Value(BinTree T,char Name[len]);               //查找指定结点
void AddDegress(BinTree &T);                           //添加祖先时树的每个成员辈分加一
void Add(BinTree &T);                                  //增加成员
void CreateTree(BinTree &T,BinTree F);                 //单个节点的录入
void BaoCun(BinTree T);                                //把家谱保存到文件中
void InPut(BinTree &B,FILE *fp);                       //从文件读取信息辅助函数
void ReadTree(BinTree &T);                             //从文件读取信息建立家谱树
void Put(BinTree T);                                   //输出成员信息
void InquireName(BinTree T);                          //姓名查询家谱成员并显示该成员的各项信息
void DeleteTree(BinTree &T);                           //删除成员
void XiuGaiName(BinTree &T);                           //修改成员姓名
void ChangeBirthday(BinTree &T);                       //修改成员出生日期
void ChangeSW(BinTree &T);                             //修改成员是否健在
void ChangeBrothadd(BinTree &T);                       //修改成员出生地址
void ChangeAddress(BinTree &T);                        //修改成员家庭住址
void ChangeVocation(BinTree &T);                       //修改成员职业
void ChangeDegree(BinTree &T);                         //修改成员简历
void OutPutFamily(BinTree T);                          //按层次遍历输出家谱
int ValueBirthday(BinTree T,Date Birth);               //按出生日期查找辅助函数
void InquireBirthday(BinTree T);                      //按出生日期查找
int ValueDie(BinTree T,Date Die);                      //按死亡日期查找辅助函数
int ValueSW(BinTree T);                                //查找健在的人的辅助函数
void InquireSW(BinTree T);                            //按成员是否健在及死亡日期查找
int ValueBrothadd(BinTree T,char Birthadd[len]);       //按成员出生地址查找辅助函数
void InquireBrothadd(BinTree T);                      //按成员出生地址查找
int ValueBrothadd(BinTree T,char Address[len]);        //按成员家庭住址查找辅助函数
void InquireAddress(BinTree T);                       //按成员家庭住址查找
int ValueVocation(BinTree T,char Vocation[len]);       //按成员职业查找辅助函数
void InquireVocation(BinTree T);                      //按成员职业查找
int ValueFather(BinTree T,char Father[len]);           //按父亲姓名查找辅助函数
void InquireFather(BinTree T);                        //按父亲姓名查找
int ValueDegress(BinTree T,int Degress);               //按辈分查找辅助函数
void InquireDegress(BinTree T);                       //按辈分查找
int ValueHeight(BinTree T,int Height);                 //按身高查找辅助函数
void InquireHeight(BinTree T);                        //按身高查
int ValueAge(BinTree T,int Age);                       //按年龄查找辅助函数
void InquireAge(BinTree T);                           //按身高查找
void MainMenueTongji(BinTree T);                       //统计操作
void CengciPut(BinTree T);                             //层次遍历输出
int ValueZhixi(BinTree T,char Name[len]);              //查询某一成员的所有直系亲属辅助函数
void InquireZhixi(BinTree T);                         //查询某一成员的所有直系亲属  
void InquireRoot(BinTree T);                           //查询某一成员的所有嫡系祖先
void RelationShip(BinTree T);                          //查询两个人的关系  
int Count_day(BinTree T);                             //生存天数计算
void Inquireday(BinTree T);                           //生存天数













