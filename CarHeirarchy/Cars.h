/////////////////////////////////////////////////////////////////////
//  Cars.h                   
//  ver 1.0                                                        
//  Language:      Visual C++ 2015                             
//  Platform:      Dell Inspiron 17R, Windows 10        
//  Application:   Coding Task for Interactive Brokers                  
//  Author:        Akhil Panchal, Syracuse University     
//                 (408) 921-0731, ahpancha@syr.edu           
/////////////////////////////////////////////////////////////////////

#ifndef CARS_H
#define CARS_H

#include<string>
#include"Vehicle.h"

class SUV : public Vehicle {
public:
	SUV(std::string brand, std::string license, bool fullSize);

	SUV(std::string brand, std::string license);

	void enableThirdRowSeating();

	void disableThirdRowSeating();

	size_t getCapacity() {
		return capacity;
	}

private:
	bool thirdRowSeatEnabled;
};


class Sedan : public Vehicle {
public:
	Sedan(std::string brand, std::string license) : Sedan(brand, license, false) {

	}

	Sedan(std::string brand, std::string license, bool sportPackage) : Vehicle(brand, license),  sportPackageEnabled(sportPackage) {
		this->capacity = 5;
	}

	void enableThirdRowSeating() {
		if (!this->sportPackageEnabled) {
			this->sportPackageEnabled = true;
		}
	}

	void disableThirdRowSeating() {
		if (this->sportPackageEnabled) {
			this->sportPackageEnabled = false;
		}
	}

	size_t getCapacity() {
		return capacity;
	}
private:
	bool sportPackageEnabled;
};


#endif
