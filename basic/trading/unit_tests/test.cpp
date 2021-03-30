#include <iostream>
#include <assert.h>
#include <stdexcept>

#include "order_cache_test.hpp"
#include "order_test.hpp"

int main() {
    OrderTestCases orderTestCase;
    OrderCacheTestCases cacheTestCase;
    
    orderTestCase.run();

    cacheTestCase.run();

}