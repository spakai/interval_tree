#pragma once

#include <string>
#include <exception>

class NoMatchException : public std::exception {
    public:
        NoMatchException(const char* msg) : mMsg(msg) {}
        virtual ~NoMatchException() throw() {}
        const char* what() const throw()  {return mMsg.c_str();}
    protected:
        std::string mMsg;
};
