#include <allfunc.h>

void main()
{      
    int func=0;
    int unum=0;

    SetSVGA64k();//启动SVGA画图界面

    mouse_init();
    
	while(1)   
	{
        switch(func)
        {
            case 0:
            {
                welcome(&func);
                break;
            }
            case 2:
            {
                user_login(&func,&unum);
                break;
            }
            case 3:
            {
                rigister_login(&func);
                break;
            }
        }
	}
	CloseSVGA();//关闭图形界面 
}

//有疑问可找