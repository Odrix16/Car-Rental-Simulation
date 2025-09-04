#include "Company.h"
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

//default constructor
Company::Company() {
	numCars = 0;
}

//regular constructor
Company::Company(int numCars1) {
	numCars = numCars1;
}

//copy constructor
Company::Company(const Company& u) {
	numCars = u.numCars;
}

//destructor
Company::~Company() {
	cout << "This has been destroyed" << endl;
}

//getters
int Company::getNumCars() const {
	return numCars;
}


//function to add a car
void Company::addCar(Car& c) {
	//if the number of cars in the company is below the capacity, add car
	if (numCars < capacity) {
		listcars.emplace_back(&c);
		numCars++;
		cout << "This car has been succesfully added" << endl;
	}
	//else, can't add car
	else {
		cout << "The car capacity is at it's limit" << endl;
	}
}

//function to remove a car from the company
void Company::removeCar(int d) {
	//kinda flag
	int count = 0;
	//goes through the company's cars
	for (int i = 0; i < numCars; i++) {
		//if specific car is equal to parameter id
		if (listcars[i]->getId() == d) {
			//remove car
			for (int j = i; j < numCars - 1; j++) {
				listcars[j] = listcars[j + 1];
			}
			cout << "Car " << d << " has been removed";
			numCars--;
			count++;
			return;
		}
	}
	//if count is 0, then no cars has been removed
	if (count == 0) {
		cout << "Car " << d << " doesn't exist." << endl;
	}
}

//function to search for a car
bool Company::searchCar(int id) {
	//goes through loop
	for (int i = 0; i < numCars; i++) {
		//if specific car id is equal to parameter id
		if (listcars[i]->getId() == id) {
			//car exists
			cout << "This car exists!" << endl;
			listcars[i]->print();
			return true;
		}
	}
	//else it doesn't
	cout << "This car doesn't exist..." << endl;
	return false;
}

//function to add a customer
void Company::addCustomer(Customer& u) {
	listcustomers.emplace_back(&u);
	cout << "This customer has been added!" << endl;
}

//function for a customer to rent
void Company::customerRent(int r, int s) {
	for (int i = 0; i < listcustomers.size(); i++) {
		if (listcustomers[i]->getCD() == r) {
			listcustomers[i]->rentCar(listcars, s);
		}
	}
}

//function for a customer to return
void Company::customerReturn(int t, int w) {
	for (int i = 0; i < listcustomers.size(); i++) {
		if (listcustomers[i]->getCD() == t) {
			listcustomers[i]->returnCar(listcars, w);
		}
	}
}

//function to print company information
void Company::printCompany() {
	cout << "These are all the cars of the company." << endl;
	for (int i = 0; i < listcars.size(); i++) {
		listcars[i]->print();
		cout << endl;
	}
	cout << "These are all the customers of the company." << endl;
	for (int j = 0; j < listcustomers.size(); j++) {
		listcustomers[j]->printCustomer();
		cout << endl;
	}
}