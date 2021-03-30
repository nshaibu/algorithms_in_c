#ifndef ORDERCACHE_TEST_HPP
#define ORDERCACHE_TEST_HPP
#include <cassert>

#include "../order_cache.hpp"

class OrderCacheTestCases {
    public:
        OrderCacheTestCases() { cache = new OrderCache; };
        void testOrderCanBeAddToCache();
        void testOrderCanBefindByOrderID();
        void testAllOrdersCanBeFindByUserID();
        void testAllOrdersCanBeFindBySecurityID();
        void testOrderCanBeCancelledByOrderID();
        void testOrdersCanBeCancelledByUserID();
        void testAllOrdersOfSecurityIDAtAQuantityLimitCanBeCancelled();
        ~OrderCacheTestCases() { delete cache; }
        void run();
    private:
        OrderCache *cache;
        int test_run =  0;
        int  fail_tests = 0;
};

#endif