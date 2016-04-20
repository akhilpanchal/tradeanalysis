
#include"StreamReader.h"

StreamReader::StreamReader(string filePath, DataStore* dataStore) {
	_ds = dataStore;
	file = filePath;
	inputFile = new ifstream(file, ifstream::in | ios::binary);
	outputFile = new ofstream("messages.txt", ofstream::out);
}

void StreamReader::saveMessages() {
	try {
		while(inputFile->good()) {
			char buffer[22];
			inputFile->read(buffer, 22);
			headerPtr header = make_shared<Header>();
			header->buildHeaderFromBuffer(buffer);
			msg_type_count[header->msg_type]++;				// Increament count of message type
			total_count++;

			switch (header->msg_type) {
				case 1:
					this->saveOrderEntryMessage(header);
					break;
				case 2:
					this->saveOrderAckMessage(header);
					break;
				case 3:
					this->saveOrderFillMessage(header);
					break;
				default:
					throw exception("Invalid message_type in Header!");
					break;
			}
		}
		inputFile->close();
		outputFile->close();
	} catch (exception e) {
		cout << e.what() << endl;
	}
}

void StreamReader::saveOrderEntryMessage(headerPtr header) {
	char *body = new char[header->msg_len];
	inputFile->read(body, header->msg_len);
	shared_ptr<Message> msg = make_shared<OrderEntryMessage>(header, body);
	*outputFile << msg;
	delete[] body;
}

void StreamReader::saveOrderAckMessage(headerPtr header) {
	char* body = new char[header->msg_len];
	inputFile->read(body, header->msg_len);
	shared_ptr<Message> msg = make_shared<OrderAcknowledgementMessage>(header, body);
	*outputFile << msg;
	delete[] body;
}

void StreamReader::saveOrderFillMessage(headerPtr header) {
	char* body = new char[header->msg_len];
	inputFile->read(body, header->msg_len);
	shared_ptr<Message> msg = make_shared<OrderFillMessage>(header, body);
	*outputFile << msg;
	delete[] body;
}

StreamReader::~StreamReader() {
	delete _ds;
	delete inputFile;
	delete outputFile;
}