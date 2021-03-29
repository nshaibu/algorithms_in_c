#include "order.hpp"
#include "order_cache.hpp"

void OrderCache::addOrder(const string& user_id, const string& company_name, int qty,
                     const string& side, const string& security_id) {
    const string orderID = getOrderID();
    Order ord(orderID, security_id, side, qty, user_id, company_name);
    mem.push_back(ord);
}

const string& OrderCache::getOrderID() {
    int len = length();
    len += 1;
    static string order_id = "OrdId" + std::to_string(len);
    return order_id;
}

int OrderCache::findOrderByOrderID(const string& order_id) {
    int postion = -1;

    for (int i=0; i<length(); ++i) {
        Order ord = mem[i];
        if (ord.getOrderID() == order_id) {
            postion = i;
            break;
        }
    }

    return postion;
}

const Order OrderCache::getOrder(int position) throw(OrderDoesNotExistError) {
    int len = length();
    if (position > len - 1)
        throw OrderDoesNotExistError("Order does not exists.");
    return mem[position]; 
}

void OrderCache::cancelOrderByOrderID(const string& order_id) throw(OrderDoesNotExistError){
    int postion = findOrderByOrderID(order_id);
    if (postion == -1)
        throw OrderDoesNotExistError("Order does not exist.");
    mem.erase(mem.begin() +  postion);
}

const vector<Order> OrderCache::findAllUserOrders(const string& order_id) {
    vector<Order> vec;
    for (Order order : mem) {
        if (order.getOrderID() == order_id)
            vec.push_back(order);
    }
    return vec;
}

const vector<Order> OrderCache::findAllSecurityIDOrders(const string& security_id) {
    vector<Order> vec;
    for (Order order : mem) {
        if (order.getSecurityID() == security_id)
            vec.push_back(order);
    }
    return vec;
}

int OrderCache::cancelOrderByUserID(const string& user_id) {
    const vector<Order> orders = findAllUserOrders(user_id);
    int failCounts = 0;
    for (Order order: orders) {
        try {
            cancelOrderByOrderID(order.getOrderID());
        } catch(Exception &ex) {
            failCounts += 1;
        }
    }
    return orders.size() - failCounts; 
}

int OrderCache::cancelOrderForSecurityID(const string& security_id, int limit_qty) {
    const vector<Order> orders = findAllSecurityIDOrders(security_id);
    int failCounts =  0;
    for (Order order: orders) {
        if  (order.getQuantity() >= limit_qty) {
            try {
                cancelOrderByOrderID(order.getOrderID());
            } catch(Exception &ex) {
                failCounts += 1;
            }
        }
    }
    return orders.size() - failCounts;
}
