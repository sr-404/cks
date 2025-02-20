#include <allfunc.h>
#include "lgfunc.h"


/**********************
功能说明：登录信息对比校验函数 
参数说明：用户线性表，用户名，密码 
返回值说明:i：用户在线性表中的位置   -2： 密码错误   -3：用户不存在 
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
功能说明：保存用户信息函数 
参数说明：用户结构体 
返回值说明:0：保存成功   -1： 保存失败 
**********************/
int save_user(USER temp)
{
	UserList UL={0};
	FILE *fp=NULL;
	ReadAllUser(&UL);
	if((fp=fopen("userinfo.dat","rb+"))==NULL)		//首次使用时应创建文件
	{
		prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	if(Check_info(UL,temp.name,temp.code)==-3)			//用户不存在 
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
功能说明：获取文件中的所有用户
参数说明：用户线性表地址 
返回值：无 
*******************/
void ReadAllUser(UserList *UL)
{
	int length=0;//接收线性表长度 
	int listsize=U_LIST_INIT_SIZE;//线性表初始长度 
	FILE *fp=NULL;
	if((fp=fopen("userinfo.dat","rb+"))==NULL)			//检测文件打开是否正常
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
	   if((UL->elem = (USER*)malloc(listsize* sizeof(USER)))==NULL)//构建用户线性表 
	   {
		 CloseSVGA();
		 printf("No enough memory!\n");
		 getch();
		 exit(-1);
	   } 
	  fread(UL->elem, sizeof(USER),length, fp);//读取文件的所有用户到线性表中 
    }
	fclose(fp);
}


/*******************
功能说明：更新用户信息 
参数说明：用户结构体 
返回值：无 
*******************/

void UpdataUser(USER user)
{
	int usernum=0;//用户位置 
	UserList UL={0};//用户线性表 
	FILE *fp=NULL;
	ReadAllUser(&UL);//获取所有用户到线性表 
	if((fp=fopen("userinfo.dat","rb+"))==NULL)
	{
		prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	usernum=Userposition(UL,user);//得到用户在线性表中的位置 
	UL.elem[usernum]=user;//更新线性表中用户信息 
	fseek(fp,0,SEEK_SET);
	fwrite(&UL.length, sizeof(int), 1, fp);
	fwrite(&UL.listsize, sizeof(int), 1, fp);
	fwrite(UL.elem, sizeof(USER), UL.length, fp);
	fclose(fp);
	DestroyUList(&UL);//销毁线性表 
}

/****************************
功能说明：建立一个线性表 
参数说明：线性表地址
返回值：  无  
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
功能说明：在线性表L末尾插入元素 
参数说明：线性表地址，要插入的元素
返回值：  无  
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
功能说明：在线性表L中删除第i个元素，并用e返回其值
参数说明：线性表地址，要删除的元素位置，接收删除元素的存储空间地址
返回值：无 
****************************/
void UListDelete(UserList*L,int i)
{
	USER*p=NULL;
	USER*q=NULL;
	if((i<0)||(i>=L->length)) //i的位置不合法 
	{
		CloseSVGA();
		printf("ListDelete Wrong!");
		getch();
		exit(1);
	}
	p=L->elem+i;  //p为被删除元素位置
	//*e=*p;  //把被删除元素的值赋给e
	q=L->elem+L->length-1;  //表尾元素的位置
	for(p++;p<=q;p++)  //被删除元素之后的元素左移
		*(p-1)=*p;
	L->length--;  //表长减一
	
}


/****************************
功能说明：销毁线性表L
参数说明：线性表地址
返回值：无 
****************************/
void DestroyUList(UserList*UL)	
{
	free(UL->elem);
	UL->listsize=0;
	UL->length=0;
}


/****************************
功能说明：得到元素E在线性表中的位置
参数说明：线性表，元素e 
返回值：  无 
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






/***画光标函数***/
void show_gb(int x,int y)
{
	Line1(x,y,x,y+16,0);
}

/***信息输入时所做的相同操作***/
void Getinfo(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1)
{
	char showtemp[2]= {0,0};
	int key;    			//按键值
	int i=0,k,temp;
	int border=x1+4;	    //border表示显示图片的左边界
	x1=x1+4;
	y1=y1+5;
	for(i=strlen(name)-1;i>=0;i--)
	{
		*showtemp=name[i];
		prt_asc16_ch(x1+i*8,y1-2,showtemp[0],0);
	}
	i=strlen(name);
	while(bioskey(1))					//清空输入缓冲区
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//当按下回车键时表示输入完毕（回车键值为13）
    {
	    show_gb(border,y1);//光标闪烁 
		if(bioskey(1)==0||!MouseGet(&mouse))			//延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for(k=0;k<100;k++)				//延时的同时检测鼠标键盘
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
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if(('0'<=temp&&temp<='9'||('a'<=temp&&temp<='z')/*||temp=='_'*/)&&i<num)	//检测为数字或字母或下划线，则记录
				{
					bar1(border,y1,border+8, y1+16, 0xffff);
					name[i]=temp;				//字符送入给定字符串			
					*showtemp=temp;
					prt_asc16(border,y1-2,showtemp,0); //显示新的字符串达到画面与实际输入的同步
					i++;
					name[i]='\0';		//标记字符串结尾
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//由于文件名不区分大小写，而后面的文件部分要用用户名做文件名 
				{						             	//故在注册时就不区分大小写了 
					bar1(border,y1,border+8, y1+16, 0xffff);
					temp+=32;
					name[i]=temp;				//字符送入给定字符串			
					*showtemp=temp;             //显示新的字符串达到画面与实际输入的同步
					prt_asc16(border,y1-2,showtemp,0);
					i++;
					name[i]='\0';		//标记字符串结尾
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//检测是否为退格键，是则消除前一个字符
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
		if(!mouse_press(a1,b1,c1,d1)&&MouseGet(&mouse))		//如果鼠标点击输入框外的部分，退出
		{
			break;
		}
		bar1(border,y1,border+8, y1+16, 0xffff);
		if(bioskey(1)==0||!MouseGet(&mouse))			//延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for(k=0;k<100;k++)				//延时的同时检测鼠标键盘
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

/***密码输入时所做的相同操作***/
void Getcode(int x1,int y1,char *code,int num,int a1,int b1,int c1,int d1)
{
	char showtemp[2]= {0,0};
	int key;    			//按键值
	int i=0,k,temp;
	int border=x1+4;	    //border表示显示图片的左边界
	x1=x1+4;
	y1=y1+5;
	for(i=strlen(code)-1;i>=0;i--)
	{
		*showtemp=code[i];
		prt_asc16_ch(x1+i*8,y1-2,'*',0);
	}
	i=strlen(code);
	while(bioskey(1))					//清空输入缓冲区
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//当按下回车键时表示输入完毕（回车键值为13）
   {
	   show_gb(border,y1);
		if(bioskey(1)==0||!MouseGet(&mouse))			//延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for(k=0;k<100;k++)				//延时的同时检测鼠标键盘
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
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if(('0'<=temp&&temp<='9'||'a'<=temp&&temp<='z'||temp=='_')&&i<num)	//检测为数字或字母或下划线，则记录
				{
					bar1(border,y1,border+8, y1+16, 0xffff);
					code[i]=temp;				//字符送入给定字符串			
					*showtemp=temp;
					prt_asc16(border,y1-2,showtemp,0); //显示新的字符串达到画面与实际输入的同步
					delay(150);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"_",0);
					delay(50);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"*",0);
					i++;
					code[i]=0;		//标记字符串结尾
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//由于文件名不区分大小写，而后面的文件部分要用用户名做文件名 
				{							//故在注册时就不区分大小写了 
					bar1(border,y1,border+8, y1+16, 0xffff);
					temp+=32;
					code[i]=temp;				//字符送入给定字符串			
					*showtemp=temp;       //显示新的字符串达到画面与实际输入的同步
					prt_asc16(border,y1-2,showtemp,0);
					delay(300);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"_",0);
					delay(100);
					bar1(border,y1,border+8, y1+16, 0xffff);
					prt_asc16(border,y1-2,"*",0);
					i++;
					code[i]=0;		//标记字符串结尾
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//检测是否为退格键，是则消除前一个字符
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
		if(!mouse_press(a1,b1,c1,d1)&&MouseGet(&mouse))		//如果鼠标点击输入框外的部分，退出
		{
			break;
		}
		bar1(border,y1,border+8, y1+16, 0xffff);
		if(bioskey(1)==0||!MouseGet(&mouse))			//延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for(k=0;k<100;k++)				//延时的同时检测鼠标键盘
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