#include"graphics.h"

int user_counting;                               //用来显示当前登录的用户编号
extern mouse_msg m;								 //存储鼠标信息			

bool IsVisitor;									
bool IsUser;
bool IsAdmin;									//三组布尔值用来判断登录身份（游客、用户、管理员）

void CloseAllSwitch();							//将三组判断登录身份的开关关闭
void LoadData();								//从文件中读取数据
void SaveData();								//将数据存入文件
extern void mainmenu();							//主界面接口

void mainpart();
void Booking(int choice);
void CheckingSituation(int choice);
void ResetPassword();                       //密码重置
void RunTimebooking(int choice);			//按时间段预订界面
void UserMessage();							//查看用户信息
void Adminmain();							//管理员登入接口
void Adminpart();							//管理员主界面
void CalculateRatio();                       //计算各场馆的当前预订率
void Calculate_time();						 //计算不同场地在不同时间利用率
void sortplace(int choice);							//对场馆信息按不同指标进行排序

double TimeRatio[7][4];                      //存放不同场地在不同时间段利用率的计算结果
double Ratio[7];                             //当前各场馆的预订率
double TotalRatio;							 //当前总预订率



struct sort_Place
{
	char name[20];
	double result1;       //按欢迎程度排序
	double result2;	      //按收入排序 
	
	
}sortPlace[7];                 //用来对场馆相关信息进行排序

struct Place
{
	int used_num;
	int money;
	int timebooking[4];
	int men;
	int women;
}place[7];              //场馆信息



struct UserPlace
{
	int timeNum[4];
};                        //用于通过用户查找用户预订的场馆信息

struct User
{
	int count;
	int sex;
	int age;
	char ID[20];
	char password[20];
	char name[20];

	int total_num;
	struct UserPlace place[7];

	void copy(struct User temp)
	{
		sex=temp.sex;
		age=temp.age;
		strcpy(ID,temp.ID);
		strcpy(password,temp.password);
		strcpy(name,temp.name);
	}//将temp结构体内信息全部拷贝到当前结构体
}user[100];                             //用户信息

typedef struct
{
	char password[20];
}admin;//管理员密码

void Denglu();
void Zhuce();
void Visitor();