#include "gtest/gtest.h"
// インクルードしたいヘッダはこの下に記載
#include "Integrator.h"

class IntegratorTest : public ::testing::Test {
protected:
	Integrator i;

	virtual void SetUp() {
		i.setValue(1.0f);
	}
	// virtual void TearDown() {}
};

TEST_F(IntegratorTest, add) {
	EXPECT_FLOAT_EQ(i.calc(2.0f), 3.0f);
	EXPECT_FLOAT_EQ(i.calc(3.0f), 6.0f);
	EXPECT_FLOAT_EQ(i.calc(0.5f), 6.5f);
}

TEST_F(IntegratorTest, reset) {
	EXPECT_FLOAT_EQ(i.calc(1.0f), 2.0f);
	i.reset();
	EXPECT_FLOAT_EQ(i.calc(1.0f), 1.0f);
}
