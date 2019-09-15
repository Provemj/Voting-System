#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>
#include<stdlib.h>
#include<文件操作.h>
#include<候选人.h>
#pragma once

using namespace std;

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

void delay(int i)
{
	clock_t start = clock();
	int secs=i;
	clock_t delay=secs*CLOCKS_PER_SEC;
	while(clock()-start<delay) ;
}

int choice1=0;

void firstMenu()//1级目录
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

int choice2=0;

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

void printInfo(bool MorV)
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
				cout<<setw(7)<<nomi[i].birthday.y<<"-"<<setw(2)<<setfill('0')<<nomi[i].birthday.m<<"-"<<setw(2)<<nomi[i].birthday.d<<setfill(' ')
				<<setw(4)<<nomi[i].votes<<setw(8)<<nomi[i].result();
			cout<<endl;
		}
	}
}
//管理人员true，投票人员false
void printSingle(bool MorV,int i)
{
	cout<<setw(5)<<"序号"<<setw(10)<<"姓名"<<setw(8)<<"性别"<<setw(12)<<"申请职务";
	if(MorV) cout<<setw(10)<<"生日"<<setw(8)<<"票数"<<setw(10)<<"申请状态";
	cout<<endl;
	cout<<nomi[i].num<<setw(10)<<nomi[i].name<<setw(5)<<nomi[i].gender<<' '<<setw(13)<<nomi[i].position;
	if(MorV)
		cout<<setw(7)<<nomi[i].birthday.y<<"-"<<setw(2)<<setfill('0')<<nomi[i].birthday.m<<"-"<<setw(2)<<nomi[i].birthday.d<<setfill(' ')
		<<setw(4)<<nomi[i].votes<<setw(8)<<nomi[i].result();
	cout<<endl;
}

void printJob(bool MorV,string in)
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

int choice21,checkNum;
void adjustMenu()//3级目录
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
		<<nomi[checkNum-180001].birthday.y<<"-"<<nomi[checkNum-180001].birthday.m<<"-"<<nomi[checkNum-180001].birthday.d
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

void changeObj(int i,int j)
{
	if(i!=4&&i!=5) cout<<"请输入对应信息："<<endl;
	else if(i==4) cout<<"请输入对应信息（用空格间隔年月日）："<<endl;
	else if(i==5) cout<<"请输入对应信息（1通过 0不通过 -1待定）："<<endl;
	if(i==1) cin>>nomi[j-180001].name;
	else if(i==2) cin>>nomi[j-180001].gender;
	else if(i==3) cin>>nomi[j-180001].position;
	else if(i==4) cin>>nomi[j-180001].birthday.y>>nomi[j-180001].birthday.m>>nomi[j-180001].birthday.d;
	else if(i==5) cin>>nomi[j-180001].yesOrno;
	cout<<"修改成功！"<<endl;
}

nominee tempN;

void insertNom()
{
	tempN.yesOrno=-1;tempN.votes=0;tempN.num=nomi.size()+180001;tempN.exisT=true;
	cout<<"请输入候选人姓名："<<endl;
	cin>>tempN.name;
	cout<<"请输入候选人性别(M男生F女生)："<<endl;
	cin>>tempN.gender;
	cout<<"请输入候选人申请职务："<<endl;
	cin>>tempN.position;
	cout<<"请输入候选人生日信息（用空格间隔年月日）："<<endl;
	cin>>tempN.birthday.y>>tempN.birthday.m>>tempN.birthday.d;
	nomi.push_back(tempN);
}

void deleteNom()
{
	int delNum;
	cout<<"请输入删除对象的序号"<<endl;
	cin>>delNum;
	if(delNum>180000+nomi.size()) cout<<"该对象不存在"<<endl;
	else if(nomi.at(delNum-180001).exisT==false) cout<<"该对象不存在"<<endl;
	else {nomi.at(delNum-180001).exisT=false;cout<<"该对象已被删除"<<endl;}
}

int choice3=0;

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

void rankNom()
{
	if(nomi.size()==0){cout<<"未有候选人在列"<<endl;return;}
	int i,j,exisT=0;
	category tempC;
	for(i=0;i<nomi.size();i++)
	{
		exisT=0;
		for(j=0;j<job.size();j++)
		{
			if(nomi.at(i).position==job.at(j).work) {job.at(j).sum++;exisT=1;break;}
		}
	if(exisT);
	else {tempC.work=nomi.at(i).position;tempC.sum=1;job.push_back(tempC);}
	}

	for(j=0;j<job.size();j++)
	{job[j].mark=new int[job[j].sum];job[j].sum=0;}

	for(i=0;i<nomi.size();i++)
	{
		for(j=0;j<job.size();j++)
		{
			if(nomi.at(i).position==job.at(j).work) {job[j].mark[job.at(j).sum++]=i;break;}
		}
	}
	
	int k,swap;
	char judge;
	for(j=0;j<job.size();j++)
		for(i=0;i<job[j].sum;i++)
			for(k=0;k<job[j].sum-i-1;k++)
				if(nomi[job[j].mark[k]].votes<nomi[job[j].mark[k+1]].votes)
				{swap=job[j].mark[k];job[j].mark[k]=job[j].mark[k+1];job[j].mark[k+1]=swap;}
	for(j=0;j<job.size();j++)
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

void help()
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
	cout<<"按任意键返回"<<endl;
	cin.get();
}

void mainMenu()
{
	string in;int markJob=0;
	startMenu();
	delay(3);
	system("cls");
	while(choice1!=4)
	{
		firstMenu();
		system("cls");
		if(choice1==1)
		{
			choice3=0;
			while(choice3!=4)
			{
				voterMenu();
				system("cls");
				if(choice3==1)
				{
					printInfo(false);
					cout<<"按任意键返回"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==2)
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
				else if(choice3==3)
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
				else if(choice3==4)
				{
					for(int i=3;i>0;i--)
					{
						cout<<"即将退出投票系统，请稍后（"<<i<<"s)..."<<endl;
						delay(1);
						system("cls");
					}
				}
			}
		}
		else if(choice1==2)
		{
			choice2=0;
			while(choice2!=6)
			{
			managerMenu();
			cin.get();
			system("cls");
				if(choice2==1)		
				{
					printInfo(true);
				}
				else if(choice2==2)
				{
					adjustMenu();
					if(checkNum!=180000)
					changeObj(choice21,checkNum);
				}
				else if(choice2==3)
					insertNom();
				else if(choice2==4)
					deleteNom();
				else if(choice2==5)
					rankNom();
				else if(choice2==6)
				{
					for(int i=3;i>0;i--)
					{
						cout<<"即将退出操作系统，请稍后（"<<i<<"s)..."<<endl;
						delay(1);
						system("cls");
					}
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
		else if(choice1==3)
		{
			help();
			cout<<"按任意键返回"<<endl;
			cin.get();
			cin.get();
			system("cls");
		}
		else if(choice1==4)
		{
			for(int i=3;i>0;i--)
			{
				cout<<"即将退出计票平台，请稍后（"<<i<<"s)..."<<endl;
				delay(1);
				system("cls");
			}
			cout<<"祝您生活愉快！"<<endl;
			delay(3);
		}
		system("cls");

	}
}

