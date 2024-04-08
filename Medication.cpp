#include "medication.h"
#include <iostream>
using namespace std;
#include<string>
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
int Medication::medCount = 0;

Medication::Medication(const Medication& other):Expiry_Date(other.Expiry_Date)
{	//Copy constructor
	medName = other.medName;
	description = other.description;
	price = other.price;
	quantity = other.quantity;
	barcode = other.barcode;
} //No need to add ++MedID since copy constructors take the same ID as the current object

Medication::Medication():Expiry_Date(1,1,2000), medID(++medCount)
{	//Default constructor
	medName = "No name";
	description = "No description";
	price = 0;
	quantity = 0;
	barcode = "";
}

Medication::Medication(string mn, string des, double p, int q, int d, int m, int y, string bar): Expiry_Date(d,m,y), medID(++medCount)
{	//Parameterized constructor
	setMedName(mn);
	setDes(des);
	setPrice(p);
	setQuan(q);
	setBar(bar);
}

Medication::~Medication() {} //Destructror

void Medication::setMedName(string mn)
{
	while (mn == "") {
		cout << "Invalid name. Please re-enter the name correctly (End it with '.')." << endl;
		cin.ignore();
		getline(cin, mn, '.');
	}
	medName = mn;
}

void Medication::setDes(string des)
{
	while (des == "") {
		cout << "Invalid description. Please enter a proper description (End it with '.')." << endl;
		cin.ignore();
		getline(cin, des, '.');
	}
	description = des;
}

void Medication::setPrice(double p)
{
	if (p >= 0) {
		price = p;
	}
	else {
		double newP;
		cout << "Price cannot be a negative value.Please re-enter a proper number." << endl;
		cin >> newP;
		setPrice(newP); //Re-calling the function using recursion until the right value is entered
	}
}

void Medication::setQuan(int q)
{
	if (q >= 0) {
		quantity = q;
	}
	else {
		cout << "Quantity cannot be a negative value. Please re-enter a proper number." << endl;
		cin >> q;
		setQuan(q); //Re-calling the function using recursion until the right value is entered
	}
}

void Medication::setBar(string bar)
{
	for (int i = 0; i < bar.length(); i++)
	{
		if (!(bar[i] == 48 || bar[i] == 49))//Making sure each digit is either 0 or 1 only (48 and 49 using ASCII)
		{
			cout << "\nIncorrect barcode value. Please only enter zeros and ones." << endl;
			cin >> bar;
			setBar(bar);
		}
	}
	barcode = bar;
}

void Medication::setDate(int d, int m, int y) {
	Expiry_Date.setDayMonthYear(d, m, y);
}

string Medication::getMedName() const
{
	return medName;
}

string Medication::getDes() const
{
	return description;
}

double Medication::getPrice() const
{
	return price;
}

int Medication::getQuan() const
{
	return quantity;
}

int Medication::getID() {
	return medID;
}

Date Medication::getDate()
{
	return Expiry_Date;
}

string Medication::getBar() const
{
	return barcode;
}

int Medication::getMedCount() {
	return medCount;
}

void Medication::printMed() const
{
	cout << "\nName of medicine: " << medName << endl;
	cout << "Medication ID : " << medID << endl;
	cout << "Description of medication: " << description << endl;
	cout << "Price of medicine: " << price << endl;
	cout << "Quantity in stock: " << quantity << endl;
	cout << "Expiry date: ";
	Expiry_Date.print();
	cout << "Barcode: " << barcode << endl;
}
