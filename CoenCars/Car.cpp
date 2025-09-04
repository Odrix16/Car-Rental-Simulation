#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//Harrixel Gohou; 40309357

//default constructor
Car::Car() {
	id = 0;
	type = "";
	flag = 0;
}

//regular constructor
Car::Car(int id1, string type1, bool flag1) {
	id = id1;
	type = type1;
	flag = flag1;
}

//copy constructor
Car::Car(const Car& o) {
	id = o.id;
	type = o.type;
	flag = o.flag;
}

Car::~Car() {

}

//getters
int Car::getId() const {
	return id;
}

string Car::getType() const {
	return type;
}

bool Car::getFlag()   {
	return flag;
}

//setters
void Car::setID(int i) {
	id = i;
}

void Car::setType(string t) {
	type = t;
}

void Car::setFlag(bool f) {
	flag = f;
}