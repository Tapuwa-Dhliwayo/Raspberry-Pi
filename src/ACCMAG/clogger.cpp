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

void compress(std::string filename){
	
	std::vector<char> char_vector = char_reader(filename);
	std::unordered_map<char, int> freq_table = freq_generator(char_vector);
	HuffmanTree tree(freq_table);
	std::unordered_map<char , std::string > code_table = tree.code();
	std::string encoded_data = encoder(char_vector,code_table);
	writer(input+"_compressed",encoded_data,code_table);

}

