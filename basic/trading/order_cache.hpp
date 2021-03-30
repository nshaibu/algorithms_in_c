#ifndef ORDER_CACHE_HPP
#define ORDER_CACHE_HPP
#include <vector>
#include <string>
#include "order.hpp"

#include "./exceptions/exceptions.hpp"

using namespace std;

class Match {
    public:
        vector<Order> sellOrders;
        vector<Order> buyOrders;
        int totalQuantityMatched = 0;
};


class OrderCache {
    public:
        void addOrder(const string& security_id, const string& side, int qty,
                     const string& user_id, const string& company_name) ;
        int findOrderByOrderID(const string& order_id);
        const Match* getOrderMatchBySecurityID(const string& security_id) throw(OrderDoesNotExistError);
        vector<Order> findAllUserOrders(const string& order_id);
        vector<Order> findAllSecurityIDOrders(const string& security_id);
        void cancelOrderByOrderID(const string& order_id) throw(OrderDoesNotExistError);
        int cancelOrderByUserID(const string& user_id);
        int cancelOrderForSecurityID(const string& security_id, int limit_qty);
        unsigned int length() const { return mem.size(); }
        const Order getOrder(int position) throw(OrderDoesNotExistError); 
        void clearCache() { mem.clear(); }
    private:
        const string& getOrderID(); 
        vector<Order> mem;
};

#endif
