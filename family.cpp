#include"graph.h"
//#include <windows.h> 

typedef BinTree QElemType;

////////////////////////////////////////////////////////////////////////////////
//                   *******���еĲ���*******

void InitQueue(LinkQueue &Q)           //��ʼ������
{
	if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))
		exit(0);
	
	Q.front->next=NULL;
	return;
}

int QueueEmpty(LinkQueue Q)           //�пղ���
{
	return(Q.front->next==NULL);
}

void EnQueue(LinkQueue &Q,QElemType e)       //����в���
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

int DeQueue(LinkQueue &Q,QElemType &e)    //�����в���
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
//                       *******�ж�ʱ�����ȷ��********
int Inspect(Date D)                    
{
	if(D.year<500||D.year>2500)    //�ж����
		return 0;
	if(D.month<1||D.month>12)      //�ж��·�
		return 0;
	if(D.month==1||D.month==3||D.month==5||D.month==7||D.month==8||D.month==10||D.month==12)  //�жϴ��µ�����
	{
		if(D.day<1||D.day>31)
		{
			return 0;
		}
	}
	if(D.month==4||D.month==6||D.month==9||D.month==11)//�ж�С�µ�����
	{
		if(D.day<1||D.day>30)
		{
			return 0;
		}
	}
	if(D.year%4==0)        //�ж����������
	{
		if(D.month==2)
		{
			if(D.day<1||D.day>29)  //����
			{
				return 0;
			}
		}
	}
	else
	{
		if(D.month==2)
		{
			if(D.day<1||D.day>28)//ƽ��
			{
				return 0;
			}
		}
	}
	return 1;
}
////////////////////////////////////////////////////////////////////////////////
//                 *******�ж����ڴ�С--B����D***********
int Inspect1(Date B,Date D)                   //B��������D֮ǰ����1
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
//                               ******���������Ϣ********
void CreateTree(BinTree &T,BinTree F)              
{
	int i,j=1;
	printf("����������:");
	scanf("%s",T->data.Name);
	for(i=0;i<100;i++)
	{
		printf("�������Ա�(��M��ŮG):");
		scanf("%s",T->data.Kind);
		if((strcmp(T->data.Kind,"M"))==0||(strcmp(T->data.Kind,"G"))==0||(strcmp(T->data.Kind,"m"))==0||(strcmp(T->data.Kind,"g"))==0) break;
		else
			printf("����������������\n");
	}
	printf("�������������:\n");
	while(j)
	{
		while(1)
		{
			printf("��:");
			scanf("%d",&T->data.Birthday.year);
			fflush(stdin);
			printf("��:");
			scanf("%d",&T->data.Birthday.month);
			fflush(stdin);
			printf("��:");
			scanf("%d",&T->data.Birthday.day);
			fflush(stdin);
			if(Inspect(T->data.Birthday)==0)
			{
				printf("���ڴ�����������룡\n");
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
				printf("�������ڱȸ���С�����������룡\n");
			}
		}
	}
	for(i=0;i<100;i++)
	{
		printf("����������Ƿ���(��Y���N):");
		scanf("%s",T->data.SW);
		if((strcmp(T->data.SW,"Y"))==0||(strcmp(T->data.SW,"N"))==0||(strcmp(T->data.SW,"y"))==0||(strcmp(T->data.SW,"n"))==0) break;
		else
			printf("����������������\n");
	}
	
	if((strcmp(T->data.SW,"N"))==0||(strcmp(T->data.SW,"n"))==0)
	{
		printf("��������������:\n");
		while(1)
		{
			for(i=0;i<100;i++)
			{
				printf("��:");
				scanf("%d",&T->data.Dieday.year);
				fflush(stdin);
				printf("��:");
				scanf("%d",&T->data.Dieday.month);
				fflush(stdin);
				printf("��:");
				scanf("%d",&T->data.Dieday.day);
				fflush(stdin);
				if(Inspect(T->data.Dieday)==0)
				{
					printf("���ڴ�����������룡\n");
				}
				else
				{
					break;
				}
			}
			if(Inspect1(T->data.Birthday,T->data.Dieday)==0)
			{
				printf("�������ڱȳ��������磬��������룡\n");
				
			}
			else
				break;
		}
	}
	while(1)
	{
		printf("����������˻���ѻ�Y��δ��N��:");
		scanf("%s",T->data.Marital);
		if((strcmp(T->data.Marital,"Y"))==0||(strcmp(T->data.Marital,"N"))==0||(strcmp(T->data.Marital,"y"))==0||(strcmp(T->data.Marital,"n"))==0)
		{
			break;
		}
		else
		{
			printf("�������!���������\n");
		}
	}
	printf("�����������ַ:");
	scanf("%s",T->data.Brothadd);
	printf("�������ͥ��ַ:");
	scanf("%s",T->data.Address);
	printf("������ְҵ:");
	scanf("%s",T->data.Vocation);
	printf("���������:");
	scanf("%s",T->data.Degree);
	printf("���������(����):");
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
		strcpy(T->data.Father,"û��");
	}
	else
		strcpy(T->data.Father,F->data.Name);
	T->data.Num=0;
	T->child=NULL;
	
}
////////////////////////////////////////////////////////////////////////////////
//                    *******����ָ�����********

BinTree Value(BinTree T,char Name[len])
{
	LinkQueue q;
	QElemType a;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                 *******�������ʱ����ÿ����Ա���ּ�һ********  
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
//                       *******���ӳ�Ա*******
void Add(BinTree &T)              
{
	char Name[len];
	BinTree Tree,F,C[len],P=NULL;
	int c,i,j=1,h=1;
	if(T==NULL)        //�����ڼ���
	{
		T=(BinTree)malloc(sizeof(BinNode));
		T->parent =NULL;
		T->brother=NULL;
		printf("�����ڼ��ף��½�������\n�������ȵ���Ϣ��\n");
		CreateTree(T,P);
		T->data.Degress=1;     
	}
	else
	{
		printf("1������³�Ա��Ϊ�������׵�����\n");
		printf("2������³�Ա��Ϊĳһ��Ա�ĺ���\n");
		while(j)
		{
			printf("���������ѡ�1~2����");
			fflush(stdin);
			scanf("%d",&c);
			fflush(stdin);
			switch(c)
			{
			case 1:
				
				Tree=(BinTree)malloc(sizeof(BinNode));
				Tree->brother=NULL;          //���Ȳ������ֵ�
				CreateTree(Tree,P);
				Tree->data.Degress=1;
				Tree->data.Num++;           //��������ʼֵΪ�㣬��������һ
				strcpy(T->data.Father,Tree->data.Name);//ԭ�ȵ����ȵĸ��������޸�Ϊ�������ȵ�����
				Tree->child=T;              //ԭ�ȵ����ȸ������ڵ�����������
				Tree->parent=NULL;
				T->parent=Tree;             //���ڵ����ȸ���ԭ�ȵ�����������
				T=Tree;
				AddDegress(T->child);       //ԭ�����г�Ա�ı��ּ�һ
				j=0;      //����whileѭ��
				break;
			case 2:
				printf("����������ӳ�Ա�ĸ�������:\n�������λ���\n");
				i=3;
				while(i)
				{
					fflush(stdin);
					scanf("%s",Name);
					fflush(stdin);
					F=Value(T,Name);     //F��Ÿ��׽��
					if(F==NULL)
					{
						i--;
						if (i==0)
						{
							printf("���������������!\n",i);
							break;
						}
						printf("���������������\n�㻹��%d�λ���\n��������룺\n",i);
					}
					else
					{
						break;
					}
				}
				if (i==0)    //���λ������꣬û���ҵ�Ҫ��ӳ�Ա�ĸ���
				{
					j=0;
					break;
				}
				printf("����������ӳ�Ա����Ϣ\n");
				Tree=(BinTree)malloc(sizeof(BinNode));
				CreateTree(Tree,F);
				Tree->data.Degress=F->data.Degress+1;        //����˵ı��ֵ��ڸ��׵ı��ּ�һ
				if (F->data.Num)                                      //����˵ĸ��״��ں���
				{
					
					C[1]=F->child;			   //���游�׵ĵ�һ������
					if (F->data.Num==1)              //ֻ��һ������
					{
						if(Inspect1(Tree->data.Birthday,C[1]->data.Birthday)==1)    //Tree�������C[1]��
						{
							Tree->brother=F->child;         //�Ѹ���ԭ�ȵĵ�һ�����Ӹ��������ֵ�
							Tree->parent=F;
							F->child=Tree;                  //�������׵ĺ��ӽڵ㴦
							Tree->child=NULL;
						}
						else                   //�ȵ�һ������С
						{
							C[1]->brother=Tree;
							Tree->parent=F;
							Tree->brother=NULL;
							Tree->child=NULL;
						}
					}
					if(F->data.Num>1)              //�ж������
					{
						for (i=2;i<=F->data.Num;i++)
						{
							C[i]=C[i-1]->brother;
							if(Inspect1(Tree->data.Birthday,C[i]->data.Birthday)==1)    //Tree�������C[i]��
							{
								Tree->brother=C[i-1]->brother;
								Tree->parent=F;
								C[i-1]->brother=Tree;
								Tree->child=NULL;
								h=0;
								break;
							}
						}
						if(h)      //�����һ������֮ǰ�����к��ӵ����䶼ҪС
						{
							if(Inspect1(Tree->data.Birthday,C[i-1]->data.Birthday)==0)     //Tree�������F��������С���ӵ����仹С 
							{
								C[i-1]->brother=Tree;
								Tree->parent=F;
								Tree->brother=NULL;
								Tree->child=NULL;
							}
						}
					}
					
				}
				else                  //�����ں���
				{
					F->child=Tree;
					Tree->parent=F;
					Tree->child=NULL;
					Tree->brother=NULL;
				}
				j=0;
				F->data.Num++;         //���׵ĺ�������һ
				break;
			default:
				printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!-----------");
				printf("\n\t-----------�����ٴ�ѡ������ķ�����!-----------------\n");
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
//                      *******�Ѽ��ױ��浽�ļ���*******
void BaoCun(BinTree T)
{
	int i;
	LinkQueue Q;
	QElemType a,C[len];
	FILE *fp;
	if ((fp=fopen("Family","wb+"))==NULL)      //�ö����Ʊ���
	{
		printf("cannot open this file\n");
		exit(0);
	}
	if(T)
	{
		InitQueue(Q);                   //����һ���ն���Q
		EnQueue(Q,T);                   //�ڶ�β������Ԫ��T
		while(!QueueEmpty(Q))           //���в�Ϊ��
		{
			DeQueue(Q,a);               //�����У����浽a��
			fprintf(fp,"%s %d %d %d %s ",a->data.Name,a->data.Birthday.year,a->data.Birthday.month,a->data.Birthday.day,a->data.SW);
			if (strcmp(a->data.SW,"N")==0||strcmp(a->data.SW,"n")==0)
			{
				fprintf(fp,"%d %d %d ",a->data.Dieday.year,a->data.Dieday.month,a->data.Dieday.day);
			}
			fprintf(fp,"%s %s %s ",a->data.Kind,a->data.Marital,a->data.Brothadd);
			fprintf(fp,"%s %s %s ",a->data.Address,a->data.Vocation,a->data.Degree);
			fprintf(fp,"%s %d ",a->data.Father,a->data.Degress);
			fprintf(fp,"%d %d %d\n",a->data.Height,a->data.Age,a->data.Num);
			if (a->data.Num)         //a�к���
			{
				C[1]=a->child;
				EnQueue(Q,C[1]);    //��һ�����������
				for (i=2;i<=a->data.Num;i++)
				{
					C[i]=C[i-1]->brother;
					EnQueue(Q,C[i]);
				}
			}
		}
	}
	fclose(fp);
	printf("\n\t*****�ļ�����ɹ���*****\n\t");	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                            *******���ļ��ж�ȡ��Ϣ*******
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
//                           *******���ļ���ȡ��Ϣ����������********
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
	EnQueue(q,B);           //�ڶ�β������Ԫ��B
	while(!QueueEmpty(q))
	{
		DeQueue(q,a);       //������
		for(i=1;i<=a->data.Num;i++)
		{
			B=(BinTree)malloc(sizeof(BinNode));
			InPut(B,fp);
			EnQueue(q,B);
		}
		EnQueue(s,a);           //�����г�Ա��˳�����ջ��
		EnQueue(h,a);           //�����г�Ա��˳�����ջ��
	}
	fclose(fp);
	DeQueue(s,p);              //��s�г����б��浽p��
	T=p;                       //���׵�����Ϊp
	while  (!QueueEmpty(h))    //����h�ǿ�
	{
		DeQueue(h,p);          //��h�г����б��浽p��
		F=Value(T,p->data.Name);//���½����ļ������ҵ�p���浽F��
		if (F->data.Num)       //����������s�г�������Ӹ�F������
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
	printf("\n\t*****�ļ���ȡ�ɹ���*****\n\t");	
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                    *******�����Ա��Ϣ*********
void Put(BinTree T)
{
	printf("\n��    ����%s ",T->data.Name);
	printf("\n��    ��");
	if((strcmp(T->data.Kind,"M"))==0||(strcmp(T->data.Kind,"m"))==0) 
	{
		printf("��               ");
	}
	else
		printf("Ů               ");
	printf("�������ڣ�%d��%d��%d��",T->data.Birthday.year,T->data.Birthday.month,T->data.Birthday.day);
	printf("\n�Ƿ��ڣ�");
	if ((strcmp(T->data.SW,"N"))==0||(strcmp(T->data.SW,"n"))==0)
	{
		printf("��               �������ڣ�%d��%d��%d��",T->data.Dieday.year,T->data.Dieday.month,T->data.Dieday.day);
	}
	else
		printf("��");
	printf("\n��    ��:");
	if ((strcmp(T->data.Marital,"Y"))==0||(strcmp(T->data.Marital,"y"))==0)
	{
		printf("�ѻ�");
	}
	else 
		printf("δ��");
	printf("\n������ַ:%s",T->data.Brothadd);
	printf("\n��ͥ��ַ:%s",T->data.Address);
	printf("\nְ    ҵ:%s",T->data.Vocation);
	printf("\n��    ��:%s",T->data.Degree);
	printf("\n��    ��:%d����",T->data.Height);
	printf("\n��    ��:%d��",T->data.Age);
	printf("\n��������:%s",T->data.Father);
	printf("\n��    ��:��%d��",T->data.Degress);
	printf("\nӵ��%d����Ů",T->data.Num);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                    *******������ѯ���׳�Ա����ʾ�ó�Ա�ĸ�����Ϣ*******
void  InquireName(BinTree T)
{
	char name[len];
	BinTree Tree;
	int j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵�������");
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n��");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
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
//                              *******ɾ����Ա*******

void DeleteTree(BinTree &T)
{
	char name[len];
	BinTree Tree,F,Q,P;
	printf("��������Ҫɾ���˵�������");
	while (1)
	{
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n������������Ҫɾ���˵�������");
		}
		else
		{
			break;
		}
	}
 	F=Tree->parent;
	Q=F;
	P=Q->child;                   //��P���游�׵ĵ�һ������
	if(P==Tree)                   //��Ҫɾ�����������׵ĵ�һ������
	{
		if(P->brother==NULL)      //��Ҫɾ����û���ֵ�
		{
			Q->child=NULL;
			free(Tree);
		}
		else                    //��Ҫɾ�������ֵ�
		{
			Q->child=P->brother; //��ɾ���˵��ֵܽڵ㸳�����׵ĺ��ӽڵ�
			free(P);
		}
		F->data.Num--;          //���׺�������һ
		return;
	}
	else
	{
		Q=P;
		while(P->brother!=NULL)     // �ֵܽڵ㲻Ϊ��
		{
			P=P->brother;               //��P���游�׵ĵڶ�������
			if(P==Tree)
			{
				if(P->brother==NULL)//��Ҫɾ����û�б���С���ֵ�
				{
					Q->brother=NULL;//��Ҫɾ���˵���һ���ֵܵ��ֵܽڵ㸳��
					free(Tree);
				}
				else
				{
					Q->brother=P->brother;//����Ҫɾ���˵���һ���ֵܸ�����һ���ֵܵ��ֵܽڵ㴦
					free(P);
				}
				F->data.Num--;
				return;
			}
			Q=P;
			P=P->brother;        //�����¸��ֵ�
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Ա����*******
void XiuGaiName(BinTree &T)
{
	int i;
	char Name[len],name[len];
	BinTree Tree,p;
	printf("��������Ҫ�޸��˵�������");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
            printf("��������Ҫ�޸������ڵ�������");
			scanf("%s",name);
	     	fflush(stdin);
			strcpy(Tree->data.Name,name);
			if (Tree->data.Num)              //���ں���
			{
				p=Tree->child;               //��P�����һ������
				strcpy(p->data.Father,name); //���޸ĵ��������ǵ����ӵĸ�������
				for (i=2;i<=Tree->data.Num;i++)
				{
					p=p->brother;
					strcpy(p->data.Father,name);
				}
			}
			break;
		}
	}
	printf("�޸ĳɹ���");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Ա��������*******
void ChangeBirthday(BinTree &T)
{
	int i=1;
	char Name[len];
	BinTree Tree;
	printf("��������Ҫ�޸��˵�������");
	while(i)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
			printf("�������������:\n");
			while(i)
			{
				while(1)
				{
					printf("��:");
					scanf("%d",&Tree->data.Birthday.year);
					fflush(stdin);
					printf("��:");
					scanf("%d",&Tree->data.Birthday.month);
					fflush(stdin);
					printf("��:");
					scanf("%d",&Tree->data.Birthday.day);
					fflush(stdin);
					if(Inspect(Tree->data.Birthday)==0)
					{
						printf("���ڴ�����������룡\n");
					}
					else
					{
						break;
					}
				}
				if((strcmp(Tree->data.SW,"N"))==0||(strcmp(Tree->data.SW,"n"))==0)//������
				{
					if(Inspect1(Tree->data.Birthday,Tree->data.Dieday)==0)    //�������ڱ�����������
					{
						printf("�������ڱ�������������������룡\n");
						break;
					}
					else                      //�������ڱ�����������
					{	
						Tree->data.Age=Tree->data.Dieday.year-Tree->data.Birthday.year;	
						printf("�޸ĳɹ���");
						i=0;
					}
				}
				else                 //���ڻ����ڣ������ж��Ƿ������������
				{
					Tree->data.Age=2011-Tree->data.Birthday.year;
					printf("�޸ĳɹ���");
					i=0;
					break;
				}
			}
		}
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Ա�Ƿ��ڼ���������*******
void ChangeSW(BinTree &T)
{
	int i;
	char Name[len];
	BinTree Tree;
	printf("��������Ҫ�޸��˵�������");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
			for(i=0;i<100;i++)
			{
				printf("��������Ҫ�޸����Ƿ���(��Y���N)��");
				scanf("%s",Tree->data.SW);
				if((strcmp(Tree->data.SW,"Y"))==0||(strcmp(Tree->data.SW,"N"))==0||(strcmp(Tree->data.SW,"y"))==0||(strcmp(Tree->data.SW,"n"))==0) break;
				else
					printf("����������������\n");
			}
			
			if((strcmp(Tree->data.SW,"N"))==0||(strcmp(Tree->data.SW,"n"))==0)
			{
				printf("��������������:\n");
				while(1)
				{
					while(1)
					{
						printf("��:");
						scanf("%d",&Tree->data.Dieday.year);
						fflush(stdin);
						printf("��:");
						scanf("%d",&Tree->data.Dieday.month);
						fflush(stdin);
						printf("��:");
						scanf("%d",&Tree->data.Dieday.day);
						fflush(stdin);
						if(Inspect(Tree->data.Dieday)==0)
						{
							printf("���ڴ�����������룡\n");
						}
						else
						{
							break;
						}
					}
					if(Inspect1(Tree->data.Birthday,Tree->data.Dieday)==0)
					{
						printf("�������ڱȳ��������磬��������룡\n");
						
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
			printf("�޸ĳɹ���");
			break;
		}	
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Ա������ַ*******
void ChangeBrothadd(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("��������Ҫ�޸��˵�������");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
            printf("��������Ҫ�޸��˵ĳ�����ַ��");
			scanf("%s",Tree->data.Brothadd);
			fflush(stdin);
			break;
		}
	}
	printf("�޸ĳɹ���");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Ա��ͥסַ*******
void ChangeAddress(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("��������Ҫ�޸��˵�������");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
            printf("��������Ҫ�޸��˵ļ�ͥ��ַ��");
			scanf("%s",Tree->data.Address);
			fflush(stdin);
			break;
		}
	}
	printf("�޸ĳɹ���");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Աְҵ*******
void ChangeVocation(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("��������Ҫ�޸��˵�������");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
            printf("��������Ҫ�޸��˵�ְҵ��");
			scanf("%s",Tree->data.Vocation);
			fflush(stdin);
			break;
		}
	}
	printf("�޸ĳɹ���");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�޸ĳ�Ա����*******
void ChangeDegree(BinTree &T)
{
	char Name[len];
	BinTree Tree;
	printf("��������Ҫ�޸��˵�������");
	while(1)
	{
		scanf("%s",Name);
		fflush(stdin);
		Tree=Value(T,Name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������Ҫ�޸��˵�������");
		}
		else
		{
            printf("��������Ҫ�޸��˵ļ�����");
			scanf("%s",Tree->data.Degree);
			fflush(stdin);
			break;
		}
	}
	printf("�޸ĳɹ���");
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******����������������*******
void OutPutFamily(BinTree T) 
{
	int i;
	BinTree P;
	for (i=1;i<T->data.Degress;i++)
	{
		printf("     ");
	}
	printf("%s\n",T->data.Name);//�����Ա������
	if (T->data.Num)
	{
		P=T->child;
		OutPutFamily(P);    //ѭ��
		for (i=2;i<=T->data.Num;i++)
		{
			P=P->brother;   
			OutPutFamily(P);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******���������ڲ��Ҹ�������******
int ValueBirthday(BinTree T,Date Birth)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
			if(a->data.Birthday.year==Birth.year)
			{
				if (a->data.Birthday.month==Birth.month)
				{
					if (a->data.Birthday.day==Birth.day)
					{
						Put(a);//�����Ա��Ϣ
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
	return i;  //�����иó������ڵĳ�Ա����1�����򷵻�0
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******���������ڲ���*******
void  InquireBirthday(BinTree T)
{
	Date Birth;
	int j=2;
	int i;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵ĳ������ڣ�\n");
		while(1)
		{
			printf("��:");
			scanf("%d",&Birth.year);
			fflush(stdin);
			printf("��:");
			scanf("%d",&Birth.month);
			fflush(stdin);
			printf("��:");
			scanf("%d",&Birth.day);
			fflush(stdin);
			if(Inspect(Birth)==0)
			{
				printf("���ڴ�����������룡\n");
				fflush(stdin);
			} 
			else
			{
				break;
			}
		}
		i=ValueBirthday(T,Birth);//����ֵ���浽i��
		if (i==0)                 
		{
			printf("�����ڷ��ϴ˳������ڵ��ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
			j=0;  //�����иó������ڵ��ˣ�j����0�˳�ѭ��
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******���������ڲ��Ҹ�������******
int ValueDie(BinTree T,Date Die)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******���ҽ��ڵ��˵ĸ�������******
int ValueSW(BinTree T)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******����Ա�Ƿ��ڼ��������ڲ���*******
void  InquireSW(BinTree T)
{
	Date Die;
	int i,j=2;
	char sw[len];
	while(j)
	{
		printf("��������Ҫ��ѯ���Ƿ���(��Y���N):");
		while(1)
		{
			scanf("%s",sw);
			if((strcmp(sw,"Y"))==0||(strcmp(sw,"N"))==0||(strcmp(sw,"y"))==0||(strcmp(sw,"n"))==0) break;
			else
				printf("����������������\n");
		}
		if((strcmp(sw,"N"))==0||(strcmp(sw,"n"))==0)     
		{
			printf("��������������:\n");
			while(1)
			{
				printf("��:");
				scanf("%d",&Die.year);
				fflush(stdin);
				printf("��:");
				scanf("%d",&Die.month);
				fflush(stdin);
				printf("��:");
				scanf("%d",&Die.day);
				fflush(stdin);
				if(Inspect(Die)==0)
				{
					printf("���ڴ�����������룡\n");
				}
				else
				{
					break;
				}
			}
			
		}
		if((strcmp(sw,"N"))==0||(strcmp(sw,"n"))==0)//����
		{
			i=ValueDie(T,Die);
			if (i==0)
			{
				printf("�����ڴ��ˣ�\n");
				printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
				while(1)
				{
					scanf("%d",&j);
					fflush(stdin);
					if (j==0||j==1)
					{
						break;
					}
					else
						printf("�����������������:");
			}
			}
			else
				j=0;
		}
		else                               //����
		{
			i=ValueSW(T);
			if (i==0)
			{
				printf("�����ڴ��ˣ�\n");
				printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
				while(1)
				{
					scanf("%d",&j);
					fflush(stdin);
					if (j==0||j==1)
					{
						break;
					}
					else
						printf("�����������������:");
			}
			}
			else
				j=0;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******����Ա������ַ���Ҹ�������*******
int ValueBrothadd(BinTree T,char Birthadd[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******����Ա������ַ����*******
void  InquireBrothadd(BinTree T)
{
	char Birthadd[len];
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵ĳ�����ַ��");
		scanf("%s",Birthadd);
		fflush(stdin);
		i=ValueBrothadd(T,Birthadd);
		if (i==0)
		{
			printf("�����ڷ��ϴ˳�����ַ���ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******����Ա��ͥסַ���Ҹ�������*******
int ValueAddress(BinTree T,char Address[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******����Ա��ͥסַ����*******
void  InquireAddress(BinTree T)
{
	char Address[len];
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵ļ�ͥסַ��");
		scanf("%s",Address);
		fflush(stdin);
		i=ValueAddress(T,Address);
		if (i==0)
		{
			printf("�����ڷ��ϴ˼�ͥסַ���ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******����Աְҵ���Ҹ�������*******
int ValueVocation(BinTree T,char Vocation[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******����Աְҵ����*******
void  InquireVocation(BinTree T)
{
	char Vocation[len];
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵�ְҵ��");
		scanf("%s",Vocation);
		fflush(stdin);
		i=ValueVocation(T,Vocation);
		if (i==0)
		{
			printf("�����ڷ��ϴ�ְҵ���ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�������������Ҹ�������*******
int ValueFather(BinTree T,char Father[len])
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******��������������*******
void  InquireFather(BinTree T)
{
	char Father[len];
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵ĸ���������");
		scanf("%s",Father);
		fflush(stdin);
		i=ValueFather(T,Father);
		if (i==0)
		{
			printf("�����ڸ��������Ǹ����ֵ��ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******�����ֲ��Ҹ�������*******
int ValueDegress(BinTree T,int Degress)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******�����ֲ���*******
void  InquireDegress(BinTree T)
{
	int Degress;
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵ı��֣�");
		scanf("%d",&Degress);
		fflush(stdin);
		i=ValueDegress(T,Degress);
		if (i==0)
		{
			printf("�����ڴ˱��ֵ��ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******����߲��Ҹ�������*******
int ValueHeight(BinTree T,int Height)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******����߲���*******
void  InquireHeight(BinTree T)
{
	int Height;
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵���ߣ�");
		scanf("%d",&Height);
		fflush(stdin);
		i=ValueHeight(T,Height);
		if (i==0)
		{
			printf("�����ڴ���ߵ��ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}	
/////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******��������Ҹ�������*******
int ValueAge(BinTree T,int Age)
{
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                        //����һ���ն���q
		EnQueue(q,T);                        //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                   //��ͷ������
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
//                              *******���������*******
void  InquireAge(BinTree T)
{
	int Age;
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵����䣺");
		scanf("%d",&Age);
		fflush(stdin);
		i=ValueAge(T,Age);
		if (i==0)
		{
			printf("�����ڴ�������ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}	
//////////////////////////////////////////////////////////////////////////
//                          *******ͳ�Ʋ���*******
void MainMenueTongji(BinTree T)
{//�˵�ѡ��
	int c;
	int people=0;                  //�������˿�
	double PHeight=0;              //ƽ�����
	double PAge=0;                 //ƽ������
	int Pfamily=0;                 //ƽ����ͥ�˿�
	int man=0;                     //����
	int woman=0;                   //Ů��
	LinkQueue q;
	QElemType a;
	InitQueue(q);                        //����һ���ն���q
	EnQueue(q,T);                        //�ڶ�β������Ԫ��T
	while(!QueueEmpty(q))
	{
		DeQueue(q,a);                   //��ͷ������
		people++;
		if((strcmp(a->data.Kind,"M"))==0||(strcmp(a->data.Kind,"m"))==0) 
		{
			man++;
		}
		else
			woman++;
		PHeight=PHeight+a->data.Height;    //��������ܺ�
		PAge=PAge+a->data.Age;             //���������ܺ�
		Pfamily=Pfamily+a->data.Num+1;     //�����ͥ�˿��ܺ�
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
		system("cls");//����Ļ
		HANDLE consolehwnd; 
		consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //����������ɫΪ��ɫ
		printf("\t");
		printf("\n\n\t         ---*****---��ѡ����Ĳ���---****---");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);//����������ɫΪ��ɫ
		printf("\n\t----------------------------------------------------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //����������ɫΪ��ɫ		
		printf("\n\t------------------1:ƽ������------------------------------");	
		printf("\n\t------------------2:ƽ�����------------------------------");
		printf("\n\t------------------3:�Ա𱨸�------------------------------");
		printf("\n\t------------------4:ƽ����ͥ�˿�--------------------------");
		printf("\n\t------------------0:�˳�ͳ�Ʋ������������˵�--------------");
		SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);  //����������ɫΪ��ɫ 
		printf("\n\t----------------------------------------------------------\n\t");
		printf("\n\t���������ѡ���0~4��");
		fflush(stdin);
		scanf("%d",&c);
		fflush(stdin);
		switch(c)
		{
		case 1:
			system("cls");//����Ļ
			printf("����ƽ��������%0.1lf",PAge);
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 2:
			system("cls");//����Ļ
			printf("����ƽ�������%0.1lf",PHeight);
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
			
		case 3:
			system("cls");//����Ļ
			printf("����������%d�ˣ�Ů��%d��",man,woman);
			printf("\n\n\t--------------�밴Enter����������--------------");
			fflush(stdin);
			getchar();
			break;
		case 4:
			system("cls");//����Ļ
			printf("�����ƽ����ͥ�˿���Ϊ%d",Pfamily);
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
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******��α������*******
void CengciPut(BinTree T)
{
	LinkQueue Q;
	QElemType a;
	BinTree C;
	int i;
	if (T->data.Num)
	{
		InitQueue(Q); 			             //����һ���ն���Q
		C=T->child;
		EnQueue(Q,C);                        //C������
		for (i=2;i<=T->data.Num;i++)
		{
			C=C->brother;
			EnQueue(Q,C);
		}
		while(!QueueEmpty(Q))
		{
			DeQueue(Q,a);                   //��ͷ������
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
//                              *******��ѯĳһ��Ա������ֱϵ������������*******
int ValueZhixi(BinTree T,char Name[len])
{
	HANDLE consolehwnd; 
	consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
	LinkQueue q;
	QElemType a;
	int i=0;
	if(T)
	{
		InitQueue(q);                                 //����һ���ն���q
		EnQueue(q,T);                                 //�ڶ�β������Ԫ��T
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);                             //��ͷ������
			if((strcmp(a->data.Name,Name))==0)        //������Ҫ��ѯ�˵�����
			{
				printf("������Ϣ:");
				Put(a);			
				if (a->parent!=NULL)
				{
					SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_RED); //����������ɫΪ��ɫ
					if (a->parent->parent!=NULL)
					{					
						printf("\n********************************************************\n");
						printf("�游����Ϣ��\n");
						Put(a->parent->parent);
					}
					else
						printf("\n����û���游");	
					SetConsoleTextAttribute(consolehwnd,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED); //����������ɫΪ��ɫ
					printf("\n********************************************************\n");
					printf("���׵���Ϣ��\n");
					Put(a->parent);
				}
				else
					printf("\n����û���游\n����û�и���");	
				SetConsoleTextAttribute(consolehwnd,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //����������ɫΪ��ɫ
				if (a->data.Num)
				{	
					printf("\n�������Ϣ��");		
					CengciPut(a);
				}
				else
					printf("\n����û����Ů");
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
//                              *******��ѯĳһ��Ա������ֱϵ����*******
void  InquireZhixi(BinTree T)
{
	char Name[len];
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵�������");
		scanf("%s",Name);
		fflush(stdin);
		i=ValueZhixi(T,Name);
		if (i==0)
		{
			printf("�����ڷ��ϴ��������ˣ�\n");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;       //����ѭ��
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			j=0;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//                              *******��ѯĳһ��Ա�����е�ϵ����*******
void InquireRoot(BinTree T)
{
	char name[len];
	BinTree Tree;
	int j=2,i;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵�������");
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n��");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
			
		}
		else
		{
			if (Tree->parent==NULL)
			{
				printf("����û�����ȣ�");
			}
			else
			{
				printf("\n********************************************************\n");
				printf("\n���׵���Ϣ��\n");
				Put(Tree->parent);
				Tree=Tree->parent;
				if (Tree->parent!=NULL)
				{
					printf("\n********************************************************\n");
					printf("\n�游����Ϣ��\n");
					Put(Tree->parent);
					Tree=Tree->parent;
				}
				i=3;
				while(1)
				{
					if (Tree->parent!=NULL)
					{
						printf("\n********************************************************\n");
						printf("\n��%d�����ȵ���Ϣ\n",i);
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
//                              *******��ѯ�����˵Ĺ�ϵ*******
void RelationShip(BinTree T)
{
	char name1[len],name2[len];
	BinTree Tree1,Tree2,p;
	int j=2,i,Deg;
	printf("�������һ���˵�������");
	while(1)
	{
		scanf("%s",name1);
		fflush(stdin);
		Tree1=Value(T,name1);
		if (Tree1==NULL)
		{
			printf("�����ڴ��ˣ�\n�����������һ���˵�������");
		}
		else
			break;
	}	
	printf("������ڶ����˵�������");
	while(1)
	{
		scanf("%s",name2);
		fflush(stdin);
		if((strcmp(name1,name2))==0)
		{
			printf("���һ�˵�������ͬ�����������룺");
			continue;
		}
		Tree2=Value(T,name2);
		if (Tree2==NULL)
		{
			printf("�����ڴ��ˣ�\n����������ڶ����˵�������");	
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
				printf("%s��%s�Ķ���",name1,name2);
			}
			if (Deg==2)
			{
				printf("%s��%s������",name1,name2);
			}
			if (Deg>2)
			{
				printf("%s��%s����%d���ĵ�ϵ��",name1,name2,Deg);
			}
		}
		else
		{
			printf("%s��%s����%d���ķǵ�ϵ��",name1,name2,Deg);
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
				printf("%s��%s�ĸ���",name1,name2);
			}
			if (Deg==2)
			{
				printf("%s��%s���游",name1,name2);
			}
			if (Deg>2)
			{
				printf("%s��%s����%d���ĵ�ϵ����",name1,name2,Deg);
			}
		}
		else
		{
			printf("%s��%s����%d���ķǵ�ϵ����",name1,name2,Deg);
		}
	}
	if (Tree1->data.Degress==Tree2->data.Degress)
	{
		if ((strcmp(Tree1->parent->data.Name,Tree2->parent->data.Name))==0)
		{
			if (Inspect1(Tree1->data.Birthday,Tree2->data.Birthday)==0)     //Tree1��Tree2֮�����
			{
				printf("%s��%s�ĵܵ�",name1,name2);
			}
			else
			printf("%s��%s�ĸ��",name1,name2);
		}
		else
		{
			if (Inspect1(Tree1->data.Birthday,Tree2->data.Birthday)==0)     //Tree1��Tree2֮�����
			{
				printf("%s��%s���õ�",name1,name2);
			}
			else
			printf("%s��%s���ø�",name1,name2);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     ******������������******
int Count_day(BinTree T)
{
	int i,k=0,day=0;
	
	i=T->data.Birthday.year;
	if(i%400==0 || i%4==0 && i%100!=0)                                //����
		k=1;
	switch(T->data.Birthday.month)                                    //�����������һ��
	{
	case 1:
		day=31-T->data.Birthday.day;                                //�����Ǹ��µ�����
		if(k)              //����                                         
			day=day+31+30+31+30+31+31+30+31+30+31+29;                                             
		else               //ƽ��
			day=day+31+30+31+30+31+31+30+31+30+31+28;
		break;
	case 2:
		if(k)      //����
		{
			day=29-T->data.Birthday.day;
			day=day+31+30+31+30+31+31+30+31+30+31;
		}
		else      //ƽ��
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
	if((strcmp(T->data.SW,"Y"))==0||(strcmp(T->data.SW,"y"))==0)               //��ǰû��ȥ��
        for(i=i+1;i<=2012;i++)
		{
			if(i%400==0 || i%4==0 && i%100!=0)                                           //����
				day=day+366;
			else
				day=day+365;                                                               //ƽ��
		}
		else                                                                              //�Ѿ�ȥ����
		{
			for(i=i+1;i<T->data.Dieday.year;i++)
			{
				if(i%400==0 || i%4==0 && i%100!=0)
					day=day+366;
				else
					day=day+365;
			}
			
			i=i+1;                                                                         //���������
			if(i%400==0 || i%4==0 && i%100!=0)          //����k=1
				k=1;
			else                                        //ƽ��
				k=0;
			switch(T->data.Dieday.month)                                                    //�����������������
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
//                                 ******��������*******
void Inquireday(BinTree T)
{
	char name[len];
	BinTree Tree;
	int i,j=2;
	while(j)
	{
		printf("��������Ҫ��ѯ�˵�������");
		scanf("%s",name);
		fflush(stdin);
		Tree=Value(T,name);
		if (Tree==NULL)
		{
			printf("�����ڴ��ˣ�\n��");
			printf("�Ƿ���Ҫ���²�ѯ��1����Ҫ��0������Ҫ����");
			while(1)
			{
				scanf("%d",&j);
				fflush(stdin);
				if (j==0||j==1)
				{
					break;
				}
				else
					printf("�����������������:");
			}
		}
		else
		{
			i=Count_day(Tree);
			printf("\n���˴��������%d��",i);
			break;
		}
	}
}