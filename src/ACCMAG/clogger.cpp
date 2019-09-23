//Logging application

#include "clogger.h"

using namespace std;

void clogger(string filename, rawData_t* data, sensorValue_t* processed){

}

void compress(){
    unsigned char nextChar;
    // first, calculate the frequencies of each character
    cin >> noskipws;
    while(cin >> nextChar)
        freqs[nextChar]++;

    Node * root = constructHeap();
    string code;
    root->fill(codebook,code);

    putOut();
}

void putOut(){
    cout<< "HUFFMA3" << '\0';

    unsigned int i;
    for(i = 0; i < 256; i++){
        cout<<(char) (0x000000ff & freqs[i]);
        cout<<(char) ((0x0000ff00 & freqs[i]) >> 8);
        cout<<(char) ((0x00ff0000 & freqs[i]) >> 16);
        cout<<(char) ((0xff000000 & freqs[i]) >> 24);
    }

    unsigned char nextChar;
    char nextByte = 0;
    int bitCounter = 0;

    cin.clear();
    cin.seekg(0);
    cin >> noskipws;
    while(cin >> nextChar){
        for(i = 0; i < codebook[nextChar].size(); i++, bitCounter++){
            if(bitCounter == 8){
                cout<< nextByte;
                nextByte = 0;
                bitCounter = 0;
            }
            if(codebook[nextChar][i] == '1')
                nextByte = nextByte | (0x01 << bitCounter);
        }
    }
    if(bitCounter)
        cout << nextByte;
}

void decompress(){
    cin >> noskipws;
    char magic[8];
    cin.read(magic,8);
    char nextByte;
    for(int i = 0; i < 256; i++){
        cin.read((char *)&freqs[i],4);
    }

    Node * root = constructHeap();
    string code;
    root->fill(codebook,code);

    while(cin>>nextByte){
        for(int i = 0; i < 8; i++){
            if((nextByte >> i) & 0x01)
                code += '1';
            else
                code += '0';
            for(int i = 0; i < 256; i++){
                if(codebook[i] == code){
                    if(freqs[i]){
                              cout << (unsigned char) i;
                              code.clear();
                              freqs[i]--;
                              break;
                    }
                    else
                        return;
                }
            } // for
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
