#ifndef __KMEANS__H__
#define __KMEANS__H__

#include<iostream>
#include<vector>
#include"point.h"

using namespace std;

void Kmeans(vector<dataPoint> &data, int dimention, int amountCluster);

double distance(vector<dataPoint> &data, vector<centerPoint> &center);

void update_center(vector<dataPoint> &data, vector<centerPoint> &center, int dimention);

#endif
