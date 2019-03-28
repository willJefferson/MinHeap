#pragma once
#include<stdlib.h>

template<class T>
class MinHeap
{
private:
	T *heapArray;
	int CurrentSize;//��ǰԪ����
	int MaxSize;//���Ԫ����
	
public:
	MinHeap(const int n);
	void BuildHeap();
	bool isempty();
	bool isLeaf(int pos)const;
	int leftchild(int pos)const;
	int rightchild(int pos)const;
	int parent(int pos)const;
	bool Remove(int pos, T &node);
	bool Insert(const T &node);
	T& RemoveMin();
	void SiftUp(int pos);
	void SiftDown(int pos);
	~MinHeap();
};

