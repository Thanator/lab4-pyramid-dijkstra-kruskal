#include "GraphAndPriorityQueue.h"


	prior_queue::prior_queue() : DHeap<int>()
	{

	}
	prior_queue::~prior_queue()
	{

	}
	prior_queue::prior_queue(int size) : DHeap<int>(2, size)
	{

	}
	void prior_queue::insert(int _elem)
	{
		DHeap<int>::insert(_elem);
		DHeap<int>::heapfy();
	}
	void prior_queue::drop() 
	{
		DHeap<int>::drop(0);
		DHeap<int>::heapfy();// ввели
		
	}
	void prior_queue::changeKey(int pos, int _newkey) // 
	{
		DHeap<int>::changeKey(pos, _newkey);


		
		
	}
	
	bool prior_queue::isEmpty()
	{
		if (size == 0)
			return true;
		else
		{
			return false;
		}
	}

	void prior_queue::heapfy()
	{
		DHeap<int>::heapfy();
	}

	Graph::Graph() // чтобы был
	{

		numnodes = 3;
		numedges = 0;
		adjmatrix = new int*[numnodes];
		for (int i = 0; i < numnodes; i++)
			adjmatrix[i] = new int[numnodes];
		for (int i = 0; i < numnodes; i++)
			for (int j = 0; j < numnodes; j++)
				adjmatrix[i][j] = 0;
	}

	Graph::Graph(Graph& B)
	{
		numnodes = B.numnodes;
		numedges = B.numedges;
		adjmatrix = new int*[numnodes];
		for (int i = 0; i < numnodes; i++)
			adjmatrix[i] = new int[numnodes];
		for (int i = 0; i < numnodes; i++)
			for (int j = 0; j < numnodes; j++)
				adjmatrix[i][j] = B.adjmatrix[i][j];
	}
	Graph::Graph(int _numnodes, int _numedges)
	{

		if ((_numnodes < 1)) // узлов мало, ребёр мало,рёбер много
			throw _numnodes;
		if (_numedges < _numnodes - 1)
			throw _numedges;
		double k = (_numnodes*(_numnodes - 1)) / 2;
		if (_numedges > k)
			throw _numedges;
		numnodes = _numnodes;
		adjmatrix = new int*[numnodes];
		for (int i = 0; i < numnodes; i++)
			adjmatrix[i] = new int[numnodes];
		for (int i = 0; i < numnodes; i++) // заполнили нулями
			for (int j = 0; j < numnodes; j++)
				adjmatrix[i][j] = -1;
		for (int i = 0; i < numnodes; i++) // диагонали максимумами
			adjmatrix[i][i] = INT_MAX;
		numedges = _numedges;
		std::pair<int, int> b(-1, -1); // просто инициализировал пару
		std::pair<int, int>*  tmp = new std::pair<int, int>[numedges]; // просто инициализировал массив пар( это как бы рёбра.first - начало, second - конец)
		for (int i = 0; i < numedges; i++)
		{
			tmp[i].first = -1;
			tmp[i].second = -1;
		}

		int numpair = 0;
		while (numpair != numedges) // если добавили в массив пар, то кол-во + 1
		{
			int line = -1;
			int column = -1;
			while (line == column) // обеспечили то, что запись не ведётся в диаг. элементы
			{
				line = rand() % (numnodes);   // выбираем строку и столбец, согласно матрице смежности. [0,numnodes)
				column = rand() % (numnodes);
				b.first = line;
				b.second = column;
			}// сравним полученный элемент пары, с остальными парами в массиве. Если они не равны и не обратны, то запишем нового члена
			if ((tmp[0].first == -1) && (tmp[0].second == -1)) // когда вводим первый элемент, сравнивать с предыдущими не требуется
			{
				tmp[0] = b;
				numpair += 1;
			}

			else // если требуется проверка с остальными элементами действуем по этому сценарию
			{
				int checkforadd = 0;
				for (int i = numpair - 1; i >= 0; i--)
				{
					if ((tmp[i] == b) || (b.first == tmp[i].second && b.second == tmp[i].first)) // проверяем новую пару на равенство и обратность с теми, что в массиве
						break;
					else
						checkforadd += 1;
				}
				if (checkforadd == numpair) // если новая пара прошла проверку с остальными парами, то вводим её в массив пар
				{
					tmp[numpair] = b;
					numpair++;
				}
			}


		} // пары определены. Пора выставить вес.

		for (int i = 0; i < numedges; i++) // выставляем рандомный вес от 1 до 9, согласно каждой из пар в массиве пар.
		{
			int weight = rand() % 9 + 1;
			adjmatrix[tmp[i].first][tmp[i].second] = adjmatrix[tmp[i].second][tmp[i].first] = weight;
		}
		delete[] tmp; // удаляем тмп, во избежание утечки памяти

	}

	void Graph::printgraph()
	{
		for (int i = 0; i < numnodes; i++)
		{
			for (int j = 0; j < numnodes; j++)
			{

				if (adjmatrix[i][j] == INT_MAX)
					printf("M ");
				else if (adjmatrix[i][j] > 20)
					printf("%c ", adjmatrix[i][j]);
				else
					printf("%d ", adjmatrix[i][j]);
				//if (adjmatrix[i][j] == 65 + j)
				//printf("%c ", adjmatrix[i][j]);
			}
			printf("\n");
		}

	}

	void Graph::Dijkstra(int _enterpoint)
	{
		adjmatrix[_enterpoint][_enterpoint] = 0; // задаём точку входа в граф
		prior_queue a(numnodes); // создаем приоритетную очередь
		for (int i = 0; i < numnodes; i++)
		{
			a.changeKey(i, adjmatrix[i][i]); //инициализируем приоритетную очередь

		}
		a.heapfy(); // после полной инициализации расставляем в ней элементы по приоритету(т.е по величине ключа)
		int k = 1; // элемент, необходимый для того, чтобы не вылететь за пределы очереди при её обходе.
		while (!a.isEmpty())
		{
			int numlock, numqueuelock; // элементы, в которые записывается индекс искомого элемента в очереди или хар.массиве
			for (int i = 0; i < numnodes; i++) // отлов индекса в хар. массиве
			{
				if (a.keys[0] == adjmatrix[i][i])
				{

					numlock = i;
					break;
				}
			}
			a.drop();
			for (int i = 0; i < numnodes; i++)
			{
				if (adjmatrix[numlock][numlock] + adjmatrix[numlock][i] < adjmatrix[i][i] && adjmatrix[numlock][i] != -1)
				{ // условие, при котором мы идём изменять значение ядра
					for (int j = 0; j < numnodes - k; j++) // отлов индекса в очереди
					{
						if (a.keys[j] == adjmatrix[i][i])
						{
							numqueuelock = j;
							break;
						}
					}
					adjmatrix[i][i] = adjmatrix[numlock][numlock] + adjmatrix[numlock][i]; //изменяем значение ядра
					a.changeKey(numqueuelock, adjmatrix[i][i]); //поэтому изменяем и значение очереди, соответствующее этому ядру
				}
				if (adjmatrix[numlock][i] != -1 && numlock != i)
				{
					adjmatrix[numlock][i] = adjmatrix[i][numlock] = -1; // удаление обойдённых рёбер,таким образом исключаем возврат к пройденным вершинам
				}
			}
			//a.heapfy(); //окучиваем. Минимальное значение будет на вершине очереди ??
			k++;
		}
	}