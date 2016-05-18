#include "separatearray.h"
#include "GraphAndPriorityQueue.h"


separate_array::separate_array()
{
	numnodes = 1;
	nodesnames = new double[1];
}
separate_array::~separate_array()
{

	delete[] nodesnames;
}

separate_array::separate_array(int _numnodes)
{
	if (_numnodes < 1)
		throw _numnodes;
	numnodes = _numnodes;
	nodesnames = new double[numnodes];
	for (int i = 0; i < numnodes; i++)
		nodesnames[i] = 65 + i;
}

double separate_array::find(int pos)
{
	if (pos < 0)
		throw pos;
	return nodesnames[pos];
}

void separate_array::merge(int pos1, int pos2)
{
	if (pos1 < 0 || pos2 < 0)
		throw pos1;
	double spec1 = nodesnames[pos1];
	double spec2 = nodesnames[pos2];
	if (spec1 < spec2)
	{
		for (int i = 0; i < numnodes; i++)
		{
			if (nodesnames[i] == spec1)
				nodesnames[i] = spec2;
		}
	}
	else
	{
		for (int i = 0; i < numnodes; i++)
		{
			if (nodesnames[i] == spec2)
				nodesnames[i] = spec1;
		}
	}

}

void separate_array::setNN(int num, double elem)
{
	if (num > numnodes - 1 || num < 0)
		throw num;
	nodesnames[num] = elem;
}
double separate_array::getNN(int num)
{
	if (num > numnodes - 1 || num < 0)
		throw num;
	return nodesnames[num];
}
int separate_array::getNuN()
{
	return numnodes;
}