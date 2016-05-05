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
		DHeap<int>::heapfy();// �����
		
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

	Graph::Graph() // ����� ���
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

		if ((_numnodes < 1)) // ����� ����, ���� ����,���� �����
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
		for (int i = 0; i < numnodes; i++) // ��������� ������
			for (int j = 0; j < numnodes; j++)
				adjmatrix[i][j] = -1;
		for (int i = 0; i < numnodes; i++) // ��������� �����������
			adjmatrix[i][i] = INT_MAX;
		numedges = _numedges;
		std::pair<int, int> b(-1, -1); // ������ ��������������� ����
		std::pair<int, int>*  tmp = new std::pair<int, int>[numedges]; // ������ ��������������� ������ ���( ��� ��� �� ����.first - ������, second - �����)
		for (int i = 0; i < numedges; i++)
		{
			tmp[i].first = -1;
			tmp[i].second = -1;
		}

		int numpair = 0;
		while (numpair != numedges) // ���� �������� � ������ ���, �� ���-�� + 1
		{
			int line = -1;
			int column = -1;
			while (line == column) // ���������� ��, ��� ������ �� ������ � ����. ��������
			{
				line = rand() % (numnodes);   // �������� ������ � �������, �������� ������� ���������. [0,numnodes)
				column = rand() % (numnodes);
				b.first = line;
				b.second = column;
			}// ������� ���������� ������� ����, � ���������� ������ � �������. ���� ��� �� ����� � �� �������, �� ������� ������ �����
			if ((tmp[0].first == -1) && (tmp[0].second == -1)) // ����� ������ ������ �������, ���������� � ����������� �� ���������
			{
				tmp[0] = b;
				numpair += 1;
			}

			else // ���� ��������� �������� � ���������� ���������� ��������� �� ����� ��������
			{
				int checkforadd = 0;
				for (int i = numpair - 1; i >= 0; i--)
				{
					if ((tmp[i] == b) || (b.first == tmp[i].second && b.second == tmp[i].first)) // ��������� ����� ���� �� ��������� � ���������� � ����, ��� � �������
						break;
					else
						checkforadd += 1;
				}
				if (checkforadd == numpair) // ���� ����� ���� ������ �������� � ���������� ������, �� ������ � � ������ ���
				{
					tmp[numpair] = b;
					numpair++;
				}
			}


		} // ���� ����������. ���� ��������� ���.

		for (int i = 0; i < numedges; i++) // ���������� ��������� ��� �� 1 �� 9, �������� ������ �� ��� � ������� ���.
		{
			int weight = rand() % 9 + 1;
			adjmatrix[tmp[i].first][tmp[i].second] = adjmatrix[tmp[i].second][tmp[i].first] = weight;
		}
		delete[] tmp; // ������� ���, �� ��������� ������ ������

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
		adjmatrix[_enterpoint][_enterpoint] = 0; // ����� ����� ����� � ����
		prior_queue a(numnodes); // ������� ������������ �������
		for (int i = 0; i < numnodes; i++)
		{
			a.changeKey(i, adjmatrix[i][i]); //�������������� ������������ �������

		}
		a.heapfy(); // ����� ������ ������������� ����������� � ��� �������� �� ����������(�.� �� �������� �����)
		int k = 1; // �������, ����������� ��� ����, ����� �� �������� �� ������� ������� ��� � ������.
		while (!a.isEmpty())
		{
			int numlock, numqueuelock; // ��������, � ������� ������������ ������ �������� �������� � ������� ��� ���.�������
			for (int i = 0; i < numnodes; i++) // ����� ������� � ���. �������
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
				{ // �������, ��� ������� �� ��� �������� �������� ����
					for (int j = 0; j < numnodes - k; j++) // ����� ������� � �������
					{
						if (a.keys[j] == adjmatrix[i][i])
						{
							numqueuelock = j;
							break;
						}
					}
					adjmatrix[i][i] = adjmatrix[numlock][numlock] + adjmatrix[numlock][i]; //�������� �������� ����
					a.changeKey(numqueuelock, adjmatrix[i][i]); //������� �������� � �������� �������, ��������������� ����� ����
				}
				if (adjmatrix[numlock][i] != -1 && numlock != i)
				{
					adjmatrix[numlock][i] = adjmatrix[i][numlock] = -1; // �������� ��������� ����,����� ������� ��������� ������� � ���������� ��������
				}
			}
			//a.heapfy(); //���������. ����������� �������� ����� �� ������� ������� ??
			k++;
		}
	}