#include"main.h"
#include <algorithm>
using namespace std;

void Usermain()		//用户登入接口
{
	cleardevice();
	CloseAllSwitch();
	
	PIMAGE img=newimage(1366,768);
	getimage(img,"image/main.jpg",0,0);
	putimage(0,0,1366,768,img,0,0);
	setfont(64,32,"华文隶书");

	int t;
	do{
		t=getInteger("1.用户登录\n2.用户注册\n3.游客登入");
	}while(t!=1&&t!=2&&t!=3);

	switch(t){
		case 1:IsUser=true;Denglu();break;
		case 2:IsUser=true;Zhuce();break;
		case 3:IsVisitor=true;Visitor();break;
	}

}



void Denglu()
{
	struct User user_temp;
	LoadData();

	inputbox_getline("用户登录","请输入您的ID",user_temp.ID,20);
	bool d=false;

	for(int i=0;i<100;i++)
	{
		if(strcmp(user[i].ID,user_temp.ID)==0)
		{
			user_counting=i;
			d=true;
			break;
		}
	}

	if(d==false)
	{
		setfont(64,32,"华文隶书");
		outtextxy(400,200,"该ID不存在！");
		delay_ms(1000);
		Usermain();
	}
	inputbox_getline("用户登录","请输入您的密码：",user_temp.password,20);

	if(strcmp(user_temp.password,user[user_counting].password)!=0)
	do{
		inputbox_getline("用户登录","密码错误！请重新输入",user_temp.password,20);
	}while(strcmp(user_temp.password,user[user_counting].password)!=0);

	setfont(64,32,"华文隶书");
	outtextxy(400,200,"登录成功！");
	mainpart();
}

void Zhuce()
{
	struct User user_temp;
	char tempch[100];
	PIMAGE img=newimage(1366,768);
	getimage(img,"image/main.jpg",0,0);
	
	LoadData();
	inputbox_getline("用户注册","请输入您的ID",user_temp.ID,20);

	bool d=false;
	
	int count=user[0].count;
	for(int i=0;i<100;i++)
	{
		if(strcmp(user[i].ID,user_temp.ID)==0)
		{
			d=true;
			break;
		}
	}

	bool c=false;
	if(d==true)
	do{
		c=false;
		inputbox_getline("用户注册","该ID已经存在！请重新输入您的ID",user_temp.ID,20);
		for(int i=0;i<100;i++)
		{
			if(strcmp(user[i].ID,user_temp.ID)==0)
			{
				c=true;
				break;
			}
		}
	}while(c==true);


	inputbox_getline("用户注册","请输入您的密码：",user_temp.password,20);
	inputbox_getline("用户注册","请确认您的密码：",tempch,20);
	if(strcmp(user_temp.password,tempch)!=0)
	{
		do{
		inputbox_getline("用户注册","输入错误，请重新输入您的密码：",user_temp.password,20);
		inputbox_getline("用户注册","请确认您的密码：",tempch,20);
		}while(strcmp(user_temp.password,tempch)!=0);
	}

	setfont(64,32,"华文隶书");
	outtextxy(400,200,"注册成功！");
	delay_ms(1000);
	putimage(0,0,1366,768,img,0,0);

	loop:
	inputbox_getline("注册信息","请输入您的姓名：",user_temp.name,20);

	d=true;
	for(int i=0;i<100;i++)
	{
		if(strcmp(user[i].name,user_temp.name)==0)
		{
			d=false;
			break;
		}
	}

	if(d==false)
	{
		setfont(32,16,"华文隶书");
		outtextxy(400,200,"该姓名已经注册不能重复注册！");
		delay_ms(1000);
		putimage(0,0,1366,768,img,0,0);
		goto loop;
	}
	
	user_temp.sex=getInteger("请输入您的性别\n 1.男性 2.女性");
	if(user_temp.sex!=1&&user_temp.sex!=2)
		do{
			user_temp.sex=getInteger("哈哈哈，请重新输入您的性别\n 1.男性 2.女性");
		}while(user_temp.sex!=1&&user_temp.sex!=2);
	user_temp.age=getInteger("请输入您的年龄：");
	if(user_temp.age<0||user_temp.age>100)
		do{
				user_temp.age=getInteger("开玩笑呢。请重新输入您的年龄：");
		}while(user_temp.age<0||user_temp.age>100);
	
	user[count].copy(user_temp);
	user_counting=count;
	user[0].count=++count;

	SaveData();
	setfont(64,32,"华文隶书");
	outtextxy(400,200,"已完成注册！");
	delay_ms(1000);

	mainpart();
}

void Visitor()
{
	CloseAllSwitch();
	IsVisitor=true;
	mainpart();
}
void Adminpart()
{
	LoadData();
	cleardevice();
	setfont(64,32,"华文隶书");
	setfontbkcolor(RGB(163,73,164));
	PIMAGE img1=newimage(1366,768);
	getimage(img1,"image/main1.png");
	PIMAGE img2=newimage(1366,768);
	getimage(img2,"image/main2.png");
	PIMAGE img3=newimage(1366,768);
	getimage(img3,"image/main3.png");
	PIMAGE img4=newimage(1366,768);
	getimage(img4,"image/main4.png");
	PIMAGE img5=newimage(1366,768);
	getimage(img5,"image/main5.png");
	PIMAGE img6=newimage(1366,768);
	getimage(img6,"image/main6.png");
	PIMAGE img7=newimage(1366,768);
	getimage(img7,"image/main7.png");
	PIMAGE img0=newimage(1366,768);
	getimage(img0,"image/main0.png");
	PIMAGE img8=newimage(288,380);
	getimage(img8,"image/Admin.png");
	PIMAGE img=newimage(399,266);
	getimage(img,"image/inputbox.png");

	int choice=0;

	while(true)
	{
		m=getmouse();
		if(m.x>167&&m.x<257&&m.y>=128&&m.y<180)
		{
			putimage(0,0,1366,768,img1,0,0);
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=1;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=180&&m.y<260)
		{
			putimage(0,0,1366,768,img2,0,0);
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=2;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=260&&m.y<344)
		{
			putimage(0,0,1366,768,img3,0,0);
		
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=3;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=344&&m.y<425)
		{
			putimage(0,0,1366,768,img4,0,0);
			
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=4;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=425&&m.y<505)
		{
			putimage(0,0,1366,768,img5,0,0);
			
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=5;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=505&&m.y<583)
		{
			putimage(0,0,1366,768,img6,0,0);
			
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=6;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=583&&m.y<653)
		{
			putimage(0,0,1366,768,img7,0,0);
			
			putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=7;
				break;
			}
		}
		else
		{
			putimage(0,0,1366,768,img0,0,0);
			putimage(1012,207,1028+514,227+648,img8,0,0);
		}


			outtextxy(1026,140,"管理员");

		if(m.x>1152&&m.x<1299&&m.y>663&&m.y<729&&m.is_down())
		{
			putimage(461,267,461+399,267+266,img,0,0);
			setfont(50,25,"华文隶书");
			outtextxy(502,324,"退出吗？");
			int t;
			while(true)
			{
				m=getmouse();
				if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
				{
					t=1;
					break;
				}
				if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
				{
					t=2;
					break;
				} 
		
			}
			if(t==1)
				exit(0);
			else
				mainpart();
			
		}
	
		if(m.x>1215&&m.x<1283&&m.y>532&&m.y<565&&m.is_down())
		{
			putimage(461,267,461+399,267+266,img,0,0);
			setfont(50,25,"华文隶书");
			outtextxy(502,324,"注销吗？");
			int t;
			while(true)
			{
				m=getmouse();
				if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
				{
					t=1;
					break;
				}
				if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
				{
					t=2;
					break;
				}
		
			}

			if(t==1)
				mainmenu();
			else
				mainpart();

		}

		if(m.x>1073&&m.x<1232&&m.y>387&&m.y<423&&m.is_down())
		{
			PIMAGE img=newimage(938,601);
			getimage(img,"image/about.png");
			putimage(214,83,214+938,83+601,img,0,0);
		//	getch();

			while(true)
			{
				m=getmouse();
				if(m.x>1096&&m.x<1128&&m.y>112&&m.y<141&&m.is_down())
					mainpart();
				if(m.x>1045&&m.x<1136&&m.y>635&&m.y<657&&m.is_down())
					exit(0);
			}
		}

		if(m.x>1070&&m.x<1232&&m.y>455&&m.y<481&&m.is_down())
		{
			putimage(461,267,461+399,267+266,img,0,0);
			setfont(50,25,"华文隶书");
			outtextxy(502,324,"修改密码？");
			int t;

			while(true)
			{
				m=getmouse();
				if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
				{
					t=1;
					break;
				}
				if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
				{
					t=2;
					break;
				}
			}
			if(t==1)//管理员修改密码
			{
				char temp[20];
				admin a;
				inputbox_getline("修改密码","请输入新密码",a.password,20);
				inputbox_getline("修改密码","请确认新密码",temp,20);
				if(strcmp(temp,a.password)!=0)
					do{
					inputbox_getline("修改密码","错误！请输入新密码",a.password,20);
					inputbox_getline("修改密码","请确认新密码",temp,20);
					}while(strcmp(temp,a.password)!=0);

				FILE *f1;
				f1=fopen("adminpassword.dat","wb");
				fwrite(&a,sizeof(a),1,f1);
				fclose(f1);
				outtextxy(400,400,"修改成功！");
				delay_ms(1000);
				mainpart();
			}
			else
				mainpart();
		}
		if(m.x>1048&&m.x<1128&&m.y>242&&m.y<325&&m.is_down())
		{
			PIMAGE img0=newimage(514,648);
			getimage(img0,"image/Check.png");
			putimage(390,80,390+514,80+648,img0,0,0);

			CalculateRatio();
			
			char temp[20];
			
			setfont(64,20,"华文隶书");
			outtextxy(410,110,"决策支持系统");
			setfont(20,10,"华文隶书");
			outtextxy(410,200,"哈喽，我是人工智能Qrr  ｖ(⌒ｏ⌒)ｖ~");
			int count=0;
			for(int i=0;i<7;i++)
			{
				switch(i){
					case 0:strcpy(temp,"体育馆");break;
					case 1:strcpy(temp,"游泳馆");break;
					case 2:strcpy(temp,"篮球馆");break;
					case 3:strcpy(temp,"网球馆");break;
					case 4:strcpy(temp,"健身房");break;
					case 5:strcpy(temp,"足球场");break;
					case 6:strcpy(temp,"赛车场");break;
				}
				//xyprintf(410,200+(i+1)*40,"%s的当前利用率为%.2f",temp,Ratio[i]);
				setfont(28,14,"方正卡通简体");
				xyprintf(440,240,"当前总利用率为 %.2f",TotalRatio);
				xyprintf(420,300,"其中如下场馆达到爆满：(利用率)");
				if(Ratio[i]>=0.8)
				{
					count++;
					xyprintf(450,300+40*count,"%s                       %f",temp,Ratio[i]);
				}

				
			}
			if(count==0)
				xyprintf(450,300+40*count,"无");
			//setfont(20,10,"方正卡通简体");
			xyprintf(420,350+40*count,"建议可增加这些场地的数量和设备");
			xyprintf(420,400+40*count,"其中如下场馆达到空闲: (利用率)");
			for(int i=0;i<7;i++)
			{
				switch(i){
					case 0:strcpy(temp,"体育馆");break;
					case 1:strcpy(temp,"游泳馆");break;
					case 2:strcpy(temp,"篮球馆");break;
					case 3:strcpy(temp,"网球馆");break;
					case 4:strcpy(temp,"健身房");break;
					case 5:strcpy(temp,"足球场");break;
					case 6:strcpy(temp,"赛车场");break;
				}
				//xyprintf(410,200+(i+1)*40,"%s的当前利用率为%.2f",temp,Ratio[i]);
				setfont(28,14,"方正卡通简体");
				
				if(Ratio[i]<=0.2)
				{
					count++;
					xyprintf(450,400+40*count,"%s                       %f",temp,Ratio[i]);
				}

				
			}
				xyprintf(420,400+40*(count+1),"建议可减小这些场地数量或降低租金");
			
			while(true)
			{
				m=getmouse();
				if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
					mainpart();
			}
	
		}
		if(m.x>1192&&m.x<1271&&m.y>245&&m.y<330&&m.is_down())
		{
			PIMAGE img0=newimage(514,648);
			getimage(img0,"image/Checking.png");
			putimage(390,80,390+514,80+648,img0,0,0);

			while(true){
				m=getmouse();
				if(m.x>491&&m.x<806&&m.y>209&&m.y<279&&m.is_down())
				{
					PIMAGE img0=newimage(514,648);
					getimage(img0,"image/Check.png");
					putimage(390,80,390+514,80+648,img0,0,0);

					while(true)
					{
						m=getmouse();
						setfont(56,20,"华文隶书");
						outtextxy(428,129," 时间段统计排序");

						Calculate_time();
						
						
						setfont(30,16,"华文隶书");
						outtextxy(428,189,"----------6:00-10:00----------");
						setfont(20,10,"方正卡通简体");
						int count=1;
						int x,y;
						char temp[20];
						for(int i=0;i<7;i++)
						{
							switch(i){
								case 0:case 1:case 2:case 3:y=0;break;
								case 4:case 5:case 6:y=1;break;
							}
							switch(i){
								case 0:case 4:x=0;break;
								case 1:case 5:x=1;break;
								case 2:case 6:x=2;break;
								case 3:x=3;break;
							}
							
							switch(i){
								case 0:strcpy(temp,"体育馆");break;
								case 1:strcpy(temp,"游泳馆");break;
								case 2:strcpy(temp,"篮球馆");break;
								case 3:strcpy(temp,"网球馆");break;
								case 4:strcpy(temp,"健身房");break;
								case 5:strcpy(temp,"足球场");break;
								case 6:strcpy(temp,"赛车场");break;
							}
							xyprintf(428+x*110,209+(y+1)*30,"%s  %.2f ",temp,TimeRatio[i][0]);
						}

						setfont(30,16,"华文隶书");
						outtextxy(428,309,"----------10:00-14:00----------");
						setfont(20,10,"方正卡通简体");
						count=1;
					//	int x,y;
						//char temp[20];
						for(int i=0;i<7;i++)
						{
							switch(i){
									case 0:strcpy(temp,"体育馆");break;
									case 1:strcpy(temp,"游泳馆");break;
									case 2:strcpy(temp,"篮球馆");break;
									case 3:strcpy(temp,"网球馆");break;
									case 4:strcpy(temp,"健身房");break;
									case 5:strcpy(temp,"足球场");break;
									case 6:strcpy(temp,"赛车场");break;
							}
							switch(i){
								case 0:case 1:case 2:case 3:y=0;break;
								case 4:case 5:case 6:y=1;break;
							}
							switch(i){
								case 0:case 4:x=0;break;
								case 1:case 5:x=1;break;
								case 2:case 6:x=2;break;
								case 3:x=3;break;
							}
							
							
							xyprintf(428+x*110,329+(y+1)*30,"%s  %.2f ",temp,TimeRatio[i][1]);
						}
						setfont(30,16,"华文隶书");
						outtextxy(428,419,"----------14:00-18:00----------");
						setfont(20,10,"方正卡通简体");
					
						for(int i=0;i<7;i++)
						{
							switch(i){
									case 0:strcpy(temp,"体育馆");break;
									case 1:strcpy(temp,"游泳馆");break;
									case 2:strcpy(temp,"篮球馆");break;
									case 3:strcpy(temp,"网球馆");break;
									case 4:strcpy(temp,"健身房");break;
									case 5:strcpy(temp,"足球场");break;
									case 6:strcpy(temp,"赛车场");break;
							}
							switch(i){
								case 0:case 1:case 2:case 3:y=0;break;
								case 4:case 5:case 6:y=1;break;
							}
							switch(i){
								case 0:case 4:x=0;break;
								case 1:case 5:x=1;break;
								case 2:case 6:x=2;break;
								case 3:x=3;break;
							}
							
							
							xyprintf(428+x*110,439+(y+1)*30,"%s  %.2f ",temp,TimeRatio[i][2]);
						}

						setfont(30,16,"华文隶书");
						outtextxy(428,529,"----------18:00-22:00----------");
						setfont(20,10,"方正卡通简体");
					
						for(int i=0;i<7;i++)
						{
							switch(i){
									case 0:strcpy(temp,"体育馆");break;
									case 1:strcpy(temp,"游泳馆");break;
									case 2:strcpy(temp,"篮球馆");break;
									case 3:strcpy(temp,"网球馆");break;
									case 4:strcpy(temp,"健身房");break;
									case 5:strcpy(temp,"足球场");break;
									case 6:strcpy(temp,"赛车场");break;
							}
							switch(i){
								case 0:case 1:case 2:case 3:y=0;break;
								case 4:case 5:case 6:y=1;break;
							}
							switch(i){
								case 0:case 4:x=0;break;
								case 1:case 5:x=1;break;
								case 2:case 6:x=2;break;
								case 3:x=3;break;
							}
							
							
							xyprintf(428+x*110,549+(y+1)*30,"%s  %.2f ",temp,TimeRatio[i][3]);
						}

						if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
							mainpart();
					}
				
				}
				if(m.x>490&&m.x<807&&m.y>372&&m.y<445&&m.is_down())
				{
					PIMAGE img0=newimage(514,648);
					getimage(img0,"image/Check.png");
					putimage(390,80,390+514,80+648,img0,0,0);


					while(true)
					{
						m=getmouse();
						setfont(56,20,"华文隶书");
						outtextxy(418,129," 欢迎程度统计结果");
						setfont(30,15,"华文隶书");
						sortplace(1);
						/*for(int i=0;i<7;i++)
						{
							for(int j=0;j<7;j++)
								if(sortPlace[j].num1==i)
									xyprintf(418,179+i*40,"%s %d %f",sortPlace[j].name,sortPlace[j].num1,sortPlace[j].result1);
						}*/
						setfont(20,11,"华文隶书");
						xyprintf(428,189,"排行  场馆名称     受欢迎指数");
						setfont(30,15,"华文隶书");
						for(int i=0;i<7;i++)
						{
							xyprintf(438,239+i*60,"%d    %s      %f",i+1,sortPlace[i].name,sortPlace[i].result1);
						}
						

						if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
							mainpart();
					}
				}
				if(m.x>490&&m.x<807&&m.y>516&&m.y<592&&m.is_down())
				{
					PIMAGE img0=newimage(514,648);
					getimage(img0,"image/Check.png");
					putimage(390,80,390+514,80+648,img0,0,0);


					while(true)
					{
						m=getmouse();
						setfont(56,20,"华文隶书");
						outtextxy(428,129," 收入统计结果");
						setfont(30,15,"华文隶书");
						sortplace(2);
						setfont(20,11,"华文隶书");
						xyprintf(428,189,"排行  场馆名称     总收入");
						setfont(30,15,"华文隶书");
						for(int i=0;i<7;i++)
						{
							xyprintf(438,239+i*60,"%d    %s      %.1f",i+1,sortPlace[i].name,sortPlace[i].result2);
						}



						if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
							mainpart();
					}
				}
				if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
					mainpart();
			}
		}
			
	}

	Booking(choice);

}


void mainpart()
{

	if(IsAdmin)
		Adminpart();

	LoadData();
	cleardevice();
	setfont(64,32,"华文隶书");
	setfontbkcolor(RGB(163,73,164));
	PIMAGE img1=newimage(1366,768);
	getimage(img1,"image/main1.png");
	PIMAGE img2=newimage(1366,768);
	getimage(img2,"image/main2.png");
	PIMAGE img3=newimage(1366,768);
	getimage(img3,"image/main3.png");
	PIMAGE img4=newimage(1366,768);
	getimage(img4,"image/main4.png");
	PIMAGE img5=newimage(1366,768);
	getimage(img5,"image/main5.png");
	PIMAGE img6=newimage(1366,768);
	getimage(img6,"image/main6.png");
	PIMAGE img7=newimage(1366,768);
	getimage(img7,"image/main7.png");
	PIMAGE img0=newimage(1366,768);
	getimage(img0,"image/main0.png");
	PIMAGE img8=newimage(288,380);
	getimage(img8,"image/Admin.png");
	PIMAGE img=newimage(399,266);
	getimage(img,"image/inputbox.png");

	int choice=0;

	while(true)
	{
		m=getmouse();
		if(m.x>167&&m.x<257&&m.y>=128&&m.y<180)
		{
			putimage(0,0,1366,768,img1,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=1;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=180&&m.y<260)
		{
			putimage(0,0,1366,768,img2,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=2;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=260&&m.y<344)
		{
			putimage(0,0,1366,768,img3,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=3;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=344&&m.y<425)
		{
			putimage(0,0,1366,768,img4,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=4;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=425&&m.y<505)
		{
			putimage(0,0,1366,768,img5,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=5;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=505&&m.y<583)
		{
			putimage(0,0,1366,768,img6,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=6;
				break;
			}
		}
		else if(m.x>167&&m.x<257&&m.y>=583&&m.y<653)
		{
			putimage(0,0,1366,768,img7,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
			if(m.is_down())
			{
				choice=7;
				break;
			}
		}
		else
		{
			putimage(0,0,1366,768,img0,0,0);
			if(IsAdmin)
				putimage(1012,207,1028+514,227+648,img8,0,0);
		}


		
		if(IsVisitor)
			outtextxy(1046,140,"游  客");
		else if(IsUser)
			outtextxy(1076,140,user[user_counting].name);
		else if(IsAdmin)
			outtextxy(1026,140,"管理员");

		if(m.x>1152&&m.x<1299&&m.y>663&&m.y<729&&m.is_down())
		{
			putimage(461,267,461+399,267+266,img,0,0);
			setfont(50,25,"华文隶书");
			outtextxy(502,324,"退出吗？");
			int t;
			while(true)
			{
				m=getmouse();
				if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
				{
					t=1;
					break;
				}
				if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
				{
					t=2;
					break;
				} 
		
			}
			if(t==1)
				exit(0);
			else
				mainpart();
			
		}
		if(m.x>1197&&m.x<1276&&m.y>222&&m.y<312&&m.is_down()&&!IsAdmin)
		{
			
			//CloseAllSwitch();
			
			putimage(461,267,461+399,267+266,img,0,0);
			setfont(50,25,"华文隶书");
			outtextxy(502,324,"注销吗？");
			int t;
			while(true)
			{
				m=getmouse();
				if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
				{
					t=1;
					break;
				}
				if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
				{
					t=2;
					break;
				}
		
			}

			if(t==1)
				mainmenu();
			else
				mainpart();
		}
		if(m.x>1034&&m.x<1172&&m.y>283&&m.y<318&&m.is_down()&&!IsAdmin)
			ResetPassword();
		if(m.x>1031&&m.x<1169&&m.y>222&&m.y<258&&m.is_down()&&!IsAdmin)
		{
			if(IsVisitor)
			{
				setfont(64,32,"华文隶书");
				outtextxy(300,200,"抱歉游客没有权限");
				delay_ms(1000);
				mainpart();
			}
			
			else
				UserMessage();
		}
	}

	Booking(choice);
}

void Booking(int choice)
{
	
	PIMAGE img=newimage(399,266);
	getimage(img,"image/input_message.png");
	putimage(461,267,461+399,267+266,img,0,0);

	int t;
	while(true)
	{
		m=getmouse();
		if(m.x>537&&m.x<770&&m.y>314&&m.y<383&&m.is_down())
		{
			if(IsVisitor)
			{
				setfont(64,32,"华文隶书");
				outtextxy(300,200,"抱歉游客没有权限");
				delay_ms(1000);
				mainpart();
			}
			if(IsAdmin)
			{
				setfont(64,32,"华文隶书");
				outtextxy(300,200,"抱歉管理员不能预订");
				delay_ms(1000);
				mainpart();
			}
			t=1;
			break;
		}
		if(m.x>537&&m.x<770&&m.y>425&&m.y<495&&m.is_down())
		{
			t=2;
			break;
		}
		if(m.x>818&&m.x<842&&m.y>262&&m.y<304&&m.is_down())
		{
			t=3;
			break;
		}
	}
	if(t==1&&(user[user_counting].age>60||user[user_counting].age<18))
	{
		if(choice==2||choice==7)
		{
			outtextxy(300,200,"这项运动有一定危险");
			outtextxy(300,300,"可能不适合您...");
			delay_ms(2000);
			mainpart();
		}
	}//对老人和小孩不适合的运动进行筛选

	switch(t){
		case 1:RunTimebooking(choice);break;
		case 2:CheckingSituation(choice);break;
		case 3:mainpart();break;
	}
}



void RunTimebooking(int choice)
{
	cleardevice();
	PIMAGE img=newimage(1366,768);
	getimage(img,"image/Time.png");
	PIMAGE img1=newimage(348,140);
	getimage(img1,"image/Timebutton.png");
	putimage(0,0,1366,768,img,0,0);
	PIMAGE img0=newimage(399,266);
	getimage(img0,"image/inputbox.png");
	//int m=choice;
	
	while(true)
	{
		m=getmouse();
		
			/*if(m.x>(0+340*i)&&m.x<(340+340*i)&&m.y>278&&m.y<278+140)
			{
				putimage(0,0,1366,768,img,0,0);
				putimage(0+340*i,278,340+340*i,278+140,img1,0,0);
				if(m.is_down())
				{
					
				}
			}*/
			if(m.x>(0+340*0)&&m.x<(340+340*0)&&m.y>288&&m.y<288+140)
			{
				putimage(0,0,1366,768,img,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40,40,"请选择时间段");
				putimage(0+340*0,308,340+340*0,308+140,img1,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40,360,"6:00-10:00");
				if(m.is_down())
				{
					putimage(461,267,461+399,267+266,img0,0,0);
					setfont(50,25,"华文隶书");
					outtextxy(502,324,"预订吗？");
					while(true)
					{
						m=getmouse();
						if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
							break;
						if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
							RunTimebooking(choice);
					}
					int num=getInteger("请输入要预订的数目");

					int require,money;
					switch(choice){
						case 1:money=100;break;
						case 2:case 3:case 4:money=120;break;
						case 5:money=150;break;
						case 6:money=200;break;
						case 7:money=1000;break;
					}
					switch(choice){
						case 1:case 4:require=20;break;
						case 2:case 3:case 5:require=30;break;
						case 6:require=10;break;
						case 7:require=5;break;
					}
					choice=choice-1;

					if(num+user[user_counting].total_num>10)
					{
						setfont(64,32,"华文隶书");
						outtextxy(300,200,"超出今日租用最大限额！");
						delay_ms(1000);
						RunTimebooking(choice);
					}
					else if(num+place[choice].used_num>require)
					{
						setfont(64,32,"华文隶书");
						outtextxy(300,200,"本时段场地剩余量不够！");
						delay_ms(1000);
						RunTimebooking(choice);
					}
					else
					{
						user[user_counting].total_num+=num;
						user[user_counting].place[choice].timeNum[0]+=num;
						place[choice].money+=money*num*4;
						place[choice].timebooking[0]+=num;
						place[choice].used_num+=num;

						if(user[user_counting].sex==1)
						{
							place[choice].men++;
						}
						else
							place[choice].women++;

						setfont(64,32,"华文隶书");
						outtextxy(300,200,"预订成功！");
						SaveData();
						delay_ms(1000);
						RunTimebooking(choice);
					}
				}
				
			}
			else if(m.x>(0+340*1)&&m.x<(340+340*1)&&m.y>288&&m.y<288+140)
			{
				putimage(0,0,1366,768,img,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40,40,"请选择时间段");
				putimage(0+340*1,308,340+340*1,308+140,img1,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40+340,360,"10:00-14:00");
				if(m.is_down())
				{
					putimage(461,267,461+399,267+266,img0,0,0);
					setfont(50,25,"华文隶书");
					outtextxy(502,324,"预订吗？");
					int t;
					while(true)
					{
						m=getmouse();
						if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
						{
							t=1;
							break;
						}
						if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
						{
							t=2;
							break;
						}
		
					}
					if(t==2)
						RunTimebooking(choice);
					else
					{
						int num=getInteger("请输入要预订的数目");

						int require,money;
						switch(choice){
							case 1:money=100;break;
							case 2:case 3:case 4:money=120;break;
							case 5:money=150;break;
							case 6:money=200;break;
							case 7:money=1000;break;
						}
						switch(choice){
							case 1:case 4:require=20;break;
							case 2:case 3:case 5:require=30;break;
							case 6:require=10;break;
							case 7:require=5;break;
						}
						choice=choice-1;

						if(num+user[user_counting].total_num>10)
						{
							setfont(64,32,"华文隶书");
							outtextxy(300,200,"超出今日租用最大限额！");
							delay_ms(1000);
							RunTimebooking(choice);
						}
						else if(num+place[choice].used_num>require)
						{
							setfont(64,32,"华文隶书");
							outtextxy(300,200,"本时段场地剩余量不够！");
							delay_ms(1000);
							RunTimebooking(choice);
							
						}
						else
						{
							user[user_counting].total_num+=num;
							user[user_counting].place[choice].timeNum[1]+=num;
							place[choice].money+=money*num*4;
							place[choice].timebooking[1]+=num;
							place[choice].used_num+=num;

							if(user[user_counting].sex==1)
							{
								place[choice].men++;
							}
							else
								place[choice].women++;

							setfont(64,32,"华文隶书");
							outtextxy(300,200,"预订成功！");
							SaveData();
							delay_ms(1000);
							RunTimebooking(choice);
						}
					}
				}
					
			}
			else if(m.x>(0+340*2)&&m.x<(340+340*2)&&m.y>288&&m.y<288+140)
			{
				putimage(0,0,1366,768,img,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40,40,"请选择时间段");
				putimage(5+340*2,308,345+340*2,308+140,img1,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40+340*2,360,"14:00-18:00");
				if(m.is_down())
				{
					putimage(461,267,461+399,267+266,img0,0,0);
					setfont(50,25,"华文隶书");
					outtextxy(502,324,"预订吗？");
					int t;
					while(true)
					{
						m=getmouse();
						if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
						{
							t=1;
							break;
						}
						if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
						{
							t=2;
							break;
						}
		
					}
					if(t==2)
						RunTimebooking(choice);
					else
					{
						int num=getInteger("请输入要预订的数目");

						int require,money;
						switch(choice){
							case 1:money=100;break;
							case 2:case 3:case 4:money=120;break;
							case 5:money=150;break;
							case 6:money=200;break;
							case 7:money=1000;break;
						}
						switch(choice){
							case 1:case 4:require=20;break;
							case 2:case 3:case 5:require=30;break;
							case 6:require=10;break;
							case 7:require=5;break;
						}
						choice=choice-1;
						if(num+user[user_counting].total_num>10)
						{
							setfont(64,32,"华文隶书");
							outtextxy(300,200,"超出今日租用最大限额！");
							delay_ms(1000);
							RunTimebooking(choice);
						}
						else if(num+place[choice].used_num>require)
						{
							setfont(64,32,"华文隶书");
							outtextxy(300,200,"本时段场地剩余量不够！");
							delay_ms(1000);
							RunTimebooking(choice);
							
						}
						else
						{
							user[user_counting].total_num+=num;
							user[user_counting].place[choice].timeNum[2]+=num;
							place[choice].money+=money*num*4;
							place[choice].timebooking[2]+=num;
							place[choice].used_num+=num;

							if(user[user_counting].sex==1)
							{
								place[choice].men++;
							}
							else
								place[choice].women++;

							setfont(64,32,"华文隶书");
							outtextxy(300,200,"预订成功！");
							SaveData();
							delay_ms(1000);
							RunTimebooking(choice);
						}
					}
				}
			}
			else if(m.x>(0+340*3)&&m.x<(340+340*3)&&m.y>288&&m.y<288+140)
			{
				putimage(0,0,1366,768,img,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40,40,"请选择时间段");
				putimage(0+340*3,308,340+340*3,308+140,img1,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40+340*3,360,"18:00-22:00");
				if(m.is_down())
				{
					putimage(461,267,461+399,267+266,img0,0,0);
					setfont(50,25,"华文隶书");
					outtextxy(502,324,"预订吗？");
					int t;
					while(true)
					{
						m=getmouse();
						if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
						{
							t=1;
							break;
						}
						if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
						{
							t=2;
							break;
						}
		
					}
					if(t==2)
						RunTimebooking(choice);
					else
					{
						int num=getInteger("请输入要预订的数目");

						int require,money;
						switch(choice){
							case 1:money=100;break;
							case 2:case 3:case 4:money=120;break;
							case 5:money=150;break;
							case 6:money=200;break;
							case 7:money=1000;break;
						}
						switch(choice){
							case 1:case 4:require=20;break;
							case 2:case 3:case 5:require=30;break;
							case 6:require=10;break;
							case 7:require=5;break;
						}
						choice=choice-1;
						if(num+user[user_counting].total_num>10)
						{
							setfont(64,32,"华文隶书");
							outtextxy(300,200,"超出今日租用最大限额！");
							delay_ms(1000);
							RunTimebooking(choice);
						}
						else if(num+place[choice].used_num>require)
						{
							setfont(64,32,"华文隶书");
							outtextxy(300,200,"本时段场地剩余量不够！");
							delay_ms(1000);
							RunTimebooking(choice);
							
						}
						else
						{
							user[user_counting].total_num+=num;
							user[user_counting].place[choice].timeNum[3]+=num;
							place[choice].money+=money*num*4;
							place[choice].timebooking[3]+=num;
							place[choice].used_num+=num;

							if(user[user_counting].sex==1)
							{
								place[choice].men++;
							}
							else
								place[choice].women++;

							setfont(64,32,"华文隶书");
							outtextxy(300,200,"预订成功！");
							SaveData();
							delay_ms(1000);
							RunTimebooking(choice);
						}
					}
				}
			}
			else
			{
				putimage(0,0,1366,768,img,0,0);
				setfont(40,20,"华文隶书");
				outtextxy(40,40,"请选择时间段");
			}

			if(m.x>1235&&m.x<1324&&m.y>36&&m.y<61&&m.is_down())
				mainpart();
	}
}



void CheckingSituation(int choice)
{
	cleardevice();
	setfont(64,32,"华文隶书");
	PIMAGE img1=newimage(1366,768);
	getimage(img1,"image/main1.png");
	PIMAGE img2=newimage(1366,768);
	getimage(img2,"image/main2.png");
	PIMAGE img3=newimage(1366,768);
	getimage(img3,"image/main3.png");
	PIMAGE img4=newimage(1366,768);
	getimage(img4,"image/main4.png");
	PIMAGE img5=newimage(1366,768);
	getimage(img5,"image/main5.png");
	PIMAGE img6=newimage(1366,768);
	getimage(img6,"image/main6.png");
	PIMAGE img7=newimage(1366,768);
	getimage(img7,"image/main7.png");
	PIMAGE img0=newimage(514,648);
	getimage(img0,"image/Check.png");
	PIMAGE img8=newimage(288,380);
	getimage(img8,"image/Admin.png");

	switch(choice){
		case 1:putimage(0,0,1366,768,img1,0,0);break;
		case 2:putimage(0,0,1366,768,img2,0,0);break;
		case 3:putimage(0,0,1366,768,img3,0,0);break;
		case 4:putimage(0,0,1366,768,img4,0,0);break;
		case 5:putimage(0,0,1366,768,img5,0,0);break;
		case 6:putimage(0,0,1366,768,img6,0,0);break;
		case 7:putimage(0,0,1366,768,img7,0,0);break;
	}
	
	putimage(390,80,390+514,80+648,img0,0,0);
	if(IsAdmin)
		putimage(1012,207,1028+514,227+648,img8,0,0);

	char temp[20];
	int total;

	switch(choice){
			case 1:strcpy(temp,"体育馆");total=20;break;
			case 2:strcpy(temp,"游泳馆");total=30;break;
			case 3:strcpy(temp,"篮球馆");total=30;break;
			case 4:strcpy(temp,"网球馆");total=20;break;
			case 5:strcpy(temp,"健身房");total=30;break;
			case 6:strcpy(temp,"足球场");total=10;break;
			case 7:strcpy(temp,"赛车场");total=5;break;
		}
	setfont(60,30,"华文隶书");
	xyprintf(442,114,"%s",temp);
	setfont(30,15,"华文隶书");
	xyprintf(720,136,"租借信息");

	setfont(30,15,"方正卡通简体");
	choice--;
	xyprintf(442,184,"该场地已经被租用的数目为 ：%d个",place[choice].used_num);
	xyprintf(442,224,"还剩余可租用的数目为 ： %d 个",total-place[choice].used_num);
	
	setfont(24,10,"华文隶书");

	xyprintf(442,294,"其中有 %d 位男性租用该场地",place[choice].men);
	xyprintf(442,334,"有 %d 位女性租用该场地",place[choice].women);
	xyprintf(442,374,"今日已收租金 %d 元",place[choice].money);


	xyprintf(442,504,"各时段租借情况如下：");

	int count=0;
	char tempp[20];
	for(int i=0;i<4;i++)
	{
		switch(i){
			case 0:strcpy(tempp,"6:00-10:00");break;
			case 1:strcpy(tempp,"10:00-14:00");break;
			case 2:strcpy(tempp,"14:00-18:00");break;
			case 3:strcpy(tempp,"18:00-22:00");break;
		}
		if(place[choice].timebooking[i]!=0)
		{
			xyprintf(442,544+count*40,"%s 被租用 %d 个",tempp,place[choice].timebooking[i]);
			count++;
		}
	}

	while(true)
	{
		m=getmouse();
		if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
			mainpart();
	}
	
}

void ResetPassword()
{
	if(IsVisitor)
	{
		setfont(64,32,"华文隶书");
		outtextxy(300,200,"抱歉游客没有权限");
		delay_ms(1000);
		mainpart();
	}
	LoadData();
	if(!IsAdmin)
	{
		PIMAGE img=newimage(399,266);
		getimage(img,"image/inputbox.png");
		putimage(461,267,461+399,267+266,img,0,0);
		setfont(50,25,"华文隶书");
		outtextxy(502,324,"修改密码？");
	}
	int t;
	while(true)
	{
		m=getmouse();
		if(m.x>501&&m.x<622&&m.y>440&&m.y<500&&m.is_down())
		{
			t=1;
			break;
		}
		if(m.x>700&&m.x<819&&m.y>440&&m.y<500&&m.is_down())
		{
			t=2;
			break;
		}
		
	}

	char temp[20];
	if(t==2)
		mainpart();
	else
	{
		inputbox_getline("修改密码","请输入原密码",temp,20);
		if(strcmp(temp,user[user_counting].password)!=0)
		{
			setfont(64,32,"华文隶书");
			outtextxy(300,200,"密码不正确！");
			delay_ms(1000);
			mainpart();
		}

		inputbox_getline("修改密码","请输入新密码",temp,20);
		inputbox_getline("修改密码","请确认新密码",user[user_counting].password,20);

		if(strcmp(temp,user[user_counting].password)!=0)
		do{
			inputbox_getline("修改密码","= =两次输入不一致，请再次输入新密码",temp,20);
			inputbox_getline("修改密码","请确认新密码",user[user_counting].password,20);
		}while(strcmp(temp,user[user_counting].password)!=0);

		setfont(64,32,"华文隶书");
		outtextxy(300,200,"修改成功！");
		delay_ms(1000);

		SaveData();
		mainpart();
	}

}

void UserMessage()
{
	PIMAGE img0=newimage(514,648);
	getimage(img0,"image/Check.png");
	putimage(390,80,390+514,80+648,img0,0,0);

	setfont(50,25,"华文隶书");
	outtextxy(472,114,user[user_counting].name);
	if(user[user_counting].sex==1)
		outtextxy(700,114,"先生");
	else
		outtextxy(700,114,"女士");
	setfont(40,20,"华文隶书");
	xyprintf(472,173,"年龄：%d",user[user_counting].age);
	setfont(40,20,"方正卡通简体");
	setfontbkcolor(RGB(163,73,164));
	xyprintf(442,230,"我的租借情况如下：");

	int type=0,time=0;
	int ttime[7]={0};
	bool tt[7]={false};
	for(int i=0;i<7;i++)
	{	
		bool d=false;
		for(int j=0;j<4;j++)
		{
			if(user[user_counting].place[i].timeNum[j]!=0)
			{
				d=true;
				tt[i]=true;
				ttime[i]+=user[user_counting].place[i].timeNum[j]*4;
				time+=user[user_counting].place[i].timeNum[j]*4;
			}
		}
		if(d)
			type++;
	}
	setfont(30,15,"方正卡通简体");
	xyprintf(442,300,"我总共租用了 %d 种场馆",type);
	xyprintf(442,340,"总租用时长为 %d 小时",time);
	xyprintf(422,680,"今日还可租用的剩余时长为 %d 小时",40-time);

	int count=1;
	char temp[20];
	for(int i=0;i<7;i++)
	{
		switch(i){
			case 0:strcpy(temp,"体育馆");break;
			case 1:strcpy(temp,"游泳馆");break;
			case 2:strcpy(temp,"篮球馆");break;
			case 3:strcpy(temp,"网球馆");break;
			case 4:strcpy(temp,"健身房");break;
			case 5:strcpy(temp,"足球场");break;
			case 6:strcpy(temp,"赛车场");break;
		}
		if(tt[i])
		{
			xyprintf(442,340+40*count,"其中租用 %s 时长 %d 小时",temp,ttime[i]);
			count++;
		}
	}

	while(true)
	{
		m=getmouse();
		if(m.x>860&&m.x<890&&m.y>99&&m.y<126&&m.is_down())
			mainpart();
	}
}

void CloseAllSwitch()
{
	IsVisitor=false;
	IsUser=false;
	IsAdmin=false;
}

void LoadData()
{
	FILE *f1,*f2;
	f1=fopen("usermessage.dat","ab");  //防止第一次运行无法读取数据文件，先用ab方式打开一下
	fclose(f1);
	f1=fopen("usermessage.dat","rb");
	fread(user,sizeof(struct User),100,f1);
	fclose(f1);

	f2=fopen("Placemessage.dat","ab");
	fclose(f2);
	f2=fopen("Placemessage.dat","rb");
	fread(place,sizeof(struct Place),7,f2);
	fclose(f2);

}
void SaveData()
{
	
	FILE *f1,*f2;
	f1=fopen("usermessage.dat","wb");
	fwrite(user,sizeof(struct User),100,f1);
	fclose(f1);
	
	f2=fopen("Placemessage.dat","wb");
	fwrite(place,sizeof(struct Place),7,f2);
	fclose(f2);
	
}
void Adminmain()
{
	cleardevice();
	CloseAllSwitch();
	
	PIMAGE img=newimage(1366,768);
	getimage(img,"image/main.jpg",0,0);
	putimage(0,0,1366,768,img,0,0);
	setfont(64,32,"华文隶书");
	IsAdmin=true;
	
	admin a;
	FILE *f1;
	strcpy(a.password,"TurboC");
	f1=fopen("adminpassword.dat","ab");
	fclose(f1);
	f1=fopen("adminpassword.dat","rb");
	fread(&a,sizeof(a),1,f1);
	fclose(f1);

	char temp[20];
	
	inputbox_getline("管理员登陆","请输入您的密码（默认：TurboC）",temp,20);
	if(strcmp(temp,a.password)!=0)
		do{
			inputbox_getline("管理员登陆","错误！请输入您的密码（默认：TurboC）",temp,20);
		}while(strcmp(temp,a.password)!=0);

	outtextxy(400,400,"登陆成功！");
	delay_ms(1000);
	
	mainpart();
}
void Calculate_time()
{
	for(int i=0;i<7;i++)
		for(int j=0;j<4;j++)
			TimeRatio[i][j]=place[i].timebooking[j]*1.0/place[i].used_num;
}

void CalculateRatio()
{

	int total=0;
	for(int i=0;i<7;i++)
	{
		switch(i){
			case 0:case 3:Ratio[i]=place[i].used_num/20.0;break;
			case 1:case 2:case 4:Ratio[i]=place[i].used_num/30.0;break;
			case 5:Ratio[i]=place[i].used_num/10.0;break;
			case 6:Ratio[i]=place[i].used_num/5.0;break;
		}
		total+=place[i].used_num;
	}

	TotalRatio=total*1.0/(20*2+30*3+10+5);

}
bool cmp1(sort_Place s1,sort_Place s2)  //自定义sort函数的排序规则
{
	return s1.result1>s2.result1;
}  
bool cmp2(sort_Place s1,sort_Place s2)  //自定义sort函数的排序规则
{
	return s1.result2>s2.result2;
}                                                                              
void sortplace(int choice)
{
	
	memset(sortPlace,0,sizeof(sortPlace));
	CalculateRatio();
	for(int i=0;i<7;i++)
	{
		sortPlace[i].result1=Ratio[i];
		sortPlace[i].result2=place[i].money;
		switch(i){
			case 0:strcpy(sortPlace[i].name,"体育馆");break;
			case 1:strcpy(sortPlace[i].name,"游泳馆");break;
			case 2:strcpy(sortPlace[i].name,"篮球馆");break;
			case 3:strcpy(sortPlace[i].name,"网球馆");break;
			case 4:strcpy(sortPlace[i].name,"健身房");break;
			case 5:strcpy(sortPlace[i].name,"足球场");break;
			case 6:strcpy(sortPlace[i].name,"赛车场");break;
		}
	}
	if(choice==1)
		sort(sortPlace,sortPlace+7,cmp1);               //快速排序
	else 
		sort(sortPlace,sortPlace+7,cmp2); 
	//for(int i=0;i<7;i++)
	//{
	//	for(int j=i+1;j<7;j++)
	//		if(sortPlace[j].result1>sortPlace[i].result1)
	//		{
	//			double t=sortPlace[i].result1;
	//			sortPlace[i].result1=sortPlace[j].result1;
	//			sortPlace[j].result1=t;                           //对结果进行冒泡排序

	//			int m=sortPlace[i].num1;
	//			sortPlace[i].num1=sortPlace[j].num1;
	//			sortPlace[j].num1=m;                              //同时对编号重新排序
	//		}
	//}
	
}