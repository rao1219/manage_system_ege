#include"initset.h"


int menu()       //返回登入信息，用户or管理员
{
	cleardevice();
	
	int choice=0;
	PIMAGE img=newimage(1366,768);
	getimage(img,"image/select.jpg",0,0);
	PIMAGE img1=newimage(1360,750);
	getimage(img1,"image/select1.jpg",0,0);
	PIMAGE img2=newimage(1366,768);
	getimage(img2,"image/select2.jpg",0,0);
	putimage(0,0,1366,768,img,0,0);

	
	m=getmouse();
	while(true)
	{
		m=getmouse();
		if(m.x>279&&m.x<520&&m.y>283&&m.y<711)
		{
			putimage(0,0,1360,750,img1,0,0);
			if(m.is_down())
			{
				choice=1;
				break;
			}
		}
		else if(m.x>773&&m.x<1006&&m.y>279&&m.y<707)
		{
			putimage(0,0,1366,768,img2,0,0);
			if(m.is_down())
			{
				choice=2;
				break;
			}
		}
		else
			putimage(0,0,1366,768,img,0,0);
	}
	cleardevice();
	return choice;
}
void mainmenu()              //进入用户界面or管理员界面
{
	int choice=0;
	choice=menu();
	
	switch(choice){
		case 1:Usermain();break;    //用户登入接口
		case 2:Adminmain();break;	//管理员登入接口
	}
}

void welcome()          // 初始化窗口设置，字体信息，以及欢迎界面
{
	setinitmode(1,0,0);
	initgraph(-1,-1);
	setfont(40,20,"方正卡通简体");
	setfontbkcolor(RGB(163,73,164));
	PIMAGE img0=newimage(1366,768);
	getimage(img0,"image/welcome.jpg",0,0);
	putimage(0,0,1366,768,img0,0,0);
	delay_ms(2000);
}
void main()
{
	welcome();
	mainmenu();
}