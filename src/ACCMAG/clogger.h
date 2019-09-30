//Function definitions for Custom logging Application
//Utilizing Huffman compression for storing logging data

#ifndef _CLOGGER_H_
#define _CLOGGER_H_

#include "accMagGyroSensor.h"
#include "huff.h"
#include <cstdint>
#include <cstring>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void clogger(string filename, rawData_t* data, sensorValue_t* processed);

void compress(string filename);
void putOut(string fileinput,string fileoutput);
void decompress(string filename);
Node* constructHeap();

#endif
