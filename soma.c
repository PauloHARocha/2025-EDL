#include<stdio.h>

int soma(int a, int b){
    int c = a + b;
    return c;
}

int main(){
    int x = 2;
    int y = 3;
    int z = soma(x, y);
    printf("Soma = %d\n", z);
    return 0;
}