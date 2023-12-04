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
  // NG! m_innerをデフォルトコンストラクタで初期化してから、CInnerClass(5)を代入する、という処理になるが、
  // CInnerClassのデフォルトコンストラクタが定義されていないため no matching function for call to 'CInnerClass::CInnerClass() になる
  COuterClass() {
    m_inner = CInnerClass(5);
  }

  void display() const {
    m_inner.display();
  }

private:
  CInnerClass m_inner;
};

int main() {
  COuterClass outerObj;
  outerObj.display();

  return 0;
}
