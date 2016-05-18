// Kruskal'sAlgAndSeparateArray.cpp: определ€ет точку входа дл€ консольного приложени€.
//


#include "separatearray.h"
#include "GraphAndPriorityQueue.h"

void kruskal(Graph& A)
{
	Graph B(A); // отметим на нЄм рЄбра, которые были пройдены успешно.
	separate_array sa(A.getNN()); // создали разд. мн-во
	for (int i = 0; i < A.getNN(); i++) // заполнили его числами от 65 до A.numnodes
	{
		A.setAE(i, i, 65 + i);
		sa.setNN(i, 65 + i);
	}
		
	prior_queue q(A.getNE()); // создали приоритетную очередь из рЄбер.
	int k = 0;
	for (int i = 0; i < A.getNN(); i++) // заполнили очередь
	{
		for (int j = 1 + i; j < A.getNN(); j++)
		{
			if (A.getAE(i,j) != -1)
			{
				q.changeKey(k, A.getAE(i, j));
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
		double current = q.getElem(0); // получили элемент с вершины очереди 
		q.drop();// выкинули полученный элемент из очереди
		for (int i = 0; i < A.getNN(); i++) //ищем строку и столбец элемента, который был на вершине очереди
		{
			for (int j = 1 + i; j < A.getNN(); j++) // получаем индексы current
			{
				if (A.getAE(i,j) == current ) // условие успешного поиска ребра в графе
				{
					if ( B.getAE(i, j) != -1) {  // если ребро не обошли, продолжаем действи€


						str = i; // строка в матрице смежности в которой находитс€ ребро
						col = j; //столбец в матрице смежности в которой находитс€ ребро
						if (sa.find(str) != sa.find(col)) // если элементы в множестве не равны, то сли€ние
						{

							sa.merge(str, col); 
						}
						else  
						{
							 // а если равны, то рЄбра в -1.
							A.setAE(str, col, -1); A.setAE(col, str, -1);
						}
						mark = 1; // метка выхода из внешнего цикла
						B.setAE(i,j,-1); //сбрасываем в ребро в спец.графе
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
	printf("1: Manual Mode\n");
	printf("2: Random Graph Mode\n");
	int s = 0;
	scanf_s("%d", &s);
	switch (s)
	{
	case 1: {
		Graph A(5, 7);
		string path;
		cin >> path;
		A.reInit(path);
		printf("Source graph:\n");
		A.printgraph();
		printf("\n");
		printf("Minimal spanning graph:\n");
		kruskal(A);
		A.printgraph();

		break; }
	case 2: {
		printf("Can you enter the number of nodes?\n");
		while (_numnodes <= 0)
		{
			scanf_s("%d", &_numnodes);
			if (_numnodes <= 0)
				printf("The number of nodes should be greater than 0.Try again.\n");
		}
		printf("Can you enter the number of edges?\n");
		while (_numedges < _numnodes - 1 || _numedges >(_numnodes*(_numnodes - 1)) / 2)
		{
			scanf_s("%d", &_numedges);
			if (_numedges < _numnodes - 1 || _numedges >(_numnodes*(_numnodes - 1)) / 2)
				printf("Incorrect entry.Try again.\n");
		}
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

