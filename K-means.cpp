#include"K-means.h"
#include"process.h"

void Kmeans(vector<dataPoint> &data, int dimention, int amountCluster)
{
	vector<centerPoint> center;

	random_initial(center,data,amountCluster);

	double result=0,last=0;

	while(1)
	{
		result = distance(data,center);
		update_center(data,center,dimention);
		if(last!=result)
		{	
			last = result;
		}
		else
		{
			break;
		}
		cout<<result<<endl;
	}
}















