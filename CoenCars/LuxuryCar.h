#pragma once
#include "Car.h"
#include <iostream>
#include <string>
using namespace std;
//Harrixel Gohou; 40309357

//derived class
class LuxuryCar :public Car {
public:
	//default constructor
	LuxuryCar();
	//regular constructor
	LuxuryCar(int, string, bool);
	//function ton print 
	virtual void print() override;
};

