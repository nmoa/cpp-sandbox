#include "gtest/gtest.h"
#include "gmock/gmock.h"
// インクルードしたいヘッダはこの下に記載
#include "Integrator.h"

TEST(IntegratorTest, add) {
	Integrator i;
	i.setValue(1.0f);
	EXPECT_FLOAT_EQ(i.calc(2.0f), 3.0f);
	EXPECT_FLOAT_EQ(i.calc(3.0f), 6.0f);
	EXPECT_FLOAT_EQ(i.calc(0.5f), 6.5f);
}

TEST(IntegratorTest, reset) {
	Integrator i;
	i.setValue(1.0f);
	EXPECT_FLOAT_EQ(i.calc(1.0f), 2.0f);
	i.reset();
	EXPECT_FLOAT_EQ(i.calc(1.0f), 1.0f);
}
