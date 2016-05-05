// PriorityQueueGraphAndDijkstra’sAlgorithm.cpp: îïğåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïğèëîæåíèÿ.
//


#include "GraphAndPriorityQueue.h"




int main()
{
	
	//prior_queue a(6);
	srand(time(NULL));
	int _numnodes = 0;
	int _numedges = 0;
	int _enterpoint = 0;
	printf("Hello! This is sample program for Priority queue class, Graph class and Dijkstra's algorithm\n");
	printf("Can you enter the number of nodes?\n");
	scanf_s("%d", &_numnodes);
	printf("Can you enter the numder of edges?\n");
	scanf_s("%d", &_numedges);
	Graph A(_numnodes, _numedges);
	
	printf("Source graph:\n");
	A.printgraph();
	printf("\n");
	printf("Can you enter enterpoint?\n");
	
	scanf_s("%d", &_enterpoint);
	printf("Result:\n");
	A.Dijkstra(_enterpoint);
	A.printgraph();
	return 0;
	
}

