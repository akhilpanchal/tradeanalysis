
#include "DataStore.h"

DataStore::DataStore() {
	msg_type_count[0] = 0;
	msg_type_count[1] = 0;
	msg_type_count[2] = 0;
	msg_type_count[3] = 0;
}

int DataStore::getCountByMsgType(int type) {
	if (type > 3 || type < 0)
		return -1;
	return msg_type_count[type];
}

void DataStore::saveOrderEntry(msgPtr msg) {
	orderEntries.push_back(msg);
	msg_type_count[0]++;
	msg_type_count[1]++;
}

void DataStore::saveOrderAck(msgPtr msg) {
	orderAcks.push_back(msg);
	msg_type_count[0]++;
	msg_type_count[2]++;
}

void DataStore::saveOrderFill(msgPtr msg) {
	orderFills.push_back(msg);
	if (msg_type_count[3] == 546)
		cout << "Here is 546!";
	msg_type_count[0]++;
	msg_type_count[3]++;
}

void DataStore::show() {
	for (auto entry : orderEntries)
		cout << entry << endl;
}
#ifdef TEST_DATASTORE

#include"Message.h"
void main() {
	DataStore<Message> ds;
	auto msg = make_shared<Message>();
	ds.add(msg);
	ds.show();
}

#endif
