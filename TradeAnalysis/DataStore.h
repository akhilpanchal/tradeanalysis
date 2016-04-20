#ifndef DATASTORE_H
#define DATASTORE_H

#include<memory>
#include<vector>
#include<iostream>
#include"Message.h"

using namespace std;

using msgPtr = shared_ptr<Message>;

class DataStore {
public:
	void add(msgPtr);
	void show();
private:
	vector<msgPtr> _container;
};



#endif