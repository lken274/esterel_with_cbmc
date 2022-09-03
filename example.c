#include <stdint.h>

int main ( ) {
    unsigned int a,b,c;
    a = nondet_uint() % 5;
    b = nondet_uint() % 5;
    assert((a+b) != 5);
    c = a / b;
    return c;
}