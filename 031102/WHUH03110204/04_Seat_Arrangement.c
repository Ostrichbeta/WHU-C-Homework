#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Task 04: Arranging Jack and Ann's seat

int main() {
    int jack_pos = 1, ann_pos = 1;
    int suitable_arrangement_count = 0;
    for (int i = 1; i <= 10 ; ++i) {
        for (int j = 1; j < 10; ++j) {
            jack_pos = i;
            ann_pos = j;
            if (abs(i - j) == 1 || abs(i - j) == 9){
                continue;
            }
            suitable_arrangement_count++;
            printf("Arrange %2d: Jack sits at position %d, and Ann sits at %d.\n", suitable_arrangement_count, jack_pos, ann_pos);
        }
    }
    return 0;
}
