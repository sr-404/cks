#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "mouse.h"
#include "hz.h"
#include <conio.h>
void image1(int x,int y);
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\code\\image");  // ��ʼ��ͼ��ģʽ
    IMAGE img;
    if (!loadimage(&img, "robot.bmp", 0, 0, true))  // ���� BMP ͼ���ļ�
    {
        printf("Error loading image file!\n");
        getch();
        closegraph();
        return 1;
    }

    // ��ʾͼ��
    putimage(x, y, &img);  // ��ͼ����ʾ�ڴ��ڵ� (50, 50) λ��

    // �ȴ��û��������˳�
    getch();
    closegraph();  // �ر�ͼ��ģʽ
    return 0;
}
