#include"Executive.h"

void Executive::showAnalysis(string input) {
	DataStore *ds = new DataStore;
	StreamReader reader(input, ds);
	ExchangeAnalyzer *ea = new ExchangeAnalyzer(ds);
	reader.saveMessages();
	cout << "Total Message Count: " << ds->getCountByMsgType(0) << endl;
	cout << "Order Entry Count: " << ds->getCountByMsgType(1) << endl;
	cout << "Order Ack Count: " << ds->getCountByMsgType(2) << endl;
	cout << "Order Fill Count: " << ds->getCountByMsgType(3) << endl;
	cout << "Most Active Trader: " << ea->getMostActiveTrader() << endl;
	cout << "Most Liquidity Provider: " << ea->getMostLiquidityProvider() << endl;
	cout << "Volume of trades per Instrument:\n" << endl;
	for (auto instrument : ea->getVolumeOfTradesPerInstrument()) {
		cout << "\tInstrument: " << instrument.first << "\tVolume: " << instrument.second << endl;
	}

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