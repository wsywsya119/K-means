#include<iostream>
#include"point.h"

using namespace std;

point::point(){}
point::point(int i)
{
	index=i;
}

int point::getIndex()
{
	return(index);
}

void point::setIndex(int i)
{
	index=i;
}

vector<double> &point::getDimention()
{
	return(dimention);
}

void point::AddDim(double in)
{
	dimention.push_back(in);
}




int centerPoint::amountPoint=0;

centerPoint::centerPoint()
{
	++amountPoint;
	point(amountPoint);
}





int dataPoint::amountPoint=0;

dataPoint::dataPoint()
{
	++amountPoint;
	point(amountPoint);
	cluster=0;
}

int dataPoint::getCluster()
{
	return(cluster);
}
