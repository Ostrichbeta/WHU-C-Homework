#include <stdio.h>
//Task 14: call a function for ten times (global way)
static int times = 0;

void function () {
    times++;
    if (times == 10) printf("Called 10 times.\n");
}

int main() {
    printf("Hello, World!\n");
    for (int i = 0; i < 11; ++i) {
        function();
    }
    return 0;
}
