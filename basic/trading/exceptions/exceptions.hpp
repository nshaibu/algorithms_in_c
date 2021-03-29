#ifndef ORDERERRORS_HPP
#define ORDERERRORS_HPP
#include "base.hpp"
#include <string>

class OrderAdditionError: public Exception {
    public:
        OrderAdditionError(const std::string& msg):Exception(msg) {}
};

class OrderDoesNotExistError: public Exception {
    public:
        OrderDoesNotExistError(const std::string& msg):Exception(msg) {}
};

#endif
