#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <string>

class Exception {
    public:
        Exception(std::string& message):error_msg(message) {}
        std::string getMessage() const { return error_msg; }
    private:
        std::string error_msg;
};

#endif
