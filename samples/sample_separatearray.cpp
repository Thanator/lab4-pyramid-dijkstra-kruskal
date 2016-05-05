// Kruskal'sAlgAndSeparateArray.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "separatearray.h"
#include "GraphAndPriorityQueue.h"

void kruskal(Graph& A)
{
	Graph B(A); // ������� �� �� ����, ������� ���� �������� �������.
	separate_array sa(A.numnodes); // ������� ����. ��-��
	for (int i = 0; i < A.numnodes; i++) // ��������� ��� ������� �� 65 �� A.numnodes
		A.adjmatrix[i][i] = sa.nodesnames[i] = 65 + i;
	prior_queue q(A.numedges); // ������� ������������ ������� �� ����.
	int k = 0;
	for (int i = 0; i < A.numnodes; i++) // ��������� �������
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
	while (!q.isEmpty()) // ��������� ���� �� ��� �� ���� ������� �� �����
	{
		int mark = 0;
		//int str = 0, col = 0;
		int current = q.keys[0]; // �������� ������� � ������� ������� 
		q.drop();// �������� ���������� ������� �� �������
		for (int i = 0; i < A.numnodes; i++) //���� ������ � ������� ��������, ������� ��� �� ������� �������
		{
			for (int j = 1 + i; j < A.numnodes; j++) // �������� ������� current
			{
				if (A.adjmatrix[i][j] == current ) // ������� ��������� ������ ����� � �����
				{
					if ( B.adjmatrix[i][j] != -1) {  // ���� ����� �� ������, ���������� ��������


						str = i; // ������ � ������� ��������� � ������� ��������� �����
						col = j; //������� � ������� ��������� � ������� ��������� �����
						if (sa.find(str) != sa.find(col)) // ���� �������� � ��������� �� �����, �� �������
						{

							sa.merge(str, col); 
						}
						else  
						{
							A.adjmatrix[str][col] = A.adjmatrix[col][str] = -1; // � ���� �����, �� ���� � -1.
						}
						mark = 1; // ����� ������ �� �������� �����
						B.adjmatrix[i][j] = -1; //���������� � ����� � ����.�����
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

