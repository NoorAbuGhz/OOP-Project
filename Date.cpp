#include "Date.h"
#include<iostream>
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}

Date::Date(int d, int m, int y)
{
	setDayMonthYear(d, m, y);
}

void Date::setDayMonthYear(int d, int m, int y) {
	while (y < 0)
	{
		cout << "Please re-enter a proper year.";
		cin >> y;
	}
	year = y;
	while (m < 1 || m>12) {
		cout << "Please enter a number between 1 and 12: ";
		cin >> m;
	}
	month = m;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) //31 day months (January,March,May,July,August,October,December)
	{
		while (!(d >= 1 && d <= 31)) {
			cout << "Please make sure the day is appropriately between 1-31: ";
			cin >> d;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) //30 day months (April,June,September,November)
	{
		while (!(d >= 1 && d <= 30)) {
			cout << "Please make sure the day is appropriately between 1-30: ";
			cin >> d;
		}
	}
	else //February 
	{
		if ((y % 4 == 0 && y % 100 != 0) || year % 400 == 0) { //Febuary during a leap year
			while (!(d >= 1 && d <= 29)) {
				cout << "Please make sure the day is appropriately between 1-29: ";
				cin >> d;
			}
		}
		else {
			while (!(d >= 1 && d <= 28)) {
				cout << "Please make sure the day is appropriately between 1-28: ";
				cin >> d;
			}
		}
	}
	day = d;
}
void Date::setDay(int d) {

	while (!(d >= 1 && d <= 31)) {
		cout << "Please make sure the day is appropriately between 1-31: ";
		cin >> d;
	}
	day = d;
}
void Date::setMonth(int m) {
	while (m < 1 || m>12) {
		cout << "Please enter a number between 1 and 12: ";
		cin >> m;
	}
	month = m;
}
void Date::setYear(int y) {
	while (y < 0)
	{
		cout << "Please re-enter a proper year.";
		cin >> y;
	}
	year = y;
}
int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::print() const
{
	cout << "Date: ";
	if (day < 10)
		cout << "0" << day << "/";
	else
		cout << day << "/";
	if (month < 10)
		cout << "0" << month << "/";
	else
		cout << month << "/";
	cout << year << endl;
}
