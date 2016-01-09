#include<iostream>
#include"point.h"

using namespace std;

int point::amountPoint=0;

point::point()
{
	++amountPoint;
	index=amountPoint;
	cluster=0;
}

int point::getIndex()
{
	return(index);
}

vector<double> &point::getDimention()
{
	return(dimention);
}

int point::getCluster()
{
	return(cluster);
}

void point::AddDim(double in)
{
	dimention.push_back(in);
}
