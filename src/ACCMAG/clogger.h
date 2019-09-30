//Function definitions for Custom logging Application
//Utilizing Huffman compression for storing logging data

#include "accMagGyroSensor.h"
#include "huff.h"
#include <string>
#include <iostream>

#ifndef _CLOGGER_H_
#define _CLOGGER_H_

void clogger(std::string filename, rawData_t* data, sensorValue_t* processed);

#endif
