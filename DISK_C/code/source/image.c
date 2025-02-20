#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "mouse.h"
#include "hz.h"
#include <conio.h>
void image1(int x,int y);
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\code\\image");  // 初始化图形模式
    IMAGE img;
    if (!loadimage(&img, "robot.bmp", 0, 0, true))  // 加载 BMP 图像文件
    {
        printf("Error loading image file!\n");
        getch();
        closegraph();
        return 1;
    }

    // 显示图像
    putimage(x, y, &img);  // 将图像显示在窗口的 (50, 50) 位置

    // 等待用户按键后退出
    getch();
    closegraph();  // 关闭图形模式
    return 0;
}
