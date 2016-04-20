/////////////////////////////////////////////////////////////////////
//  Vehicle.h                   
//  ver 1.0                                                        
//  Language:      Visual C++ 2015                             
//  Platform:      Dell Inspiron 17R, Windows 10        
//  Application:   Coding Task for Interactive Brokers                  
//  Author:        Akhil Panchal, Syracuse University     
//                 (408) 921-0731, ahpancha@syr.edu           
/////////////////////////////////////////////////////////////////////
/*
	Provides a Base class Vehicle that contains common data members across all vehicles:
	  Private:
		-BrandName
		-License Number
	  Protected:
		-Capacity
	Implementers must provide definition for capacity as the capacity calculation depends on the concrete vehicle.

*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
#include<iostream>

class Vehicle {
public:
	Vehicle(std::string brandName, std::string licensePlate) :brand(brandName), license_plate(licensePlate) {

	}
	void setBrand(std::string brandName) {
		this->brand = brandName;
	}
	void setLicensePlate(std::string licensePlate) {
		this->license_plate = licensePlate;
	}

	std::string getBrand() {
		return brand;
	}

	std::string getLicensePlate() {
		return license_plate;
	}

	virtual size_t getCapacity() = 0;
	virtual void details() {
		std::cout << "Brand:\t\t" << this->brand << std::endl;
		std::cout << "License:\t" << this->license_plate << std::endl;
		std::cout << "Capacity:\t" << this->capacity << std::endl << std::endl;
	}

private:
	std::string brand;
	std::string license_plate;
protected:
	size_t capacity;
};

#endif


