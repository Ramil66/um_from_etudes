#ifndef EXCEPT_H
#define EXCEPT_H
#include <exception>
#include <string>

class vm_error:public std::exception{
public:
    vm_error(const std::string& message): message{message}
    {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};

#endif // EXCEPT_H
