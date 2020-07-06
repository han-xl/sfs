#include"graph.h"
//#include <windows.h> 

typedef BinTree QElemType;

////////////////////////////////////////////////////////////////////////////////
//                   *******队列的操作*******

void InitQueue(LinkQueue &Q)           //初始化操作
{
	if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
		exit(0);
	
	Q.front->next=NULL;
	return;
}

int QueueEmpty(LinkQueue Q)           //判空操作
{
	return(Q.front->next==NULL);
}

void EnQueue(LinkQueue &Q,QElemType e)       //入队列操作
{
	QueuePtr p;
	if(!(p=(QueuePtr)malloc(sizeof(QNode))))
		exit (0);
	p->Data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return;
}

int DeQueue(LinkQueue &Q,QElemType &e)    //出队列操作
{
	QueuePtr p;
	if(Q.front==Q.rear)
		return 0;
	p=Q.front->next;
	e=p->Data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return 1;
}

////////////////////////////////////////////////////////////////////////////////
//                       *******判断时间的正确性********
int Inspect(Date D)                    
{
	if(D.year<500||D.year>2500)    //判断年份
		return 0;
	if(D.month<1||D.month>12)      //判断月份
		return 0;
	if(D.month==1||D.month==3||D.month==5||D.month==7||D.month==8||D.month==10||D.month==12)  //判断大月的天数
	{
		if(D.day<1||D.day>31)
		{
			return 0;
		}
	}
	if(D.month==4||D.month==6||D.month==9||D.month==11)//判断小月的天数
	{
		if(D.day<1||D.day>30)
		{
			return 0;
		}
	}
	if(D.year%4==0)        //判断闰年的天数
	{
		if(D.month==2)
		{
			if(D.day<1||D.day>29)  //闰年
			{
				return 0;
			}
		}
	}
	else
	{
		if(D.month==2)
		{
			if(D.day<1||D.day>28)//平年
			{
				return 0;
			}
		}
	}
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
//                 *******判断日期大小--B大于D***********
int Inspect1(Date B,Date D)                   //B的日期在D之前返回1
{
	if(B.year>D.year)
		return 0;
	if(B.year==D.year)
	{
		if(B.month>D.month)
		{
			return 0;
		}
	}
	if(B.year==D.year)
	{
		if(B.month==D.month)
		{
			if(B.day>D.day)
			{
				return 0;
			}
		}
	}
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////
//                               ******输入个人信息********
void CreateTree(BinTree &T,BinTree F)              
{
	int i,j=1;
	printf("请输入姓名:");
	scanf("%s",T->data.Name);
	for(i=0;i<100;i++)
	{
		printf("请输入性别(男M或女G):");
		scanf("%s",T->data.Kind);
		if((strcmp(T->data.Kind,"M"))==0||(strcmp(T->data.Kind,"G"))==0||(strcmp(T->data.Kind,"m"))==0||(strcmp(T->data.Kind,"g"))==0) break;
		else
			printf("输入错误！请从新输入\n");
	}
	printf("请输入出生日期:\n");
	while(j)
	{
		while(1)
		{
			printf("年:");
			scanf("%d",&T->data.Birthday.year);
			fflush(stdin);
			printf("月:");
			scanf("%d",&T->data.Birthday.month);
			fflush(stdin);
			printf("日:");
			scanf("%d",&T->data.Birthday.day);
			fflush(stdin);
			if(Inspect(T->data.Birthday)==0)
			{
				printf("日期错误！请从新输入！\n");
				fflush(stdin);
			} 
			else
			{
				j=0;
				break;
			}
		}
		if (F!=NULL)
		{
			
			if (Inspect1(T->data.Birthday,F->data.Birthday)==0)
			{
				break;
			}
			else
			{
				j=1;
				printf("出生日期比父亲小，请重新输入！\n");
			}
		}
	}
	for(i=0;i<100;i++)
	{
		printf("请输入此人是否健在(是Y或否N):");
		scanf("%s",T->data.SW);
		if((strcmp(T->data.SW,"Y"))==0||(strcmp(T->data.SW,"N"))==0||(strcmp(T->data.SW,"y"))==0||(strcmp(T->data.SW,"n"))==0) break;
		else
			printf("输入错误！请从新输入\n");
	}
	
	if((strcmp(T->data.SW,"N"))==0||(strcmp(T->data.SW,"n"))==0)
	{
		printf("请输入死亡日期:\n");
		while(1)
		{
			for(i=0;i<100;i++)
			{
				printf("年:");
				scanf("%d",&T->data.Dieday.year);
				fflush(stdin);
				printf("月:");
				scanf("%d",&T->data.Dieday.month);
				fflush(stdin);
				printf("日:");
				scanf("%d",&T->data.Dieday.day);
				fflush(stdin);
				if(Inspect(T->data.Dieday)==0)
				{
					printf("日期错误！请从新输入！\n");
				}
				else
				{
					break;
				}
			}
			if(Inspect1(T->data.Birthday,T->data.Dieday)==0)
			{
				printf("死亡日期比出生日期早，请从新输入！\n");
				
			}
			else
				break;
		}
	}
	while(1)
	{
		printf("请输入这个人婚否（已婚Y或未婚N）:");
		scanf("%s",T->data.Marital);
		if((strcmp(T->data.Marital,"Y"))==0||(strcmp(T->data.Marital,"N"))==0||(strcmp(T->data.Marital,"y"))==0||(strcmp(T->data.Marital,"n"))==0)
		{
			break;
		}
		else
		{
			printf("输入错误!请从新输入\n");
		}
	}
	printf("请输入出生地址:");
	scanf("%s",T->data.Brothadd);
	printf("请输入家庭地址:");
	scanf("%s",T->data.Address);
	printf("请输入职业:");
	scanf("%s",T->data.Vocation);
	printf("请输入简历:");
	scanf("%s",T->data.Degree);
	printf("请输入身高(厘米):");
	scanf("%d",&(T->data.Height));
	fflush(stdin);
	if((strcmp(T->data.SW,"N"))==0)
	{
		T->data.Age=T->data.Dieday.year-T->data.Birthday.year;
	}
	else
	{
		T->data.Age=2011-T->data.Birthday.year;
	}
	if (F==NULL)
	{
		strcpy(T->data.Father,"没有");
	}
	else
		strcpy(T->data.Father,F->data.Name);
	T->data.Num=0;
	T->child=NULL;
	
}
////////////////////////////////////////////////////////////////////////////////
//                    *******查找指定结点********

BinTree Value(BinTree T,char Name[len])
{
	LinkQueue q;
	QElemType a;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.Name,Name))==0)
				return a;
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////
//                 *******添加祖先时树的每个成员辈分加一********  
void AddDegress(BinTree &T)
{
	T->data.Degress++;
	if (T->child!=NULL)
	{
		AddDegress(T->child);
	}
	if (T->brother!=NULL)
	{
		AddDegress(T->brother);
	}

}
////////////////////////////////////////////////////////////////////////////////
//                       *******增加成员*******
void Add(BinTree &T)              
{
	char Name[len];
	BinTree Tree,F,C[len],P=NULL;
	int c,i,j=1,h=1;
	if(T==NULL)        //不存在家谱
	{
		T=(BinTree)malloc(sizeof(BinNode));
		T->parent =NULL;
		T->brother=NULL;
		printf("不存在家谱，新建家谱树\n输入祖先的信息：\n");
		CreateTree(T,P);
		T->data.Degress=1;     
	}
	else
	{
		printf("1：添加新成员作为整个家谱的祖先\n");
		printf("2：添加新成员作为某一成员的孩子\n");
		while(j)
		{
			printf("请输入你的选项（1~2）：");
			fflush(stdin);
			scanf("%d",&c);
			fflush(stdin);
			switch(c)
			{
			case 1:
				
				Tree=(BinTree)malloc(sizeof(BinNode));
				Tree->brother=NULL;          //祖先不存在兄弟
				CreateTree(Tree,P);
				Tree->data.Degress=1;
				Tree->data.Num++;           //孩子数初始值为零，在这增加一
				strcpy(T->data.Father,Tree->data.Name);//原先的祖先的父亲姓名修改为现在祖先的姓名
				Tree->child=T;              //原先的祖先赋给现在的祖先做孩子
				Tree->parent=NULL;
				T->parent=Tree;             //现在的祖先赋给原先的祖先做父亲
				T=Tree;
				AddDegress(T->child);       //原先所有成员的辈分加一
				j=0;      //跳出while循环
				break;
			case 2:
				printf("请输入所添加成员的父亲姓名:\n你有三次机会\n");
				i=3;
				while(i)
				{
					fflush(stdin);
					scanf("%s",Name);
					fflush(stdin);
					F=Value(T,Name);     //F存放父亲结点
					if(F==NULL)
					{
						i--;
						if (i==0)
						{
							printf("父亲姓名输入错误!\n",i);
							break;
						}
						printf("父亲姓名输入错误\n你还有%d次机会\n请从新输入：\n",i);
					}
					else
					{
						break;
					}
				}
				if (i==0)    //三次机会用完，没有找到要添加成员的父亲
				{
					j=0;
					break;
				}
				printf("请输入所添加成员的信息\n");
				Tree=(BinTree)malloc(sizeof(BinNode));
				CreateTree(Tree,F);
				Tree->data.Degress=F->data.Degress+1;        //添加人的辈分等于父亲的辈分加一
				if (F->data.Num)                                      //添加人的父亲存在孩子
				{
					
					C[1]=F->child;			   //保存父亲的第一个孩子
					if (F->data.Num==1)              //只有一个孩子
					{
						if(Inspect1(Tree->data.Birthday,C[1]->data.Birthday)==1)    //Tree的年龄比C[1]大
						{
							Tree->brother=F->child;         //把父亲原先的第一个孩子赋给他当兄弟
							Tree->parent=F;
							F->child=Tree;                  //赋到父亲的孩子节点处
							Tree->child=NULL;
						}
						else                   //比第一个孩子小
						{
							C[1]->brother=Tree;
							Tree->parent=F;
							Tree->brother=NULL;
							Tree->child=NULL;
						}
					}
					if(F->data.Num>1)              //有多个孩子
					{
						for (i=2;i<=F->data.Num;i++)
						{
							C[i]=C[i-1]->brother;
							if(Inspect1(Tree->data.Birthday,C[i]->data.Birthday)==1)    //Tree的年龄比C[i]大
							{
								Tree->brother=C[i-1]->brother;
								Tree->parent=F;
								C[i-1]->brother=Tree;
								Tree->child=NULL;
								h=0;
								break;
							}
						}
						if(h)      //比最好一个孩子之前的所有孩子的年龄都要小
						{
							if(Inspect1(Tree->data.Birthday,C[i-1]->data.Birthday)==0)     //Tree的年龄比F的年龄最小孩子的年龄还小 
							{
								C[i-1]->brother=Tree;
								Tree->parent=F;
								Tree->brother=NULL;
								Tree->child=NULL;
							}
						}
					}
					
				}
				else                  //不存在孩子
				{
					F->child=Tree;
					Tree->parent=F;
					Tree->child=NULL;
					Tree->brother=NULL;
				}
				j=0;
				F->data.Num++;         //父亲的孩子数加一
				break;
			default:
				printf("\n\n\t--------对不起!你的选择不在服务范围之内!-----------");
				printf("\n\t-----------请您再次选择所需的服务项!-----------------\n");
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
//                      *******把家谱保存到文件中*******
void BaoCun(BinTree T)
{
	int i;
	LinkQueue Q;
	QElemType a,C[len];
	FILE *fp;
	if ((fp=fopen("Family","wb+"))==NULL)      //用二进制保存
	{
		printf("cannot open this file\n");
		exit(0);
	}
	if(T)
	{
		InitQueue(Q);                   //构建一个空队列Q
		EnQueue(Q,T);                   //在队尾插入新元素T
		while(!QueueEmpty(Q))           //队列不为空
		{
			DeQueue(Q,a);               //出队列，保存到a中
			fprintf(fp,"%s %d %d %d %s ",a->data.Name,a->data.Birthday.year,a->data.Birthday.month,a->data.Birthday.day,a->data.SW);
			if (strcmp(a->data.SW,"N")==0||strcmp(a->data.SW,"n")==0)
			{
				fprintf(fp,"%d %d %d ",a->data.Dieday.year,a->data.Dieday.month,a->data.Dieday.day);
			}
			fprintf(fp,"%s %s %s ",a->data.Kind,a->data.Marital,a->data.Brothadd);
			fprintf(fp,"%s %s %s ",a->data.Address,a->data.Vocation,a->data.Degree);
			fprintf(fp,"%s %d ",a->data.Father,a->data.Degress);
			fprintf(fp,"%d %d %d\n",a->data.Height,a->data.Age,a->data.Num);
			if (a->data.Num)         //a有孩子
			{
				C[1]=a->child;
				EnQueue(Q,C[1]);    //第一个孩子入队列
				for (i=2;i<=a->data.Num;i++)
				{
					C[i]=C[i-1]->brother;
					EnQueue(Q,C[i]);
				}
			}
		}
	}
	fclose(fp);
	printf("\n\t*****文件保存成功！*****\n\t");	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                            *******从文件中读取信息*******
void InPut(BinTree &B,FILE *fp)
{
	fscanf(fp,"%s %d %d %d %s ",B->data.Name,&B->data.Birthday.year,&B->data.Birthday.month,&B->data.Birthday.day,B->data.SW);
	fflush(stdin);
	if (strcmp(B->data.SW,"N")==0||strcmp(B->data.SW,"n")==0)
	{
		fscanf(fp,"%d %d %d ",&B->data.Dieday.year,&B->data.Dieday.month,&B->data.Dieday.day);
		fflush(stdin);
	}
	fscanf(fp,"%s %s %s ",B->data.Kind,B->data.Marital,B->data.Brothadd);
	fflush(stdin);
	fscanf(fp,"%s %s %s ",B->data.Address,B->data.Vocation,B->data.Degree);
	fflush(stdin);
	fscanf(fp,"%s %d ",B->data.Father,&B->data.Degress);
	fflush(stdin);
	fscanf(fp,"%d %d %d\n",&B->data.Height,&B->data.Age,&B->data.Num);
	fflush(stdin);

}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                           *******从文件读取信息建立家谱树********
void ReadTree(BinTree &T)
{
	int i;
	BinTree B=NULL;
	LinkQueue q;
	QElemType a;

	BinTree C[len],F;
	QElemType p;
	LinkQueue s,h;

	B=(BinTree)malloc(sizeof(BinNode));
	B->brother=NULL;
	B->child=NULL;
	B->parent=NULL;
	FILE *fp;
	if ((fp=fopen("Family","rb+"))==NULL)
	{
		printf("Can not open file\n");
		exit (0);
	}
	InPut(B,fp);
	InitQueue(q);
	InitQueue(s);
	InitQueue(h);
	EnQueue(q,B);           //在队尾插入新元素B
	while(!QueueEmpty(q))
	{
		DeQueue(q,a);       //出队列
		for(i=1;i<=a->data.Num;i++)
		{
			B=(BinTree)malloc(sizeof(BinNode));
			InPut(B,fp);
			EnQueue(q,B);
		}
		EnQueue(s,a);           //把所有成员按顺序放入栈中
		EnQueue(h,a);           //把所有成员按顺序放入栈中
	}
	fclose(fp);
	DeQueue(s,p);              //从s中出队列保存到p中
	T=p;                       //家谱的祖先为p
	while  (!QueueEmpty(h))    //队列h非空
	{
		DeQueue(h,p);          //从h中出队列保存到p中
		F=Value(T,p->data.Name);//在新建立的家谱中找到p保存到F中
		if (F->data.Num)       //按孩子数从s中出队列添加给F做孩子
		{ 
			DeQueue(s,C[1]);
			F->child=C[1];
			C[1]->child=NULL;
			C[1]->brother=NULL;
			C[1]->parent=F;
			for (i=2;i<=p->data.Num;i++)
			{
				DeQueue(s,C[i]);
				C[i-1]->brother=C[i];
				C[i]->child=NULL;
				C[i]->brother=NULL;
		    	C[i]->parent=F;
			}
		}
		
	}
	fclose(fp);
	printf("\n\t*****文件读取成功！*****\n\t");	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                    *******输出成员信息*********
void Put(BinTree T)
{
	printf("\n姓    名：%s ",T->data.Name);
	printf("\n性    别：");
	if((strcmp(T->data.Kind,"M"))==0||(strcmp(T->data.Kind,"m"))==0) 
	{
		printf("男               ");
	}
	else
		printf("女               ");
	printf("出生日期：%d年%d月%d日",T->data.Birthday.year,T->data.Birthday.month,T->data.Birthday.day);
	printf("\n是否健在：");
	if ((strcmp(T->data.SW,"N"))==0||(strcmp(T->data.SW,"n"))==0)
	{
		printf("否               死亡日期：%d年%d月%d日",T->data.Dieday.year,T->data.Dieday.month,T->data.Dieday.day);
	}
	else
		printf("是");
	printf("\n婚    否:");
	if ((strcmp(T->data.Marital,"Y"))==0||(strcmp(T->data.Marital,"y"))==0)
	{
		printf("已婚");
	}
	else 
		printf("未婚");
	printf("\n出生地址:%s",T->data.Brothadd);
	printf("\n家庭地址:%s",T->data.Address);
	printf("\n职    业:%s",T->data.Vocation);
	printf("\n简    历:%s",T->data.Degree);
	printf("\n身    高:%d厘米",T->data.Height);
	printf("\n年    龄:%d岁",T->data.Age);
	printf("\n父亲姓名:%s",T->data.Father);
	printf("\n辈    分:第%d辈",T->data.Degress);
	printf("\n拥有%d个儿女",T->data.Num);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                    *******姓名查询家谱成员并显示该成员的各项信息*******
void  InquireName(BinTree T)
{
	char name[len];
	BinTree Tree;
	int j=2;
	while(j)
	{
		printf("请输入你要查询人的姓名：");
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n：");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			Put(Tree);
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******删除成员*******

void DeleteTree(BinTree &T)
{
	char name[len];
	BinTree Tree,F,Q,P;
	printf("请输入你要删除人的姓名：");
	while (1)
	{
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请重新输入你要删除人的姓名：");
		}
		else
		{
			break;
		}
	}
 	F=Tree->parent;
	Q=F;
	P=Q->child;                   //用P保存父亲的第一个孩子
	if(P==Tree)                   //所要删除人是他父亲的第一个孩子
	{
		if(P->brother==NULL)      //所要删除人没有兄弟
		{
			Q->child=NULL;
			free(Tree);
		}
		else                    //所要删除人有兄弟
		{
			Q->child=P->brother; //把删除人的兄弟节点赋到父亲的孩子节点
			free(P);
		}
		F->data.Num--;          //父亲孩子数减一
		return;
	}
	else
	{
		Q=P;
		while(P->brother!=NULL)     // 兄弟节点不为空
		{
			P=P->brother;               //用P保存父亲的第二个孩子
			if(P==Tree)
			{
				if(P->brother==NULL)//所要删除人没有比他小的兄弟
				{
					Q->brother=NULL;//所要删除人的上一个兄弟的兄弟节点赋空
					free(Tree);
				}
				else
				{
					Q->brother=P->brother;//把所要删除人的下一个兄弟赋到上一个兄弟的兄弟节点处
					free(P);
				}
				F->data.Num--;
				return;
			}
			Q=P;
			P=P->brother;        //跳到下个兄弟
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员姓名*******
void XiuGaiName(BinTree &T)
{
	int i;
	char Name[len],name[len];
	BinTree Tree,p;
	printf("请输入你要修改人的姓名：");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
            printf("请输入你要修改人现在的姓名：");
			scanf("%s",name);
	     	fflush(stdin);
			strcpy(Tree->data.Name,name);
			if (Tree->data.Num)              //存在孩子
			{
				p=Tree->child;               //用P保存第一个孩子
				strcpy(p->data.Father,name); //把修改的姓名覆盖到孩子的父亲姓名
				for (i=2;i<=Tree->data.Num;i++)
				{
					p=p->brother;
					strcpy(p->data.Father,name);
				}
			}
			break;
		}
	}
	printf("修改成功！");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员出生日期*******
void ChangeBirthday(BinTree &T)
{
	int i=1;
	char Name[len];
	BinTree Tree;
	printf("请输入你要修改人的姓名：");
	while(i)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
			printf("请输入出生日期:\n");
			while(i)
			{
				while(1)
				{
					printf("年:");
					scanf("%d",&Tree->data.Birthday.year);
					fflush(stdin);
					printf("月:");
					scanf("%d",&Tree->data.Birthday.month);
					fflush(stdin);
					printf("日:");
					scanf("%d",&Tree->data.Birthday.day);
					fflush(stdin);
					if(Inspect(Tree->data.Birthday)==0)
					{
						printf("日期错误！请从新输入！\n");
					}
					else
					{
						break;
					}
				}
				if((strcmp(Tree->data.SW,"N"))==0||(strcmp(Tree->data.SW,"n"))==0)//已死亡
				{
					if(Inspect1(Tree->data.Birthday,Tree->data.Dieday)==0)    //出生日期比死亡日期晚
					{
						printf("出生日期比死亡日期晚，请从新输入！\n");
						break;
					}
					else                      //出生日期比死亡日期早
					{	
						Tree->data.Age=Tree->data.Dieday.year-Tree->data.Birthday.year;	
						printf("修改成功！");
						i=0;
					}
				}
				else                 //现在还健在，不用判断是否比死亡日期晚
				{
					Tree->data.Age=2011-Tree->data.Birthday.year;
					printf("修改成功！");
					i=0;
					break;
				}
			}
		}
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员是否健在及死亡日期*******
void ChangeSW(BinTree &T)
{
	int i;
	char Name[len];
	BinTree Tree;
	printf("请输入你要修改人的姓名：");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
			for(i=0;i<100;i++)
			{
				printf("请输入你要修改人是否健在(是Y或否N)：");
				scanf("%s",Tree->data.SW);
				if((strcmp(Tree->data.SW,"Y"))==0||(strcmp(Tree->data.SW,"N"))==0||(strcmp(Tree->data.SW,"y"))==0||(strcmp(Tree->data.SW,"n"))==0) break;
				else
					printf("输入错误！请从新输入\n");
			}
			
			if((strcmp(Tree->data.SW,"N"))==0||(strcmp(Tree->data.SW,"n"))==0)
			{
				printf("请输入死亡日期:\n");
				while(1)
				{
					while(1)
					{
						printf("年:");
						scanf("%d",&Tree->data.Dieday.year);
						fflush(stdin);
						printf("月:");
						scanf("%d",&Tree->data.Dieday.month);
						fflush(stdin);
						printf("日:");
						scanf("%d",&Tree->data.Dieday.day);
						fflush(stdin);
						if(Inspect(Tree->data.Dieday)==0)
						{
							printf("日期错误！请从新输入！\n");
						}
						else
						{
							break;
						}
					}
					if(Inspect1(Tree->data.Birthday,Tree->data.Dieday)==0)
					{
						printf("死亡日期比出生日期早，请从新输入！\n");
						
					}
					else
					{
						Tree->data.Age=Tree->data.Dieday.year-Tree->data.Birthday.year;
						break;
					}
				}
			}
			else
			{
				Tree->data.Age=2011-Tree->data.Birthday.year;
			}
			printf("修改成功！");
			break;
		}	
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员出生地址*******
void ChangeBrothadd(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("请输入你要修改人的姓名：");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
            printf("请输入你要修改人的出生地址：");
			scanf("%s",Tree->data.Brothadd);
			fflush(stdin);
			break;
		}
	}
	printf("修改成功！");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员家庭住址*******
void ChangeAddress(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("请输入你要修改人的姓名：");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
            printf("请输入你要修改人的家庭地址：");
			scanf("%s",Tree->data.Address);
			fflush(stdin);
			break;
		}
	}
	printf("修改成功！");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员职业*******
void ChangeVocation(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("请输入你要修改人的姓名：");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
            printf("请输入你要修改人的职业：");
			scanf("%s",Tree->data.Vocation);
			fflush(stdin);
			break;
		}
	}
	printf("修改成功！");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******修改成员简历*******
void ChangeDegree(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("请输入你要修改人的姓名：");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n请从新输入你要修改人的姓名：");
		}
		else
		{
            printf("请输入你要修改人的简历：");
			scanf("%s",Tree->data.Degree);
			fflush(stdin);
			break;
		}
	}
	printf("修改成功！");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按先序遍历输出家谱*******
void OutPutFamily(BinTree T) 
{
	int i;
	BinTree P;
	for (i=1;i<T->data.Degress;i++)
	{
		printf("     ");
	}
	printf("%s\n",T->data.Name);//输出成员的姓名
	if (T->data.Num)
	{
		P=T->child;
		OutPutFamily(P);    //循环
		for (i=2;i<=T->data.Num;i++)
		{
			P=P->brother;   
			OutPutFamily(P);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按出生日期查找辅助函数******
int ValueBirthday(BinTree T,Date Birth)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if(a->data.Birthday.year==Birth.year)
			{
				if (a->data.Birthday.month==Birth.month)
				{
					if (a->data.Birthday.day==Birth.day)
					{
						Put(a);//输出成员信息
						i=1;   
					}
				}
			}
			
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;  //存在有该出生日期的成员返回1，否则返回0
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按出生日期查找*******
void  InquireBirthday(BinTree T)
{
	Date Birth;
	int j=2;
	int i;
	while(j)
	{
		printf("请输入你要查询人的出生日期：\n");
		while(1)
		{
			printf("年:");
			scanf("%d",&Birth.year);
			fflush(stdin);
			printf("月:");
			scanf("%d",&Birth.month);
			fflush(stdin);
			printf("日:");
			scanf("%d",&Birth.day);
			fflush(stdin);
			if(Inspect(Birth)==0)
			{
				printf("日期错误！请从新输入！\n");
				fflush(stdin);
			} 
			else
			{
				break;
			}
		}
		i=ValueBirthday(T,Birth);//返回值保存到i中
		if (i==0)                 
		{
			printf("不存在符合此出生日期的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
			j=0;  //存在有该出生日期的人，j等于0退出循环
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按死亡日期查找辅助函数******
int ValueDie(BinTree T,Date Die)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.SW,"N"))==0||(strcmp(a->data.SW,"n"))==0)
			{
				if(a->data.Dieday.year==Die.year)
				{
					if (a->data.Dieday.month==Die.month)
					{
						if (a->data.Dieday.day==Die.day)
						{
							Put(a);
							printf("\n********************************************************\n");
							i=1;
						}
					}
				}
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******查找健在的人的辅助函数******
int ValueSW(BinTree T)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.SW,"Y"))==0||(strcmp(a->data.SW,"y"))==0)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员是否健在及死亡日期查找*******
void  InquireSW(BinTree T)
{
	Date Die;
	int i,j=2;
	char sw[len];
	while(j)
	{
		printf("请输入你要查询人是否健在(是Y或否N):");
		while(1)
		{
			scanf("%s",sw);
			if((strcmp(sw,"Y"))==0||(strcmp(sw,"N"))==0||(strcmp(sw,"y"))==0||(strcmp(sw,"n"))==0) break;
			else
				printf("输入错误！请从新输入\n");
		}
		if((strcmp(sw,"N"))==0||(strcmp(sw,"n"))==0)     
		{
			printf("请输入死亡日期:\n");
			while(1)
			{
				printf("年:");
				scanf("%d",&Die.year);
				fflush(stdin);
				printf("月:");
				scanf("%d",&Die.month);
				fflush(stdin);
				printf("日:");
				scanf("%d",&Die.day);
				fflush(stdin);
				if(Inspect(Die)==0)
				{
					printf("日期错误！请从新输入！\n");
				}
				else
				{
					break;
				}
			}
			
		}
		if((strcmp(sw,"N"))==0||(strcmp(sw,"n"))==0)//死亡
		{
			i=ValueDie(T,Die);
			if (i==0)
			{
				printf("不存在此人！\n");
				printf("是否需要重新查询（1：需要。0：不需要）：");
				while(1)
				{
					scanf("%d",&j);
					fflush(stdin);
					if (j==0||j==1)
					{
						break;
					}
					else
						printf("输入错误，请重新输入:");
			}
			}
			else
				j=0;
		}
		else                               //健在
		{
			i=ValueSW(T);
			if (i==0)
			{
				printf("不存在此人！\n");
				printf("是否需要重新查询（1：需要。0：不需要）：");
				while(1)
				{
					scanf("%d",&j);
					fflush(stdin);
					if (j==0||j==1)
					{
						break;
					}
					else
						printf("输入错误，请重新输入:");
			}
			}
			else
				j=0;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员出生地址查找辅助函数*******
int ValueBrothadd(BinTree T,char Birthadd[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.Brothadd,Birthadd))==0)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员出生地址查找*******
void  InquireBrothadd(BinTree T)
{
	char Birthadd[len];
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的出生地址：");
		scanf("%s",Birthadd);
		fflush(stdin);
		i=ValueBrothadd(T,Birthadd);
		if (i==0)
		{
			printf("不存在符合此出生地址的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员家庭住址查找辅助函数*******
int ValueAddress(BinTree T,char Address[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.Address,Address))==0)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员家庭住址查找*******
void  InquireAddress(BinTree T)
{
	char Address[len];
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的家庭住址：");
		scanf("%s",Address);
		fflush(stdin);
		i=ValueAddress(T,Address);
		if (i==0)
		{
			printf("不存在符合此家庭住址的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员职业查找辅助函数*******
int ValueVocation(BinTree T,char Vocation[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.Vocation,Vocation))==0)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按成员职业查找*******
void  InquireVocation(BinTree T)
{
	char Vocation[len];
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的职业：");
		scanf("%s",Vocation);
		fflush(stdin);
		i=ValueVocation(T,Vocation);
		if (i==0)
		{
			printf("不存在符合此职业的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按父亲姓名查找辅助函数*******
int ValueFather(BinTree T,char Father[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if((strcmp(a->data.Father,Father))==0)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按父亲姓名查找*******
void  InquireFather(BinTree T)
{
	char Father[len];
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的父亲姓名：");
		scanf("%s",Father);
		fflush(stdin);
		i=ValueFather(T,Father);
		if (i==0)
		{
			printf("不存在父亲姓名是该名字的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按辈分查找辅助函数*******
int ValueDegress(BinTree T,int Degress)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if(a->data.Degress==Degress)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按辈分查找*******
void  InquireDegress(BinTree T)
{
	int Degress;
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的辈分：");
		scanf("%d",&Degress);
		fflush(stdin);
		i=ValueDegress(T,Degress);
		if (i==0)
		{
			printf("不存在此辈分的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按身高查找辅助函数*******
int ValueHeight(BinTree T,int Height)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if(a->data.Height==Height)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按身高查找*******
void  InquireHeight(BinTree T)
{
	int Height;
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的身高：");
		scanf("%d",&Height);
		fflush(stdin);
		i=ValueHeight(T,Height);
		if (i==0)
		{
			printf("不存在此身高的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}	
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按年龄查找辅助函数*******
int ValueAge(BinTree T,int Age)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //构建一个空队列q
		EnQueue(q,T);                        //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //对头出队列
			if(a->data.Age==Age)
			{
				Put(a);
				printf("\n********************************************************\n");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******按年龄查找*******
void  InquireAge(BinTree T)
{
	int Age;
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的年龄：");
		scanf("%d",&Age);
		fflush(stdin);
		i=ValueAge(T,Age);
		if (i==0)
		{
			printf("不存在此年龄的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}	
//////////////////////////////////////////////////////////////////////////
//                          *******统计操作*******
void MainMenueTongji(BinTree T)
{//菜单选择
	int c;
	int people=0;                  //家族总人口
	double PHeight=0;              //平均身高
	double PAge=0;                 //平均年龄
	int Pfamily=0;                 //平均家庭人口
	int man=0;                     //男性
	int woman=0;                   //女性
	LinkQueue q;
	QElemType a;
	InitQueue(q);                        //构建一个空队列q
	EnQueue(q,T);                        //在队尾插入新元素T
	while(!QueueEmpty(q))
	{
		DeQueue(q,a);                   //对头出队列
		people++;
		if((strcmp(a->data.Kind,"M"))==0||(strcmp(a->data.Kind,"m"))==0) 
		{
			man++;
		}
		else
			woman++;
		PHeight=PHeight+a->data.Height;    //计算身高总和
		PAge=PAge+a->data.Age;             //计算年龄总和
		Pfamily=Pfamily+a->data.Num+1;     //计算家庭人口总和
		if(a->child)
			EnQueue(q,a->child);
		if(a->brother)
			EnQueue(q,a->brother);
	}
	PHeight=PHeight/people;
	PAge=PAge/people;
	Pfamily=Pfamily/people;
	while(1)
	{
		system("cls");//清屏幕
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //设置文字颜色为黄色
		printf("\t");
		printf("\n\n\t         ---*****---请选择你的操作---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//设置文字颜色为白色
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //设置文字颜色为绿色		
		printf("\n\t------------------1:平均年龄------------------------------");	
		printf("\n\t------------------2:平均身高------------------------------");
		printf("\n\t------------------3:性别报告------------------------------");
		printf("\n\t------------------4:平均家庭人口--------------------------");
		printf("\n\t------------------0:退出统计操作，返回主菜单--------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  //设置文字颜色为白色 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t请输入你的选项：（0~4）");
		fflush(stdin);
		scanf("%d",&c);
		fflush(stdin);
		switch(c)
		{
		case 1:
			system("cls");//清屏幕
			printf("家族平均年龄是%0.1lf",PAge);
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 2:
			system("cls");//清屏幕
			printf("家族平均身高是%0.1lf",PHeight);
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
			
		case 3:
			system("cls");//清屏幕
			printf("家族有男性%d人，女性%d人",man,woman);
			printf("\n\n\t--------------请按Enter键继续操作--------------");
			fflush(stdin);
			getchar();
			break;
		case 4:
			system("cls");//清屏幕
			printf("家族的平均家庭人口数为%d",Pfamily);
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
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******层次遍历输出*******
void CengciPut(BinTree T)
{
	LinkQueue Q;
	QElemType a;
	BinTree C;
	int i;
	if (T->data.Num)
	{
		InitQueue(Q); 			             //构建一个空队列Q
		C=T->child;
		EnQueue(Q,C);                        //C进队列
		for (i=2;i<=T->data.Num;i++)
		{
			C=C->brother;
			EnQueue(Q,C);
		}
		while(!QueueEmpty(Q))
		{
			DeQueue(Q,a);                   //对头出队列
			printf("\n********************************************************\n");		
			Put(a);
			if (a->data.Num)
			{
				C=a->child;
				EnQueue(Q,C);
				for (i=2;i<=a->data.Num;i++)
				{
					C=C->brother;
					EnQueue(Q,C);
				}
			}
		}
	}			
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******查询某一成员的所有直系亲属辅助函数*******
int ValueZhixi(BinTree T,char Name[len])
{
	HANDLE consolehwnd; 
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                                 //构建一个空队列q
		EnQueue(q,T);                                 //在队尾插入新元素T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                             //对头出队列
			if((strcmp(a->data.Name,Name))==0)        //符合所要查询人的姓名
			{
				printf("本人信息:");
				Put(a);			
				if (a->parent!=NULL)
				{
					SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED); //设置文字颜色为红色
					if (a->parent->parent!=NULL)
					{					
						printf("\n********************************************************\n");
						printf("祖父的信息：\n");
						Put(a->parent->parent);
					}
					else
						printf("\n此人没有祖父");	
					SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //设置文字颜色为黄色
					printf("\n********************************************************\n");
					printf("父亲的信息：\n");
					Put(a->parent);
				}
				else
					printf("\n此人没有祖父\n此人没有父亲");	
				SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //设置文字颜色为绿色
				if (a->data.Num)
				{	
					printf("\n后代的信息：");		
					CengciPut(a);
				}
				else
					printf("\n此人没有子女");
				i=1;
			}
			if(a->child)
				EnQueue(q,a->child);
			if(a->brother)
				EnQueue(q,a->brother);
		}
	}
	return i;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******查询某一成员的所有直系亲属*******
void  InquireZhixi(BinTree T)
{
	char Name[len];
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的姓名：");
		scanf("%s",Name);
		fflush(stdin);
		i=ValueZhixi(T,Name);
		if (i==0)
		{
			printf("不存在符合此姓名的人！\n");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;       //跳出循环
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			j=0;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******查询某一成员的所有嫡系祖先*******
void InquireRoot(BinTree T)
{
	char name[len];
	BinTree Tree;
	int j=2,i;
	while(j)
	{
		printf("请输入你要查询人的姓名：");
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n：");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
			
		}
		else
		{
			if (Tree->parent==NULL)
			{
				printf("此人没有祖先！");
			}
			else
			{
				printf("\n********************************************************\n");
				printf("\n父亲的信息：\n");
				Put(Tree->parent);
				Tree=Tree->parent;
				if (Tree->parent!=NULL)
				{
					printf("\n********************************************************\n");
					printf("\n祖父的信息：\n");
					Put(Tree->parent);
					Tree=Tree->parent;
				}
				i=3;
				while(1)
				{
					if (Tree->parent!=NULL)
					{
						printf("\n********************************************************\n");
						printf("\n上%d辈祖先的信息\n",i);
						Put(Tree->parent);
						Tree=Tree->parent;
					}
					else
						break;
				}
			}			
			break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******查询两个人的关系*******
void RelationShip(BinTree T)
{
	char name1[len],name2[len];
	BinTree Tree1,Tree2,p;
	int j=2,i,Deg;
	printf("请输入第一个人的姓名：");
	while(1)
	{
		scanf("%s",name1);
		fflush(stdin);
		Tree1=Value(T,name1);
		if (Tree1==NULL)
		{
			printf("不存在此人！\n请重新输入第一个人的姓名：");
		}
		else
			break;
	}	
	printf("请输入第二个人的姓名：");
	while(1)
	{
		scanf("%s",name2);
		fflush(stdin);
		if((strcmp(name1,name2))==0)
		{
			printf("与第一人的姓名相同，请重新输入：");
			continue;
		}
		Tree2=Value(T,name2);
		if (Tree2==NULL)
		{
			printf("不存在此人！\n请重新输入第二个人的姓名：");	
		}
		else
			break;
	}
	if (Tree1->data.Degress>Tree2->data.Degress)
	{
		Deg=Tree1->data.Degress-Tree2->data.Degress;
		p=Tree1->parent;
		for (i=2;i<=Deg;i++)
		{
			p=p->parent;
		}
		if ((strcmp(p->data.Name,name2))==0)
		{
			if (Deg==1)
			{
				printf("%s是%s的儿子",name1,name2);
			}
			if (Deg==2)
			{
				printf("%s是%s的孙子",name1,name2);
			}
			if (Deg>2)
			{
				printf("%s是%s的下%d辈的嫡系晚辈",name1,name2,Deg);
			}
		}
		else
		{
			printf("%s是%s的下%d辈的非嫡系晚辈",name1,name2,Deg);
		}
	}
	if (Tree1->data.Degress<Tree2->data.Degress)
	{
		Deg=Tree2->data.Degress-Tree1->data.Degress;
		p=Tree2->parent;
		for (i=2;i<=Deg;i++)
		{
			p=p->parent;
		}
		if ((strcmp(name1,p->data.Name))==0)
		{
			if (Deg==1)
			{
				printf("%s是%s的父亲",name1,name2);
			}
			if (Deg==2)
			{
				printf("%s是%s的祖父",name1,name2);
			}
			if (Deg>2)
			{
				printf("%s是%s的上%d辈的嫡系祖先",name1,name2,Deg);
			}
		}
		else
		{
			printf("%s是%s的上%d辈的非嫡系祖先",name1,name2,Deg);
		}
	}
	if (Tree1->data.Degress==Tree2->data.Degress)
	{
		if ((strcmp(Tree1->parent->data.Name,Tree2->parent->data.Name))==0)
		{
			if (Inspect1(Tree1->data.Birthday,Tree2->data.Birthday)==0)     //Tree1在Tree2之后出生
			{
				printf("%s是%s的弟弟",name1,name2);
			}
			else
			printf("%s是%s的哥哥",name1,name2);
		}
		else
		{
			if (Inspect1(Tree1->data.Birthday,Tree2->data.Birthday)==0)     //Tree1在Tree2之后出生
			{
				printf("%s是%s的堂弟",name1,name2);
			}
			else
			printf("%s是%s的堂哥",name1,name2);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     ******生存天数计算******
int Count_day(BinTree T)
{
	int i,k=0,day=0;
	
	i=T->data.Birthday.year;
	if(i%400==0 || i%4==0 && i%100!=0)                                //闰年
		k=1;
	switch(T->data.Birthday.month)                                    //计算出生的那一年
	{
	case 1:
		day=31-T->data.Birthday.day;                                //出生那个月的天数
		if(k)              //闰年                                         
			day=day+31+30+31+30+31+31+30+31+30+31+29;                                             
		else               //平年
			day=day+31+30+31+30+31+31+30+31+30+31+28;
		break;
	case 2:
		if(k)      //闰年
		{
			day=29-T->data.Birthday.day;
			day=day+31+30+31+30+31+31+30+31+30+31;
		}
		else      //平年
		{
			day=28-T->data.Birthday.day;
			day=day+31+30+31+30+31+31+30+31+30+31;
		}
		break;
	case 3:
		day=31-T->data.Birthday.day;
		day=day+31+30+31+30+31+31+30+31+30;
		break;
	case 4:
		day=30-T->data.Birthday.day;
		day=day+31+30+31+30+31+31+30+31;
		break;
	case 5:
		day=31-T->data.Birthday.day;
		day=day+31+30+31+30+31+31+30;
		break;
	case 6:
		day=30-T->data.Birthday.day;
		day=day+31+30+31+30+31+31;
	       break;
	case 7:
		day=31-T->data.Birthday.day;
		day=day+31+30+31+30+31;
		break;
	case 8:
		day=31-T->data.Birthday.day;
		day=day+31+30+31+30;
		break;
	case 9:
		day=30-T->data.Birthday.day;
		day=day+31+30+31;
	       break;
	case 10:
		day=31-T->data.Birthday.day;
		day=day+31+30;
		break;
	case 11:
		day=30-T->data.Birthday.day;
		day=day+31;
	       break;
	case 12:
		day=31-T->data.Birthday.day;
		break;
	}
	if((strcmp(T->data.SW,"Y"))==0||(strcmp(T->data.SW,"y"))==0)               //当前没有去世
        for(i=i+1;i<=2012;i++)
		{
			if(i%400==0 || i%4==0 && i%100!=0)                                           //闰年
				day=day+366;
			else
				day=day+365;                                                               //平年
		}
		else                                                                              //已经去世了
		{
			for(i=i+1;i<T->data.Dieday.year;i++)
			{
				if(i%400==0 || i%4==0 && i%100!=0)
					day=day+366;
				else
					day=day+365;
			}
			
			i=i+1;                                                                         //死亡的年份
			if(i%400==0 || i%4==0 && i%100!=0)          //闰年k=1
				k=1;
			else                                        //平年
				k=0;
			switch(T->data.Dieday.month)                                                    //计算死亡那年的天数
			{
			case 1:
				day=day+T->data.Dieday.day;
				break;
			case 2:
				day=day+T->data.Dieday.day+31;
				break;
			case 3:
				if(k)                                                                   
					day=day+T->data.Dieday.day+31+29;
				else
					day=day+T->data.Dieday.day+31+28;								   	
				break;
			case 4:
				if(k)                                                                   
					day=day+T->data.Dieday.day+31+29+31;
				else
					day=day+T->data.Dieday.day+31+28+31;								   	
				break;
			case 5:
				if(k)                                                                   
					day=day+T->data.Dieday.day+31+29+31+30;
				else
					day=day+T->data.Dieday.day+31+28+31+30;								   	
				break;
			case 6:
				if(k)                                                                   
					day=day+T->data.Dieday.day+31+29+31+30+31;
				else
					day=day+T->data.Dieday.day+31+28+31+30+31;								   	
				break;
			case 7:			
				if(k)                                                                   
					day=day+T->data.Dieday.day+31+29+31+30+31+30;
				else
					day=day+T->data.Dieday.day+31+28+31+30+31+30;								   	
				break;
			case 8:				
				if(k)                                                                   
					day=day+T->data.Dieday.day+31+29+31+30+31+30+31;
				else
					day=day+T->data.Dieday.day+31+28+31+30+31+30+31;								   	
				break;
			case 9:				
			   if(k)                                                                   
			       day=day+T->data.Dieday.day+31+29+31+30+31+30+31+31;
			   else
				   day=day+T->data.Dieday.day+31+28+31+30+31+30+31+31;								  	
               break;
		case 10:
			   if(k)                                                                  
			       day=day+T->data.Dieday.day+31+29+31+30+31+30+31+31+30;
			   else
				   day=day+T->data.Dieday.day+31+28+31+30+31+30+31+31+30;								  	
               break;
		case 11:
			   if(k)                                                                   
			       day=day+T->data.Dieday.day+31+29+31+30+31+30+31+31+30+31;
			   else
				   day=day+T->data.Dieday.day+31+28+31+30+31+30+31+31+30+31;								   	
               break;
		case 12:
			   if(k)                                                                   
			       day=day+T->data.Dieday.day+31+29+31+30+31+30+31+31+30+31+30;
			   else
				   day=day+T->data.Dieday.day+31+28+31+30+31+30+31+31+30+31+30;								   	
               break;
		}
	}
	return day;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                 ******生存天数*******
void Inquireday(BinTree T)
{
	char name[len];
	BinTree Tree;
	int i,j=2;
	while(j)
	{
		printf("请输入你要查询人的姓名：");
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("不存在此人！\n：");
			printf("是否需要重新查询（1：需要。0：不需要）：");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("输入错误，请重新输入:");
			}
		}
		else
		{
			i=Count_day(Tree);
			printf("\n此人存活天数：%d天",i);
			break;
		}
	}
}