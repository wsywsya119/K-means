#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include"read.h"

using namespace std;

void read(string filename, vector<point> &data)
{
	ifstream input;
	string line;

	input.open(filename.c_str(),ifstream::in);

	int Dim=0;
	while(getline(input,line))
	{
		
		istringstream token(line);
		string word;

		point initial;
		while(getline(token,word,','))
		{
			//cout<<word<<endl;
			initial.AddDim(atof(word.c_str()));
			//data[DataPoint].AddDim(atof(word.c_str()));
			++Dim;
			if(Dim==4)break;
		}
		data.push_back(initial);

		Dim=0;
		//cout<<endl;
		
	}


	input.close();
}
