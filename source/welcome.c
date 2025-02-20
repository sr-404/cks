#include "allfunc.h"

void welcome(int* func)
{
    mouse_off(&mouse);
	delay(100);


    draw_basic_logging();//画登录、注册界面必备基本元素
    draw_welcome();//画欢迎界面的特有元素

    mouse_on(mouse);

    //GenerateBMP(0,0,1024,768);

    while(1)
    {
        mouse_show(&mouse);

        if(mouse_press(535,395,855,485)==1)//点击进入登录选项页func=2
        {
            *func=2;
            break;
        }

        else if(mouse_press(535,540,855,630)==1)
        {
            *func=3;
            break;
        }
        delay(15);
    }
}


//画登录、注册界面必备基本元素
void draw_basic_logging()
{
    bar1(0,0,1024,768,0xFFFFBB);
	//上层圈圈
	Circlefill(480,60,40,0x00FF00);
	Circlefill(655,40,45,0xFFAAAA);
	Circlefill(380,240,60,0xBDBD00);
	Circlefill(575,105,35,0x00BD2E);
    Circlefill(391,310,40,0xAAAA);
	Circlefill(391,310,38,0xFFFFFF);
	Circlefill(982,310,40,0xAAAA);
	Circlefill(982,310,38,0xFFFFFF);
	bar1(390,270,980,768,0xFFFFFF);
	bar1(352,310,1022,768,0xFFFFFF);	
	Line_Thick(391, 270, 982,270,1,0xAAAA );
	Line_Thick(351, 310, 351,768,1,0xAAAA );
	Line_Thick(170, 760, 460,450,9,0xBDBD );
	Line_Thick(230, 760, 460,520,9,0xBDBD );
	Line_Thick(290, 760, 460,590,9,0xBDBD );
	bar1(451,363,497,666,0xFFFFFF);
	bar1(387,546,413,622,0xFFFFFF);
	Line_Thick(351, 310, 351,768,1,0xAAAA );
    puthz(425,230,"官方预定丨景点速览丨出行规划丨服务保障", 32,27, 0x000000);
	Readbmp64k(0,0,"bmp\\wel.bmp"); 
}


void draw_welcome()
{
    //标题
	puthz(460,140,"欢迎来到", 48,50, 0x000000);
	puthz(666,140,"武汉欢乐谷", 48,50, 0x00FF);

	//选项框
    draw_botton(535,393,855,487,0x00FF,0xDDDD);//登录矩形框
    draw_botton(535,538,855,632,0x00FF,0xDDDD);//注册矩形框

	//写字
	prt_hz16_size(650,420, 3, 3, "登录", 0xFFFFFF, "HZK\\HZK16s");
	prt_hz16_size(650,565, 3, 3, "注册", 0xFFFFFF, "HZK\\HZK16s");
    //prt_hz16_size(485,695, 1, 1, "管理人员登录", 0x00FF, "HZK\\HZK16s");


}

void draw_botton(int x1 ,int y1,int x2,int y2,int Cowercolor,int Bordercolor)
{
	Cirbar(x1,y1,x2,y2, Bordercolor);
	Cirbar(x1,y1+2,x2,y2-2, Cowercolor);
}