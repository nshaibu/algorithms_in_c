#include <string>

#include "order_cache_test.hpp"

void OrderCacheTestCases::testOrderCanBeAddToCache() {
    test_run += 1;
    cache->addOrder("SecId1", "Sell", 100, "User10", "Company2");
    cache->addOrder("SecId3", "Sell", 200, "User8", "Company2");
    cache->addOrder("SecId2", "Buy", 900, "User6", "Company2");
    cache->addOrder("SecId1", "Sell", 1100, "User13", "Company2");
    cache->addOrder("SecId1", "Sell", 200, "User8", "Company2");
    assert((cache->length() == 5));
}

void OrderCacheTestCases::testOrderCanBefindByOrderID() {
    test_run += 1;
    std::string order_id = "OrdId1";
    int position = cache->findOrderByOrderID(order_id);
    assert((position != -1));
}

void OrderCacheTestCases::testAllOrdersCanBeFindByUserID() {
    test_run += 1;
    std::string user_id = "User8";
    vector<Order> orders = cache->findAllUserOrders(user_id);
    assert((orders.size() == 2));
}

void OrderCacheTestCases::testAllOrdersCanBeFindBySecurityID() {
    test_run += 1;
    std::string security_id = "SecId1";
    vector<Order> orders = cache->findAllSecurityIDOrders(security_id);
    assert((orders.size() == 3));
}

void OrderCacheTestCases::testOrderCanBeCancelledByOrderID() {
    test_run += 1;
    std::string order_id = "OrdId1";
    cache->cancelOrderByOrderID(order_id);
    int position = cache->findOrderByOrderID(order_id);
    assert((position == -1));
}

void OrderCacheTestCases::testOrdersCanBeCancelledByUserID() {
    test_run += 1;
    std::string user_id = "User8";
    int count =  cache->cancelOrderByUserID(user_id);
    assert((count == 2));
}

void OrderCacheTestCases::testAllOrdersOfSecurityIDAtAQuantityLimitCanBeCancelled() {
    test_run += 1;
    std::string security_id = "SecId1";
    int count = cache->cancelOrderForSecurityID(security_id, 200);
    assert((count == 2));
}

void OrderCacheTestCases::run() {
    std::cout << "\nTesting order cache:" << "\n"
                << "----------------------" << std::endl;
    try {
        testOrderCanBeAddToCache();
        testOrderCanBefindByOrderID();
        testAllOrdersCanBeFindByUserID();
        testAllOrdersCanBeFindBySecurityID();
        testOrderCanBeCancelledByOrderID();
        testOrdersCanBeCancelledByUserID();
        testAllOrdersOfSecurityIDAtAQuantityLimitCanBeCancelled();
    }catch(const std::exception& r_e ) {
        std::cerr << "Test failed: " << r_e.what() << std::endl;
        fail_tests += 1;
    }

    cout << test_run << " tests runned. But " << fail_tests << " tests failed" << std::endl;
}

