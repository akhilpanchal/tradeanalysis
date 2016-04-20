#include"Executive.h"

void Executive::showAnalysis(string input) {
	DataStore *ds = new DataStore;
	StreamReader reader(input, ds);
	reader.saveMessages();
}

#ifdef TEST_EXECUTIVE

#include<iostream>
using namespace std;

int main(int argc, char* args[]) {
	cout << "Current Directory: " << args[0] << endl;
	if (argc < 2) {
		cout << "Give input file spec as a command-line argument!" << endl;
		return 1;
	}
	Executive executive;
	executive.showAnalysis(args[1]);

	return 0;
}

#endif