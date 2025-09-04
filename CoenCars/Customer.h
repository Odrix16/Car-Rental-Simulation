#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Car.h"
#include "StandardCar.h"
#include "LuxuryCar.h"
#include "Rent.h"
using namespace std;
//Harrixel Gohou; 40309357

class Customer {
private:
	int cd; //customer id
	string name; //customer name
	string address; //customer address
	string telNum; //customer telephone number
	string type; //either regular or corporate
	vector<Car*> rentedcars; //list of cars rented from company
	vector<Rent> rentaldate;
	vector<Rent> returndate;

public:
	Customer(); //default constructor
	Customer(int, string, string, string, string); //regular constructor
	Customer(const Customer&); //copy constructor
	~Customer(); //destructor

	//getters
	int getCD() const;
	string getAddress() const;
	string getName() const;
	string getTelNum() const;
	string getType() const;

	vector<Car*>getRentedCars();

	//setters
	void setCD(int);
	void setName(string);
	void setAddress(string);
	void setTelNum(string);
	void setType(string);

	//functions to rent and return cars
	bool rentCar(vector<Car*>&, int);
	bool returnCar(vector<Car*>&, int);

	//function to add a renting date
	void addRentDate(int, int, int);
	//function to add a returning date
	void addReturnDate(int, int, int);
	void removeRentDate();
	void removeReturnDate();

	void printCustomer();
};


