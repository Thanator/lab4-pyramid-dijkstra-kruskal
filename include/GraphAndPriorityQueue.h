#pragma once
#include <limits.h>
#include <iostream>
#include <time.h> 
#include "dheap.h"



class prior_queue : public DHeap<int>
{
public:
	prior_queue();
	~prior_queue();
	prior_queue(int size);
	void insert(int _elem);
	void drop();
	void changeKey(int pos, int _newkey);
	bool isEmpty();
	void heapfy();

};

class Graph
{
public:
	int** adjmatrix;
	int numnodes;
	int numedges;
public:
	Graph();
	Graph(Graph& B);
	Graph(int _numnodes, int _numedges);
	void printgraph();
	void Dijkstra(int _enterpoint);

};

