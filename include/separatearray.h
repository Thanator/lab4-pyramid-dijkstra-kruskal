#pragma once

class separate_array
{
public:
	int* nodesnames;
	int numnodes;
public:
	separate_array();
	~separate_array();
	separate_array(int numnodes);
	void merge(int pos1, int pos2);
	int find(int pos);
};

