/*
error.hpp

Defining error type
*/

#pragma once

#include <map>
#include <string>
#include <iostream>

namespace CEB
{
    class CEBError;
    class _CEBErrorType;
    typedef const _CEBErrorType CEBErrorType;

    class CEBError
    {
    private:
        int status;
        std::string message;

    public:
        // constructors

        CEBError();
        CEBError(CEBError &);
        CEBError(CEBErrorType);
        CEBError(int);
        CEBError(int, std::string);

        std::string messageWithErrorType() const;
        std::string getMessage() const;
        std::string getErrorType() const;
        int getStatus() const;

        // operators

        friend std::ostream &operator<<(std::ostream &, const CEBError &);
        bool operator==(const CEBError &) const;
        bool operator==(CEBErrorType &) const;
        bool operator!=(const CEBError &) const;
        bool operator!=(CEBErrorType &) const;

    private:
        // static variables

        // error type
        static inline std::map<int, std::string> errorTypes;

    public:
        // static functions

        // set error type
        static bool setErrorType(int, std::string);
    };

    class _CEBErrorType
    {
    private:
        const int status;

    public:
        // constructors
        _CEBErrorType(int, std::string);

        int getStatus() const;
        CEBError operator()(std::string) const;
    };

    // global variables

    namespace cebet
    {
        CEBErrorType NoErr(0, "No Error");
        CEBErrorType MoveBackErr(110, "Move Back Error");
        CEBErrorType MoveErr(120, "Move Error");
    }
}