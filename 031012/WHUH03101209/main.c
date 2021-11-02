
#include <stdio.h>
#include "qdbmp.h"
#pragma comment(lib, "BmpStaticLibrary.lib")


int main() {
    BMP* bmp;
    bmp = BMP_ReadFile("lena512.bmp");
    printf("Hello, World!\n");
    return 0;
}
