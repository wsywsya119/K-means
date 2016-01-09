#include<iostream>
#include<stdlib.h>
#include"point.h"
#include"read.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if(argc<4)
	{
		cout<<"1.Enter the file name of data>>"<<endl;
		cout<<"2.Enter the dimention of data>>"<<endl;
		cout<<"3.Enter the amount of cluster>>"<<endl;
		return 0;
	}

	string Filename=argv[1];
	int Dimention=atoi(argv[2]);
	int AmountCluster=atoi(argv[3]);

	vector<point> data;


	read(Filename,Dimention,data);

	/*
	for(int i=0;i<data.size();i++)
	{
		cout<<data[i].getIndex()<<" ";
		vector<double> temp;
		temp=data[i].getDimention();
		for(int j=0;j<Dimention;j++)
		{
			cout<<temp[j]<<" ";
		}
		cout<<endl;
	}
	*/
}
