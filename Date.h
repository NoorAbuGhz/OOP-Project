#pragma once
#include<iostream>
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
class Date {
private:
	int day, month, year;
public:
	//Constructors
	Date();
	Date(const Date&);
	Date(int, int, int);

	//Setters
	void setDayMonthYear(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	//Getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	//Print function
	void print() const;
};

