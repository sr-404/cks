#include <allfunc.h>

void main()
{      
    int func=0;
    int unum=0;

    SetSVGA64k();//����SVGA��ͼ����

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
	CloseSVGA();//�ر�ͼ�ν��� 
}

//�����ʿ���