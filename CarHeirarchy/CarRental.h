#ifndef CARRENTAL_H
#define CARRENTAL_H
/////////////////////////////////////////////////////////////////////
//  CarRental.h                    
//  ver 1.0                                                        
//  Language:      Visual C++ 2015                             
//  Platform:      Dell Inspiron 17R, Windows 10        
//  Application:   Coding Task for Interactive Brokers                  
//  Author:        Akhil Panchal, Syracuse University     
//                 (408) 921-0731, ahpancha@syr.edu           
/////////////////////////////////////////////////////////////////////

/*
Statement:
Implement the following car hierarchy along with the accessor functions
and a CarRental class which contains the container to store them.
 
A car rental company wants to keep track of its cars. Each vehicle has a
license plate and a brand. (eg. BWM). Currently the company has SUVs and
Sedans. SUV-s have an optional third row seat that increases the
passenger capacity by three, sedans have an optional sport package. Each
car can be queried to inquire the number of passengers it can carry.
 */


/*
Note: Unordered Map can be used for efficient lookUp by license plate number.
*/

#include<memory>
#include<unordered_map>
#include<vector>
#include "Vehicle.h"
#include "Cars.h"

class CarRental {
public:
	using vPtr = std::shared_ptr<Vehicle>;
	void addVehicle(vPtr vehicle) {
		_vehicles.push_back(vehicle);
		_vehicleLookUp[vehicle->getLicensePlate()] = vehicle;
	}
	vPtr getVehicleInfoByLicense(std::string license) {
		return _vehicleLookUp[license];
	}
	void showCars();
private:
	std::unordered_map<std::string, vPtr> _vehicleLookUp;		// Not used
	std::vector<vPtr> _vehicles;
};

#endif