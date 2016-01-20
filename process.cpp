#include"process.h"
#include"point.h"
#include<stdlib.h>
#include<time.h>

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
