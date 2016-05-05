// Kruskal'sAlgAndSeparateArray.cpp: определ€ет точку входа дл€ консольного приложени€.
//


#include "separatearray.h"
#include "GraphAndPriorityQueue.h"

void kruskal(Graph& A)
{
	Graph B(A); // отметим на нЄм рЄбра, которые были пройдены успешно.
	separate_array sa(A.numnodes); // создали разд. мн-во
	for (int i = 0; i < A.numnodes; i++) // заполнили его числами от 65 до A.numnodes
		A.adjmatrix[i][i] = sa.nodesnames[i] = 65 + i;
	prior_queue q(A.numedges); // создали приоритетную очередь из рЄбер.
	int k = 0;
	for (int i = 0; i < A.numnodes; i++) // заполнили очередь
	{
		for (int j = 1 + i; j < A.numnodes; j++)
		{
			if (A.adjmatrix[i][j] != -1)
			{
				q.changeKey(k, A.adjmatrix[i][j]);
				k++;
			}	
		}
	}//
	q.heapfy();
	int str = -1, col = -1;
	while (!q.isEmpty()) // выполн€ем цикл до тех по пока очередь не пуста
	{
		int mark = 0;
		//int str = 0, col = 0;
		int current = q.keys[0]; // получили элемент с вершины очереди 
		q.drop();// выкинули полученный элемент из очереди
		for (int i = 0; i < A.numnodes; i++) //ищем строку и столбец элемента, который был на вершине очереди
		{
			for (int j = 1 + i; j < A.numnodes; j++) // получаем индексы current
			{
				if (A.adjmatrix[i][j] == current ) // условие успешного поиска ребра в графе
				{
					if ( B.adjmatrix[i][j] != -1) {  // если ребро не обошли, продолжаем действи€


						str = i; // строка в матрице смежности в которой находитс€ ребро
						col = j; //столбец в матрице смежности в которой находитс€ ребро
						if (sa.find(str) != sa.find(col)) // если элементы в множестве не равны, то сли€ние
						{

							sa.merge(str, col); 
						}
						else  
						{
							A.adjmatrix[str][col] = A.adjmatrix[col][str] = -1; // а если равны, то рЄбра в -1.
						}
						mark = 1; // метка выхода из внешнего цикла
						B.adjmatrix[i][j] = -1; //сбрасываем в ребро в спец.графе
						break;
					}
				}
			}
			if (mark != 0)
				break;
		} //

	}

}

int main()
{

	srand(time(NULL));
	int _numnodes = 0;
	int _numedges = 0;
	int _enterpoint = 0;
	printf("Hello! This is sample program for Separate array class and Kruskal's algorithm\n");
	printf("Select the operating mode:\n");
	printf("1: Test Mode\n");
	printf("2: Random Graph Mode\n");
	int s = 0;
	scanf_s("%d", &s);
	switch (s)
	{
	case 1: {
		Graph A(4, 6);
		A.adjmatrix[0][1] = A.adjmatrix[1][0] = 9;
		A.adjmatrix[0][2] = A.adjmatrix[2][0] = 1;
		A.adjmatrix[0][3] = A.adjmatrix[3][0] = 3;
		A.adjmatrix[1][2] = A.adjmatrix[2][1] = 5;
		A.adjmatrix[1][3] = A.adjmatrix[3][1] = 1;
		A.adjmatrix[2][3] = A.adjmatrix[3][2] = 1;
		printf("Source graph:\n");
		A.printgraph();
		printf("\n");
		printf("Minimal spanning graph:\n");
		kruskal(A);
		A.printgraph();

		break; }
	case 2: {
		printf("Can you enter the number of nodes?\n");
		scanf_s("%d", &_numnodes);
		printf("Can you enter the number of edges?\n");
		scanf_s("%d", &_numedges);
		Graph B(_numnodes, _numedges);
		printf("Source graph:\n");
		B.printgraph();
		printf("\n");
		printf("Minimal spanning graph:\n");
		kruskal(B);
		B.printgraph();
		break; }

	}


	
}

