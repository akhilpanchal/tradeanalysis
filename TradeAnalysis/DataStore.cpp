
#include "DataStore.h"

void DataStore::add(msgPtr objPtr) {
	_container.push_back(objPtr);
}

void DataStore::show() {
	for (auto object : _container)
		cout << object << endl;
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
