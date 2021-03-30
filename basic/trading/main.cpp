#include <iostream>
#include "order_cache.hpp"


int main() {
    OrderCache cache;

    cout << "Output for Example 0:" << "\n" 
        << "----------------------------------------" << std::endl;
    cache.addOrder("SecId1", "Buy", 1000, "User1", "CompanyA");
    cache.addOrder("SecId2", "Sell", 3000, "User2", "CompanyB");
    cache.addOrder("SecId1", "Sell", 500, "User3", "CompanyA");
    cache.addOrder("SecId2", "Buy", 600, "User4", "CompanyC");
    cache.addOrder("SecId2", "Buy", 100, "User5", "CompanyB");
    cache.addOrder("SecId3", "Buy", 1000, "User6", "CompanyD");
    cache.addOrder("SecId2", "Buy", 2000, "User7", "CompanyE");
    cache.addOrder("SecId2", "Sell", 5000, "User8", "CompanyE");

    cout << "Total number of orders in cache:  " << cache.length() << std::endl;
    const Match *secId1Example0 = cache.getOrderMatchBySecurityID("SecId1");
    const Match *secId2Example0 = cache.getOrderMatchBySecurityID("SecId2");
    const Match *secId3Example0 = cache.getOrderMatchBySecurityID("SecId3");
    cout << "Total matched quantity for security ID: SecId1 is " << secId1Example0->totalQuantityMatched << std::endl;
    cout << "Total matched quantity for security ID: SecId2 is " << secId2Example0->totalQuantityMatched << std::endl;
    cout << "Total matched quantity for security ID: SecId3 is " << secId3Example0->totalQuantityMatched << std::endl;

    delete secId1Example0;
    delete secId2Example0;
    delete secId3Example0;
    cache.clearCache();

    cout << "\n\nOutput for Example 1:" << "\n" 
        << "----------------------------------------" << std::endl;
    cache.addOrder("SecId1", "Sell", 100, "User10", "Company2");
    cache.addOrder("SecId3", "Sell", 200, "User8", "Company2");
    cache.addOrder("SecId1", "Buy", 300, "User13", "Company2");
    cache.addOrder("SecId2", "Sell", 400, "User12", "Company2");
    cache.addOrder("SecId3", "Sell", 500, "User7", "Company2");
    cache.addOrder("SecId3", "Buy", 600, "User3", "Company1");
    cache.addOrder("SecId1", "Sell", 700, "User10", "Company2");
    cache.addOrder("SecId1", "Sell", 800, "User2", "Company1");
    cache.addOrder("SecId2", "Buy", 900, "User6", "Company2");
    cache.addOrder("SecId2", "Sell",  1000, "User5", "Company1");
    cache.addOrder("SecId1", "Sell", 1100, "User13", "Company2");
    cache.addOrder("SecId2", "Buy", 1200, "User9", "Company2");
    cache.addOrder("SecId1", "Sell", 1300, "User1", "Company");

    cout << "Total number of orders in cache:  " << cache.length() << std::endl;
    const Match *secId1Example1 = cache.getOrderMatchBySecurityID("SecId1");
    const Match *secId2Example1 = cache.getOrderMatchBySecurityID("SecId2");
    const Match *secId3Example1 = cache.getOrderMatchBySecurityID("SecId3");
    cout << "Total matched quantity for security ID: SecId1 is " << secId1Example1->totalQuantityMatched << std::endl;
    cout << "Total matched quantity for security ID: SecId2 is " << secId2Example1->totalQuantityMatched << std::endl;
    cout << "Total matched quantity for security ID: SecId3 is " << secId3Example1->totalQuantityMatched << std::endl;

    delete secId1Example1; 
    delete secId2Example1;
    delete secId3Example1;
    cache.clearCache();

    cout << "\n\nOutput for Example 2:" << "\n" 
        << "----------------------------------------" << std::endl;
    cache.addOrder("SecId3", "Sell", 100, "User1", "Company1");
    cache.addOrder("SecId3", "Sell", 200, "User3", "Company2");
    cache.addOrder("SecId1", "Buy", 300, "User2", "Company1");
    cache.addOrder("SecId3", "Sell", 400, "User5", "Company2");
    cache.addOrder("SecId2", "Sell", 500, "User2", "Company1");
    cache.addOrder("SecId2", "Buy", 600, "User3",  "Company2");
    cache.addOrder("SecId2", "Sell", 700, "User1", "Company1");
    cache.addOrder("SecId1", "Sell", 800, "User2", "Company1");
    cache.addOrder("SecId1", "Buy", 900, "User5", "Company2");
    cache.addOrder("SecId1", "Sell", 1000, "User1", "Company1");
    cache.addOrder("SecId2", "Sell", 1100, "User6", "Company2");

    cout << "Total number of orders in cache:  " << cache.length() << std::endl;
    const Match *secId1Example2 = cache.getOrderMatchBySecurityID("SecId1");
    const Match *secId2Example2 = cache.getOrderMatchBySecurityID("SecId2");
    const Match *secId3Example2 = cache.getOrderMatchBySecurityID("SecId3");
    cout << "Total matched quantity for security ID: SecId1 is " << secId1Example2->totalQuantityMatched << std::endl;
    cout << "Total matched quantity for security ID: SecId2 is " << secId2Example2->totalQuantityMatched << std::endl;
    cout << "Total matched quantity for security ID: SecId3 is " << secId3Example2->totalQuantityMatched << std::endl;

    delete secId1Example2;
    delete secId2Example2;
    delete secId3Example2;
    cache.clearCache();
    return 0;
}