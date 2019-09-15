#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<map>
#pragma once
using namespace std;

class Date 
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
	out<<"Year: "<<emm.y<<endl<<"Month: "<<emm.m<<endl<<"Day: "<<emm.d<<endl;
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

class nominee//基类
{
public:
	string name;
	string position;
	char gender;
	int votes;
	int yesOrno;
	int num;
	Date birthday;
	string result();
	bool exisT;
};

string nominee::result()
{
	if(yesOrno==-1) return "待选";
	else if(yesOrno==0) return "失败";
	else if(yesOrno==1) return "成功";
	return "状态异常";
}

vector<nominee> nomi;

class category
{
public:
	string work;
	int sum;
	int * mark;
	category(){sum=0;};
};

vector<category> job;

string password;