#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h> 
#include"graph.h" 
//typedef BinTree QElemType;
//////////////////////////////////////////////////////////////////////////
void MainMenue1(BinTree T)
{//�˵�ѡ��
	int c;
	while(1)
	{
		system("cls");//����������Ļ
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_BLUE); //����������ɫΪ��ɫ
		printf("\t");
		printf("\n\n\t         ---*****---��ѡ����Ĳ���---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_BLUE|FOREGROUND_BLUE);//����������ɫΪ��ɫ
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); //����������ɫΪ��ɫ	
		printf("\n\t------------------1:�޸�����------------------------------");	
		printf("\n\t------------------2:�޸ĳ�������--------------------------");
		printf("\n\t------------------3:�޸ĳ�Ա�Ƿ��ڼ���������------------");
		printf("\n\t------------------4:�޸ĳ�����ַ--------------------------");
		printf("\n\t------------------5:�޸ļ�ͥסַ--------------------------");
		printf("\n\t------------------6:�޸�ְҵ------------------------------");
		printf("\n\t------------------7:�޸ļ���------------------------------");
		printf("\n\t------------------0:������һ�˵�--------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE);  //����������ɫΪ��ɫ 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t���������ѡ���0~5��");
		fflush(stdin);
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				 XiuGaiName(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 2:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				ChangeBirthday(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
			
		case 3:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				ChangeSW(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 4:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
			ChangeBrothadd(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 5:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
			ChangeAddress(T); 
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 6:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
			ChangeVocation(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 7:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				ChangeDegree(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 0:
			break;
		default:
			fflush(stdin);
			system("cls");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED);//����������ɫΪ��ɫ
			printf("\n\t---------�Բ���!���ѡ���ڷ���Χ֮��!-------------");
			printf("\n\t------------�����ٴ�ѡ������ķ�����!-----------------");
			printf("\n\t--------------�밴���������������--------------------");
			printf("\n\t-------------------лл����!--------------------------\n\t");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//����������ɫΪ��ɫ
			getchar();
			break;
		}
		if(c==0) break;	
	}
}
///////////////////////////////////////////////////////////////////////////////
void MainMenueInquire(BinTree T)
{//�˵�ѡ��
	int c;
	while(1)
	{
		c=100;
		system("cls");//����������Ļ
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //����������ɫΪ��ɫ
		printf("\t");
		printf("\n\n\t         ---*****---��ѡ����Ĳ���---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//����������ɫΪ��ɫ
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //����������ɫΪ��ɫ		
		printf("\n\t------------------1:����������----------------------------");	
		printf("\n\t------------------2:���������ڲ���------------------------");
		printf("\n\t------------------3:����Ա�Ƿ��ڼ��������ڲ���----------");
		printf("\n\t------------------4:��������ַ����------------------------");
		printf("\n\t------------------5:����ͥסַ����------------------------");
		printf("\n\t------------------6:����������----------------------------");
		printf("\n\t------------------7:��������������------------------------");
		printf("\n\t------------------8:�����ֲ���----------------------------");
		printf("\n\t------------------9:����߲���----------------------------");
		printf("\n\t-----------------10:���������----------------------------");
		printf("\n\t-----------------11:��ѯĳһ��Ա������ֱϵ����------------");
		printf("\n\t-----------------12:��ѯĳһ��Ա�����е�ϵ����------------");
		printf("\n\t-----------------13:��ѯ�����˵Ĺ�ϵ----------------------");
		printf("\n\t-----------------14:��ѯĳ����������----------------------");
		printf("\n\t------------------0:������һ�˵����˳�����----------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  //����������ɫΪ��ɫ 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t���������ѡ���0~5��");
		fflush(stdin);
		scanf("%d",&c);
		fflush(stdin);
		switch(c)
		{
		case 1:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				 InquireName(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 2:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireBirthday(T);    
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
			
		case 3:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireSW(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 4:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireBrothadd(T); 
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 5:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireAddress(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 6:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireVocation(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 7:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireFather(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 8:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireDegress(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 9:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireHeight(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 10:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireAge(T); 
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 11:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireZhixi(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 12:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				InquireRoot(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 13:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				RelationShip(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 14:
			system("cls");//����Ļ
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				Inquireday(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 0:
			break;
		default:
			fflush(stdin);
			system("cls");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED);//����������ɫΪ��ɫ
			printf("\n\t---------�Բ���!���ѡ���ڷ���Χ֮��!-------------");
			printf("\n\t------------�����ٴ�ѡ������ķ�����!-----------------");
			printf("\n\t--------------�밴���������������--------------------");
			printf("\n\t-------------------лл����!--------------------------\n\t");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//����������ɫΪ��ɫ
			getchar();
			break;
		}
		if(c==0) break;	
	}
}
///////////////////////////////////////////////////////////////////////////////


void MainMenue(BinTree T)
{//�˵�ѡ��
	int c;
	BinTree F=NULL;
	SYSTEMTIME calendar;
	GetLocalTime(&calendar);
	
	while(1)
	{
		system("cls");//����Ļ
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //����������ɫΪ��ɫ
		printf("");
		printf("\t         ��ǰʱ��Ϊ��");
		printf("%4d��%02d��%02d�� %02d:%02d:%02d\n", calendar.wYear, calendar.wMonth, calendar.wDay, calendar.wHour, calendar.wMinute, calendar.wSecond); 
		printf("\n\t         ---*****---��ѡ����Ĳ���---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//����������ɫΪ��ɫ
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //����������ɫΪ��ɫ		
		printf("\n\t-----------------1:�� �� �� ��----------------------------");	
		printf("\n\t-----------------2:�� Ա �� �� ---------------------------");
		printf("\n\t-----------------3:��ѯ��Ա��Ϣ---------------------------");
		printf("\n\t-----------------4:ɾ�����׳�Ա---------------------------");
		printf("\n\t-----------------5:��Ա��Ϣ�޸�---------------------------");
		printf("\n\t-----------------6:����������ʾ---------------------------");
		printf("\n\t-----------------7:ͳ�Ʋ���-------------------------------");
		printf("\n\t-----------------8:���ļ��ж�ȡ��Ϣ�ؽ�������-------------");
		printf("\n\t-----------------9:������׵��ļ�-------------------------");
		printf("\n\t-----------------0:�˳�-----------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  //����������ɫΪ��ɫ 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t���������ѡ�0~8����");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			system("cls");//����Ļ
			T=(BinTree)malloc(sizeof(BinNode));
			T->parent =NULL;
			T->brother=NULL;
			CreateTree(T,F);
			T->data.Degress=1;
			printf("\n\t--------------����ͼ�Ѿ������ɹ�---------------\n\n");
			printf("\n\n\t--------------�밴Enter����������--------------");
			getchar();
			break;
		case 2:
			Add(T);
			fflush(stdin);
			printf("\n\n\t--------------�밴Enter����������--------------");
			getchar();
			break;
		case 3:
			MainMenueInquire(T);        //�����Ӳ˵�
			fflush(stdin);
			break;
		case 4:		
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				DeleteTree(T);
				printf("\n\n\t-------------------ɾ���ɹ���------------------");
			}
			printf("\n\n\t--------------�밴Enter�����ز˵�--------------");
			fflush(stdin);
			getchar();
			break;
		case 5:
			MainMenue1(T);       //�޸��Ӳ˵�
			fflush(stdin);
			break;
		case 6:
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				OutPutFamily(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 7:
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
				printf("\n\n\t--------------�밴Enter����������--------------");
				fflush(stdin);
				getchar();
			}
			else
			{
				MainMenueTongji(T); 
			}
			fflush(stdin);
			break;		
		case 8:
			ReadTree(T);
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 9:
			if (T==NULL)
			{
				printf("\n\t�����ڼ��������뷵������ѡ��");
			}
			else
			{
				BaoCun(T);
			}
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 0:
			break;
		default:
			fflush(stdin);
			//system("cls");//����Ļ
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED);//����������ɫΪ��ɫ
			printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!-----------");
			printf("\n\t-----------�����ٴ�ѡ������ķ�����!-----------------");
			printf("\n\t-------------�밴���������������--------------------");
			printf("\n\t------------------лл����!------------------------\n\t");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//����������ɫΪ��ɫ
			getchar();
			break;
		}
		if(c==0) break;
	}
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	void MainMenue(BinTree T);  //�����˵�
	BinTree T=NULL;
	MainMenue(T);
	
}