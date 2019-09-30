//Huffman Compression source file

#include "huff.h"


//Function Implementations
std::vector<char> char_reader(std::string input){

	input = input + ".txt";

	std::ifstream file;
	char hold;

	file.open(input);

	if(!file){
		std::cout<<"File could not be opened."<<std::endl;
	}
	//Writes charatcers in the file into the char vector ignores all spaces tabs and newlines and generates a continuous stream of text as a vector of chars
	std::vector<char> characters;
	while(!file.eof()){

		file>>hold>>std::ws;
		characters.push_back(hold);

	}

	file.close();

	return characters;
}

std::unordered_map<char, int> freq_generator(std::vector<char> characters){

	std::unordered_map<char , int> freq_table;

	auto ref = characters.begin();
	int count = 0;
	for(int i =0; i < (signed int)characters.size(); i++){

		//Counts how many times the char appears in the the array
		for(int j = 0; j < (signed int)characters.size(); j++){

			if(characters.at(j) == *(ref+i)){
				count++;
			}
		}
		//Only added the char and its freq if there is no instance of the character present in the frequency table
		if(freq_table.count(*(ref+i)) == 0){

			//std::cout<<*(ref+i)<<" -> "<<count<<std::endl;
			freq_table.insert(std::make_pair(*(ref+i),count));
		}
		count = 0;
	}

	return freq_table;
}

std::string encoder(std::vector<char> charater_order, std::unordered_map<char , std::string> code_table){

	std::string encoded_data = "";
	//Geenerates the encoded data by looping over the order of the char vector present 
	//and writing the matching code to the present char in the loop if they match

	for(auto& order: charater_order){
		
		for(auto& trace: code_table){

			if(order == trace.first){

				encoded_data = encoded_data + trace.second;
			}
		}
	}

	return encoded_data;

}

void writer(std::string output, std::string encoded_data, std::unordered_map<char , std::string> code_table){

	int len = encoded_data.length();
	char buffer[len + 1];
	//Byte array - buffer of the encoded data has been generated
	strcpy(buffer, encoded_data.c_str());

	//Writing out the endcoded data array to an output file
	std::ofstream out_file(output,std::ofstream::binary);
	out_file<<buffer;
	out_file.close();

	//Creating a file output.hdr
	std::string header_name = output + ".hdr";

	//Writes the code table to the hdr file in the form 'char' -> 'code_symbol'
	std::ofstream out_file2(header_name);
	for(auto &code: code_table){
		out_file2<<code.first<<" -> "<<code.second<<"\n";
	}
	out_file2.close();

}


