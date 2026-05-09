#include <stdio.h>

int main(){

    int x = 10;
    int *p = &x; // ponteiro pra x  
    *p = 20;
    printf("Valor de x: %d\n", x); // Imprime o valor de x  
    printf("Valor apontado por p: %d\n", *p); // Imprime o valor apontado por p (que é x)
    printf("Endereço de x: %p\n", (void*)&x); // Imprime o endereço de x
    printf("Valor do ponteiro p: %p\n", (void*)p); // Imprime o valor do ponteiro p (que é o endereço de x  )       



    return 0;
}