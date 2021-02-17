#ifndef INDEXOUTOFRANGE_HPP
#define INDEXOUTOFRANGE_HPP
#include "base.hpp"
#include <string>

class IndexOutOfRangeError: public Exception {
    public:
        IndexOutOfRangeError(const std::string& msg):Exception(msg) {}
};

#endif
