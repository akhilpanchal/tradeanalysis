#ifndef MESSAGE_H
#define MESSAGE_H

#include<memory>
#include<string>
#include<iostream>

using namespace std;

struct Header;

using headerPtr = shared_ptr<Header>;

struct Header {
	uint16_t marker;
	uint8_t msg_type;
	uint64_t sequence_id;
	uint64_t timestamp;
	uint8_t msg_direction;
	uint16_t msg_len;
	void buildHeaderFromBuffer(char*);
	string show();
	
};

class Message {
public:
	virtual ~Message();
	friend ostream& operator<<(ostream& ostrm, const Message& a);

	headerPtr getHeader() { return _header; }
	void setHeader(headerPtr header) { this->_header = header; }
	string showHeader() { return _header->show(); }
	virtual string showBody() = 0;
protected:
	headerPtr _header;
};

inline ostream& operator<<(ostream& ostrm, const Message& b) {
	ostrm << b._header->show();
	return ostrm;
}
#endif