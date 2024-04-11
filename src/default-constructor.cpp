#include <iostream>

class CInnerClass {
public:
  CInnerClass(int rv_value) : m_inner_value(rv_value) {}

  void display() const {
    std::cout << "InnerClass: " << m_inner_value << std::endl;
  }

private:
  int m_inner_value;
};

class COuterClass {
public:
  void display() const {
    for(const auto& inner : m_inners) {
      inner.display();
    }
  }

private:
  // C++11以降では以下のようにメンバ変数のデフォルト値を定義できる
  CInnerClass m_inners[3] = {CInnerClass(1), CInnerClass(2), CInnerClass(3)};
};

int main() {
  COuterClass outer;
  outer.display();

  CInnerClass inners[3] = {CInnerClass(1), CInnerClass(2), CInnerClass(3)};
  for(const auto& inner : inners) {
    inner.display();
  }

  return 0;
}
