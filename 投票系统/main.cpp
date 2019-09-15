#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#pragma once
using namespace std;

class Date //日期的类，记录生日
{
public:
	Date(){d=1;m=1;y=2018;};
	int d, m, y;
	void Print() { cout <<y<< "/" <<setw(2)<<setfill('0')<< m << "/" <<setw(2)<<  d  << endl;cout<<setfill(' ');}
	friend ostream & operator << (ostream &,Date &);
	friend istream & operator >> (istream &,Date &);
	void input(int a,int b,int c){y=a;m=b;d=c;};
};

ostream & operator << (ostream & out,Date & emm)
{
	out<<emm.y<<"-"<<emm.m<<"-"<<emm.d;
	return out;
}
istream & operator >> (istream & in,Date & emm)
{
	cout<<"Input"<<endl;
	cout<<"Please input the date(year month day):"<<endl;
	in>>emm.y;
	in>>emm.m;
	in>>emm.d;
	return in;
}

class nominee:public Date //继承日期类中的成员
{
public:
	string name;
	string position;
	char gender;
	int votes;//票数
	int yesOrno;//是否当选，未评选则置为-1
	int num;//编号
	string result();//是否当选
	bool exisT;//被删除则从1变为0

};

string nominee::result()
{
	if(yesOrno==-1) return "待选";
	else if(yesOrno==0) return "失败";
	else if(yesOrno==1) return "成功";
	return "状态异常";
}

vector<nominee> nomi;//操作对象

class category//对每种职务进行统计
{
public:
	string work;
	int sum;//参选人数
	int * mark;//参选人的编号
	category(){sum=0;};
	category(int i){sum=i;};
};

vector<category> job;//操作对象

void endIn()//程序退出后将信息写入文件
{
	int i=0;
	int s=nomi.size();
	ofstream operate;
	operate.open("候选信息.txt",ios::out|ios::binary|ios::trunc);
	if(nomi.size()==1) {operate.close();return;}
	while(i<s)
	{
		operate.write((char*)&(nomi[i].num),4);
		operate.write((char*)&nomi[i].name,32);
		operate.write((char*)&(nomi[i].gender),1);
		operate.write((char*)&nomi[i].position,32);
		operate.write((char*)&(nomi[i].y),4);
		operate.write((char*)&(nomi[i].m),4);
		operate.write((char*)&(nomi[i].d),4);
		operate.write((char*)&(nomi[i].votes),4);
		operate.write((char*)&(nomi[i].yesOrno),4);
		operate.write((char*)&(nomi[i].exisT),1);
		i++;
	};
	operate.close();
	system("pause");
	return;
}

int m;//首目录选项计数

void startMenu()//主界面
{
	for(m=1;m<35;m++) cout<<"￥";  //使用人民币形状主要是因为这个全角字符比较好使
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl<<"￥";
	cout.width(42);
	cout.setf(ios::right);
	cout<<"欢迎使用班干计票软件";
	cout.width(24);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl;
	for(m=1;m<35;m++) cout<<"￥";
}

void delay(int i)//为了让某些页面不要一闪而过，停留i秒钟
{
	clock_t start = clock();
	int secs=i;
	clock_t delay=secs*CLOCKS_PER_SEC;
	while(clock()-start<delay) ;
}

int choice1=0;//一级目录的选项

void firstMenu()//一级目录
{
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"1.投票人员";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"2.管理人员";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"3.菜单帮助";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;	
	cout<<"￥";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"4.退出系统";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"请选择选项（1-4）";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl;
	cout<<"您的选项：";
	cin>>choice1;
}

int choice2=0;//管理菜单的选项

void managerMenu()//管理人员目录
{
	choice2=0;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"--候选人员信息操作--";
	cout.width(26);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"1.候选信息查询";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"2.更改已有信息";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"3.添加候选信息";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"4.删除候选信息";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"5.统计候选得票";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"6.退出管理界面";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"请选择选项（1-6）";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl;
	cout<<"您的选项：";
	cin>>choice2;
}

void printInfo(bool MorV)//输出全部信息
{
//	if(nomi.size()==1&&nomi[1].num<0){cout<<"未存在候选人在列"<<endl;}
	
	cout<<setw(5)<<"序号"<<setw(10)<<"姓名"<<setw(8)<<"性别"<<setw(12)<<"申请职务";
	if(MorV) cout<<setw(10)<<"生日"<<setw(8)<<"票数"<<setw(10)<<"申请状态";
	cout<<endl;
	for(int i=0;i<nomi.size();i++)
	{
		if(nomi[i].exisT){
			cout<<nomi[i].num<<setw(10)<<nomi[i].name<<setw(5)<<nomi[i].gender<<' '<<setw(13)<<nomi[i].position;
			if(MorV)
				cout<<setw(7)<<nomi[i].y<<"-"<<setw(2)<<setfill('0')<<nomi[i].m<<"-"<<setw(2)<<nomi[i].d<<setfill(' ')
				<<setw(4)<<nomi[i].votes<<setw(8)<<nomi[i].result();
			cout<<endl;
		}
	}
}
//管理人员true，投票人员false
void printSingle(bool MorV,int i)//输出第i个人的信息
{
	cout<<setw(5)<<"序号"<<setw(10)<<"姓名"<<setw(8)<<"性别"<<setw(12)<<"申请职务";
	if(MorV) cout<<setw(10)<<"生日"<<setw(8)<<"票数"<<setw(10)<<"申请状态";
	cout<<endl;
	cout<<nomi[i].num<<setw(10)<<nomi[i].name<<setw(5)<<nomi[i].gender<<' '<<setw(13)<<nomi[i].position;
	if(MorV)
		cout<<setw(7)<<nomi[i].y<<"-"<<setw(2)<<setfill('0')<<nomi[i].m<<"-"<<setw(2)<<nomi[i].d<<setfill(' ')
		<<setw(4)<<nomi[i].votes<<setw(8)<<nomi[i].result();
	cout<<endl;
}

void printJob(bool MorV,string in)//输出某项职务的认领情况
{
	int mark=0;
	for(int n=0;n<nomi.size();n++)
		if(nomi[n].exisT&&nomi[n].position==in)
		{
			printSingle(MorV,n);
			mark=1;
		}
	if(mark==0) cout<<"还没有同学认领该职务"<<endl;
}

int choice21,checkNum;//三级目录的选项
void adjustMenu()//3级目录，用来修改候选人信息
{
	cout<<"请输入操作对象序号："<<endl;
	cin>>checkNum;
	if(checkNum-180001<0||checkNum-180001>nomi.size()) {cout<<"查找失败"<<endl;checkNum=180000;return;}
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(42);
	cout.setf(ios::right);
	cout<<"--操作内容选择菜单--";
	cout.width(24);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout<<setw(5)<<"序号"<<setw(10)<<"姓名"<<setw(8)<<"性别"<<setw(12)<<"申请职务"
		<<setw(10)<<"生日"<<setw(8)<<"票数"<<setw(10)<<"申请状态";
	cout<<" ￥";
	cout<<endl;
	cout<<"￥";
	cout<<setw(5)<<nomi[checkNum-180001].num<<setw(9)<<nomi[checkNum-180001].name<<setw(6)<<nomi[checkNum-180001].gender
		<<setw(14)<<nomi[checkNum-180001].position<<setw(8)
		<<nomi[checkNum-180001].y<<"-"<<nomi[checkNum-180001].m<<"-"<<nomi[checkNum-180001].d
		<<setw(4)<<nomi[checkNum-180001].votes<<setw(8)<<nomi[checkNum-180001].result();
	cout<<"    ￥"<<endl;
	cout<<"￥";
	cout.width(35);
	cout.setf(ios::right);
	cout<<"1.姓名";
	cout.width(31);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(35);
	cout.setf(ios::right);
	cout<<"2.性别";
	cout.width(31);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"3.申请职务";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"4.生日日期";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"5.申请状态";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(38);
	cout.setf(ios::right);
	cout<<"6.返回上层菜单";
	cout.width(28);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"请选择选项（1-6）";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl;
	cout<<"您的选项：";
	cin>>choice21;
}

void changeObj(int i,int j)//修改第j个人的第i项信息信息
{
	if(i!=4&&i!=5) cout<<"请输入对应信息："<<endl;
	else if(i==4) cout<<"请输入对应信息（用空格间隔年月日）："<<endl;
	else if(i==5) cout<<"请输入对应信息（1通过 0不通过 -1待定）："<<endl;
	if(i==1) cin>>nomi[j-180001].name;
	else if(i==2) cin>>nomi[j-180001].gender;
	else if(i==3) cin>>nomi[j-180001].position;
	else if(i==4) cin>>nomi[j-180001].y>>nomi[j-180001].m>>nomi[j-180001].d;
	else if(i==5) cin>>nomi[j-180001].yesOrno;
	cout<<"修改成功！"<<endl;
}

nominee tempN;//中间对候选人新型操作时用的变量

void insertNom()//插入一个候选人
{
	tempN.yesOrno=-1;tempN.votes=0;tempN.num=nomi.size()+180001;tempN.exisT=true;
	cout<<"请输入候选人姓名："<<endl;
	cin>>tempN.name;
	cout<<"请输入候选人性别(M男生F女生)："<<endl;
	cin>>tempN.gender;
	cout<<"请输入候选人申请职务："<<endl;
	cin>>tempN.position;
	cout<<"请输入候选人生日信息（用空格间隔年月日）："<<endl;
	cin>>tempN.y>>tempN.m>>tempN.d;
	nomi.push_back(tempN);
}

void deleteNom()//删除候选人
{
	int delNum;
	cout<<"请输入删除对象的序号"<<endl;
	cin>>delNum;
	if(delNum>180000+nomi.size()) cout<<"该对象不存在"<<endl;
	else if(nomi.at(delNum-180001).exisT==false) cout<<"该对象不存在"<<endl;
	else {nomi.at(delNum-180001).exisT=false;cout<<"该对象已被删除"<<endl;}
}

int choice3=0;//管理人员目录的选项

void voterMenu()//管理人员目录
{
	choice2=0;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"--投票人员操作平台--";
	cout.width(26);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"1.候选信息总览";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"2.相关职务查询";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"3.进入投票操作";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"4.退出投票界面";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"请选择选项（1-4）";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl;
	cout<<"你的选项：";
	cin>>choice3;
}

void rankNom()//将竞选某职务的候选人按票数排名
{
	if(nomi.size()==0){cout<<"未有候选人在列"<<endl;return;}
	int i,j,exisT=0;
	category tempC;
	for(i=0;i<nomi.size();i++)//记录每种职务的竞选人数
	{
		exisT=0;
		for(j=0;j<job.size();j++)
		{
			if(nomi.at(i).position==job.at(j).work) {job.at(j).sum++;exisT=1;break;}//
		}
	if(exisT);
	else {tempC.work=nomi.at(i).position;tempC.sum=1;job.push_back(tempC);}
	}
	for(j=0;j<job.size();j++) //为每种职务分配内存
	{job[j].mark=new int[job[j].sum];job[j].sum=0;}
	for(i=0;i<nomi.size();i++) //把每种职务的候选人序号记录下来
	{
		for(j=0;j<job.size();j++)
		{
			if(nomi.at(i).position==job.at(j).work) {job[j].mark[job.at(j).sum++]=i;break;}
		}
	}
	
	int k,swap;
	char judge;
	for(j=0;j<job.size();j++)//下面对每种职务进行排序
		for(i=0;i<job[j].sum;i++)
			for(k=0;k<job[j].sum-i-1;k++)
				if(nomi[job[j].mark[k]].votes<nomi[job[j].mark[k+1]].votes)
				{swap=job[j].mark[k];job[j].mark[k]=job[j].mark[k+1];job[j].mark[k+1]=swap;}
	for(j=0;j<job.size();j++)//排完序之后询问每种职务是否进行选举，如果选举则选取最高的一位
	{
		if(nomi[job[j].mark[0]].yesOrno==-1){
		for(i=0;i<job[j].sum;i++)
			printSingle(true,job[j].mark[i]);
		cout<<"是否进行选举？<y/n?>"<<endl;
		cin>>judge;
		if(judge=='n') continue;
		else if(judge=='y')
		{
			nomi[job[j].mark[0]].yesOrno=1;
			cout<<nomi[job[j].mark[0]].name<<"成功当选"<<nomi[job[j].mark[0]].position<<endl;
			for(i=1;i<job[j].sum;i++)
				nomi[job[j].mark[i]].yesOrno=0;
		}
		else cout<<"输出有误"<<endl;
		}
	}
}

void help()//帮助菜单
{
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl<<"￥";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(42);
	cout.setf(ios::right);
	cout<<"--班干选举投票帮助--";
	cout.width(24);
	cout<<"￥"<<endl;
	cout<<"￥";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"系统简介";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::right);
	cout<<"  本系统为班干选举涉及，用于票数统计。所含功能包括查询、修改、记"<<"￥"<<endl;
	cout<<"￥";
	cout<<"录投票以及存档历史。";
	cout<<setw(46)<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::right);
	cout<<"  管理系统包括全部信息查找、按序号查找、按职务的查找，由管理员系";
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.unsetf(ios::right);
	cout.setf(ios::left);
	cout<<"统操作可实现参照上述信息的查询。";
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  投票功能包括候选信息的查询，单个职务的查询，可实现灵活处理。";
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  此外，投票功能经投票系统操作将数据反馈到控制系统，实现排序以及";
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"统计，并将相关信息记录在文档中，其后可继续使用。";
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  祝您使用愉快！";
	cout<<"￥";
	cout<<endl;
	cout<<"￥";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  ";
	cout<<"￥";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"￥";
	cout<<endl;
}

void mainMenu()//主程序
{
	string in;int markJob=0;
	startMenu();
	delay(3);
	system("cls");
	while(choice1!=4)
	{
		firstMenu();//主菜单
		system("cls");
		if(choice1==1)
		{
			choice3=0;
			while(choice3!=4)
			{
				voterMenu();
				system("cls");
				if(choice3==1)//输出全部信息
				{
					printInfo(false);
					cout<<"按任意键返回"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==2)//查询某个人的信息
				{
					cout<<"请输入想要查询的职务："<<endl;
					cin>>in;
					system("cls");
					printJob(false,in);
					cout<<"按任意键返回"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==3)//投票
				{
					printInfo(false);
					cout<<"请输入想要投票对象的序号："<<endl;
					cin>>m;
					if(m-180000>nomi.size()) cout<<"对象不存在"<<endl;
					else 
					{nomi[m-180001].votes++;cout<<"投票成功！"<<endl;}
					cout<<"按任意键返回"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==4)//退出
				{
					for(int i=3;i>0;i--)
					{
						cout<<"即将退出投票系统，请稍后（"<<i<<"s)..."<<endl;
						delay(0);//延时多少秒在这里设置
						system("cls");
					}
				}
				else 
				{
					cout<<"输入内容错误"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
			}
		}
		else if(choice1==2)//操作者界面
		{
			choice2=0;
			while(choice2!=6)
			{
			managerMenu();
			cin.get();
			system("cls");
				if(choice2==1)//输出全部信息
				{
					printInfo(true);
				}
				else if(choice2==2)//输出某个信息
				{
					adjustMenu();
					if(checkNum!=180000)
					changeObj(choice21,checkNum);
				}
				else if(choice2==3)//插入信息
					insertNom();
				else if(choice2==4)//删除信息
					deleteNom();
				else if(choice2==5)//排名
					rankNom();
				else if(choice2==6)//退出系统
				{
					for(int i=3;i>0;i--)
					{
						cout<<"即将退出操作系统，请稍后（"<<i<<"s)..."<<endl;
						delay(0);//延时，时间在这里设置
						system("cls");
					}
				}
				else 
				{
					cout<<"输入内容错误"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				if(choice2!=6)
				{
					cout<<"按任意键返回"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
			}
		}
		else if(choice1==3)//帮助菜单
		{
			help();
			cout<<"按任意键返回"<<endl;
			cin.get();
			cin.get();
			system("cls");
		}
		else if(choice1==4)//退出系统
		{
			for(int i=3;i>0;i--)
			{
				cout<<"即将退出计票平台，请稍后（"<<i<<"s)..."<<endl;
				delay(0);
				system("cls");
			}
			cout<<"祝您学习愉快！"<<endl;
			delay(3);
		}
		else 
		{
			cout<<"输入内容错误"<<endl;
			cin.get();
			cin.get();
			system("cls");
		}
		system("cls");

	}
}

int main()
{
	int j=0;
	nominee tempN;
	ifstream operate2;
	operate2.open("候选信息.txt",ios::in|ios::beg|ios::binary);
	operate2.seekg(ios::beg);
	while(!operate2.eof())
	{
		if(j) nomi.push_back(tempN);
		j=1;
		operate2.read((char*)&(tempN.num),4);
		operate2.read((char*)&tempN.name,32);
		operate2.read((char*)&(tempN.gender),1);
		operate2.read((char*)&tempN.position,32);
		operate2.read((char*)&(tempN.y),4);
		operate2.read((char*)&(tempN.m),4);
		operate2.read((char*)&(tempN.d),4);
		operate2.read((char*)&(tempN.votes),4);
		operate2.read((char*)&(tempN.yesOrno),4);
		operate2.read((char*)&(tempN.exisT),1);
	}
	operate2.close();
	//上述为将文件数据读取
	mainMenu();
	//主要操作
	endIn();
	//将信息写入文件
	system("cls");

	return 0;
}