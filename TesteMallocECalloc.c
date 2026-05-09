#include <stdio.h>
#include <stdlib.h>

int main(){

    int *x;

    //x = malloc(sizeof(int)); // Aloca memória para um inteiro e atribui o endereço a x
    x = calloc(1, sizeof(int)); // Aloca memória para um inteiro e inicializa com zero);

    if(x){
        printf("Valora alocado corretamente!\n");
        printf("x: %d\n", *x);
        *x = 50;
        printf("x: %d\n", *x);
    }else{
        printf("Erro ao alocar memória!");
    }


    return 0;
}