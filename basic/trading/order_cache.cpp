#include "order.hpp"
#include "order_cache.hpp"

void OrderCache::addOrder(const string& security_id, const string& side, 
                        int qty, const string& user_id,
                        const string& company_name) {
    const string orderID = getOrderID();
    Order ord(orderID, security_id, side, qty, user_id, company_name);
    mem.push_back(ord);
}

string OrderCache::getOrderID() {
    int len = length();
    len += 1;
    return "OrdId" + std::to_string(len);
}

void OrderCache::print() {
    for (Order ord: mem) {
            cout << ord << endl;
    }
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
    int position = findOrderByOrderID(order_id);
    if (position == -1)
        throw OrderDoesNotExistError("Order does not exist.");
    vector<Order>::iterator it = mem.begin();
    mem.erase(it + position);
}

vector<Order> OrderCache::findAllUserOrders(const string& user_id) {
    vector<Order> vec;
    for (Order order : mem) {
        if (order.getUserID() == user_id)
            vec.push_back(order);
    }
    return vec;
}

vector<Order> OrderCache::findAllSecurityIDOrders(const string& security_id) {
    vector<Order> vec;
    for (Order order : mem) {
        if (order.getSecurityID() == security_id) {
            vec.push_back(order);
        }
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
    int count = 0;
    for (Order order: orders) {
        if  (order.getQuantity() >= limit_qty) {
            try {
                cancelOrderByOrderID(order.getOrderID());
                count++;
            } catch(Exception &ex) {}
        }
    }
    return count;
}

const Match* OrderCache::getOrderMatchBySecurityID(const string& security_id) throw(OrderDoesNotExistError) {
    vector<Order> orders = findAllSecurityIDOrders(security_id);
    if (orders.empty()) 
        throw OrderDoesNotExistError("Not orders discovered for security ID.");

    Match *match = new Match;

    // Classify  orders into buy and sell
    for (Order order: orders) {
        if (order.getSide() == "Buy")
            match->buyOrders.push_back(order);
        else 
            match->sellOrders.push_back(order);
    }

    int buyQuantity, sellQuantity, diffQuantity;

    if (match->buyOrders.empty() || match->sellOrders.empty()) {
        match->totalQuantityMatched = 0;
        return match;
    }

    for (Order buyOrder: match->buyOrders) {
        for (Order sellOrder: match->sellOrders) {
            buyQuantity = buyOrder.getQuantity();
            sellQuantity = sellOrder.getQuantity();
            
            if (sellQuantity == 0 || buyQuantity == 0) continue;

            if (buyOrder.getCompanyName() != sellOrder.getCompanyName()){
                if (buyQuantity == sellQuantity) {
                    buyOrder.setQuantity(0);
                    sellOrder.setQuantity(0);
                    match->totalQuantityMatched += buyQuantity;
                } else if (buyQuantity > sellQuantity) {
                    diffQuantity = buyQuantity -  sellQuantity;
                    buyOrder.setQuantity(diffQuantity);
                    sellOrder.setQuantity(0);
                    match->totalQuantityMatched += sellQuantity;
                } else {
                    diffQuantity = sellQuantity - buyQuantity;
                    buyOrder.setQuantity(0);
                    sellOrder.setQuantity(diffQuantity);
                    match->totalQuantityMatched += buyQuantity;
                }
            }
        }
    }

    return match;
}
