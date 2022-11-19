#include "error.hpp"

namespace CEB
{
    // CEBError

    // constructors

    CEBError::CEBError() : status(0), message(""){};
    CEBError::CEBError(CEBError &err) : status(err.status), message(err.message){};
    CEBError::CEBError(CEBErrorType errt) : status(errt.getStatus()), message(""){};
    CEBError::CEBError(int _status) : status(_status){};
    CEBError::CEBError(int _status, std::string _message) : status(_status), message(_message){};

    // functions

    std::string CEBError::messageWithErrorType() const
    {
        return getErrorType() + " : " + message;
    }

    std::string CEBError::getMessage() const { return message; }
    std::string CEBError::getErrorType() const
    {
        return (errorTypes.find(status) == errorTypes.end()) ? "Unknown Error" : errorTypes[status];
    }
    int CEBError::getStatus() const { return status; }

    std::ostream &operator<<(std::ostream &os, const CEBError &err)
    {
        os << err.messageWithErrorType() << std::endl;
        return os;
    }

    bool CEBError::operator==(const CEBError &err) { return (status == err.status); }
    bool CEBError::operator==(CEBErrorType &errt) { return (status == errt.getStatus()); }
    bool CEBError::operator!=(const CEBError &err) { return !(*this != err); };
    bool CEBError::operator!=(CEBErrorType &errt) { return !(*this != errt); }

    bool CEBError::setErrorType(int _status, std::string _errorType)
    {
        // if overlap status, return false
        if (errorTypes.find(_status) == errorTypes.end())
            return false;

        // set mapping status to error type
        errorTypes[_status] = _errorType;
        return true;
    }

    // CEBErrorType

    _CEBErrorType::_CEBErrorType(int _status, std::string errorType) : status(_status)
    {
        CEBError::setErrorType(_status, errorType);
    }

    int _CEBErrorType::getStatus() const { return status; }
    CEBError _CEBErrorType::operator()(std::string message) const { return CEBError(status, message); }
}