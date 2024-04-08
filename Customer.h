#pragma once
#include<string>
#include<iostream>
#include "Address.h"
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
class Customer {
private:
	string CName;
	const int ID;
	static int IDcounter;
	Address Customer_Add;
public:
	//CONSTRUCTORS/DESTRUCTORS
	Customer();
	Customer(const Customer&);
	Customer(string, Address);
	~Customer();

	//SETTERS
	void setName(string);
	void setAddress(string, string, string, string);

	//GETTERS
	string getName() const;
	int getID() const;
	Address getAddress() const;
	static int getIdCounter();

	//PRINTING DETAILS
	void printCustomer() const;
};


