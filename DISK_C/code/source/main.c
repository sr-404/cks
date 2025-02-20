
#include "allfunc.h"

void main()
{
	int k = 0,n=0;
    int gd=VGA,gm=VGAHI;
	initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
	//SetSVGA64k();//启动SVGA画图界面
/*	puthz(200,200,"你好",24,24,WHITE);
	setcolor(1);
	circle(320,220,50);
	setfillstyle(1,YELLOW);
	floodfill(320,220,BLUE);
	bar(100,20,200,50);
	puthz(130,22,"登录",24,24,RED);
		
		
 
	
	while (1) 
	{
        newmouse(&MouseX, &MouseY, &press);  // ???????????
        if (MouseX >= 100 && MouseX <= 200 && MouseY >= 20 && MouseY <= 50) 
		{
            if (!k) 
			{  // ?????????
                k = 1;  // ???????
				bar(100,20,200,50);
                setfillstyle(1,GREEN );  // ?????????
                floodfill(100, 30, BLACK);  // ????
				puthz(130,22,"登录",24,24,WHITE);
				MouseS=1;	
            }
        } 
		if (MouseX < 100 || MouseX > 200 || MouseY < 20 || MouseY > 50)  
			{
            	if (k) 
					{  // ???????????????
                		k = 0;  // ???????
                		bar(100,20,200,50);
                		setfillstyle(1, YELLOW);  // ???????
                		floodfill(100, 30, BLACK);  // ????
						puthz(130,22,"登录",24,24,RED);
                		MouseS=0;	
            		}
        	}
        if(mouse_press(100,20,200,50)==1)
        {
        	clrmous(MouseX,MouseY);
        	break;
		}
}*/
	welcome();
	/*clrmous(MouseX,MouseY);
    delay(100);
    save_bk_mou(MouseX,MouseY);
	MouseS=0;*/
	
	cleardevice();
	setbkcolor(BLUE);
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		bar(200,200,450,220);
		setfillstyle(1, WHITE);  // ???????
        floodfill(250, 210, BLACK);  // ????
		bar(200,240,450,260);
		setfillstyle(1, WHITE);  // ???????
        floodfill(250, 250, BLACK);  // ????
		puthz(120,200,"用户名",24,24,RED);
		puthz(125,240,"密码",24,24,RED);
		if (MouseX >= 200 && MouseX <= 450 && MouseY >= 200 && MouseY <= 220)
		{  
			MouseS=2;
        } 
		else
		{  
			MouseS=0;		
        }
		
	
		if(mouse_press(200,200,450,220)==1)
        {
			break;
		}
	}

	delay(10000);
	//CloseSVGA();//关闭图形界面 

}





