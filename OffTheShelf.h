#pragma once
#include "Medication.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

class OffTheShelf : public Medication {
private:
	bool BOGOF;
	Date OfferEnds;
public:
	//Constructors and deconstructor
	OffTheShelf();
	OffTheShelf(bool b, const Date& o, const Medication& med);
	OffTheShelf(bool b, int d, int m, int y, string mn, string des, double p, int q, int dMed, int mMed, int yMed, string bar);
	OffTheShelf(const OffTheShelf& ots);
	~OffTheShelf();

	//Setters
	void setBOGOF(bool b);
	void setOffEndObj(const Date& o);
	void setOffEnd(int d, int m, int y);

	//Getters
	bool getBOGOF() const;
	Date getOffEnd() const;

	//Print function
	void printOTS();
};
