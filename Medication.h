#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Date.h"
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

class Medication {
private:
	int medID;  
	string medName;
	string description;
	double price;
	int quantity;
	Date Expiry_Date;
	string barcode;
	static int medCount;
	int day;
	int month;
	int year;

public:
	//CONSTRUCTORS/DESTRUCTORS
	Medication(const Medication&);
	Medication();
	Medication(string, string, double, int, int, int, int, string);
	~Medication();

	//SETTERS
	void setMedName(string);
	void setDes(string);
	void setPrice(double);
	void setQuan(int);
	void setBar(string);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);

	//GETTERS
	string getMedName() const;
	string getDes() const;
	double getPrice() const;
	int getQuan() const;
	string getBar() const;
	int getID();
	Date getDate();
	int getMedCount();
	

	//PRINTING DETAILS
	void printMed() const;
};

