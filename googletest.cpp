#include <gtest/gtest.h>
#include <gmock/gmock.h>

class FooTest : public testing::TestWithParam<const char*> {
	// You can implement all the usual fixture class members here.
	// To access the test parameter, call GetParam() from class
	// TestWithParam<T>.
};

class BaseTest : public testing::Test {
protected:
};
class BarTest : public BaseTest, public testing::WithParamInterface<const char*> {
protected:
};

TEST_P(BarTest, DoesBlah) {
	// Inside a test, access the test parameter with the GetParam() method
	// of the TestWithParam<T> class:
	const char* str = GetParam();
	std::cout << str << std::endl;
	EXPECT_TRUE(true);
}

INSTANTIATE_TEST_SUITE_P(MeenyMinyMoe, BarTest, testing::Values("meeny", "miny", "moe"));
