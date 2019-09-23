//Huffman Compression source file

#include "huff.h"
#include <iostream>
using namespace std;

void Node::fill(string* codebook, string &code){
	if(!left && !right){
		codebook[data] = code;
		return;
	}
	if(left){
		code += '0';
		left->fill(codebook, code);
		code.erase(code.end()-1);
	}
	if(right){
		code += '1';
		right->fill(codebook, code);
		code.erase(code.end()-1);
	}
}

Node::Node(Node *r,Node *l){
	freq = r->freq + l->freq;
	right = r;
	left = l;
	min = (r->min < l->min) ? r->min : l->min;

}

void Heap:: push(Node *newNode) {
    int currentHeapNode = ++heapSize;
    while (currentHeapNode != 1 && *minHeap[currentHeapNode / 2] > *newNode) {
        minHeap[currentHeapNode] = minHeap[currentHeapNode / 2];
        currentHeapNode = currentHeapNode / 2;
    }
    minHeap[currentHeapNode] = newNode;
}

void Heap:: pop(){
    Node *lastNode = minHeap[heapSize];
    minHeap [heapSize--] = minHeap[1];
    int currentHeapNode = 1;
    int child = 2;
    
    while (child <= heapSize) {
        if (child < heapSize && *minHeap[child] > *minHeap[child + 1])
            child++;

        if (*minHeap[child] > *lastNode)
            break;

        minHeap[currentHeapNode] = minHeap[child];
        currentHeapNode = child;
        child *= 2;
    } // while not at end of heap
    
    minHeap[currentHeapNode] = lastNode;
}

bool Node::operator> (const Node &rhs){
	if(freq > rhs.freq)
        	return true;
    	if(freq < rhs.freq)
        	return false;
    	if(freq == rhs.freq)
        	if(min > rhs.min)
            		return true;
    	return false;
}


