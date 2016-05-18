#include "GraphAndPriorityQueue.h"
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

	prior_queue::prior_queue() : DHeap<double>()
	{

	}
	prior_queue::~prior_queue()
	{

	}
	prior_queue::prior_queue(int size) : DHeap<double>(2, size)
	{

	}
	void prior_queue::insert(int _elem)
	{
		DHeap<double>::insert(_elem);
		DHeap<double>::heapfy();
	}
	void prior_queue::drop() 
	{
		DHeap<double>::drop(0);
		DHeap<double>::heapfy();// �����
		
	}
	void prior_queue::changeKey(int pos, double _newkey) // 
	{
		DHeap<double>::changeKey(pos, _newkey);


		
		
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
		DHeap<double>::heapfy();
	}

	Graph::Graph() // ����� ���
	{

		numnodes = 3;
		numedges = 0;
		adjmatrix = new double*[numnodes];
		for (int i = 0; i < numnodes; i++)
			adjmatrix[i] = new double[numnodes];
		for (int i = 0; i < numnodes; i++)
			for (int j = 0; j < numnodes; j++)
				adjmatrix[i][j] = 0;
	}

	Graph::Graph(Graph& B)
	{
		numnodes = B.numnodes;
		numedges = B.numedges;
		adjmatrix = new double*[numnodes];
		for (int i = 0; i < numnodes; i++)
			adjmatrix[i] = new double[numnodes];
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
		adjmatrix = new double*[numnodes];
		for (int i = 0; i < numnodes; i++)
			adjmatrix[i] = new double[numnodes];
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
			double weight = rand() % 9 + 1; 
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
					printf("%c ", (int)adjmatrix[i][j]);
				else
					printf("%f ", adjmatrix[i][j]);
				//if (adjmatrix[i][j] == 65 + j)
				//printf("%c ", adjmatrix[i][j]);
			}
			printf("\n");
		}

	}

	void Graph::Dijkstra(int _enterpoint)
	{
		int* previndex = new int[numnodes];
		int* specarr = new int[numnodes]; //��� ��������
		for (int i = 0; i < numnodes; i++)
			specarr[i] = i;
		int prevcounter = 0;


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
				if (a.getElem(0) == adjmatrix[i][i] && specarr[i] != -1)
				{
					if (previndex[prevcounter - 1] != i)
					{
						previndex[prevcounter] = i;
						prevcounter++;
					}
					specarr[i] = -1;
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
						if (a.getElem(j) == adjmatrix[i][i])
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
		printf("%d, ", previndex[0]);
		for (int i = 1; i < numnodes; i++)
		{
			printf("%d -> %d, ", previndex[i-1], previndex[i]);
		}
			
		printf("\n");
	}

	void Graph::reInit(string path)
	{
		string s;
		double* kek = new double[numnodes*numnodes];
		int k = 0;
		ifstream file(path);
		while (getline(file, s))
		{
				for (int i = 0; i < s.length(); i++)
					{

						if (s[i] == 'I')
						{

							kek[k] = INT_MAX;
							i += 7;
							k++;
						}
						else if (s[i] == ' ')
						{

						}
						else if (s[i] == '.')
						{
							
							string temp = "";
							temp += s[i - 1];
							
							while (s[i] != ' ' && s[i] != '\0')
							{
								temp += s[i];
								i++;
							}
							kek[k] = atof(temp.c_str());
							k++;
							
						}
						else if (s[i] == '-') 
						{
							kek[k] = -1;
							k++;
							i += 2;
						}
						else
						{
							if (s[i + 1] == '.')
							{ }
							else
							{
								kek[k] = s[i] - '0';
								k++;
							}
						}

					}
		} 
		k = 0;
	
			
		for (int i = 0; i < numnodes; i++)
		{
			for (int j = 0; j < numnodes; j++)
			{
				adjmatrix[i][j] = kek[k];
				k++;
			}
		}



		file.close();
		
	}

	double Graph::getAE(int num, int num1)
	{
		if ((num < 0 || num > numnodes - 1) || (num1 < 0 || num1 > numnodes - 1))
			throw num;
		return adjmatrix[num][num1];
	}

	int Graph::getNE()
	{
		return numedges;
	}

	int Graph::getNN()
	{
		return numnodes;
	}

	void Graph::setAE(int num, int num1, double newelem)
	{
		if ((num < 0 || num > numnodes - 1) || (num1 < 0 || num1 > numnodes - 1))
			throw num;
		adjmatrix[num][num1] = newelem;


	}