#include "StandardCar.h"
#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//Harrixel Gohou; 40309357

//default constructor
StandardCar::StandardCar() :Car() {

}

//regular constructor
StandardCar::StandardCar(int id1, string type1, bool flag1) :Car(id1, type1, flag1) {

}

//function to print a standard car info
void StandardCar::print() {
	//cout << "This is a standard car." << endl;
	cout << "The ID of this car: " << id << endl;
	cout << "The type of car: " << type << endl;
	if (flag == true) {
		cout << "This car is available" << endl;
	}
	else {
		cout << "This isn't available" << endl;
	}
}