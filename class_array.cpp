#include <iostream>

using namespace std;

class Hoge {
public:
    struct Pole {
        explicit Pole(float rv_poles[]) : a1(rv_poles[0]), a2(rv_poles[1]) {}
        float a1;
        float a2;
    };
    float a;
    float b;
    explicit Hoge(const Pole& rv_pole) : a(rv_pole.a1), b(rv_pole.a2) {}
};

struct SFuga {
    int a;
    int b;
};

int main() {
    SFuga s[3] = {{1, 2}, {3, 4}, {5, 6}};
    float f[2] = {0.1, 0.2};
    Hoge  h    = Hoge(Hoge::Pole(f));
    cout << s[0].a << endl;
    return 0;
}
