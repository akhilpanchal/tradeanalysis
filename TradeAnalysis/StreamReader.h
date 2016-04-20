#ifndef STREAMREADER_H
#define STREAMREADER_H

#include<string>
#include<fstream>
#include<unordered_map>

#include "DataStore.h"
#include "Message.h"
#include "MessageTypes.h"

using namespace std;

class StreamReader {
public:
	StreamReader(string filePath, DataStore* ds);
	~StreamReader();
	void saveMessages();
	void saveOrderEntryMessage(headerPtr header);
	void saveOrderAckMessage(headerPtr header);
	void saveOrderFillMessage(headerPtr header);
private:
	DataStore* _ds;
	string file;
	ifstream *inputFile;
	ofstream *outputFile;
	unordered_map<uint8_t, int> msg_type_count;
	int total_count;
};


#endif