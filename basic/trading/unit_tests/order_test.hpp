#ifndef ORDER_TEST_HPP
#define ORDER_TEST_HPP
#include <cassert>

#include "../order.hpp"

class OrderTestCases {
    public:
        OrderTestCases();
        void testOrderIDHasBeenSet();
        void testSecurityIDHasBeenSet();
        void testCompanyNameHaveBeenSet();
        void testSideHasBeenSet();
        void testQuantityHasBeenSet();
        ~OrderTestCases() { delete order; }
        void run();
    private:
        Order *order;
        int test_run =  0;
        int  fail_tests = 0;
};

#endif