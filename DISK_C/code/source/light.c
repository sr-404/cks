#include "allfunc.h"
int light(int x1,int y1,int x2,int y2,int x, int y,char *s1,char *s2,char *s3,char *s4,int flag,int part)
{
	setcolor(YELLOW);
	setfillstyle(1,YELLOW);
	bar(x1,y1,x2,y2);
			puthz(x,y,*s1,flag,part,RED);
			puthz(x,y,*s2,flag,part,RED);
			puthz(x,y,*s3,flag,part,RED);
			puthz(x,y,*s4,flag,part,RED);
}
int dark(int x1,int y1,int x2,int y2,int x, int y,char *s1,char *s2,char *s3,char *s4,int flag,int part)
{
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	bar(x1,y1,x2,y2);
			puthz(x,y,*s1,flag,part,WHITE);
			puthz(x,y,*s2,flag,part,WHITE);
			puthz(x,y,*s3,flag,part,WHITE);
			puthz(x,y,*s4,flag,part,WHITE);
}
	
