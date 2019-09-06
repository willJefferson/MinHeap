#pragma once
#include<stdlib.h>

/*
 * 写模板函数或模板类时，头文件和cpp文件不能分离，
 * 就是说你头文件里有模板的函数必须在头文件里实现，
 * 或者是分离，调用时用 #include "minheap.cpp"
 * */

template<class T>
class MinHeap
{
private:
	T *heapArray;
	int CurrentSize;//µ±Ç°ÔªËØÊý
	int MaxSize;//×î´óÔªËØÊý
	
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

