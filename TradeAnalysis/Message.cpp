#include "Message.h"

string Header::show() {
	string header = "Header:\n";
	header += "\tmarker: " + to_string(marker) + "\n";
	header += "\tmsg_type: " + to_string(msg_type) + "\n";
	header += "\tsequence_id: " + to_string(sequence_id) + "\n";
	header += "\ttimestamp: " + to_string(timestamp) + "\n";
	header += "\tmsg_direction: " + to_string(msg_direction) + "\n";
	header += "\tmsg_len: " + to_string(msg_len) + "\n\n";
	return header;
}

void Header::buildHeaderFromBuffer(char* buffer) {
	this->marker = *((uint16_t*)buffer);
	buffer += sizeof(uint16_t);
	this->msg_type = *((uint8_t *)buffer);
	buffer += sizeof(uint8_t);
	this-> sequence_id = *((uint64_t *)buffer);
	buffer += sizeof(uint64_t);
	this->timestamp = *((uint64_t *)buffer);
	buffer += sizeof(uint64_t);
	this->msg_direction = *((uint8_t *)buffer);
	buffer += sizeof(uint8_t);
	this->msg_len = *((uint16_t *)buffer);
	buffer += sizeof(uint16_t);
}

Message::~Message() {

}