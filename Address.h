#pragma once
#include <iostream>
#include <string>
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
using namespace std;
class Address {
private:
	string Email;
	string City;
	string PhoneNum;
	string StreetName;
public:
	//Constructors and deconstructor
	Address();
	Address(const Address&);
	Address(string, string, string, string);
	~Address();

	//Setters
	void SetEmail(string);
	void SetCity(string);
	void SetPhoneNum(string);
	void SetStreetName(string);

	//Getters
	string GetEmail() const;
	string GetCity() const;
	string GetPhoneNum() const;
	string GetStreetName() const;

	//Print Function
	void print() const;
};