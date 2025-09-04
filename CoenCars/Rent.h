#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//private member attribute
class Rent {
private:
	int day, month, year;

	//public
public:
	//default constructor
	Rent();
	//regular constructor
	Rent(int, int, int);
	//copy constructor
	Rent(const Rent&);

	//getters
	int getDay() const;
	int getMonth()  const;
	int getYear() const;

	//setters
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	//print date
	void printRent() const;
};


