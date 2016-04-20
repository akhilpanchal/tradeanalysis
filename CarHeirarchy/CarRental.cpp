#include "CarRental.h"
/////////////////////////////////////////////////////////////////////
//  CarRental.cpp                    
//  ver 1.0                                                        
//  Language:      Visual C++ 2015                             
//  Platform:      Dell Inspiron 17R, Windows 10        
//  Application:   Coding Task for Interactive Brokers                  
//  Author:        Akhil Panchal, Syracuse University     
//                 (408) 921-0731, ahpancha@syr.edu           
/////////////////////////////////////////////////////////////////////
void CarRental::showCars() {
	for (auto vehicle : _vehicles) {
		vehicle->details();
	}
}

#ifdef TEST_CARRENTAL

using namespace std;

int main(int argc, const char* args[]) {
	auto cr = make_unique<CarRental>();

	auto suv = make_shared<SUV>("BMW","SHH1009", true);
	cr->addVehicle(suv);
	auto sedan = make_shared<Sedan>("Audi", "AKH7899", true);
	cr->addVehicle(sedan);
	sedan = make_shared<Sedan>("Ferrari", "ARISFRRI");
	cr->addVehicle(sedan);
	suv = make_shared<SUV>("Toyota", "TOY8730");
	cr->addVehicle(suv);
	sedan = make_shared<Sedan>("Wolkswagen", "702WOLK");
	cr->addVehicle(sedan);

	cr->showCars();
}

#endif