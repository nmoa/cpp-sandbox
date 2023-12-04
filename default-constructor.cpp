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
  // NG! m_inner���f�t�H���g�R���X�g���N�^�ŏ��������Ă���ACInnerClass(5)��������A�Ƃ��������ɂȂ邪�A
  // CInnerClass�̃f�t�H���g�R���X�g���N�^����`����Ă��Ȃ����� no matching function for call to 'CInnerClass::CInnerClass() �ɂȂ�
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
