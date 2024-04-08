#include "Prescription.h"
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

Prescription::Prescription() : ApprovalDate()
{	//Default constructor
	FDANumber = 0;
}

Prescription::Prescription(const Prescription& obj) : Medication(obj)
{	//Copy constructor
	FDANumber = obj.FDANumber;
	ApprovalDate = obj.ApprovalDate;
}
Prescription::Prescription(string mn, string des, double p, int q, int d, int m, int y, string bar, int FDA, Date AppDate): Medication(mn,des,p,q,d,m,y,bar),FDANumber(FDA),ApprovalDate(AppDate)
{	//Parameterized constructor
}

Prescription::~Prescription()
{	//Destructor
}

void Prescription::setFDA(int FDA)
{
	while (FDA < 0) {
		cout << "Invalid FDA number. Please enter it properly: ";
		cin >> FDA;
	}
	FDANumber = FDA;
}

void Prescription::setAppDate(int d,int m,int y)
{
	ApprovalDate=Date::Date(d, m, y);
	
}

int Prescription::getFDA() const
{
	return FDANumber;
}

Date Prescription::getAppDate() const
{
	return ApprovalDate;
}

void Prescription::printMed() const
{
	Medication::printMed();
	cout << "FDA Number: " << FDANumber << endl;
	cout << "Approval date: ";
	ApprovalDate.print();
}
