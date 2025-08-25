#include <stdio.h>

int main() {
    printf("char:      %d bytes\n", (int) sizeof(char));
    printf("float:     %d bytes\n", (int) sizeof(float));
    printf("long:      %d bytes\n", (int) sizeof(long));
    printf("int:       %d bytes\n", (int) sizeof(int));
    printf("int *:     %d bytes\n", (int) sizeof(int *));
    printf("char *:    %d bytes\n", (int) sizeof(char *));
    printf("float *:   %d bytes\n", (int) sizeof(float *));
    return 0;
}