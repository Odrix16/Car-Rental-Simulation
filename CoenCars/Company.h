#pragma once
#include "Car.h"
#include "StandardCar.h"
#include "LuxuryCar.h"
#include "Customer.h"
#include "Rent.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Harrixel Gohou; 40309357

class Company {
	//private member attribute
private:
	vector<Car*> listcars;
	vector<Customer*> listcustomers;
	const int capacity = 1000;
	int numCars;

	//public member attribute
public:
	//default constructor
	Company();
	//copy constructor
	Company(const Company&);
	//destructor
	virtual ~Company();
	//create copy constructor
	Company(int);

	int getNumCars() const;
	//function to add a car
	void addCar(Car&);
	//function to remove a car with id
	void removeCar(int);
	//function to search for a car with id
	bool searchCar(int);

	//function to add a customer
	void addCustomer(Customer&);
	//function for a customer to rent with their id and car id
	void customerRent(int, int);
	//function for a customer to return with their id and car id
	void customerReturn(int, int);

	//function to print company information
	void printCompany();
};

