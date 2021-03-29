#include "order.hpp"

Order::Order(const string& order_id, 
            const string& security_id,
            const string& _side, int qty,
            const string& user_id, const string& company_name
            ){
        orderID = order_id;
        securityID = security_id;
        side = _side;
        quantity = qty;
        userID = user_id;
        companyName = company_name;
}

ostream& operator<<(ostream& out, const Order& order) {
    out << "Order ID : "  << order.getOrderID() << "\n"
        << "Security ID : " << order.getSecurityID() << "\n"
        << "User ID : " << order.getUserID() << "\n"
        // << "Quantity : " << order.getQuantity() << "\n"
        << "Side : " << order.getSide() << "\n"
        << "Company Name : "  << order.getCompanyName() << endl;
    return out;
}

