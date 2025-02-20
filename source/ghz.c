#include <allfunc.h>

void puthz(int x, int y,char *s,int flag,int part,int color)
{
	FILE *hzk_p=NULL;                                       //���庺�ֿ��ļ�ָ��
	unsigned char quma,weima;                 //���庺�ֵ������λ��
	unsigned long offset;                          //���庺�����ֿ��е�ƫ����
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  //�������飬������ʾ���ֵ����е�����
	int i,j,pos;


	switch(flag)    //��ͬ��flag��Ӧ��ͬ�ĺ��ֿ⣬ʵ���˺��ֵĴ�С�ɸ�����Ҫ�ı�
	{
		case 16 :
				  {
					 char mat[32];   //16*16�ĺ�����Ҫ32���ֽڵ��������洢
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZ16","rb");            //ʹ�����·��
					 if(hzk_p==NULL)
					 {
						CloseSVGA();
						printf("cant open HZ16");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*32L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
							fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
							fread (mat,32,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ���������

							for(i=0;i<16;i++)
							{
								pos=2*i;       //16*16��������ÿһ���������ֽ�
								for(j=0;j<16;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;


							}
							/*====================================================
								������һ��������ʾ��
							====================================================*/
							x+=part;        //��x һ��ƫ����part
							s+=2;           //�������ŵ������룬2���ֽڣ�����Ҫ��2

						}
						x=x0;y0+=flag+10; //һ�к�����ʾ���,���´���࿪ʼ������֣���yһ��ƫ����
					}

					break;

				 }


		case 24 :
				  {
					char mat[72];   //24*24����Ҫ72���ֽ����洢
					 int y0=y;
					 int x0=x;
					hzk_p = fopen("HZK\\Hzk24k","rb");
					if (hzk_p==NULL)
					{
						CloseSVGA();
						printf("cant open HZ24");
						getch();
						exit(1);

					}
					while(*s!=NULL)
					{
						while(x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*72L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,72,1,hzk_p);
							for (i=0;i<24;i++)
							{
								pos=3*i;   //������ÿһ���������ֽ�
								for (j=0;j<24;j++)   // ÿһ����24λ
								{
									if ((mask[j%8]&mat[pos+j/8])!=NULL)
										Putpixel64k(x+j,y,color);

								}
								y++;

							}
							x+=part;
							s+=2;
						}
						x=x0;y0+=flag+10;
					}
						break;
				}

		case 32 :
				  {
					 char mat[128];   //32*32�ĺ�����Ҫ128���ֽڵ��������洢
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZK32S","rb");
					 if(hzk_p==NULL)
					 {
						CloseSVGA();
						printf("cant open HZ32");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*128L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,128,1,hzk_p);
							for(i=0;i<32;i++)
							{
								pos=4*i;       //32*32��������ÿһ���������ֽ�
								for(j=0;j<32;j++)
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;


							}
								//������һ��������ʾ��
							x+=part;    //��x һ��ƫ����part
							s+=2;          //�������ŵ������룬2���ֽڣ�����Ҫ��2

						}
						x=x0;y0+=flag+10;   //һ�к�����ʾ��󣬸�yһ��ƫ����
					}
						break;

				 }


		case 48:
				  {
					char mat[288];   //48*48�ĺ�����Ҫ288���ֽڵ��������洢
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\Hzk48k","rb");
					 if(hzk_p==NULL)
					 {
						CloseSVGA();
						printf("cant open HZ48");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*288L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
							fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
							fread (mat,288,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ���������

							for(i=0;i<48;i++)
							{
								pos=6*i;
								for(j=0;j<48;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;
							}
								//������һ��������ʾ��
							x+=part;    //��x һ��ƫ����part
							s+=2;          //�������ŵ������룬2���ֽڣ�����Ҫ��2

						}
						x=x0;y0+=flag+10;   //һ�к�����ʾ��󣬸�yһ��ƫ����
					}
						break;

				}

		default:
				  break;

	}

	fclose(hzk_p);
}

void puthz_coverd(int x, int y,char *s,int n,int flag,int part,int color)
{
	int i=0;
	for(i=0;i<part*n;i++)
	{
		Line_Thick(x+i,y,x+i,y+flag+1,1,Getpixel64k(x+i,y-1));
	}
	puthz( x,  y, s, flag, part, color);

}
void puthz_coverd2(int x, int y,char *s,int n,int flag,int part,int color,int backcolor)
{
	int i=0;
	for(i=0;i<part*n;i++)
	{
		Line_Thick(x+i,y,x+i,y+flag+1,1,backcolor);
	}
	puthz( x,  y, s, flag, part, color);

}