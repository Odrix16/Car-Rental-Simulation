#pragma once
#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//Harrixel Gohou; 40309357

//derived class
class StandardCar : public Car {
public:
	//default constructor
	StandardCar();
	//regular constructor
	StandardCar(int, string, bool);
	//virtual function to print
	virtual void print() override;
};


