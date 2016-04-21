#ifndef EXCHANGE_ANALYZER_H
#define EXCHANGE_ANALYZER_H

#include<string>
#include<map>
#include<unordered_map>
#include"DataStore.h"
#include"Message.h"
#include"MessageTypes.h"

using namespace std;

class ExchangeAnalyzer {
public:
	ExchangeAnalyzer(DataStore* _ds);
	~ExchangeAnalyzer();

	//----------Alt imp--------
	string getMostActiveTrader2();
	void populateTraderFills2(unordered_map<uint64_t, string> traders,
		unordered_map<uint32_t, uint64_t>& clients,
		unordered_map<string, size_t>& traderFills
		);
	//----------End------------

	string getMostActiveTrader();
	string getMostLiquidityProvider();
	map<string, size_t> getVolumeOfTradesPerInstrument();

private:
	DataStore *_ds;

	void populateTraders(unordered_map<uint64_t, string>& traders);
	void populateClients(unordered_map<uint32_t, uint64_t>& clients);
	void populateTraderFills(unordered_map<uint64_t, string> traders,
							unordered_map<uint32_t, uint64_t>& clients,
							unordered_map<string, size_t>& traderFills);
	size_t getFillQty(shared_ptr<OrderFillMessage> fill_msg);

	void populateInstruments(unordered_map<uint64_t, string>& traders);
	map<string, size_t> getTradePerInstrument(unordered_map<uint64_t, string>& instruments,
						unordered_map<uint32_t, uint64_t> clients);
};

#endif