#include <gtest/gtest.h>
#include "../../src/basic/error.hpp"

using namespace CEB;

TEST(CEBErrorTest, NoErrorTest)
{
    EXPECT_EQ(CEBError(NoErr).getErrorType(), "No Error");

    CEBError noErrT = NoErr;
    EXPECT_EQ(noErrT.getStatus(), 0);
    EXPECT_EQ(noErrT.getMessage(), "");

    CEBError noErrWithMes = NoErr("message");
    EXPECT_EQ(noErrWithMes.getStatus(), 0);
    EXPECT_EQ(noErrWithMes.getMessage(), "message");
}

TEST(CEBErrorTest, SetErrorTypesTest)
{
    CEBError::setErrorType(-50, "New Error1");
    EXPECT_EQ(CEBError(-50).getErrorType(), "New Error1");
}

CEBErrorType NewError(-100, "New Error2");

TEST(CEBErrorTypeTest, NewErrorTypeTest)
{
    EXPECT_EQ(NewError.getStatus(), -100);

    CEBError newErrorT = NewError;
    EXPECT_EQ(newErrorT.getStatus(), -100);
    EXPECT_EQ(newErrorT.getMessage(), "");

    CEBError newErrorWithMes = NewError("message2");
    EXPECT_EQ(newErrorWithMes.getStatus(), -100);
    EXPECT_EQ(newErrorWithMes.getMessage(), "message2");
}