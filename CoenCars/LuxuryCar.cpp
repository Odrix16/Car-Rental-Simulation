#include "LuxuryCar.h"
#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//Harrixel Gohou; 40309357

//default constructor
LuxuryCar::LuxuryCar() :Car() {

}

//regular constructor
LuxuryCar::LuxuryCar(int id1, string type1, bool flag1) : Car(id1, type1, flag1) {

}

//function to print the luxury car info
void LuxuryCar::print() {
	//cout << "This is a luxury car" << endl;
	cout << "The ID of this luxury car is: " << id << endl;
	cout << "The type of car: " << endl;
	if (flag == true) {
		cout << "This car is available" << endl;
	}
	else {
		cout << "This isn't available" << endl;
	}
}