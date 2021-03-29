#include <iostream>
#include "order_cache.hpp"


int main() {
    OrderCache cache;

    cache.addOrder("SecId1", "Buy", 1000, "User1",  "CompanyA");
    cache.addOrder("SecId2", "Sell", 3000, "User2",  "CompanyB");
    cache.addOrder("SecId1", "Sell", 500, "User3",  "CompanyA");
    cache.addOrder("SecId2", "Buy", 600, "User4",  "CompanyC");
    cache.addOrder("SecI2", "Buy", 100, "User5",  "CompanB");
    cache.addOrder("SecId3", "Buy", 1000, "User6", "CompanyD");
    cache.addOrder("SecId2", "Buy", 2000, "User7", "CompanyE");
    cache.addOrder("SecId2", "Sell", 5000, "User8", "CompanyE");

    cout << cache.findOrderByOrderID("OrdId1") << std::endl;
    cout << cache.getOrder(3) << std::endl;
    cout << cache.length() << std::endl;
    return 0;
}