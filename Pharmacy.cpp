#include "Pharmacy.h"
/*
* ZAINA HASAN 20220512
* KINDA MASHAL 20220021
* MURAD SALAYTAH 20220020
* NOOR ABU GHAZALEH 20220785
*/

int Pharmacy::ID_counter = 0;
Pharmacy::Pharmacy() :ID(++ID_counter)
{
    currM = 0;
    currC = 0;
    PharName = " ";
    maxM = 10;
    maxC = 10;
    meds = new Medication[maxM];
    cust = new Customer[maxC];
}//default constructer

Pharmacy::~Pharmacy()
{
    delete[]meds;
    meds = 0;
    delete[]cust;
    cust = 0;

}//destructer

void Pharmacy::setName(string n)
{
    if (n != "\0") {
        PharName = n;
    }
}

string Pharmacy::getName()
{
    return PharName;
}

int Pharmacy::getCurrM()
{
    return currM;
}//this returns the number of medication

int Pharmacy::getCurrC()
{
    return currC;
}//this returns the number of customers

int Pharmacy::getID()
{
    return ID;
}

void Pharmacy::AddMed(Medication m)
{
    if (currM == maxM) {  //if the number of medications reached the max then the user cant add medication
        expandM();
    }

    meds[currM].setMedName(m.getMedName());
    meds[currM].setDes(m.getDes());
    meds[currM].setPrice(m.getPrice());
    meds[currM].setQuan(m.getQuan());
    meds[currM].setBar(m.getBar());
    currM++;
    //the code above adds medication to the list by using the number of medication as an index
    //and changes the default values by setting new values
}

void Pharmacy::AddCust(Customer c)
{
    if (currC == maxC) {  //if the number of customers reached the max then the user cant add customers
        expandC();
    }

    cust[currC].setName(c.getName());
    cust[currC].getAddress().SetCity(c.getAddress().GetCity());
    cust[currC].getAddress().SetEmail(c.getAddress().GetEmail());
    cust[currC].getAddress().SetPhoneNum(c.getAddress().GetPhoneNum());
    cust[currC].getAddress().SetStreetName(c.getAddress().GetStreetName());
    currC++;
    //the code above adds customer to the list by using the number of customers as an index
    //and changes the default values by setting new values
}

void Pharmacy::RemoveMed(Medication m)
{
    int index = -1;//to store the index where the medication is found in the meds list
    for (int i = 0; i < currM; i++) {
        if (meds[i].getMedName() == m.getMedName()) {
            index = i;

        }
    }
    // the code above searches for the medication in the list using the ID because ID is unique for each medication
    if (index == -1) {
        cout << "Medication not found\n";
    }//if index == -1 then the medication was not found
    else {
        for (int i = index + 1; i < currM; i++) {
            meds[i - 1].setMedName(meds[i].getMedName());
            meds[i - 1].setDes(meds[i].getDes());
            meds[i - 1].setPrice(meds[i].getPrice());
            meds[i - 1].setQuan(meds[i].getQuan());
            meds[i - 1].setBar(meds[i].getBar());
        }//if medication is found then the code above will remove it from the list
        //and will shift the medications in the list to fill in the gap of the removed medication
    }
    currM--;//this hints that the number of medications has decreased by 1 after the medication was removed
}
void Pharmacy::expandM() {
    maxM = maxM + 5;
    Medication* m = new Medication[maxM];
    for (int i = 0; i < currM; i++) {
        m[i].setMedName(meds[i].getMedName());
        m[i].setDes(meds[i].getDes());
        m[i].setPrice(meds[i].getPrice());
        m[i].setQuan(meds[i].getQuan());
        m[i].setBar(meds[i].getBar());
    }
    delete[]meds;
    meds = 0;
    meds = m;
    delete[]m;
    m = 0;
}//this code above expands the list of mediactions to add in the pharmacy
void Pharmacy::expandC() {
    maxC = maxC + 5;
    Customer* c = new Customer[maxM];
    for (int i = 0; i < currC; i++) {
        c[i].setName(cust[i].getName());
        c[i].getAddress().SetCity(cust[i].getAddress().GetCity());
        c[i].getAddress().SetEmail(cust[i].getAddress().GetEmail());
        c[i].getAddress().SetPhoneNum(cust[i].getAddress().GetPhoneNum());
        c[i].getAddress().SetStreetName(cust[i].getAddress().GetStreetName());
    }
    delete[]cust;
    cust = 0;
    cust = c;
    delete[]c;
    c = 0;
}//this code above expands the list of customers to add in the pharmacy
void Pharmacy::DisplayMed()
{
    for (int i = 0; i < currM; i++) {
        meds[i].printMed();
    }
}//this prints out all the available medication in the pharmacy

void Pharmacy::DisplayCust()
{
    for (int i = 0; i < currC; i++) {
        cust[i].printCustomer();
    }
}//this prints out a list of customers
double Pharmacy::getSales()
{
    return sumSales;
}//Returns total sales per pharmacy

void Pharmacy::purchases(string name, int quan)
{ //Subtracts number of medication bought from its quantity
    int k = currM;
    while (k >= 0) {
        if (meds[k].getMedName() == name) {
            meds[k].setQuan(meds[k].getQuan() - quan);
            break;
        }
        if (k == 0) {
            cout << "Medicine entered not in pharmacy." << endl;
            break;
        }
        k--;
    }
}

void Pharmacy::stocks(string name, int quan)
{ //Summing up total sales of medications
    for (int k = 0; k < currM; k++) {
        if (meds[k].getMedName() == name) {
            sumSales += meds[k].getPrice() * quan;
        }
    }
}

bool Pharmacy::compareCustNum(const Pharmacy& p) {//Compares number of customers of two pharmacies, returning true if current pharmacy has more
    if (currC > p.currC) {
        cout << PharName << " has more customers than " << p.PharName << endl;
        return true;
    }
    else if (currC == p.currC) {
        cout << PharName << " has the same number of customers as " << p.PharName << endl;
        return false;
    }
    else {
        cout << PharName << " has less customers than " << p.PharName << endl;
        return false;
    }
}

bool Pharmacy::compareMedNum(const Pharmacy& p) {//Compares number of medications of two pharmacies, returning true if current pharmacy has more
    if (currM > p.currM) {
        cout << PharName << " has more medications than " << p.PharName << endl;
        return true;
    }
    else if (currM == p.currM) {
        cout << PharName << "has the same number of medications as " << p.PharName << endl;
        return false;
    }
    else {
        cout << PharName << "has less medications than " << p.PharName << endl;
        return false;
    }
}

bool Pharmacy::compareSales(const Pharmacy& p) {//Compares number of sales of two pharmacies, returning true if current pharmacy has more
    if (sumSales > p.sumSales) {
        cout << PharName << " has more sales than " << p.PharName << endl;
        return true;
    }
    else if (sumSales == p.sumSales) {
        cout << PharName << " has the same sales of medications as " << p.PharName << endl;
        return false;
    }
    else {
        cout << PharName << " has less sales than " << p.PharName << endl;
        return false;
    }
}

