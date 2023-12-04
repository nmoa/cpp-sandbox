#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../fakeit.hpp"
using namespace fakeit;

#include "SampleConcrete.h"

TEST(hoge, fuga) {
	// 実装したクラスの場合は、オブジェクトを生成してMockに渡す
	SampleConcrete       obj;
	Mock<SampleConcrete> mock(obj);

	// 実装しているメソッドを一部だけを上書きできる
	When(Method(mock, SampleMethod1)).AlwaysReturn(5);

	// SampleConcrete型のオブジェクトを取得
	SampleConcrete& sample = mock.get();

	// 上書きしたメソッド
	EXPECT_EQ(5, sample.SampleMethod1(1));

	// 実装されている元のメソッド
	EXPECT_EQ(3, sample.SampleMethod2(1, 2));
}
