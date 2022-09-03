#include <stdio.h>
typedef int boolean;
extern int ABRO_run(void);
extern void ABRO_I_A (void);
extern void ABRO_I_B (void);
extern void ABRO_I_R (void);

#ifndef CBMC
    #define assert (void)
    #define nondet_bool() 0
#endif

void ABRO_O_O() {
    printf("ABRO Output triggered!");
    assert(0);
}

int main () {
    printf("Running ABRO!\n");
    ABRO_run();
    if (nondet_bool()) {
        ABRO_I_A();
    }
    if (nondet_bool()) {
        ABRO_I_B();
    }
    ABRO_run();
}