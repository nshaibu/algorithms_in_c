#ifndef ORDER_HPP
#define ORDER_HPP
#include <iostream>
#include <string>
using namespace std;

class Order {
    public:
        Order(const string& order_id, const string& security_id, 
         const string& _side, int qty, const string& user_id, const string& company_name);
        string getOrderID() const { return orderID; }
        string getUserID() const { return userID; }
        string getSecurityID() const { return securityID; }
        int getQuantity() { return quantity; }
        string getCompanyName() const { return companyName; }
        string getSide() const { return side; }
    private:
        string orderID;
        string securityID;
        string side;
        int quantity;
        string userID;
        string companyName;
};

ostream& operator<<(ostream& out, const Order& order);

#endif