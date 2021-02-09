#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H
#include<iostream>
#include<string>
using namespace std;

class CreditCard {
    public:
        CreditCard(const string& no, const string& nm, int lim, double bal=0);
        string getNumber() const { return number; }
        string getName() const { return name; }
        double getBalance() const {  return balance; }
        int getLimit() const { return limit; }

        bool chargelt(double price);
        void makePayment(double payment);
    private:
        string number;
        string name;
        int limit;
        double balance;
};

ostream& operator<<(ostream& out, const CreditCard& card);
#endif
