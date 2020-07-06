#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <time.h> 

#define len 20
#define MAX 100

////////////////////////////////////////////////
typedef struct Date                 //����ʱ��ṹ��
{
	int year;              //��
	int month;             //��
	int day;               //��
}Date;
typedef struct ifo                      //��Ա��Ϣ�ṹ��
{	char        Name[len];              //��¼����˵�����
	Date        Birthday;               //��¼����˵ĳ�������
	char        SW[len];                //��¼������Ƿ�����
	Date        Dieday;                 //��¼����˵���������
	char        Kind[len];              //��¼����˵��Ա�
	char        Marital[len];           //��¼������Ƿ���
	char        Brothadd[len];          //��¼����˵ĳ�����ַ
	char        Address[len];           //��¼����˵ļ�ͥסַ
	char        Vocation[len];          //��¼����˵�ְҵ
	char        Degree[len];            //��¼����˵ļ���
	char        Father[len];            //��¼����˵ĸ�������
	int         Degress;                //��¼����˵ı���
	int         Height;                 //��¼��������
	int         Age;                    //��¼���������
	int         Num;                    //��¼�����ӵ�м�����Ů
}ifo;
typedef struct BinNode                //������
{	
	ifo    data;                      //��Ա��Ϣ
	struct BinNode *child;                  //���庢��ָ��
	struct BinNode *brother;                //�����ֵ�ָ��
	struct BinNode *parent;                 //���常��ָ��
}BinNode,*BinTree;
///////////////////////////////////////////////////////////////////////
typedef BinTree QElemType;
typedef struct QNode                          //����
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
void MainMenue1(BinTree T);                            //�Ӳ˵�ѡ��
void MainMenue(BinTree T);                             //�˵�ѡ��
int Inspect1(Date B,Date D);                           //�ж����ڴ�С--B����D
int Inspect(Date D);                                   //�ж�ʱ�����ȷ��
BinTree Value(BinTree T,char Name[len]);               //����ָ�����
void AddDegress(BinTree &T);                           //�������ʱ����ÿ����Ա���ּ�һ
void Add(BinTree &T);                                  //���ӳ�Ա
void CreateTree(BinTree &T,BinTree F);                 //�����ڵ��¼��
void BaoCun(BinTree T);                                //�Ѽ��ױ��浽�ļ���
void InPut(BinTree &B,FILE *fp);                       //���ļ���ȡ��Ϣ��������
void ReadTree(BinTree &T);                             //���ļ���ȡ��Ϣ����������
void Put(BinTree T);                                   //�����Ա��Ϣ
void InquireName(BinTree T);                          //������ѯ���׳�Ա����ʾ�ó�Ա�ĸ�����Ϣ
void DeleteTree(BinTree &T);                           //ɾ����Ա
void XiuGaiName(BinTree &T);                           //�޸ĳ�Ա����
void ChangeBirthday(BinTree &T);                       //�޸ĳ�Ա��������
void ChangeSW(BinTree &T);                             //�޸ĳ�Ա�Ƿ���
void ChangeBrothadd(BinTree &T);                       //�޸ĳ�Ա������ַ
void ChangeAddress(BinTree &T);                        //�޸ĳ�Ա��ͥסַ
void ChangeVocation(BinTree &T);                       //�޸ĳ�Աְҵ
void ChangeDegree(BinTree &T);                         //�޸ĳ�Ա����
void OutPutFamily(BinTree T);                          //����α����������
int ValueBirthday(BinTree T,Date Birth);               //���������ڲ��Ҹ�������
void InquireBirthday(BinTree T);                      //���������ڲ���
int ValueDie(BinTree T,Date Die);                      //���������ڲ��Ҹ�������
int ValueSW(BinTree T);                                //���ҽ��ڵ��˵ĸ�������
void InquireSW(BinTree T);                            //����Ա�Ƿ��ڼ��������ڲ���
int ValueBrothadd(BinTree T,char Birthadd[len]);       //����Ա������ַ���Ҹ�������
void InquireBrothadd(BinTree T);                      //����Ա������ַ����
int ValueBrothadd(BinTree T,char Address[len]);        //����Ա��ͥסַ���Ҹ�������
void InquireAddress(BinTree T);                       //����Ա��ͥסַ����
int ValueVocation(BinTree T,char Vocation[len]);       //����Աְҵ���Ҹ�������
void InquireVocation(BinTree T);                      //����Աְҵ����
int ValueFather(BinTree T,char Father[len]);           //�������������Ҹ�������
void InquireFather(BinTree T);                        //��������������
int ValueDegress(BinTree T,int Degress);               //�����ֲ��Ҹ�������
void InquireDegress(BinTree T);                       //�����ֲ���
int ValueHeight(BinTree T,int Height);                 //����߲��Ҹ�������
void InquireHeight(BinTree T);                        //����߲�
int ValueAge(BinTree T,int Age);                       //��������Ҹ�������
void InquireAge(BinTree T);                           //����߲���
void MainMenueTongji(BinTree T);                       //ͳ�Ʋ���
void CengciPut(BinTree T);                             //��α������
int ValueZhixi(BinTree T,char Name[len]);              //��ѯĳһ��Ա������ֱϵ������������
void InquireZhixi(BinTree T);                         //��ѯĳһ��Ա������ֱϵ����  
void InquireRoot(BinTree T);                           //��ѯĳһ��Ա�����е�ϵ����
void RelationShip(BinTree T);                          //��ѯ�����˵Ĺ�ϵ  
int Count_day(BinTree T);                             //������������
void Inquireday(BinTree T);                           //��������













