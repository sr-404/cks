#include <allfunc.h>

//新用户注册
void rigister_login(int *func)
{
	struct USER temp={0};//存储信息的用户结构体 
	char judge[10]="\0";//用于判断的密码 

    mouse_off(&mouse);
    bar1(364,300,992,445,0xFFFFFF);
    bar1(460,400,930,700,0xFFFFFF); 
    bar1(389,706,1020,750,0xFFFFFF);
    bar1(433,142,1000,190,0xFFFFBB);
    bar1(443,274,970,306,0xffffff);
    bar1(467,678,961,741,0xffffff);
    puthz(497,140,"注册", 48,50, 0x000000);
	puthz(600,140,"武汉欢乐谷", 48,50, 0x00FF);
    draw_commoninput(495,330,"请设定您的账户名"); 
    draw_commoninput(495,390,"请设定您的密码"); 
    draw_commoninput(495,450,"请确认您的密码"); 
    draw_confirmbotton(573,512,"返回登录");
    draw_confirmbotton(573,612,"立即注册");
    prt_hz16_size(485,695, 2, 2, "已阅读并同意", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(670,695, 2, 2, "《欢乐谷隐私政策》", 0x00FF, "HZK\\HZK16s");
    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        
        if(mouse_press(498,287,870,326)==1)   //输入账号
		{
			mouse_off(&mouse);
			bar1(498,282,870,326,0xffff);
			strcpy(temp.name,"\0");
			Getinfo(498,287,temp.name,10,498,287,870,326);
			mouse_on(mouse);
		}
		else if(mouse_press(498,347,870,386)==1)    //输入密码
		{
			mouse_off(&mouse);
			bar1(498,342,870,386,0xffff);
			strcpy(temp.code,"\0");
			Getcode(498,347,temp.code,10,498,347,870,386);
			mouse_on(mouse);
		}
		else if(mouse_press(498,407,870,446)==1)     //重新输入密码
		{
			mouse_off(&mouse);
			bar1(498,402,870,446,0xffff);
			strcpy(judge,"\0");
			Getcode(498,407,judge,10,498,407,870,446);
			mouse_on(mouse);
		}
		if(mouse_press(545,610,835,670)==1)     //点击确认键
		{
			if(strcmp(temp.name,"\0")!=0)//用户名不为空 
			{
				if(strcmp(temp.code,"\0")!=0)//密码不为空 
				{
					if(!strcmp(temp.code,judge))//两次密码相同 
			        {
				      if(save_user(temp)==0)
                      {
                        *func=2;
				        break;
                      }
                      else
                      {
                        prt_hz24(570,575,"用户名已被注册！",10,"HZK\\Hzk24h");
                        delay(1500);
				        bar1(570,575,800,600,0xffff);
                      }
			        }
			        else
			        {
				      prt_hz24(570,575,"两次密码不相同！",0,"HZK\\Hzk24h");
				      delay(1500);
				      bar1(570,575,800,600,0xffff);
			        }  
				}
				else
				{
					prt_hz24(570,575,"密码为空！",0,"HZK\\Hzk24h");
				    delay(1500);
				    bar1(570,575,800,600,0xffff);
				}	
			}
			else
			{
				prt_hz24(570,575,"用户名为空！",0,"HZK\\Hzk24h");
				delay(1500);
				bar1(570,575,800,600,0xffff);
			}	
		}
		if(mouse_press(545,510,835,570)==1)
		{
			*func=0;
			break;
		}
    }
}

//画出普通输入栏
void draw_commoninput(int x1,int y1,char *s)
{
	Line_Thick(x1, y1, x1 + 380, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 16, y1 - 46, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//画出确认按钮
void draw_confirmbotton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+236, y1+55, 0xFFFFFF, 0x00FF);
	puthz(x1+12,y1+4,s, 48,55, 0x000000);
}



//用户使用账号登录
void user_login(int *func,int *unum)
{
    char name[10]="\0";
	char code[10]="\0";
    int i=-5;

    UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);

    mouse_off(&mouse);

    bar1(364,300,992,445,0xFFFFFF);
    bar1(460,400,930,700,0xFFFFFF); 
    bar1(389,706,1020,750,0xFFFFFF);
    bar1(433,142,1000,190,0xFFFFBB);
    bar1(443,274,970,306,0xffffff);
    bar1(467,678,961,741,0xffffff);
    puthz(497,140,"登录", 48,50, 0x000000);
	puthz(600,140,"武汉欢乐谷", 48,50, 0x00FF);

    puthz(365,300,"返回上级", 32,34, 0xBD32);
	Line_Thick(510, 290, 510,345,1,0xBD32 );
	puthz(525,300,"账号登录", 32,34, 0x000000); 

    //画出账户名输入栏
    draw_commoninput(495,448,"请输入您的账号"); 
    //画出密码输入栏
    draw_commoninput(495,522,"请输入您的密码"); 

	puthz(480,535,"注册", 24,24, 0x000000);

    //画出确认按钮
    draw_confirmbotton(573,612,"立即登录");
    prt_hz16_size(485,695, 2, 2, "已阅读并同意", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(670,695, 2, 2, "《欢乐谷隐私政策》", 0x00FF, "HZK\\HZK16s");


    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        if(mouse_press(495,400,870,445)==1)//点击账号框 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(495,400,870,445,0xffff);
			Getinfo(497,398,name,10,495,400,870,445);//得到账号 
			mouse_on(mouse);
		}
        else if(mouse_press(495,475,870,520)==1)//点击密码框 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(495,475,870,520,0xffff);
			Getcode(497,473,code,10,495,475,870,520);//得到密码 
			mouse_on(mouse);
		}
        else if(mouse_press(573,612,809,667)==1)//点击登录
        {
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				*unum=i;
				DestroyUList(&UL);
				*func=5;      //进入主界面
                break;
			}
			if(i==-2)//密码输入错误 
			{
				prt_hz24(570,550,"密码错误！",0,"HZK\\Hzk24h");
			    delay(1500);
				bar1(570,550,690,574,0xffff);
			}
			if(i==-3)//用户不存在 
			{
				prt_hz24(570,550,"用户不存在！",0,"HZK\\Hzk24h");
			    delay(1500);
				bar1(570,550,570+144,574,0xffff);
			} 
        }
        else if(mouse_press(365,300,510,335)==1)
        {
            *func=0;
            break;
        }
        else if(mouse_press(480,533,526,558)==1)
        {
            *func=3;
            break;
        }
    }

}









