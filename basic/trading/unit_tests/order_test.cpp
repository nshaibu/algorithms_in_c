#include <cassert>
using namespace std;

#include "order_test.hpp"

OrderTestCases::OrderTestCases(){
    order = new Order("OrdId1", "SecId1", "Sell", 100, "User10", "Company2");
}

void OrderTestCases::testOrderIDHasBeenSet() {
    assert((order->getOrderID() == "OrdId1"));
}

void OrderTestCases::testSecurityIDHasBeenSet() {
    test_run += 1;
    assert((order->getSecurityID() == "SecId1"));
}

void OrderTestCases::testCompanyNameHaveBeenSet() {
    test_run += 1;
    assert((order->getCompanyName() == "Company2"));
}

void OrderTestCases::testSideHasBeenSet() {
    test_run += 1;
    assert((order->getSide() == "Sell"));
}

void OrderTestCases::testQuantityHasBeenSet() {
    test_run += 1;
    assert((order->getQuantity() == 100));
}

void OrderTestCases::run() {
    std::cout << "Testing order:" << "\n"
                << "----------------------" << std::endl;
    try {
        testCompanyNameHaveBeenSet();
        testOrderIDHasBeenSet();
        testQuantityHasBeenSet();
        testSecurityIDHasBeenSet();
        testSideHasBeenSet();
        testQuantityHasBeenSet();
    }catch(const std::exception& r_e ) {
        std::cerr << "Test failed: " << r_e.what() << std::endl;
        fail_tests += 1;
    }

    cout << test_run << " tests runned. But " << fail_tests << " tests failed" << std::endl;
}