#include <stdio.h>
 
int main() {
    int entrada;
    while(scanf("%d", &entrada)!=EOF){
        (entrada==0) ? printf("vai ter copa!\n") : printf("vai ter duas!\n");
    }
    return 0;
}