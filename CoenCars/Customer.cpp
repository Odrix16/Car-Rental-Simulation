#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
#include "Car.h"
#include "StandardCar.h"
#include "Rent.h"
#include "LuxuryCar.h"
using namespace std;
//Harrixel Gohou;40309357

//default constructor
Customer::Customer() {
	cd = 0;
	name = "";
	address = "";
	telNum = "";
	type = "";
}

//regular constructor
Customer::Customer(int cd1, string name1, string address1, string telNum1, string type1) {
	cd = cd1;
	name = name1;
	address = address1;
	telNum = telNum1;
	type = type1;
}

//copy constructor
Customer::Customer(const Customer& p) {
	cd = p.cd;
	name = p.name;
	address = p.address;
	telNum = p.telNum;
	type = p.type;
}

//destructor
Customer::~Customer() {
	cout << "This has been deleted" << endl;
}

//getters
int Customer::getCD() const {
	return cd;
}

string Customer::getAddress() const {
	return address;
}

string Customer::getName() const {
	return name;
}

string Customer::getTelNum() const {
	return telNum;
}

string Customer::getType() const {
	return type;
}

vector<Car*> Customer::getRentedCars() {
	return rentedcars;
}

//setters
void Customer::setCD(int c) {
	cd = c;
}

void Customer::setAddress(string a) {
	address = a;
}

void Customer::setName(string n) {
	name = n;
}

void Customer::setTelNum(string t) {
	telNum = t;
}

void Customer::setType(string y) {
	type = y;
}

//adding rental date
void Customer::addRentDate(int d, int m, int y) {
	Rent rental(d, m, y);
	rentaldate.emplace_back(rental);
}

//adding returning date
void Customer::addReturnDate(int h, int g, int k) {
	Rent returnal(h, g, k);
	returndate.emplace_back(returnal);
}



//renting car
bool Customer::rentCar(vector<Car*> &s, int id1) {
	//goes through pass down car array
	for (int i = 0; i < s.size(); i++) {
		//if the id of specific car is the same as parameter
		if (s[i]->getId() == id1) {
			//if the flag of specific car is true, available
			if (s[i]->getFlag() == true) {
				cout << "This car can be rented" << endl;
				s[i]->setFlag(false);
				s[i]->print();
				rentedcars.emplace_back(s[i]);
				return true;
			}
			//false, unavailable
			else if(s[i]->getFlag()==false){
				cout << "This car isn't available" << endl;
				return false;
			}
		}
	}
	//program goes here if it doesn't find the specific car
	cout << "This car doesn't exist" << endl;
	return false;
}

//does the opposite of the previous function
bool Customer::returnCar(vector<Car*> &o,int id2) {
	for (int i = 0; i < rentedcars.size(); i++) {
		if (rentedcars[i]->getId() == id2) {
			rentedcars.erase(rentedcars.begin() + i);
			cout << "This car has been returned" << endl;
			for (int j = 0; j < o.size(); j++) {
				if (o[i]->getId() == id2) {
					o[i]->setFlag(true);
					o[i]->print();
					return true;
				}
			}
		}
	}
	cout << "This car doesn't exist" << endl;
	return false;
}

//function to print customer info
void Customer::printCustomer() {
	cout << "The type of customer: " << type << endl;
	cout << "Customer's Id: " << cd << endl;
	cout << "Customer's name: " << name << endl;
	cout << "Customer's address: " << address << endl;
	cout << "Customer's skin tone chicken bone telephone number: " << telNum << endl;
	for (int i = 0; i < rentedcars.size(); i++) {
		rentedcars[i]->print();
		rentaldate[i].printRent();
		returndate[i].printRent();
		cout << endl;
	}
}