#pragma once
#include <limits.h>
#include <iostream>
#include <time.h> 
#include "dheap.h"
#include <stdio.h>
#include <string>
using namespace std;



class prior_queue : public DHeap<double>//
{
public:
	prior_queue();
	~prior_queue();
	prior_queue(int size);
	void insert(int _elem);
	void drop();
	void changeKey(int pos, double _newkey);//
	bool isEmpty();
	void heapfy();

};

class Graph
{
protected:
	double** adjmatrix;//
	int numnodes;
	int numedges;
public:
	Graph();
	Graph(Graph& B);
	Graph(int _numnodes, int _numedges);
	void printgraph();
	void Dijkstra(int _enterpoint);
	void reInit(string path); // инициализация графа из файла
	double getAE(int num, int num1); // ТЕСТЫ
	int getNN(); // ТЕСТЫ
	int getNE(); // ТЕСТЫ
	void setAE(int num, int num1, double newelem);// ТЕСТЫ
	int GetMin(int num, Graph B);

};

