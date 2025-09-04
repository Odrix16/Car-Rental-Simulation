#include "Car.h"
#include "StandardCar.h"
#include "LuxuryCar.h"
#include "Company.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  
#include <chrono>   
#include <thread>
using namespace std;
//Harrixel Gohou; 40309357

//interface
static void menu() {
	cout << "Welcome to the CoenCars System Simulation!" << endl;
	cout << "To make a choice, choose the corresponding number." << endl;
	cout << "Fyi, if you press the exit number or any other number, the simulation will automatically end." << endl;
	cout << endl;
	cout << "1. Look at the information in the company." << endl;
	cout << "2. Add a standard car in the company." << endl;
	cout << "3. Add a luxury car in the company." << endl;
	cout << "4. Remove a car from the company." << endl;
	cout << "5. Add customer." << endl;
	cout << "6. Have a customer rent a car." << endl;
	cout << "7. Have a customer return a car." << endl;
	cout << "8. Search if a car exists." << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "Enter your choice: "<<endl;
}
int main() {
	//Base information about company (will be modifiable)
	int choice, id, cd;
	string type, name, address, phone;
	bool flag;
	Company CoenCar;
	StandardCar sc;
	LuxuryCar lc;
	Customer cc;

	StandardCar s1(1, "standard", true);
	StandardCar s2(2, "standard", false);
	StandardCar s3(3, "standard", true);
    LuxuryCar l1(4, "luxury", false);
	LuxuryCar l2(5, "luxury", true);
	LuxuryCar l3(6, "luxury", false);

	Customer c1(1, "Rix", "Sherbrooke", "444", "standard");
	Customer c2(2, "Gohou", "Montreal", "555", "corporate");

	CoenCar.addCar(s1);
	CoenCar.addCar(s2);
	CoenCar.addCar(s3);
	CoenCar.addCar(l1);
	CoenCar.addCar(l2);
	CoenCar.addCar(l3);

	CoenCar.addCustomer(c1);
	CoenCar.addCustomer(c2);

	cout << endl;
	do {
		system("CLS");
		menu();
		//user enters a choice
		cin >> choice;
		switch (choice) {

		case 1: //checking company's information
			system("CLS");
			cout << "This is the company's entire information" << endl;
			CoenCar.printCompany();
			this_thread::sleep_for(chrono::seconds(10));
			break;

		case 2: //adding a standard car to the company
			system("CLS");
			cout << "ID of this standard car?" << endl;
			cin >> id;
			cout << "Is this standard car currently available?(true or false)" << endl;
			cin >> flag;
			sc.setID(id);
			sc.setFlag(flag);
			CoenCar.addCar(sc);
			this_thread::sleep_for(chrono::seconds(2));
			break;

		case 3: //adding a luxury car to the company
			system("CLS");
			cout << "ID of this luxury car?" << endl;
			cin >> id;
			cout << "Is this luxury car currently available?(true or false)" << endl;
			cin >> flag;
			lc.setID(id);
			lc.setFlag(flag);
			CoenCar.addCar(lc);
			this_thread::sleep_for(chrono::seconds(2));
			break;

		case 4: //removing a car from the company
			system("CLS");
			cout << "ID of the car you want to remve from this company?" << endl;
			cin >> id;
			CoenCar.removeCar(id);
			this_thread::sleep_for(chrono::seconds(2));
			break;

		case 5: //adding a customer
			system("CLS");
			cout << "ID of the customer?" << endl;
			cin >> cd;
			cout << "Name of the customer?" << endl;
			getline(cin, name);
			cin.ignore();
			cout << "Address of this customer?" << endl;
			getline(cin, address);
			cin.ignore();
			cout << "Phone number of this customer?" << endl;
			getline(cin, phone);
			cin.ignore();
			cout << "The type of customer? (either regular or corporate)" << endl;
			getline(cin, type);
			cin.ignore();
			cc.setCD(cd);
			cc.setName(name);
			cc.setAddress(address);
			cc.setTelNum(phone);
			cc.setType(type);

			CoenCar.addCustomer(cc);
			cc.printCustomer();
			this_thread::sleep_for(chrono::seconds(5));
			break;

		case 6: //customer renting
			system("CLS");
			cout << "Enter the id of the customer who wants to rent" << endl;
			cin >> cd;
			cout << "Enter the id of the car." << endl;
			cin >> id;

			CoenCar.customerRent(cd, id);
			this_thread::sleep_for(chrono::seconds(5));
			break; 

		case 7: //customer returning
			system("CLS");
			cout << "Enter the id of the customer who wants to return" << endl;
			cin >> cd;
			cout << "Enter the id of the car." << endl;
			cin >> id;

			CoenCar.customerReturn(cd, id);
			this_thread::sleep_for(chrono::seconds(5));
			break;

		case 8: //searching if a car exist in the company
			system("CLS");
			cout << "Enter the ID of the car you want to search for:" << endl;
			cin >> id;
			
			CoenCar.searchCar(id);
			this_thread::sleep_for(chrono::seconds(5));
			break;

		default: //ending the simulation
			cout << "Hope you had fun!" << endl;
			break;
		} 
	} while (0 < choice < 8);

	return 0;
}