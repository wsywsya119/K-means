#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include"point.h"
#include"read.h"
#include"K-means.h"

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

	vector<dataPoint> data;

	read(Filename,Dimention,data);

	cout<<setw(28)<<"========"<<setw(12)<<"K-means"<<setw(12)<<"========"<<endl;
	Kmeans(data,Dimention,AmountCluster);
	cout<<setw(28)<<"========"<<setw(12)<<"K-means"<<setw(12)<<"========"<<endl;
	
}
