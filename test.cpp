#include<iostream>
#include"MinHeap.cpp"
using namespace std;
int main()
{
	int de;
	MinHeap<int> heap(20);
	heap.Insert(100);
	heap.Insert(28);
	heap.Insert(39);
	heap.Insert(47);
	heap.Insert(34);
	heap.Insert(78);
	heap.Insert(12);

	heap.Remove(2,de);
	cout << de << endl;
	heap.Insert(58);
	while(!heap.isempty())
		cout << heap.RemoveMin() << ' ';
	cout << endl;
	system("pause");
}