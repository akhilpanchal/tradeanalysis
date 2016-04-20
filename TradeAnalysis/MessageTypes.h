#ifndef MESSAGE_TYPES_H
#define MESSAGE_TYPES_H

#include "Message.h"
#include<string>
#include<vector>

class OrderEntryMessage : public Message {
public:
	OrderEntryMessage(headerPtr header, char*);
	friend ostream& operator<<(ostream& ostrm, shared_ptr<Message> msg);
	string showBody();
private:
	uint64_t price;
	uint32_t qty;
	string instrument;
	uint8_t side;
	uint64_t client_assigned_id;
	uint8_t time_in_force;
	string trader_tag;
	uint8_t firm_id;
	string firm;
	string termination_string;
};




class OrderAcknowledgementMessage : public Message {

public:
	OrderAcknowledgementMessage(headerPtr header, char*);
	friend ostream& operator<<(ostream& ostrm, shared_ptr<Message> msg);
	string showBody();
private:
	uint32_t order_id;
	uint64_t client_id;
	uint8_t order_status;
	uint8_t reject_code;
	string termination_string;
};

struct Group {
	Group(char*);
	uint8_t firm_id;
	string trader_tag;
	uint32_t qty;
	string show();
};

class OrderFillMessage : public Message {

public:
	using gPtr = shared_ptr<Group>;
	OrderFillMessage(headerPtr header, char*);
	friend ostream& operator<<(ostream& ostrm, shared_ptr<Message> msg);
	string showBody();
private:
	uint32_t order_id;
	uint64_t fill_price;
	uint32_t fill_qty;
	uint8_t no_of_contras;
	vector<gPtr> groups;

	void addGroup(gPtr group) { groups.push_back(group); }
};


#endif