#include "Customer.h"
#include<string>

/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

int Customer::IDcounter = 0;

Customer::Customer() : ID(++IDcounter), Customer_Add() { //Default constructor
	CName = "";
}

Customer::Customer(string n, Address other) :ID(++IDcounter), Customer_Add(other) { //Parameterized constructor
	setName(n);
}

Customer::Customer(const Customer& other) : ID(other.ID), Customer_Add(other.Customer_Add) //Copy constructor
{
	CName = other.CName;
}

Customer::~Customer() {} //Destructor

void Customer::setName(string n)
{
	while (n == "") {
		cout << "Invalid entry. Please re-enter the name correctly (End it with '.')." << endl;
		cin.ignore();
		getline(cin, n, '.');
	}
	CName = n;
}

void Customer::setAddress(string E, string C, string PN, string SN) {
	Customer_Add.SetEmail(E);
	Customer_Add.SetCity(C);
	Customer_Add.SetPhoneNum(PN);
	Customer_Add.SetStreetName(SN);
}

string Customer::getName() const
{
	return CName;
}

int Customer::getID() const
{
	return ID;
}


Address Customer::getAddress() const
{
	return Customer_Add;
}

int Customer::getIdCounter() {
	return IDcounter;
}

void Customer::printCustomer() const
{
	cout << "Customer Name: " << CName << endl;
	cout << "Customer ID: " << ID << endl;
	Customer_Add.print();
}
