#include "credit_card.hpp"


CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal) {
    number = no;
    name = nm;
    balance = bal;
    limit = lim;
}

bool CreditCard::chargelt(double price) {
    if (price + balance > (double)limit)
        return false;
    balance += price;
    return true;
}

void CreditCard::makePayment(double payment) {
    balance -= payment;
}

ostream& operator<<(ostream& out, const CreditCard& card) {
    out << "Number = "  << card.getNumber() << "\n"
        << "Name = " << card.getName() << "\n"
        << "Balance = " << card.getBalance() << "\n"
        << "Limit = " << card.getLimit() << endl;
    return out;
}