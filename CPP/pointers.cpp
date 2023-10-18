#include <stdio.h>

void foo(int *p){
    printf("%d\n", *p);
    printf("%p\n", p);
    printf("%p\n", &p);
}

int main(){
    int a = 10;
    int *p = &a;
    foo(p);
    return 0;
}