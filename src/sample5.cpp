#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs;
using ::testing::DoDefault;
using ::testing::DoAll;

class DataBaseConnect {
public:
    virtual bool login(string username, string password)
    { cout << "Original LOGIN" << endl; return false; }
    virtual bool login2(string username, string password)
    { return true; }
    virtual bool logout(string username)
    { return true; }
};

class MockDB : public DataBaseConnect {
public:
    MOCK_METHOD1(logout, bool (string username));
    MOCK_METHOD2(login, bool(string username, string password));
    MOCK_METHOD2(login2, bool(string username, string password));
};

class MyDatabase {
    DataBaseConnect & dbC;
public:
    MyDatabase(DataBaseConnect & _dbC) : dbC(_dbC) {}

    int Init(string username, string password) {
        if(dbC.login(username, password) != true) {
            cout << "DB FAILURE" << endl; return -1;
        }else {
            cout << "DB SUCCESS" << endl; return 1;
        }
    }
};

struct testABC {
    bool dummylogin(string a, string b){
        cout << "Dummy Login gets called" << endl;
        return true;
    }
};

bool DummyFn() {
    cout << "Global Fn. Called..." << endl;
    return true;
}

TEST(MyDBTest, LoginTest) {
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);
    testABC dbTest;

    ON_CALL(mdb, login(_,_)).WillByDefault(Invoke(&dbTest, &testABC::dummylogin));

    EXPECT_CALL(mdb, login(_, _))
    .Times(AtLeast(1))
    .WillOnce(DoAll(Invoke(&dbTest, &testABC::dummylogin), 
        Invoke(&dbTest, &testABC::dummylogin), Return(true)));

    // Act
    int retValue = db.Init("Terminator", "I'm Back");

    // Assert
    EXPECT_EQ(retValue, 1);
}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}