/////////////////////////////////////////////////////////////////////
//  Cars.cpp                   
//  ver 1.0                                                        
//  Language:      Visual C++ 2015                             
//  Platform:      Dell Inspiron 17R, Windows 10        
//  Application:   Coding Task for Interactive Brokers                  
//  Author:        Akhil Panchal, Syracuse University     
//                 (408) 921-0731, ahpancha@syr.edu           
/////////////////////////////////////////////////////////////////////

#include "Cars.h"

SUV::SUV(std::string brand, std::string license, bool fullSize) : Vehicle(brand, license), thirdRowSeatEnabled(fullSize) {
	this->capacity = 5;
	if (this->thirdRowSeatEnabled)
		this->capacity += 3;
}

SUV::SUV(std::string brand, std::string license) : SUV(brand, license, false) {
	
}

void SUV::enableThirdRowSeating() {
	if (!this->thirdRowSeatEnabled) {
		this->thirdRowSeatEnabled = true;
		this->capacity += 3;
	}
}

void SUV::disableThirdRowSeating() {
	if (this->thirdRowSeatEnabled) {
		this->thirdRowSeatEnabled = false;
		this->capacity -= 3;
	}
}
