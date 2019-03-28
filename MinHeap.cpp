#include "MinHeap.h"

template<class T>
void MinHeap<T>::BuildHeap()
{
	for (int i = CurrentSize / 2 - 1; i >= 0; --i)
		SiftDown(i);
}

template<class T>
MinHeap<T>::MinHeap(const int n)
{
	MaxSize = n;
	heapArray = new T[n];
	CurrentSize = 0;
}

template<class T>
bool MinHeap<T>::isempty()
{
	if (CurrentSize == 0)
		return true;
	return false;
}

template<class T>
bool MinHeap<T>::isLeaf(int pos) const
{
	if (pos > (CurrentSize-1) / pos)
		return true;
	return false;
}

template<class T>
int MinHeap<T>::leftchild(int pos) const
{
	if (2 * pos + 1 <= (CurrentSize-1))
		return 2 * pos + 1;
	return 0;
}

template<class T>
int MinHeap<T>::rightchild(int pos) const
{
	if (2 * pos + 2 <= (CurrentSize-1))
		return 2 * pos + 2;
	return 0;
}

template<class T>
int MinHeap<T>::parent(int pos) const
{
	if (pos&&CurrentSize > 0)
		return (pos-1) / 2;
	return 0;
}

template<class T>
bool MinHeap<T>::Remove(int pos, T & node)
{
	if (pos > CurrentSize - 1 || pos < 0)
		return false;
	T temp = heapArray[pos];
	heapArray[pos] = heapArray[--CurrentSize];
	if (heapArray[parent(pos)] > heapArray[pos])
		SiftUp(pos);
	else
		SiftDown(pos);
	node = temp;
	return true;
}

template<class T>
bool MinHeap<T>::Insert(const T & node)
{
	if (CurrentSize == MaxSize)
		return false;
	heapArray[CurrentSize] = node;
	SiftUp(CurrentSize);
	CurrentSize++;
	return true;
}

template<class T>
T & MinHeap<T>::RemoveMin()
{
	T temp = NULL;
	if(CurrentSize>0)
		Remove(0, temp);
	return temp;
	// TODO: 在此处插入 return 语句
}


template<class T>
void MinHeap<T>::SiftUp(int pos)
{
	int i = pos;
	T temp = heapArray[i];
	while (i > 0 && heapArray[parent(i)] > temp)
	{
		heapArray[i] = heapArray[parent(i)];
		i = parent(i);
	}
	heapArray[i] = temp;
}

template<class T>
void MinHeap<T>::SiftDown(int pos)
{
	int i = pos;
	int j = 2 * i + 1;//子节点
	T temp = heapArray[i];//父节点
	while (j < CurrentSize)
	{
		if((j<CurrentSize-1)&&(heapArray[j]>heapArray[j+1]))//指向左右子节点中较小的
			++j;
		if (temp > heapArray[j])
		{
			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;
		}
		else
			break;
	}
	heapArray[i] = temp;
}

template<class T>
MinHeap<T>::~MinHeap()
{
	delete[]heapArray;
}
