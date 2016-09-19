// Node.h
#ifndef NODE_H
#define NODE_H

#include <vector>

struct EdNo;

struct Key{
	double k1;
	double k2;
	bool operator<(Key one){

		return (this->k1 < one.k1 || (this->k1 == one.k1 && this->k2 < one.k2));
	}
	bool operator>(Key one){

		return (this->k1 > one.k1 || (this->k1 == one.k1 && this->k2 > one.k2));
	}
};

class node {
public:
	Key k;
	int MapState;
	bool InQueue = false;
	int HeapIndex;
	double rhs = DBL_MAX;
	double g = DBL_MAX;
	std::vector<EdNo> successors;
	std::vector<EdNo> predecessors;
};

struct Edge{
	int name;
	double cost;
};

struct EdNo{
	node* next;
	Edge edge;
	//int index;
};


#endif