// BinaryHeap.h
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include "Node.h"

class BinaryHeap
{
private:
	std::vector <node*> heap;
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyup(int index);
	void heapifydown(int index);
public:
	BinaryHeap()
	{}
	void Insert(node* element);
	void DeleteMin();
	void Resize(int sz);
	void RemoveV(int index);
	void Update(Key knew, int index);
	node* ExtractMin();
	int Size();
};

#endif