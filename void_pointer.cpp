#include <stdio.h>

void outString(const void*);

int main() {
    int    i = 65;
    double d = 10.101;

    outString(&i);
    outString(&d);
    outString("Kitty on your lap");

    return 0;
}

void outString(const void* text) { printf("%s\n", (const char*)text); }
