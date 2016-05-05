// dheapandpyramidsort.cpp: определяет точку входа для консольного приложения.
//


#include "dheap.h"
#include <iostream>
#include <time.h>

template <class T>
void pyramidsort(DHeap<T>& A)
{
	A.heapfy();
	int sizeA = A.size - 1;
	int sizeB = A.size;
	T *tmp = new T[sizeB];
	int n = 0;
	while (sizeA > 0)
	{
		tmp[n] = A.keys[0];
		A.transposition(A.keys[0], A.keys[sizeA]);
		A.drop(sizeA);
		sizeA -= 1;
		A.dip(0);
		n++;
	}
	tmp[n] = A.keys[0];
	for (int i = 0; i < sizeB - 1; i++)
		A.insert(0);
	for (int i = 0; i < sizeB; i++)
		A.changeKey(i, tmp[i]);

	
	delete[] tmp;

}

int main()
{
	srand(time(NULL));
	int _dim = 0;
	int _size = 0;
	printf("Hello! This is sample programm for D-heap class and pyramid sort\n");
	printf("Can you enter the dimension, please?\n");
	scanf_s("%d", &_dim);
	printf("Can you enter the size of heap, please?\n");
	scanf_s("%d", &_size);
	DHeap<int> A(_dim, _size);
	for (int i = 0; i < A.size; i++)
		A.changeKey(i, rand() % 10 + 0);
	A.heapfy();
	printf("It's your array of heap without sorting\n");
	A.printHeap();
	printf("\n");
	pyramidsort(A);
	printf("It's your array of heap after sorting\n");
	A.printHeap();

    return 0;
}

