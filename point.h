#ifndef __POINT__H__
#define __POINT__H__

#include<iostream>
#include<vector>

using namespace std;

class point{
	private:
		int index;
		vector<double> dimention;
	public:
		point();
		point(int i);
		int getIndex();
		void setIndex(int i);
		vector<double> &getDimention();
		void AddDim(double in);
};

class centerPoint: public point{
	private:
		static int amountPoint;
	public:
		centerPoint();
};

class dataPoint: public point{
	private:
		static int amountPoint;
		int cluster;
		double distance;
	public:
		dataPoint();
		int getCluster();
};


#endif
