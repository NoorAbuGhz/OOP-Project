#include <iostream>
#include <string>
#include "Customer.h"
#include "Medication.h"
#include "Prescription.h"
#include "OffTheShelf.h"
#include"Pharmacy.h"
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

Pharmacy* phar; // Global dynamic Pharmacy array
int SIZE; //Size of the array, variable value taken from user input

void AddPharmacy() {  //Function to ask user to input name of pharmacies SIZE times
	for (int i = 0; i < SIZE; i++) {
		string name;
		cout << "\nEnter pharmacy " << i+1 << " name (End it with '.') : ";
		cin.ignore();
		getline(cin, name, '.');
		phar[i].setName(name);
	}
}
int main() {
	string option;

	cout << "Please Enter Number of Pharmacies: ";
	cin >> SIZE;
	while (SIZE < 1) {
		cout << "Please enter a positive number: ";
		cin >> SIZE;
	}

	phar = new Pharmacy[SIZE]; //Setting the size of the dynamic array
	
	AddPharmacy();  //Calling funtion to input pharmacy names

	while (option != "-1") { //Displaying menu and asking user to pick and option
		cout << "\nEnter a number:\n"; 
		cout << "1 - Add medication(s) to a pharmacy inventory\n";
		cout << "2 - Add customer(s) to a pharmacy\n";
		cout << "3 - Display details of a medication in a pharmacy\n";
		cout << "4 - Display a list of customers\n";
		cout << "5 - Remove medication from pharmacy\n";
		cout << "6 - Show the number of medications in a pharmacy\n";
		cout << "7 - Show the number of customers in a pharmacy\n";
		cout << "8 - Add a customer purchase in a pharmacy\n";
		cout << "9 - Calculate sales in a pharmacy\n";
		cout << "10 - Change number of pharmacies\n";
		cout << "Enter -1 to exit the menu\n";
		cin >> option;
		//Below are if statements for every option
		
		 if (option == "1") {//Adding the medication to a specified pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want to add the medication to its inventory (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					Medication m;
					string mname, des, bar;
					double p;
					int q, d, mth, y;
					cout << "Enter the name of medication (End it with '.'): ";
					cin.ignore();
					getline(cin, mname, '.');
					m.setMedName(mname);
					cout << "Enter the medication description (End it with '.'): ";
					cin.ignore();
					getline(cin, des, '.');
					m.setDes(des);
					cout << "Enter the medication price: ";
					cin >> p;
					m.setPrice(p);
					cout << "Enter the medication quantity: ";
					cin >> q;
					m.setQuan(q);
					cout << "Enter expiration date in the format d m yyyy: ";
					cin >> d >> mth >> y;
					m.setDate(d, mth, y);
					cout << "Enter the medication barcode: ";
					cin >> bar;
					m.setBar(bar);
					phar[i].AddMed(m);
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "2") {//Adding a customer to a specified pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want to add the customer in (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					Customer c;
					string cname, city, str, em, pn;
					cout << "Enter the name of customer (End it with '.'): ";
					cin.ignore();
					getline(cin, cname, '.');
					c.setName(cname);
					cout << "Enter the customer city (End it with '.'): ";
					cin.ignore();
					getline(cin, city, '.');
					cout << "Enter the customer streetname (End it with '.'): ";
					cin.ignore();
					getline(cin, str, '.');
					cout << "Enter the customer phone number: ";
					cin >> pn;
					cout << "Enter the customer email: ";
					cin >> em;
					c.getAddress().SetCity(city);
					c.getAddress().SetEmail(em);
					c.getAddress().SetPhoneNum(pn);
					c.getAddress().SetStreetName(str);
					phar[i].AddCust(c);
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "3") {//Diplay the medication list for a specified pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want to display the medication list (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					phar[i].DisplayMed();
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "4") {
			//Diplay the customer list for a specified pharmacy
			string pname;
			cout << "Enter the name of the pharmacy you want to display the customer list (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					phar[i].DisplayCust();
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "5") {//Remove a medication from a specific pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want to remove medication (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					Medication m;
					cout << "Enter the name of medication (End it with '.'): ";
					string mname;
					cin.ignore();
					getline(cin, mname, '.');
					m.setMedName(mname);
					phar[i].RemoveMed(m);
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}

			}
		}
		else if (option == "6") {//Display the amount of medication in a specific pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want display medication amount (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					cout << phar[i].getCurrM() << endl;
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "7") {//Display the amount of customers in a specific pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want display customer amount (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');
			for (int i = 0;i < SIZE;i++) {
				if (phar[i].getName() == pname) {
					cout << phar[i].getCurrC() << endl;
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "8") { //Add a customer purchase in a pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want display customer amount (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');

			for (int i = 0; i < SIZE; i++) {
				if (phar[i].getName() == pname) {
					if(phar[i].getCurrM() == 0)
						cout << "\nNo medications in stock." << endl;
					else {
						int numOfPur, purPerMed;
						string name;

						cout << "\nEnter the number of different medications to be purchased: ";
						cin >> numOfPur;
						while (numOfPur > 0) {
							cout << "\nEnter the medication name (End it with '.'): ";
							cin.ignore();
							getline(cin, name, '.');
							cout << "\nEnter quantity to be purchased from the previously entered medication: ";
							cin >> purPerMed;
							phar[i].stocks(name,purPerMed);
							phar[i].purchases(name, purPerMed);
							numOfPur--;
						}
					}
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "9") {//Calculate sales in a pharmacy
			string pname;
			cout << "\nEnter the name of the pharmacy you want display customer amount (End it with '.'): ";
			cin.ignore();
			getline(cin, pname, '.');

			for (int i = 0; i < SIZE; i++) {
				if (phar[i].getName() == pname) {
					if (phar[i].getCurrM() == 0)
						cout << "\nNo medications in stock." << endl;
					else
						cout << "\nTotal sales: $" << phar[i].getSales() << endl;
					break;
				}
				if (i == SIZE - 1) {
					cout << "Pharmacy not found.\n";
					break;
				}
			}
		}
		else if (option == "10") { //Changing number of pharmacies
			int s;
			cout << "Please Enter Number of Pharmacies: ";
			cin >> s;

			delete[] phar; //Changing size of dynamic array and performing proper grarbage disposal of any unecessary data
			phar = new Pharmacy[s];
			SIZE = s;

			AddPharmacy(); //Re-entering pharmacy names after the size has been changed
		}
		else {//If any other number other than 1-10 and -1 was entered
			if (option == "-1")
				break;
			else
				cout << "\nInvalid option.\n";
		}
		cout << "\n";
	} //Sentinel check to exit the while loop
	
	if (SIZE > 1) { //Comparing pharmacies created after exiting out of system
		for (int i = 1; i < SIZE; i++) { 
			phar[i - 1].compareCustNum(phar[i]); //Customers
			phar[i - 1].compareMedNum(phar[i]); //Medications
			phar[i - 1].compareSales(phar[i]); //Sales
			cout << endl;
		}
	}

	delete[] phar; //Dynamic array disposal
	phar = 0;

	//Creating 4 objects including both sub-types/categories.  
	Date d1(8,3,2004); //An object in static memory with attributes in static memory
	Pharmacy P1; //An object in static memory with attributes in dynamic memory (cust, meds)
	Date* d2 = new Date(18,2,2004); //An object in dynamic memory with attributes in static memory
	Pharmacy* P2 = new Pharmacy(); //An object in dynamic memory with attributes in dynamic memory (cust, meds)

	//Printing details of objects with inheritence
	Prescription pres1;
	OffTheShelf ots1;
	cout << "\nDefault Prescription object:" << endl;
	pres1.printMed();
	cout << "\nDefault OffTheShelf object:" << endl;
	ots1.printOTS();

	return 0;
}