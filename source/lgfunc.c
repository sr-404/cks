#include <allfunc.h>
#include "lgfunc.h"


/**********************
����˵������¼��Ϣ�Ա�У�麯�� 
����˵�����û����Ա��û��������� 
����ֵ˵��:i���û������Ա��е�λ��   -2�� �������   -3���û������� 
**********************/
int Check_info(UserList UL,char name[10],char code[10])
{
	int i=0;
	for(i=0;i<UL.length;i++)
	{
		if(strcmp(UL.elem[i].name,name)==0)
		{
			if(strcmp(UL.elem[i].code,code)==0)
			{
				return i;
			}
			else
			{
				return -2;
			}
		}
	}
	return -3;
}

/**********************
����˵���������û���Ϣ���� 
����˵�����û��ṹ�� 
����ֵ˵��:0������ɹ�   -1�� ����ʧ�� 
**********************/
int save_user(USER temp)
{
	UserList UL={0};
	FILE *fp=NULL;
	ReadAllUser(&UL);
	if((fp=fopen("userinfo.dat","rb+"))==NULL)		//�״�ʹ��ʱӦ�����ļ�
	{
		prt_hz24(400,400,"�޷����ļ���",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	if(Check_info(UL,temp.name,temp.code)==-3)			//�û������� 
	{
	    UListInsert(&UL,temp);
	    fseek(fp,0,SEEK_SET);
	    rewind(fp);
	    fwrite(&UL.length, sizeof(int), 1, fp);
	    fwrite(&UL.listsize, sizeof(int), 1, fp);
	    fwrite(UL.elem, sizeof(USER), UL.length, fp);
	    fclose(fp);
		DestroyUList(&UL);
		delay(500);
		return 0;
	}
	else
	{
		DestroyUList(&UL);
		delay(500);		
		fclose(fp);
		return -1;
	}
}


/*******************
����˵������ȡ�ļ��е������û�
����˵�����û����Ա��ַ 
����ֵ���� 
*******************/
void ReadAllUser(UserList *UL)
{
	int length=0;//�������Ա��� 
	int listsize=U_LIST_INIT_SIZE;//���Ա��ʼ���� 
	FILE *fp=NULL;
	if((fp=fopen("userinfo.dat","rb+"))==NULL)			//����ļ����Ƿ�����
	{
		fp=fopen("userinfo.dat","wb");
		rewind(fp);
		fwrite(&length, sizeof(int), 1, fp);
		fwrite(&listsize, sizeof(int), 1, fp);
	}								
    else
    {
       fseek(fp,0,SEEK_SET);
	   fread(&length, sizeof(int), 1, fp);
	   fread(&listsize, sizeof(int), 1, fp);
	   UL->length = length;
	   UL->listsize = listsize;
	   if((UL->elem = (USER*)malloc(listsize* sizeof(USER)))==NULL)//�����û����Ա� 
	   {
		 CloseSVGA();
		 printf("No enough memory!\n");
		 getch();
		 exit(-1);
	   } 
	  fread(UL->elem, sizeof(USER),length, fp);//��ȡ�ļ��������û������Ա��� 
    }
	fclose(fp);
}


/*******************
����˵���������û���Ϣ 
����˵�����û��ṹ�� 
����ֵ���� 
*******************/

void UpdataUser(USER user)
{
	int usernum=0;//�û�λ�� 
	UserList UL={0};//�û����Ա� 
	FILE *fp=NULL;
	ReadAllUser(&UL);//��ȡ�����û������Ա� 
	if((fp=fopen("userinfo.dat","rb+"))==NULL)
	{
		prt_hz24(400,400,"�޷����ļ���",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	usernum=Userposition(UL,user);//�õ��û������Ա��е�λ�� 
	UL.elem[usernum]=user;//�������Ա����û���Ϣ 
	fseek(fp,0,SEEK_SET);
	fwrite(&UL.length, sizeof(int), 1, fp);
	fwrite(&UL.listsize, sizeof(int), 1, fp);
	fwrite(UL.elem, sizeof(USER), UL.length, fp);
	fclose(fp);
	DestroyUList(&UL);//�������Ա� 
}

/****************************
����˵��������һ�����Ա� 
����˵�������Ա��ַ
����ֵ��  ��  
****************************/
void InitUList(UserList*UL)  
{
	if((UL->elem=(USER*)malloc(U_LIST_INIT_SIZE*sizeof(USER)))==NULL)
	{
		CloseSVGA();
		printf("No enough memory!\n");
		exit(-1);
	}
	UL->length=0;
	UL->listsize=U_LIST_INIT_SIZE;
}


/****************************
����˵���������Ա�Lĩβ����Ԫ�� 
����˵�������Ա��ַ��Ҫ�����Ԫ��
����ֵ��  ��  
****************************/
void UListInsert(UserList*UL,USER e) 
{
	USER*newbase=NULL;
	if(UL->length>=UL->listsize)
	{
		if((newbase=(USER*)realloc(UL->elem,(UL->listsize+U_LISTINCEREMENT)*sizeof(USER)))==NULL)
	    {
		CloseSVGA();
		printf("No enough memory!\n");
		exit(-1);
	    }
		UL->elem=newbase;
		UL->listsize+=U_LISTINCEREMENT;
	}
	*(UL->elem+(UL->length))=e;
	UL->length++;
}



/****************************
����˵���������Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
����˵�������Ա��ַ��Ҫɾ����Ԫ��λ�ã�����ɾ��Ԫ�صĴ洢�ռ��ַ
����ֵ���� 
****************************/
void UListDelete(UserList*L,int i)
{
	USER*p=NULL;
	USER*q=NULL;
	if((i<0)||(i>=L->length)) //i��λ�ò��Ϸ� 
	{
		CloseSVGA();
		printf("ListDelete Wrong!");
		getch();
		exit(1);
	}
	p=L->elem+i;  //pΪ��ɾ��Ԫ��λ��
	//*e=*p;  //�ѱ�ɾ��Ԫ�ص�ֵ����e
	q=L->elem+L->length-1;  //��βԪ�ص�λ��
	for(p++;p<=q;p++)  //��ɾ��Ԫ��֮���Ԫ������
		*(p-1)=*p;
	L->length--;  //����һ
	
}


/****************************
����˵�����������Ա�L
����˵�������Ա��ַ
����ֵ���� 
****************************/
void DestroyUList(UserList*UL)	
{
	free(UL->elem);
	UL->listsize=0;
	UL->length=0;
}


/****************************
����˵�����õ�Ԫ��E�����Ա��е�λ��
����˵�������Ա�Ԫ��e 
����ֵ��  �� 
****************************/
int Userposition(UserList UL,USER e)
{
	int i=-1;
	for(i=0;i<UL.length;i++)
	{
		if(strcmp(e.name,UL.elem[i].name)==0)
		{
			return i;
		}	
	}
	return -1;
}






/***����꺯��***/
void show_gb(int x,int y)
{
	Line1(x,y,x,y+16,0);
}

/***��Ϣ����ʱ��������ͬ����***/
void Getinfo(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1)
{
	char showtemp[2]= {0,0};
	int key;    			//����ֵ
	int i=0,k,temp;
	int border=x1+4;	    //border��ʾ��ʾͼƬ����߽�
	x1=x1+4;
	y1=y1+5;
	for(i=strlen(name)-1;i>=0;i--)
	{
		*showtemp=name[i];
		prt_asc16_ch(x1+i*8,y1-2,showtemp[0],0);
	}
	i=strlen(name);
	while(bioskey(1))					//������뻺����
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//�����»س���ʱ��ʾ������ϣ��س���ֵΪ13��
    {
	    show_gb(border,y1);//�����˸ 
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
		if(bioskey(1))
		{
			temp=bioskey(0)&0x00ff;
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				if(('0'<=temp&&temp<='9'||('a'<=temp&&temp<='z')/*||temp=='_'*/)&&i<num)	//���Ϊ���ֻ���ĸ���»��ߣ����¼
				{
					bar1(border,y1,border+8, y1+16, 0xffff);
					name[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;
					prt_asc16(border,y1-2,showtemp,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;
					name[i]='\0';		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//�����ļ��������ִ�Сд����������ļ�����Ҫ���û������ļ��� 
				{						             	//����ע��ʱ�Ͳ����ִ�Сд�� 
					bar1(border,y1,border+8, y1+16, 0xffff);
					temp+=32;
					name[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;             //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					prt_asc16(border,y1-2,showtemp,0);
					i++;
					name[i]='\0';		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					border-=8;
					bar1(border,y1,border+8, y1+16, 0xffff);
					i--;
					name[i]='\0';
					bar1(border,y1,border+8, y1+16, 0xffff);
					show_gb(border,y1);
				}
			}
			else
			{
				break;
			}
		}
		if(!mouse_press(a1,b1,c1,d1)&&MouseGet(&mouse))		//���������������Ĳ��֣��˳�
		{
			break;
		}
		bar1(border,y1,border+8, y1+16, 0xffff);
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
	}
	bar1(border,y1,border+8, y1+16, 0xffff);
}

/***��������ʱ��������ͬ����***/
void Getcode(int x1,int y1,char *code,int num,int a1,int b1,int c1,int d1)
{
	char showtemp[2]= {0,0};
	int key;    			//����ֵ
	int i=0,k,temp;
	int border=x1+4;	    //border��ʾ��ʾͼƬ����߽�
	x1=x1+4;
	y1=y1+5;
	for(i=strlen(code)-1;i>=0;i--)
	{
		*showtemp=code[i];
		prt_asc16_ch(x1+i*8,y1-2,'*',0);
	}
	i=strlen(code);
	while(bioskey(1))					//������뻺����
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//�����»س���ʱ��ʾ������ϣ��س���ֵΪ13��
   {
	   show_gb(border,y1);
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
		if(bioskey(1))
		{
			temp=bioskey(0)&0x00ff;
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				if(('0'<=temp&&temp<='9'||'a'<=temp&&temp<='z'||temp=='_')&&i<num)	//���Ϊ���ֻ���ĸ���»��ߣ����¼
				{
					bar1(border,y1,border+8, y1+16, 0xffff);
					code[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;
					prt_asc16(border,y1-2,showtemp,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					delay(150);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"_",0);
					delay(50);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"*",0);
					i++;
					code[i]=0;		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//�����ļ��������ִ�Сд����������ļ�����Ҫ���û������ļ��� 
				{							//����ע��ʱ�Ͳ����ִ�Сд�� 
					bar1(border,y1,border+8, y1+16, 0xffff);
					temp+=32;
					code[i]=temp;				//�ַ���������ַ���			
					*showtemp=temp;       //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					prt_asc16(border,y1-2,showtemp,0);
					delay(300);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"_",0);
					delay(100);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"*",0);
					i++;
					code[i]=0;		//����ַ�����β
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					border-=8;
					bar1(border,y1,border+8, y1+16, 0xffff);
					i--;
					code[i]=0;
					bar1(border,y1,border+8, y1+16, 0xffff);
					show_gb(border,y1);
				}
			}
			else
			{
				break;
			}
		}
		if(!mouse_press(a1,b1,c1,d1)&&MouseGet(&mouse))		//���������������Ĳ��֣��˳�
		{
			break;
		}
		bar1(border,y1,border+8, y1+16, 0xffff);
		if(bioskey(1)==0||!MouseGet(&mouse))			//��ʱ������ʹ�����˸���ڵ������������ʱ�˳�
		{
			for(k=0;k<100;k++)				//��ʱ��ͬʱ���������
			{
				delay(2);
				if(bioskey(1)||MouseGet(&mouse))
				{
					break;
				}
			}
		}
	}
	bar1(border,y1,border+8, y1+16, 0xffff);
}