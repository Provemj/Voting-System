#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>
#include<stdlib.h>
#include<�ļ�����.h>
#include<��ѡ��.h>
#pragma once

using namespace std;

int m;//��Ŀ¼ѡ�����


void startMenu()//������
{
	for(m=1;m<35;m++) cout<<"��";  //ʹ���������״��Ҫ����Ϊ���ȫ���ַ��ȽϺ�ʹ
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl<<"��";
	cout.width(42);
	cout.setf(ios::right);
	cout<<"��ӭʹ�ð�ɼ�Ʊ���";
	cout.width(24);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl;
	for(m=1;m<35;m++) cout<<"��";
}

void delay(int i)
{
	clock_t start = clock();
	int secs=i;
	clock_t delay=secs*CLOCKS_PER_SEC;
	while(clock()-start<delay) ;
}

int choice1=0;

void firstMenu()//1��Ŀ¼
{
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"1.ͶƱ��Ա";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"2.������Ա";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"3.�˵�����";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;	
	cout<<"��";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"4.�˳�ϵͳ";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"��ѡ��ѡ�1-4��";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl;
	cout<<"����ѡ�";
	cin>>choice1;
}

int choice2=0;

void managerMenu()//������ԱĿ¼
{
	choice2=0;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"--��ѡ��Ա��Ϣ����--";
	cout.width(26);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"1.��ѡ��Ϣ��ѯ";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"2.����������Ϣ";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"3.��Ӻ�ѡ��Ϣ";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"4.ɾ����ѡ��Ϣ";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"5.ͳ�ƺ�ѡ��Ʊ";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"6.�˳��������";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"��ѡ��ѡ�1-6��";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl;
	cout<<"����ѡ�";
	cin>>choice2;
}

void printInfo(bool MorV)
{
//	if(nomi.size()==1&&nomi[1].num<0){cout<<"δ���ں�ѡ������"<<endl;}
	
	cout<<setw(5)<<"���"<<setw(10)<<"����"<<setw(8)<<"�Ա�"<<setw(12)<<"����ְ��";
	if(MorV) cout<<setw(10)<<"����"<<setw(8)<<"Ʊ��"<<setw(10)<<"����״̬";
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
//������Աtrue��ͶƱ��Աfalse
void printSingle(bool MorV,int i)
{
	cout<<setw(5)<<"���"<<setw(10)<<"����"<<setw(8)<<"�Ա�"<<setw(12)<<"����ְ��";
	if(MorV) cout<<setw(10)<<"����"<<setw(8)<<"Ʊ��"<<setw(10)<<"����״̬";
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
	if(mark==0) cout<<"��û��ͬѧ�����ְ��"<<endl;
}

int choice21,checkNum;
void adjustMenu()//3��Ŀ¼
{
	cout<<"���������������ţ�"<<endl;
	cin>>checkNum;
	if(checkNum-180001<0||checkNum-180001>nomi.size()) {cout<<"����ʧ��"<<endl;checkNum=180000;return;}
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(42);
	cout.setf(ios::right);
	cout<<"--��������ѡ��˵�--";
	cout.width(24);
	cout<<"��"<<endl;
	cout<<"��";
	cout<<setw(5)<<"���"<<setw(10)<<"����"<<setw(8)<<"�Ա�"<<setw(12)<<"����ְ��"
		<<setw(10)<<"����"<<setw(8)<<"Ʊ��"<<setw(10)<<"����״̬";
	cout<<" ��";
	cout<<endl;
	cout<<"��";
	cout<<setw(5)<<nomi[checkNum-180001].num<<setw(9)<<nomi[checkNum-180001].name<<setw(6)<<nomi[checkNum-180001].gender
		<<setw(14)<<nomi[checkNum-180001].position<<setw(8)
		<<nomi[checkNum-180001].birthday.y<<"-"<<nomi[checkNum-180001].birthday.m<<"-"<<nomi[checkNum-180001].birthday.d
		<<setw(4)<<nomi[checkNum-180001].votes<<setw(8)<<nomi[checkNum-180001].result();
	cout<<"    ��"<<endl;
	cout<<"��";
	cout.width(35);
	cout.setf(ios::right);
	cout<<"1.����";
	cout.width(31);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(35);
	cout.setf(ios::right);
	cout<<"2.�Ա�";
	cout.width(31);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"3.����ְ��";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"4.��������";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"5.����״̬";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(38);
	cout.setf(ios::right);
	cout<<"6.�����ϲ�˵�";
	cout.width(28);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"��ѡ��ѡ�1-6��";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl;
	cout<<"����ѡ�";
	cin>>choice21;
}

void changeObj(int i,int j)
{
	if(i!=4&&i!=5) cout<<"�������Ӧ��Ϣ��"<<endl;
	else if(i==4) cout<<"�������Ӧ��Ϣ���ÿո��������գ���"<<endl;
	else if(i==5) cout<<"�������Ӧ��Ϣ��1ͨ�� 0��ͨ�� -1��������"<<endl;
	if(i==1) cin>>nomi[j-180001].name;
	else if(i==2) cin>>nomi[j-180001].gender;
	else if(i==3) cin>>nomi[j-180001].position;
	else if(i==4) cin>>nomi[j-180001].birthday.y>>nomi[j-180001].birthday.m>>nomi[j-180001].birthday.d;
	else if(i==5) cin>>nomi[j-180001].yesOrno;
	cout<<"�޸ĳɹ���"<<endl;
}

nominee tempN;

void insertNom()
{
	tempN.yesOrno=-1;tempN.votes=0;tempN.num=nomi.size()+180001;tempN.exisT=true;
	cout<<"�������ѡ��������"<<endl;
	cin>>tempN.name;
	cout<<"�������ѡ���Ա�(M����FŮ��)��"<<endl;
	cin>>tempN.gender;
	cout<<"�������ѡ������ְ��"<<endl;
	cin>>tempN.position;
	cout<<"�������ѡ��������Ϣ���ÿո��������գ���"<<endl;
	cin>>tempN.birthday.y>>tempN.birthday.m>>tempN.birthday.d;
	nomi.push_back(tempN);
}

void deleteNom()
{
	int delNum;
	cout<<"������ɾ����������"<<endl;
	cin>>delNum;
	if(delNum>180000+nomi.size()) cout<<"�ö��󲻴���"<<endl;
	else if(nomi.at(delNum-180001).exisT==false) cout<<"�ö��󲻴���"<<endl;
	else {nomi.at(delNum-180001).exisT=false;cout<<"�ö����ѱ�ɾ��"<<endl;}
}

int choice3=0;

void voterMenu()//������ԱĿ¼
{
	choice2=0;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"--ͶƱ��Ա����ƽ̨--";
	cout.width(26);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"1.��ѡ��Ϣ����";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"2.���ְ���ѯ";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"3.����ͶƱ����";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(37);
	cout.setf(ios::right);
	cout<<"4.�˳�ͶƱ����";
	cout.width(29);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(40);
	cout.setf(ios::right);
	cout<<"��ѡ��ѡ�1-4��";
	cout.width(26);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl;
	cout<<"���ѡ�";
	cin>>choice3;
}

void rankNom()
{
	if(nomi.size()==0){cout<<"δ�к�ѡ������"<<endl;return;}
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
		cout<<"�Ƿ����ѡ�٣�<y/n?>"<<endl;
		cin>>judge;
		if(judge=='n') continue;
		else if(judge=='y')
		{
			nomi[job[j].mark[0]].yesOrno=1;
			cout<<nomi[job[j].mark[0]].name<<"�ɹ���ѡ"<<nomi[job[j].mark[0]].position<<endl;
			for(i=1;i<job[j].sum;i++)
				nomi[job[j].mark[i]].yesOrno=0;
		}
		else cout<<"�������"<<endl;
		}
	}
}

void help()
{
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl<<"��";
	cout.width(66);
	cout.setf(ios::right);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(42);
	cout.setf(ios::right);
	cout<<"--���ѡ��ͶƱ����--";
	cout.width(24);
	cout<<"��"<<endl;
	cout<<"��";
	cout.width(36);
	cout.setf(ios::right);
	cout<<"ϵͳ���";
	cout.width(30);
	cout.setf(ios::right);
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::right);
	cout<<"  ��ϵͳΪ���ѡ���漰������Ʊ��ͳ�ơ��������ܰ�����ѯ���޸ġ���"<<"��"<<endl;
	cout<<"��";
	cout<<"¼ͶƱ�Լ��浵��ʷ��";
	cout<<setw(46)<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::right);
	cout<<"  ����ϵͳ����ȫ����Ϣ���ҡ�����Ų��ҡ���ְ��Ĳ��ң��ɹ���Աϵ";
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.unsetf(ios::right);
	cout.setf(ios::left);
	cout<<"ͳ������ʵ�ֲ���������Ϣ�Ĳ�ѯ��";
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  ͶƱ���ܰ�����ѡ��Ϣ�Ĳ�ѯ������ְ��Ĳ�ѯ����ʵ������";
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  ���⣬ͶƱ���ܾ�ͶƱϵͳ���������ݷ���������ϵͳ��ʵ�������Լ�";
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"ͳ�ƣ����������Ϣ��¼���ĵ��У����ɼ���ʹ�á�";
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  ף��ʹ����죡";
	cout<<"��";
	cout<<endl;
	cout<<"��";
	cout.width(64);
	cout.setf(ios::left);
	cout<<"  ";
	cout<<"��";
	cout<<endl;
	for(m=1;m<35;m++) cout<<"��";
	cout<<endl;
	cout<<"�����������"<<endl;
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
					cout<<"�����������"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==2)
				{
					cout<<"��������Ҫ��ѯ��ְ��"<<endl;
					cin>>in;
					system("cls");
					printJob(false,in);
					cout<<"�����������"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==3)
				{
					printInfo(false);
					cout<<"��������ҪͶƱ�������ţ�"<<endl;
					cin>>m;
					if(m-180000>nomi.size()) cout<<"���󲻴���"<<endl;
					else 
					{nomi[m-180001].votes++;cout<<"ͶƱ�ɹ���"<<endl;}
					cout<<"�����������"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
				else if(choice3==4)
				{
					for(int i=3;i>0;i--)
					{
						cout<<"�����˳�ͶƱϵͳ�����Ժ�"<<i<<"s)..."<<endl;
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
						cout<<"�����˳�����ϵͳ�����Ժ�"<<i<<"s)..."<<endl;
						delay(1);
						system("cls");
					}
				}
				if(choice2!=6)
				{
					cout<<"�����������"<<endl;
					cin.get();
					cin.get();
					system("cls");
				}
			}
		}
		else if(choice1==3)
		{
			help();
			cout<<"�����������"<<endl;
			cin.get();
			cin.get();
			system("cls");
		}
		else if(choice1==4)
		{
			for(int i=3;i>0;i--)
			{
				cout<<"�����˳���Ʊƽ̨�����Ժ�"<<i<<"s)..."<<endl;
				delay(1);
				system("cls");
			}
			cout<<"ף��������죡"<<endl;
			delay(3);
		}
		system("cls");

	}
}

