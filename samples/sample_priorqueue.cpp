// PriorityQueueGraphAndDijkstra’sAlgorithm.cpp: îïğåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïğèëîæåíèÿ.
//


#include "GraphAndPriorityQueue.h"




int main()
{
	
	Graph Z(5, 9);
	Z.setAE(3, 1, 0.5); Z.setAE(1, 3, 0.5);
	Z.printgraph();
	Z.Dijkstra(0);
	printf("\n");
	Z.printgraph();
	//prior_queue a(6);
	srand(time(NULL));
	int _numnodes = 0;
	int _numedges = 0;
	int _enterpoint = 0;
	printf("Hello! This is sample program for Priority queue class, Graph class and Dijkstra's algorithm\n");
	printf("Can you enter the number of nodes?\n");
	while (_numnodes <= 0)
	{
		scanf_s("%d", &_numnodes);
		if (_numnodes <= 0)
			printf("The number of nodes should be greater than 0.Try again.\n");
	}
	printf("Can you enter the numder of edges?\n");
	while (_numedges < _numnodes - 1 || _numedges >(_numnodes*(_numnodes - 1)) / 2)
	{
		scanf_s("%d", &_numedges);
		if (_numedges < _numnodes - 1 || _numedges >(_numnodes*(_numnodes - 1)) / 2)
			printf("Incorrect entry.Try again.\n");
	}
	
	Graph A(_numnodes, _numedges);
	int sw = 0;
	printf("Select the operating mode:\n");
	printf("1. Manual mode\n");
	printf("2. Random mode\n");
	scanf_s("%d", &sw);
	switch (sw)
	{
	case 1:
	{
		printf("Enter the path to graph file:\n");
		string path;
		cin >> path;
		A.reInit(path);
		printf("Source graph:\n");
		A.printgraph();
		printf("\n");
		printf("Can you enter enterpoint?\n");
		scanf_s("%d", &_enterpoint);
		while (_enterpoint < 0 || _enterpoint > _numnodes - 1)
		{
			printf("Incorrect entry.Try again.\n");
			scanf_s("%d", &_enterpoint);

		}
		printf("Result:\n");
		A.Dijkstra(_enterpoint);
		A.printgraph();
		break;
	}
	case 2:
	{
		printf("Source graph:\n");
		A.printgraph();
		printf("\n");
		printf("Can you enter enterpoint?\n");

		scanf_s("%d", &_enterpoint);
		while (_enterpoint < 0 || _enterpoint > _numnodes - 1)
		{
			printf("Incorrect entry.Try again.\n");
			scanf_s("%d", &_enterpoint);

		}
		printf("Result:\n");
		A.Dijkstra(_enterpoint);
		A.printgraph();
	}
	}
	

	return 0;
	
}

