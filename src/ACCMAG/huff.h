//Function definitions for Custom logging Application
//Utilizing Huffman compression for storing logging data

#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <fstream>
#include <unordered_map>

#ifndef _HUFF_H_
#define _HUFF_H_

//Node structure for building the HuffmanTree
struct HuffmanNode{

	char data;

	unsigned freq;

	std::shared_ptr<HuffmanNode> left;

	std::shared_ptr<HuffmanNode> right;

	HuffmanNode(char data, unsigned freq){

		this->data = data;
		this->freq = freq;
	}

};

//For comparison of two heap nodes
struct compare{

	bool operator()(std::shared_ptr<HuffmanNode> l, std::shared_ptr<HuffmanNode> r){

		return(l->freq > r->freq);
	}
};

//HuffmanTree class
class HuffmanTree{

private:

	//Priority queue for building the tree
	std::priority_queue<std::shared_ptr<HuffmanNode>, std::vector<std::shared_ptr<HuffmanNode>>, compare> minHeap;

public:

	//Default empty
	HuffmanTree();
	//Default with intialisation values from unordered_map
	HuffmanTree(std::unordered_map<char,int> table);
	//Copy constructor
	HuffmanTree(const HuffmanTree & H);
	//Move constructor
	HuffmanTree(HuffmanTree && H);
	//Destructor
	~HuffmanTree();


	//Copy operator override
	HuffmanTree& operator=(const HuffmanTree &H);

	//Move operator override
	HuffmanTree& operator=(HuffmanTree &&H);

	//Checking state of tree
	bool isempty();

	//Generates the code table for the tree
	std::unordered_map<char , std::string > code();

};

#endif
