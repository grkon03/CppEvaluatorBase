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
    EXPECT_EQ(noErrWithMes.messageWithErrorType(), "No Error : message");
}

TEST(CEBErrorTest, SetErrorTypesTest)
{
    CEBError::setErrorType(-50, "New Error1");
    EXPECT_EQ(CEBError(-50).getErrorType(), "New Error1");

    CEBError newErrorT1(-50, "message");
    EXPECT_EQ(newErrorT1.getStatus(), -50);
    EXPECT_EQ(newErrorT1.getMessage(), "message");
}

CEBErrorType NewError2(-100, "New Error2");

TEST(CEBErrorTypeTest, NewErrorTypeTest)
{
    EXPECT_EQ(NewError2.getStatus(), -100);

    CEBError newErrorT2 = NewError2;
    EXPECT_EQ(newErrorT2.getStatus(), -100);
    EXPECT_EQ(newErrorT2.getMessage(), "");

    CEBError newErrorWithMes2 = NewError2("message2");
    EXPECT_EQ(newErrorWithMes2.getStatus(), -100);
    EXPECT_EQ(newErrorWithMes2.getMessage(), "message2");
}