// Kruskal'sAlgAndSeparateArray.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "separatearray.h"
#include "GraphAndPriorityQueue.h"

void kruskal(Graph& A)
{
	Graph B(A); // ������� �� �� ����, ������� ���� �������� �������.
	separate_array sa(A.getNN()); // ������� ����. ��-��
	for (int i = 0; i < A.getNN(); i++) // ��������� ��� ������� �� 65 �� A.numnodes
	{
		A.setAE(i, i, 65 + i);
		sa.setNN(i, 65 + i);
	}
		
	prior_queue q(A.getNE()); // ������� ������������ ������� �� ����.
	int k = 0;
	for (int i = 0; i < A.getNN(); i++) // ��������� �������
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
	while (!q.isEmpty()) // ��������� ���� �� ��� �� ���� ������� �� �����
	{
		int mark = 0;
		//int str = 0, col = 0;
		double current = q.getElem(0); // �������� ������� � ������� ������� 
		q.drop();// �������� ���������� ������� �� �������
		for (int i = 0; i < A.getNN(); i++) //���� ������ � ������� ��������, ������� ��� �� ������� �������
		{
			for (int j = 1 + i; j < A.getNN(); j++) // �������� ������� current
			{
				if (A.getAE(i,j) == current ) // ������� ��������� ������ ����� � �����
				{
					if ( B.getAE(i, j) != -1) {  // ���� ����� �� ������, ���������� ��������


						str = i; // ������ � ������� ��������� � ������� ��������� �����
						col = j; //������� � ������� ��������� � ������� ��������� �����
						if (sa.find(str) != sa.find(col)) // ���� �������� � ��������� �� �����, �� �������
						{

							sa.merge(str, col); 
						}
						else  
						{
							 // � ���� �����, �� ���� � -1.
							A.setAE(str, col, -1); A.setAE(col, str, -1);
						}
						mark = 1; // ����� ������ �� �������� �����
						B.setAE(i,j,-1); //���������� � ����� � ����.�����
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

