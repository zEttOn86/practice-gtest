#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class MyClass {
    string id;
public:
    MyClass(string _id) : id(_id) {}
    string GetId() { return id; }
};

TEST(TestName, increment_by_5) {

    // Arrange
    MyClass mc("root");

    // Act
    string value = mc.GetId();

    // Assert
    EXPECT_STREQ(value.c_str(), "root1");
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}