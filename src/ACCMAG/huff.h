//Function definitions for Custom logging Application
//Utilizing Huffman compression for storing logging data

#ifndef _HUFF_H_
#define _HUFF_H_

#include <string>
#include <cstdlib>

using namespace std;

class Node{
	unsigned char data;
	unsigned int freq;
	unsigned char min;
	Node* left;
	Node* right;
public:
	Node(){};
	Node(const Node &n){data = n.data; freq = n.freq; left = n.left; right = n.right;}
	Node(unsigned char d, unsigned int f): data(d), freq(f), min(d){}
	Node(Node*, Node*);
	void fill(string*,string&);
	bool operator>(const Node &);

};

class Heap{
	Node** minHeap;
	int heapSize;
public:
	Heap(){heapSize = 0; minHeap = new Node*[257];}
	void push(Node*);
	int size(){return heapSize;}
	void pop();
	Node* top(){return minHeap[1];}

};

#endif
