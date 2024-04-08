#include "Address.h"
using namespace std;
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/
Address::Address() {//Default constructor
	Email = "No email";
	City = "No City";
	PhoneNum = "";
	StreetName = "No Street name";
}
Address::Address(const Address& other) {//Copy constructor
	Email = other.Email;
	City = other.City;
	PhoneNum = other.PhoneNum;
	StreetName = other.StreetName;
}
Address::Address(string E, string C, string PN, string SN) {//Parameterized constructor
	SetEmail(E);
	SetCity(C);
	SetPhoneNum(PN);
	SetStreetName(SN);
}
Address::~Address() {

}
void Address::SetEmail(string E) {
	while (E == "") {
		cout << "Invalid email. Please re-enter the email correctly (End it with '.')." << endl;
		cin.ignore();
		getline(cin, E, '.');
	}
	Email = E;
}
void Address::SetCity(string C) {
	while (C == "") {
		cout << "Invalid city. Please re-enter the city correctly (End it with '.')." << endl;
		cin.ignore();
		getline(cin, C, '.');
	}
	City = C;
}
void Address::SetPhoneNum(string PN) {
	while (PN.length() != 10) //Phone number is only 10 digits
	{
		cout << "\nPlease enter a valid phone number of 10 digits only: ";
		cin >> PN;
	}

	for (int i = 0; i < 10; i++)
	{ //Making sure all the characters in the string are numbers and not characters, if they are we re-call the function using recursion
		if (!(PN[i] >= 48 && PN[i] <= 57))
		{
			cout << "\nPlease enter a valid phone number with digits only: ";
			cin >> PN;
			SetPhoneNum(PN);
		}
	}
	PhoneNum = PN;
}
void Address::SetStreetName(string SN) {
	while (SN == "") {
		cout << "Invalid street name. Please re-enter the street name correctly (End it with '.')." << endl;
		cin.ignore();
		getline(cin, SN, '.');
	}
	StreetName = SN;
}

string Address::GetEmail() const { 
	return Email; 
}

string Address::GetCity() const { 
	return City; 
}

string Address::GetPhoneNum() const { 
	return PhoneNum; 
}

string Address::GetStreetName() const {
	return StreetName; 
}

void Address::print() const {
	cout << "Customer email: " << Email << endl;
	cout << "Customer city: " << City << endl;
	cout << "Customer phone number: " << PhoneNum << endl;
	cout << "Customer street name: " << StreetName << endl;
}