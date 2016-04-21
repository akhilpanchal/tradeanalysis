#ifndef DATASTORE_H
#define DATASTORE_H

#include<memory>
#include<vector>
#include<unordered_map>
#include<iostream>
#include"Message.h"

using namespace std;

using msgPtr = shared_ptr<Message>;

class DataStore {
public:
	DataStore();
	void saveOrderEntry(msgPtr msg);
	void saveOrderAck(msgPtr msg);
	void saveOrderFill(msgPtr msg);

	vector<msgPtr> getOrderEntries(){ return orderEntries; }
	vector<msgPtr> getOrderAcks() { return orderAcks; }
	vector<msgPtr> getOrderFills() { return orderFills; }

	int getCountByMsgType(int type = 0);
	void show();
private:
	vector<msgPtr> orderEntries;
	vector<msgPtr> orderAcks;
	vector<msgPtr> orderFills;
	unordered_map<uint8_t, int> msg_type_count;
	int total_count;

};



#endif