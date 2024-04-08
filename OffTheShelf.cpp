#pragma once
#include "Medication.h"
#include "Date.h"
#include <iostream>
#include <string>
#include "OffTheShelf.h"
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

OffTheShelf::OffTheShelf() : OfferEnds()
{ //Default constructor
	BOGOF = false;
	OfferEnds.setYear(OfferEnds.getYear() + 2); 
}

OffTheShelf::OffTheShelf(bool b, const Date& o, const Medication& med) : OfferEnds(o), Medication(med)
{//Parametarised constructor that takes date object
	setBOGOF(b);
	if (BOGOF == 0)  //CHanging date accordingly based off BOGOF's value
		OfferEnds.setYear(OfferEnds.getYear() + 2);
	else {
		if (OfferEnds.getMonth() > 9)
			OfferEnds.setMonth(OfferEnds.getMonth() + 3 - 12);
		else
			OfferEnds.setMonth(OfferEnds.getMonth() + 3);
	}
}

OffTheShelf::OffTheShelf(bool b, int d, int m, int y, string mn, string des, double p, int q, int dMed, int mMed, int yMed, string bar) : OfferEnds(d, m, y), Medication(mn, des, p, q, d, m, y, bar)
{//Parametarised constructor that takes each data member individually
	setBOGOF(b);
	if (BOGOF == 0) //CHanging date accordingly based off BOGOF's value
		OfferEnds.setYear(OfferEnds.getYear() + 2);
	else {
		if (OfferEnds.getMonth() > 9)
			OfferEnds.setMonth(OfferEnds.getMonth() + 3 - 12);
		else
			OfferEnds.setMonth(OfferEnds.getMonth() + 3);
	}
}

OffTheShelf::OffTheShelf(const OffTheShelf& ots) : OfferEnds(ots.OfferEnds), Medication(ots.getMedName(), ots.getDes(), ots.getPrice(), ots.getQuan(), ots.OfferEnds.getDay(), ots.OfferEnds.getMonth(), ots.OfferEnds.getYear(), ots.getBar()) 
{//Copy constructor
	BOGOF = ots.BOGOF;
}

OffTheShelf::~OffTheShelf() {} //Deconstructor

void OffTheShelf::setBOGOF(bool b)
{//Setter for BOGOF data member
	if (b == 0 || b == 1) {
		BOGOF = b;
	}
}

void OffTheShelf::setOffEndObj(const Date& o)
{//Setter for OfferEnds data member that takes an object of type Date
	OfferEnds.setDayMonthYear(o.getDay(), o.getMonth(), o.getYear());
}

void OffTheShelf::setOffEnd(int d, int m, int y)
{//Setter for OfferEnds data member that takes each data member needed for creation of OfferEnds data member individually
	OfferEnds.setDayMonthYear(d, m, y);
}

bool OffTheShelf::getBOGOF() const
{//Getter for BOGOF data member
	return false;
}

Date OffTheShelf::getOffEnd() const
{//Getter for OfferEnds data member
	return OfferEnds;
}

void OffTheShelf::printOTS()
{//Print function
	printMed();
	if (BOGOF == 1)
		cout << "Buy One Get One Free: Yes" << endl;
	else
		cout << "Buy One Get One Free: No" << endl;
	OfferEnds.print();
}
