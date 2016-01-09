#ifndef __POINT__H__
#define __POINT__H__

#include<iostream>
#include<vector>

using namespace std;

class point{
	private:
		int index;
		vector<double> dimention;
		int cluster;
		static int amountPoint;
	public:
		point();
		int getIndex();
		vector<double> &getDimention();
		int getCluster();
		void AddDim(double in);
};

class center: public point{

};


#endif
