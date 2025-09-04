#include "Rent.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//default constructor
Rent::Rent() {
	day = 0;
	month = 0;
	year = 0;
}

//regular construcot
Rent::Rent(int day1, int month1, int year1) {
	day = day1;
	month = month1;
	year = year1;
}

//copy construcotr
Rent::Rent(const Rent& r) {
	day = r.day;
	month = r.month;
	year = r.year;
}

//getters
int Rent::getDay() const {
	return day;
}

int Rent::getMonth() const {
	return month;
}

int Rent::getYear() const {
	return year;
}

//setters
void Rent::setDay(int d) {
	day = d;
}

void Rent::setMonth(int m) {
	month = m;
}

void Rent::setYear(int y) {
	year = y;
}
//function to print date
void Rent::printRent() const{
	cout << "Day: " << day << endl;
	cout << "Month: " << month << endl;
	cout << "Year: " << year << endl;
}