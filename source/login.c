#include <allfunc.h>

//���û�ע��
void rigister_login(int *func)
{
	struct USER temp={0};//�洢��Ϣ���û��ṹ�� 
	char judge[10]="\0";//�����жϵ����� 

    mouse_off(&mouse);
    bar1(364,300,992,445,0xFFFFFF);
    bar1(460,400,930,700,0xFFFFFF); 
    bar1(389,706,1020,750,0xFFFFFF);
    bar1(433,142,1000,190,0xFFFFBB);
    bar1(443,274,970,306,0xffffff);
    bar1(467,678,961,741,0xffffff);
    puthz(497,140,"ע��", 48,50, 0x000000);
	puthz(600,140,"�人���ֹ�", 48,50, 0x00FF);
    draw_commoninput(495,330,"���趨�����˻���"); 
    draw_commoninput(495,390,"���趨��������"); 
    draw_commoninput(495,450,"��ȷ����������"); 
    draw_confirmbotton(573,512,"���ص�¼");
    draw_confirmbotton(573,612,"����ע��");
    prt_hz16_size(485,695, 2, 2, "���Ķ���ͬ��", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(670,695, 2, 2, "�����ֹ���˽���ߡ�", 0x00FF, "HZK\\HZK16s");
    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        
        if(mouse_press(498,287,870,326)==1)   //�����˺�
		{
			mouse_off(&mouse);
			bar1(498,282,870,326,0xffff);
			strcpy(temp.name,"\0");
			Getinfo(498,287,temp.name,10,498,287,870,326);
			mouse_on(mouse);
		}
		else if(mouse_press(498,347,870,386)==1)    //��������
		{
			mouse_off(&mouse);
			bar1(498,342,870,386,0xffff);
			strcpy(temp.code,"\0");
			Getcode(498,347,temp.code,10,498,347,870,386);
			mouse_on(mouse);
		}
		else if(mouse_press(498,407,870,446)==1)     //������������
		{
			mouse_off(&mouse);
			bar1(498,402,870,446,0xffff);
			strcpy(judge,"\0");
			Getcode(498,407,judge,10,498,407,870,446);
			mouse_on(mouse);
		}
		if(mouse_press(545,610,835,670)==1)     //���ȷ�ϼ�
		{
			if(strcmp(temp.name,"\0")!=0)//�û�����Ϊ�� 
			{
				if(strcmp(temp.code,"\0")!=0)//���벻Ϊ�� 
				{
					if(!strcmp(temp.code,judge))//����������ͬ 
			        {
				      if(save_user(temp)==0)
                      {
                        *func=2;
				        break;
                      }
                      else
                      {
                        prt_hz24(570,575,"�û����ѱ�ע�ᣡ",10,"HZK\\Hzk24h");
                        delay(1500);
				        bar1(570,575,800,600,0xffff);
                      }
			        }
			        else
			        {
				      prt_hz24(570,575,"�������벻��ͬ��",0,"HZK\\Hzk24h");
				      delay(1500);
				      bar1(570,575,800,600,0xffff);
			        }  
				}
				else
				{
					prt_hz24(570,575,"����Ϊ�գ�",0,"HZK\\Hzk24h");
				    delay(1500);
				    bar1(570,575,800,600,0xffff);
				}	
			}
			else
			{
				prt_hz24(570,575,"�û���Ϊ�գ�",0,"HZK\\Hzk24h");
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

//������ͨ������
void draw_commoninput(int x1,int y1,char *s)
{
	Line_Thick(x1, y1, x1 + 380, y1, 1, 0xBD32 );
	prt_hz16_size(x1 + 16, y1 - 46, 2, 2, s, 0xBD32, "HZK\\HZK16s");
}

//����ȷ�ϰ�ť
void draw_confirmbotton(int x1,int y1,char *s)
{
	draw_botton(x1, y1, x1+236, y1+55, 0xFFFFFF, 0x00FF);
	puthz(x1+12,y1+4,s, 48,55, 0x000000);
}



//�û�ʹ���˺ŵ�¼
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
    puthz(497,140,"��¼", 48,50, 0x000000);
	puthz(600,140,"�人���ֹ�", 48,50, 0x00FF);

    puthz(365,300,"�����ϼ�", 32,34, 0xBD32);
	Line_Thick(510, 290, 510,345,1,0xBD32 );
	puthz(525,300,"�˺ŵ�¼", 32,34, 0x000000); 

    //�����˻���������
    draw_commoninput(495,448,"�����������˺�"); 
    //��������������
    draw_commoninput(495,522,"��������������"); 

	puthz(480,535,"ע��", 24,24, 0x000000);

    //����ȷ�ϰ�ť
    draw_confirmbotton(573,612,"������¼");
    prt_hz16_size(485,695, 2, 2, "���Ķ���ͬ��", 0x000000, "HZK\\HZK16s");
	prt_hz16_size(670,695, 2, 2, "�����ֹ���˽���ߡ�", 0x00FF, "HZK\\HZK16s");


    mouse_on(mouse);

    while(1)
    {
        mouse_show(&mouse);
        
        if(mouse_press(495,400,870,445)==1)//����˺ſ� 
		{
			mouse_off(&mouse);
			strcpy(name,"\0");
			bar1(495,400,870,445,0xffff);
			Getinfo(497,398,name,10,495,400,870,445);//�õ��˺� 
			mouse_on(mouse);
		}
        else if(mouse_press(495,475,870,520)==1)//�������� 
		{
			mouse_off(&mouse);
			strcpy(code,"\0");
			bar1(495,475,870,520,0xffff);
			Getcode(497,473,code,10,495,475,870,520);//�õ����� 
			mouse_on(mouse);
		}
        else if(mouse_press(573,612,809,667)==1)//�����¼
        {
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				*unum=i;
				DestroyUList(&UL);
				*func=5;      //����������
                break;
			}
			if(i==-2)//����������� 
			{
				prt_hz24(570,550,"�������",0,"HZK\\Hzk24h");
			    delay(1500);
				bar1(570,550,690,574,0xffff);
			}
			if(i==-3)//�û������� 
			{
				prt_hz24(570,550,"�û������ڣ�",0,"HZK\\Hzk24h");
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









