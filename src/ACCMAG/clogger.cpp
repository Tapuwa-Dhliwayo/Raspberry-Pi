//Logging function utilising huffman algorithm for compression

#include "clogger.h"

void clogger(std::string filename, rawData_t* data, sensorValue_t* processed){

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

