#pragma once
template <class T>
class DHeap
{
protected:
	int dim;
	int size;
	T* keys;
public:
	DHeap();
	DHeap(const DHeap& a);
	DHeap(int _dim, int _size);
	~DHeap();
	void insert(T _key);
	void drop(int pos);
	void transposition(T& pos1, T& pos2);
	void dip(int pos);
	void pop(int pos);
	int minchild(int pos);
	void printHeap();
	void changeKey(int pos, T _newkey);
	void heapfy();
	int getSize(); // ТЕСТЫ
	T& getElem(int num); // от нуля до сайз ТЕСТЫ
};

template <class T>
DHeap<T>::DHeap() // создаст корень кучи с размерностью 2;
{
	dim = 2;
	size = 1;
	keys = new T[size];
	keys[0] = 0;
	
}

template <class T>
DHeap<T>::DHeap(const DHeap<T>& a)
{
	
	dim = a.dim;
	size = a.size;
	keys = new T[size];
	for (int i = 0; i < size; i++)
		keys[i] = a.keys[i];
}

template <class T>
DHeap<T>::DHeap(int _dim, int _size) // инициализация нулями
{
	if (_dim < 1 || _size < 1)
		throw _dim;
	dim = _dim;
	size = _size;
	keys = new T[size];
	for (int i = 0; i < size; i++)
		keys[i] = 0;

}
template <class T>
DHeap<T>::~DHeap()
{
	delete[] keys;
}

template <class T>
void DHeap<T>::insert(T _key)// 
{
	T* tmp = new T[size];
	for (int i = 0; i < size; i++)
		tmp[i] = keys[i];
	size += 1;
	delete[] keys;
	keys = new T[size];
	for (int i = 0; i < size - 1; i++)
		keys[i] = tmp[i];
	keys[size-1] = _key;
	pop(size-1);
	delete[] tmp;

}

template <class T>
void DHeap<T>::transposition(T& key1, T& key2) // защита должна быть
{

	T tmp;
	tmp = key1;
	key1 = key2;
	key2 = tmp;
}


template <class T>
void DHeap<T>::pop(int pos)
{
	if (pos < 0 || pos >= size)
		throw pos;
	int dad = (pos - 1)/dim;
	while ((pos != 0) && (keys[pos] < keys[dad]))
	{
		transposition(keys[pos], keys[dad]);
		pos = dad;
		dad = (pos - 1) / dim;
	}
}

template <class T>
int DHeap<T>::minchild(int pos)
{
	if ((pos >= size) || (pos < 0)) 
		throw pos;
	if ((pos*dim + 1) >= size)
		return 0;
	int st = pos*dim + 1;
	int fn = dim*(pos + 1);
	if (fn >= size)
		fn = size - 1;
	T min_key = keys[st];
	for (int i = st + 1; i <= fn; i++)
	{
		if (min_key > keys[i])
		{
			min_key = keys[i];
			st = i;
		}
	}
	return st;
}

template <class T>
void DHeap<T>::dip(int pos)
{
	if ((pos >= size) || (pos < 0))
		throw pos;
	int min = minchild(pos);
	while ((keys[pos] > keys[min]) && (min != 0))
	{
		transposition(keys[pos], keys[min]);
		pos = min;
		min = minchild(pos);
	}
}

template <class T>
void DHeap<T>::drop(int pos) 
{
	if (pos >= size || pos < 0)
		throw pos;
	int last = size - 1; 
	transposition(keys[last], keys[pos]);
	T* tmp = new T[size - 1];
	for (int i = 0; i < size - 1; i++)
		tmp[i] = keys[i];
	delete[] keys;
	size -= 1;
	keys = new T[size];
	for (int i = 0; i < size; i++)
		keys[i] = tmp[i];
	if (keys[pos] == keys[last]) 
	{

	}
	else if (pos != 0 && keys[pos] < keys[((pos - 1)/dim)]) 
		pop(pos);
	else
		dip(pos);
	delete[] tmp;

}

template <class T>
void DHeap<T>::printHeap()
{
	for (int i = 0; i < size; i++)
		printf("%d ", keys[i]);
}

template <class T>
void DHeap<T>::changeKey(int pos, T _newkey)
{
	if (pos >= size || pos < 0)
		throw pos;
	keys[pos] = _newkey;
}

template <class T>
void DHeap<T>::heapfy()
{
	for (int i = size - 1; i >= 0; i--)
		dip(i);
}

template <class T>
int DHeap<T>::getSize()
{
	return size;
}

template <class T>
T& DHeap<T>::getElem(int num)
{
	if (num<0 || num > size - 1)
		throw num;
	return keys[num];
}









