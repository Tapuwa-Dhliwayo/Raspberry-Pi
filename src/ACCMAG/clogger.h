//Function definitions for Custom logging Application
//Utilizing Huffman compression for storing logging data

#ifndef _CLOGGER_H_
#define _CLOGGER_H_

#include "accMagGyroSensor.h"
#include "huff.h"
#include <cstdint>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void clogger(string filename, rawData_t* data, sensorValue_t* processed);

void compress();
void putOut();
void decompress();
Node* constructHeap();
unsigned int freqs[256] = {0};
string codebook[256];

#endif
