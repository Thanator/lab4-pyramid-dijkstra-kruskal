#pragma once

class separate_array
{
protected:
	double* nodesnames;
	int numnodes;
public:
	separate_array();
	~separate_array();
	separate_array(int numnodes);
	void merge(int pos1, int pos2);
	double find(int pos);
	void setNN(int num, double elem); // реярш
	double getNN(int num); //реярш
	int getNuN(); //реярш
};

