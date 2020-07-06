#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h> 
#include"graph.h" 
//typedef BinTree QElemType;
//////////////////////////////////////////////////////////////////////////
void MainMenue1(BinTree T)
{//菜单选择
	int c;
	while(1)
	{
		system("cls");//好像是清屏幕
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_BLUE); //设置文字颜色为蓝色
		printf("\t");
		printf("\n\n\t         ---*****---请选择你的操作---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_BLUE|FOREGROUND_BLUE);//设置文字颜色为蓝色
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_BLUE|FOREGROUND_INTENSITY); //设置文字颜色为蓝色	
		printf("\n\t------------------1:修改姓名------------------------------");	
		printf("\n\t------------------2:修改出生日期--------------------------");
		printf("\n\t------------------3:修改成员是否健在及死亡日期------------");
		printf("\n\t------------------4:修改出生地址--------------------------");
		printf("\n\t------------------5:修改家庭住址--------------------------");
		printf("\n\t------------------6:修改职业------------------------------");
		printf("\n\t------------------7:修改简历------------------------------");
		printf("\n\t------------------0:返回上一菜单--------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE);  //设置文字颜色为白色 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t请输入你的选项：（0~5）");
		fflush(stdin);
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				 XiuGaiName(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 2:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				ChangeBirthday(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
			
		case 3:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				ChangeSW(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 4:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
			ChangeBrothadd(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 5:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
			ChangeAddress(T); 
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 6:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
			ChangeVocation(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 7:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				ChangeDegree(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 0:
			break;
		default:
			fflush(stdin);
			system("cls");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED);//设置文字颜色为红色
			printf("\n\t---------对不起!你的选择不在服务范围之内!-------------");
			printf("\n\t------------请您再次选择所需的服务项!-----------------");
			printf("\n\t--------------请按任意键键继续操作--------------------");
			printf("\n\t-------------------谢谢合作!--------------------------\n\t");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//设置文字颜色为白色
			getchar();
			break;
		}
		if(c==0) break;	
	}
}
///////////////////////////////////////////////////////////////////////////////
void MainMenueInquire(BinTree T)
{//菜单选择
	int c;
	while(1)
	{
		c=100;
		system("cls");//好像是清屏幕
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //设置文字颜色为黄色
		printf("\t");
		printf("\n\n\t         ---*****---请选择你的操作---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//设置文字颜色为白色
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //设置文字颜色为绿色		
		printf("\n\t------------------1:按姓名查找----------------------------");	
		printf("\n\t------------------2:按出生日期查找------------------------");
		printf("\n\t------------------3:按成员是否健在及死亡日期查找----------");
		printf("\n\t------------------4:按出生地址查找------------------------");
		printf("\n\t------------------5:按家庭住址查找------------------------");
		printf("\n\t------------------6:按简历查找----------------------------");
		printf("\n\t------------------7:按父亲姓名查找------------------------");
		printf("\n\t------------------8:按辈分查找----------------------------");
		printf("\n\t------------------9:按身高查找----------------------------");
		printf("\n\t-----------------10:按年龄查找----------------------------");
		printf("\n\t-----------------11:查询某一成员的所有直系亲属------------");
		printf("\n\t-----------------12:查询某一成员的所有嫡系祖先------------");
		printf("\n\t-----------------13:查询两个人的关系----------------------");
		printf("\n\t-----------------14:查询某人生存天数----------------------");
		printf("\n\t------------------0:返回上一菜单，退出查找----------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  //设置文字颜色为白色 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t请输入你的选项：（0~5）");
		fflush(stdin);
		scanf("%d",&c);
		fflush(stdin);
		switch(c)
		{
		case 1:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				 InquireName(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 2:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireBirthday(T);    
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
			
		case 3:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireSW(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 4:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireBrothadd(T); 
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 5:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireAddress(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 6:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireVocation(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 7:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireFather(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 8:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireDegress(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 9:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireHeight(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 10:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireAge(T); 
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 11:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireZhixi(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 12:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				InquireRoot(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 13:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				RelationShip(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 14:
			system("cls");//清屏幕
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				Inquireday(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 0:
			break;
		default:
			fflush(stdin);
			system("cls");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED);//设置文字颜色为红色
			printf("\n\t---------对不起!你的选择不在服务范围之内!-------------");
			printf("\n\t------------请您再次选择所需的服务项!-----------------");
			printf("\n\t--------------请按任意键键继续操作--------------------");
			printf("\n\t-------------------谢谢合作!--------------------------\n\t");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//设置文字颜色为白色
			getchar();
			break;
		}
		if(c==0) break;	
	}
}
///////////////////////////////////////////////////////////////////////////////


void MainMenue(BinTree T)
{//菜单选择
	int c;
	BinTree F=NULL;
	SYSTEMTIME calendar;
	GetLocalTime(&calendar);
	
	while(1)
	{
		system("cls");//清屏幕
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //设置文字颜色为黄色
		printf("");
		printf("\t         当前时间为：");
		printf("%4d年%02d月%02d日 %02d:%02d:%02d\n", calendar.wYear, calendar.wMonth, calendar.wDay, calendar.wHour, calendar.wMinute, calendar.wSecond); 
		printf("\n\t         ---*****---请选择你的操作---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//设置文字颜色为白色
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //设置文字颜色为绿色		
		printf("\n\t-----------------1:新 建 家 谱----------------------------");	
		printf("\n\t-----------------2:成 员 添 加 ---------------------------");
		printf("\n\t-----------------3:查询成员信息---------------------------");
		printf("\n\t-----------------4:删除家谱成员---------------------------");
		printf("\n\t-----------------5:成员信息修改---------------------------");
		printf("\n\t-----------------6:家谱树的显示---------------------------");
		printf("\n\t-----------------7:统计操作-------------------------------");
		printf("\n\t-----------------8:从文件中读取信息重建家谱树-------------");
		printf("\n\t-----------------9:保存家谱到文件-------------------------");
		printf("\n\t-----------------0:退出-----------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  //设置文字颜色为白色 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t请输入你的选项（0~8）：");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			system("cls");//清屏幕
			T=(BinTree)malloc(sizeof(BinNode));
			T->parent =NULL;
			T->brother=NULL;
			CreateTree(T,F);
			T->data.Degress=1;
			printf("\n\t--------------家谱图已经建立成功---------------\n\n");
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			getchar();
			break;
		case 2:
			Add(T);
			fflush(stdin);
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			getchar();
			break;
		case 3:
			MainMenueInquire(T);        //查找子菜单
			fflush(stdin);
			break;
		case 4:		
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				DeleteTree(T);
				printf("\n\n\t-------------------删除成功！------------------");
			}
			printf("\n\n\t--------------请按Enter键返回菜单--------------");
			fflush(stdin);
			getchar();
			break;
		case 5:
			MainMenue1(T);       //修改子菜单
			fflush(stdin);
			break;
		case 6:
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				OutPutFamily(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 7:
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
				printf("\n\n\t--------------请按Enter键继续操作--------------");
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
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 9:
			if (T==NULL)
			{
				printf("\n\t不存在家谱树！请返回重新选择");
			}
			else
			{
				BaoCun(T);
			}
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 0:
			break;
		default:
			fflush(stdin);
			//system("cls");//清屏幕
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED);//设置文字颜色为红色
			printf("\n\n\t--------对不起!你的选择不在服务范围之内!-----------");
			printf("\n\t-----------请您再次选择所需的服务项!-----------------");
			printf("\n\t-------------请按任意键键继续操作--------------------");
			printf("\n\t------------------谢谢合作!------------------------\n\t");
			SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//设置文字颜色为白色
			getchar();
			break;
		}
		if(c==0) break;
	}
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	void MainMenue(BinTree T);  //声明菜单
	BinTree T=NULL;
	MainMenue(T);
	
}