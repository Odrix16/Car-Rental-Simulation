#pragma once
#include <iostream>
#include <string>
using namespace std;
//Harrixel Gohou; 40309357


class Car {
	//protected member attributes
protected:
	int id;
	string type;
	bool flag;

	//public member attributes
public:
	//default constructor
	Car();
	//regular constructor
	Car(int, string, bool);
	Car(const Car&);
	virtual ~Car();

	//getters
	int getId() const;
	string getType() const;
	bool getFlag() ;

	//setters
	void setID(int i);
	void setType(string t);
	void setFlag(bool f);

	//pure virtual function to print
	virtual void print() = 0;
};

