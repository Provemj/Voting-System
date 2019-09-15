#include<候选人.h>
#include<fstream>
#pragma once
using namespace std;

void init()
{
	nominee tempN;
	ifstream operate;
	operate.open("候选信息.txt",ios::in|ios::beg|ios::binary);
	operate.seekg(ios::beg);
	while(!operate.eof())
	{
		operate.read((char*)&(tempN.num),4);
		operate.read((char*)&tempN.name,32);
		operate.read((char*)&(tempN.gender),1);
		operate.read((char*)&tempN.position,32);
		operate.read((char*)&(tempN.birthday.y),4);
		operate.read((char*)&(tempN.birthday.m),4);
		operate.read((char*)&(tempN.birthday.d),4);
		operate.read((char*)&(tempN.votes),4);
		operate.read((char*)&(tempN.yesOrno),4);
		operate.read((char*)&(tempN.exisT),1);
		nomi.push_back(tempN);
	}
	operate.close();
}

void endIn()
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
		operate.write((char*)&(nomi[i].birthday.y),4);
		operate.write((char*)&(nomi[i].birthday.m),4);
		operate.write((char*)&(nomi[i].birthday.d),4);
		operate.write((char*)&(nomi[i].votes),4);
		operate.write((char*)&(nomi[i].yesOrno),4);
		operate.write((char*)&(nomi[i].exisT),1);
		i++;
	};
	operate.close();
	system("pause");
	return;
}

