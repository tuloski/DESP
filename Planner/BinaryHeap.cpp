//BinaryHeap.cpp

#include "BinaryHeap.h"
#include <iostream>

/*
* Return Heap Size
*/
int BinaryHeap::Size()
{
	return heap.size();
}

/*
* Resize Heap
*/
void BinaryHeap::Resize(int sz)
{
	heap.resize(sz);
}

/*
* Insert Element into a Heap
*/
void BinaryHeap::Insert(node* element)
{
	heap.push_back(element);
	element->HeapIndex = (heap.size() - 1);
	element->InQueue = true;
	heapifyup(heap.size() - 1);
}
/*
* Update a vertex key
*/
void BinaryHeap::Update(Key knew, int index)
{
	if (heap.size() == 0)
	{
		std::cout << "Heap is Empty" << std::endl;
		return;
	}
	if (knew > heap[index]->k){
		heap[index]->k = knew;
		heapifydown(index);
	}
	if (knew > heap[index]->k){
		heap[index]->k = knew;
		heapifyup(index);
	}
}

/*
* Remove a vertex from the heap
*/
void BinaryHeap::RemoveV(int index)
{
	if (heap.size() == 0)
	{
		std::cout << "Heap is Empty" << std::endl;
		return;
	}
	heap[index]->InQueue = false;			//sets node that is to be removed as non in queue
	if (heap.size() - 1 != 0){
		heap[index] = heap[heap.size() - 1];    //deletes the node by overwriting on it the last element
		heap[index]->HeapIndex = index;      //sets the equivalent heap index of the moved node to "index"
	}
	heap.pop_back();                      //pops the last useless element
	if (heap.size() - 1 != 0)
		heapifydown(index);						//moves the node at position "index" down the tree until the heap-property is satisfied
}

/*
* Delete Minimum Element
*/
void BinaryHeap::DeleteMin()
{
	if (heap.size() == 0)
	{
		std::cout << "Heap is Empty" << std::endl;
		return;
	}
	heap[0]->InQueue = false;			//sets node that is the min as non in queue
	heap[0] = heap[heap.size() - 1];    //deletes the min by overwriting on it the last element
	heap[0]->HeapIndex = 0;				//sets the equivalent heap index of the moved node to 0
	heap.pop_back();					//pops the last useless element
	heapifydown(0);						//moves the node at position 0 down the tree until the heap-property is satisfied
}

/*
* Extract Minimum Element
*/
node* BinaryHeap::ExtractMin()
{
	if (heap.size() == 0)
	{
		std::cout << "Heap is Empty" << std::endl;
		return nullptr;
	}
	else
		return heap.front();
}

/*
* Return Left Child
*/
int BinaryHeap::left(int parent)
{
	unsigned int l = 2 * parent + 1;
	if (l < heap.size())
		return l;
	else
		return -1;
}

/*
* Return Right Child
*/
int BinaryHeap::right(int parent)
{
	unsigned int r = 2 * parent + 2;
	if (r < heap.size())
		return r;
	else
		return -1;
}

/*
* Return Parent
*/
int BinaryHeap::parent(int child)
{
	int p = (child - 1) / 2;
	if (child == 0)
		return -1;
	else
		return p;
}

/*
* Heapify- Maintain Heap Structure bottom up
*/
void BinaryHeap::heapifyup(int in)
{
	if (in >= 0 && parent(in) >= 0 && heap[parent(in)]->k > heap[in]->k)
	{
		node* temp = heap[in];
		heap[in] = heap[parent(in)];
		heap[in]->HeapIndex = in;
		heap[parent(in)] = temp;
		heap[parent(in)]->HeapIndex = parent(in);
		heapifyup(parent(in));
	}
}

/*
* Heapify- Maintain Heap Structure top down
*/
void BinaryHeap::heapifydown(int in)
{

	int child = left(in);
	int child1 = right(in);
	if (child >= 0 && child1 >= 0 && heap[child]->k > heap[child1]->k)
	{
		child = child1;
	}
	if (child > 0 && heap[in]->k > heap[child]->k)
	{
		node* temp = heap[in];
		heap[in] = heap[child];
		heap[in]->HeapIndex = in;
		heap[child] = temp;
		heap[child]->HeapIndex = child;
		heapifydown(child);
	}
}