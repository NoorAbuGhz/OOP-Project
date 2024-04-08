#pragma once
#include "Medication.h"
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

class Prescription : public Medication {
private:
	int FDANumber;
	Date ApprovalDate;
public:
	//Constructors and deconstructor
	Prescription();
	Prescription(const Prescription&obj);
	Prescription(string mn, string des, double p, int q, int d, int m, int y, string bar, int FDA, Date AppDate);
	~Prescription();

	//Setters and getters
	void setFDA(int);
	void setAppDate(int,int,int);
	int getFDA() const;
	Date getAppDate() const;

	//print function
	void printMed() const;
};