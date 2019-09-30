//Logging function utilising huffman algorithm for compression

#include "clogger.h"

using namespace std;

unsigned int freqs[256] = {0};
string codebook[256];
string codebook2[256];

void clogger(string filename, rawData_t* data, sensorValue_t* processed){

	ofstream logfile;
	logfile.open(filename+".txt");
	logfile << "Raw Data \n";
	logfile << "x: "<< data->x <<"\n";
	logfile << "y: "<< data->y <<"\n";
	logfile << "z: "<< data->z <<"\n";
	logfile << "Processed Data \n";
	logfile << "x: "<< processed->x <<"\n";
	logfile << "y: "<< processed->y <<"\n";
	logfile << "z: "<< processed->z <<"\n";
	logfile.close();

}

void compress(string filename){

	ifstream filein(filename+".txt");
    	unsigned char nextChar;
    	// first, calculate the frequencies of each character
	if(filein.is_open()){
    		filein >> noskipws;
    		while(filein >> nextChar){
        		freqs[nextChar]++;
		}
	}
	filein.close();

    	Node * root = constructHeap();
    	string code;
    	root->fill(codebook,code);

    	putOut(filename,filename+"_compressed");
}

void putOut(string fileinput,string fileoutput){

	ofstream fileout(fileoutput+".txt");
	if(fileout.is_open()){
    		fileout<< "HUFFMA3" << '\0';

    		unsigned int i;
    		for(i = 0; i < 256; i++){
        		fileout<<(char) (0x000000ff & freqs[i]);
        		fileout<<(char) ((0x0000ff00 & freqs[i]) >> 8);
        		fileout<<(char) ((0x00ff0000 & freqs[i]) >> 16);
        		fileout<<(char) ((0xff000000 & freqs[i]) >> 24);
    		}

    		unsigned char nextChar;
    		char nextByte = 0;
    		int bitCounter = 0;

		ifstream filein(fileinput+".txt");
		if(filein.is_open()){

    			filein.seekg(0);
    			filein >> noskipws;
    			while(filein >> nextChar){
        			for(i = 0; i < codebook[nextChar].size(); i++, bitCounter++){
            				if(bitCounter == 8){
                				fileout<< nextByte;
                				nextByte = 0;
                				bitCounter = 0;
            				}
            				if(codebook[nextChar][i] == '1'){
                				nextByte = nextByte | (0x01 << bitCounter);
					}
        			}
    			}
    			if(bitCounter){
        			fileout << nextByte;
			}
		}
		filein.close();
	}
	fileout.close();
}

void decompress(string filename){
	cout<<"ok"<<endl;

	ifstream filein(filename+".txt",ios::binary);

	if(filein.is_open()){

    		filein >> noskipws;
    		char magic[8];
    		filein.get(magic,7);
    		char nextByte;

    		for(int i = 0; i < 256; i++){
        		filein.get((char *)&freqs[i],4);
    		}

    		Node * root2 = constructHeap();
    		string code2;
    		root2->fill(codebook2,code2);
		cout << "ok2" <<endl;

		ofstream fileout(filename+"_uncompressed.txt");
		
		if(fileout.is_open()){
			/*
    			while(filein>>nextByte){
        			for(int i = 0; i < 8; i++){
            				if((nextByte >> i) & 0x01){
                				code += '1';
					}
            				else{
                				code += '0';
					}
            				for(int i = 0; i < 256; i++){
                				if(codebook[i] == code){
                    					if(freqs[i]){
                              					fileout << (unsigned char) i;
                              					code.clear();
                              					freqs[i]--;
                              					break;
                    					}
                    					else{
                        					return;
							}
                				}
            				} // for 2
        			}// for 1
    			}// while*/
		}

	}
}

Node * constructHeap(){
    Heap minHeap;
    Node *nextNode;
    for(int i = 0; i < 256; i++){
        if (freqs[i]){
            nextNode = new Node(i, freqs[i]);
            minHeap.push(nextNode);
        }
    }

    Node * node1;
    Node * node2;
    Node * merged;
    while(minHeap.size() > 1){
        node1 = minHeap.top();
        minHeap.pop();
        node2 = minHeap.top();
        minHeap.pop();
        merged = new Node(node1, node2);
        minHeap.push(merged);
    }

    return minHeap.top();
}
