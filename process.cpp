#include"process.h"
#include"point.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits>

void random_initial(vector<centerPoint> &center, vector<dataPoint> &data, int amountCluster)
{
	int ran=0;

	srand((unsigned)time(NULL));
	for(int i=0;i<amountCluster;i++)
	{
		ran=rand()%data.size();
		centerPoint ini;
		ini.copyDimention(data[ran]);
		center.push_back(ini);
	}
}



double distance(vector<dataPoint> &data, vector<centerPoint> &center)
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
		dis = numeric_limits<double>::max();
	}
	return(result);
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
			center[i].addDim(dimDistance[i][j] / amount[i]);
		}
	}

}

