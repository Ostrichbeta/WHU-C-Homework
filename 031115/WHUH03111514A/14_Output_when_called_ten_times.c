#include <stdio.h>
//Task 14: Call a function 10 times (local way)

void function(){
    static int count = 0;
    count++;
    if (count == 10) {
        printf("This function has been called ten times.");
    }
}

int main() {
    for (int i = 0; i < 20; ++i) {
        printf("[%2d] ", i + 1);
        function();
        printf("\n");
    }
    return 0;
}
