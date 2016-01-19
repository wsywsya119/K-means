#include"K-means.h"
#include"process.h"
#include<math.h>
#include<limits>

void Kmeans(vector<dataPoint> &data, int dimention, int amountCluster)
{
	vector<centerPoint> center;

	random_initial(center,data,amountCluster);


	int a=0;
	while(a!=30)
	{
		distance(data,center);
		update_center(data,center,dimention);
		++a;
	}
}

void distance(vector<dataPoint> &data, vector<centerPoint> &center)
{
	vector<double> c_temp,d_temp;
	double dis_temp = 0, dis = numeric_limits<double>::max();
	double result=0;

	for(int i=0;i<(int)data.size();i++)
	{
		d_temp = data[i].getDimention();
		for(int j=0;j<(int)center.size();j++)
		{
			c_temp = center[j].getDimention();
			for(int k=0;k<(int)c_temp.size();k++)
			{
				dis_temp = dis_temp + pow((d_temp[k] - c_temp[k]),2);
			}
			if(dis_temp < dis)
			{
				dis = dis_temp;
				data[i].setDistance(dis);
				data[i].setCluster(center[j].getIndex());
			}
			dis_temp=0;
		}
		result = result + data[i].getDistance();
		//center[data[i].getCluster()-1].addAmountDataPoint();
		dis = numeric_limits<double>::max();
	}

	cout<<result<<endl;
}

void update_center(vector<dataPoint> &data, vector<centerPoint> &center, int dimention)
{
	vector< vector<double> > dimDistance(center.size(),vector<double>(dimention,0));

	vector<int> amount(center.size(),0);

	vector<double> temp;
	
	for(int i=0;i<(int)data.size();i++)
	{
		temp = data[i].getDimention();
		++amount[data[i].getCluster()-1];
		for(int j=0;j<dimention;j++)
		{
			dimDistance[data[i].getCluster()-1][j] = dimDistance[data[i].getCluster()-1][j] + temp[j];
		}
	}
	
	
	for(int i=0;i<(int)center.size();i++)
	{
		center[i].clearDim();
		for(int j=0;j<dimention;j++)
		{
			center[i].AddDim(dimDistance[i][j] / amount[i]);
		}
	}
	

}














