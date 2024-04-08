#pragma once
#include "Customer.h"
#include "Medication.h"
#include<string>
#include<iostream>
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
class Pharmacy {
private:
	const int ID;
	static int ID_counter;
	string PharName;
	Medication* meds;
	Customer* cust;
	int currM;//to check the number of medication in the list
	int currC;//to check the number of customers in the list
	int maxM;//the max number of medications to be added
	int maxC;//the max number of costi=umers to be added
	void expandM(); //to expand the list of medications
	void expandC(); //to expand the list of costumers
	double sumSales;
public:
	//constructers and destructers
	Pharmacy();
	~Pharmacy();

	//setters and getters
	void setName(string);
	string getName();
	int getCurrM();
	int getCurrC();
	int getID();
	double getSales();

	//Member functions
	void AddMed(Medication);//this function adds medication in the mediaction list
	void AddCust(Customer);//this function adds customers in the customers list 
	void RemoveMed(Medication);//this removes mediaction from the medication list
	void DisplayMed();
	void DisplayCust();
	void purchases(string, int);
	void stocks(string, int);
	bool compareCustNum(const Pharmacy&);
	bool compareMedNum(const Pharmacy&);
	bool compareSales(const Pharmacy&);



};