#include "allfunc.h"
void draw_button(int x1, int y1, int x2, int y2, int active, int color, const char* text1, const char* text2) {
    if (active) {
        setcolor(YELLOW);
        setfillstyle(1, YELLOW);
        bar(x1, y1, x2, y2);
        puthz(x1 + 10, y1 + 10, text1, 24, 24, RED);
        puthz(x1 + 40, y1 + 10, text2, 24, 24, RED);
    } else {
        setcolor(GREEN);
        setfillstyle(1, GREEN);
        bar(x1, y1, x2, y2);
        puthz(x1 + 10, y1 + 10, text1, 24, 24, WHITE);
        puthz(x1 + 40, y1 + 10, text2, 24, 24, WHITE);
    }
}
void drawlogin()
{
	int p=0,m=0; 
	setbkcolor(BLUE);
	puthz(64,100,"立体仓库机器人搬运系统",48,48,WHITE);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	bar(150,320,230,360);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	bar(400,320,480,360);
	puthz(160,330,"登",24,24,WHITE);
	puthz(190,330,"陆",24,24,WHITE);
	puthz(410,330,"注",24,24,WHITE);
	puthz(440,330,"册",24,24,WHITE);
	/*while(1)
	{
		
		newmouse(&MouseX, &MouseY, &press); 
			if ((mouse_press(150,320,230,360)==2 )) 
			{
				if(!p)
				{
				
				p=1; 
				setcolor(YELLOW);
				
                setfillstyle(1,YELLOW );  // ?????????
                bar(150,320,230,360);
                puthz(160,330,"登",24,24,RED);
				puthz(190,330,"陆",24,24,RED);
				MouseS=1;
			}
			}
     else
		//if ((MouseX < 150 || MouseX > 230 || MouseY < 320 || MouseY > 360) && p==1&&(MouseX < 400 || MouseX > 480 || MouseY < 320 || MouseY > 360)) 
		
			{
						if(p)
		{
				p=0;
				setcolor(GREEN);
                	
                		setfillstyle(1,GREEN );  // ?????????
                	bar(400,320,480,360);
                puthz(160,330,"登",24,24,WHITE);
				puthz(190,330,"陆",24,24,WHITE);
						MouseS=0;
					}
            }
		if ((mouse_press(400,320,480,360)==2 )) 
			{
				if(!m)
				{

				m=1; 
				setcolor(YELLOW);
				
                setfillstyle(1,YELLOW );  // ?????????

                bar(400,320,480,360);
                puthz(410,330,"注",24,24,RED);
				puthz(440,330,"册",24,24,RED);
				MouseS=1;
			}
			
			}
     else
		//if ((MouseX < 400 || MouseX > 480 || MouseY < 320 || MouseY > 360) && m==1&&(MouseX < 150 || MouseX > 230 || MouseY < 320 || MouseY > 360)) 
			{
				if(m)
				{
				m=0;
				setcolor(GREEN);
                	
                		setfillstyle(1,GREEN );  // ?????????

                bar(400,320,480,360);
                puthz(410,330,"注",24,24,WHITE);
				puthz(440,330,"册",24,24,WHITE);
						MouseS=0;
					}
            }
            
		if((mouse_press(400,320,480,360)==1)||(mouse_press(150,320,230,360)==1 ))
        {
        	break;
		}
	}*/
	while (1) {
    newmouse(&MouseX, &MouseY, &press);

    // 登录按钮逻辑
    if (mouse_press(150, 320, 230, 360) == 2) {
        if (!p) {
            p = 1;
            draw_button(150, 320, 230, 360, 1, YELLOW, "登", "陆");
        }
    } else {
        if (p) {
            p = 0;
            draw_button(150, 320, 230, 360, 0, GREEN, "登", "陆");
        }
    }

    // 注册按钮逻辑
    if (mouse_press(400, 320, 480, 360) == 2) {
        if (!m) {
            m = 1;
            draw_button(400, 320, 480, 360, 1, YELLOW, "注", "册");
        }
    } else {
        if (m) {
            m = 0;
            draw_button(400, 320, 480, 360, 0, GREEN, "注", "册");
        }
    }

    // 退出条件
    if ((mouse_press(400, 320, 480, 360) == 1) || (mouse_press(150, 320, 230, 360) == 1)) {
        break;
    }
}
			
}

void welcome()
{
	int n=0; 
	puthz(64,100,"立体仓库机器人搬运系统",48,48,WHITE);
	delay(1000);
	puthz(100,200,"等待中",24,24,WHITE);
	delay(1000);
	/*setcolor(YELLOW);
	circle(120,350,30);
	setfillstyle(1,YELLOW);
	floodfill(120,420,BLUE);
	delay(1000);
	setcolor(YELLOW);
	circle(270,350,30);
	setfillstyle(1,YELLOW);
	floodfill(120,420,BLUE);
	delay(1000);
	setcolor(YELLOW);
	circle(320,350,30);
	setfillstyle(1,YELLOW);
	floodfill(120,420,BLUE);
	delay(1000);*/
    setcolor(YELLOW);
	setfillstyle(1,YELLOW);
	pieslice(120,350,0,360,30);
	delay(1000);
	setcolor(YELLOW);
	setfillstyle(1,YELLOW);
	pieslice(270,350,0,360,30);
	delay(1000);
	setcolor(YELLOW);
	setfillstyle(1,YELLOW);
	pieslice(420,350,0,360,30);
	delay(1000);
	cleardevice();
	setbkcolor(BLUE);
	puthz(64,100,"立体仓库机器人搬运系统",48,48,WHITE);
			bar(150,250,450,330);
			puthz(155,262,"点",48,48,RED);
			puthz(235,262,"击",48,48,RED);
			puthz(315,262,"进",48,48,RED);
			puthz(395,262,"入",48,48,RED);
	while(1)
	{
		
		newmouse(&MouseX, &MouseY, &press); 
			if ((mouse_press(140,230,460,340)==2 )&& n==0) 
			{
				n=1; 
				setcolor(YELLOW);
				
                setfillstyle(1,YELLOW );  // ?????????
                /*floodfill(100, 80, BLACK);  // ????*/
                bar(150,250,450,330);
				puthz(155,262,"点",48,48,RED);
				puthz(235,262,"击",48,48,RED);
				puthz(315,262,"进",48,48,RED);
				puthz(395,262,"入",48,48,RED);
				MouseS=1;
				delay(100);
			
			}
     
		if ((MouseX < 140 || MouseX > 460 || MouseY < 230 || MouseY > 340) && n==1)
			{
				n=0;
				setcolor(GREEN);
                	
                		setfillstyle(1,GREEN );  // ?????????
                bar(150,250,450,330);
			puthz(155,262,"点",48,48,WHITE);
			puthz(235,262,"击",48,48,WHITE);
			puthz(315,262,"进",48,48,WHITE);
			puthz(395,262,"入",48,48,WHITE);	
						MouseS=0;
					delay(100);
            }
		if(mouse_press(150,250,450,330)==1)
        {
        	break;
		}
	}
	clrmous(MouseX,MouseY);
	cleardevice();
	drawlogin();

    
} 








