#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int linhasA,colunasA;
    int linhasB,colunasB;

    printf("Digite a quantidade de Linhas da Matriz A: ");
    scanf("%i",&linhasA);

    printf("Digite a quantidade de Colunas da Matriz A: ");
    scanf("%i",&colunasA);

    if(linhasA <= 0 && colunasA <= 0){
        printf("Error");
        return 1;
    }

    int matrizA[linhasA][colunasA];

    for(int i = 0; i < linhasA ; i++){
        for(int j = 0 ; j < colunasA ; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Matriz A:\n\t");

    for(int i = 0; i < linhasA ; i++){
        for(int j = 0 ; j < colunasA ; j++){
            printf("%d ",matrizA[i][j]);
        }
        if(i != linhasA - 1){
            printf("\n\t");
        }else{
            printf("\n");
        }
    }

    printf("Digite a quantidade de Linhas da Matriz B: ");
    scanf("%i",&linhasB);

    printf("Digite a quantidade de Colunas da Matriz B: ");
    scanf("%i",&colunasB);

    if(linhasB <= 0 && colunasB <= 0){
        printf("Error");
        return 1;
    }

    int matrizB[linhasB][colunasB];

    for(int i = 0; i < linhasB ; i++){
        for(int j = 0 ; j < colunasB ; j++){
            scanf("%d", &matrizB[i][j]);
        }
    }

    printf("Matriz B:\n\t");

    for(int i = 0; i < linhasB ; i++){
        for(int j = 0 ; j < colunasB ; j++){
            printf("%d ",matrizB[i][j]);
        }
        if(i != linhasB - 1){
            printf("\n\t");
        }else{
            printf("\n");
        }
    }

    int soma = 0;

    if(linhasA != linhasB || colunasA != colunasB){
        printf("Não é possível realizar a soma das matrizes A e B\n");
    }else{
        printf("Soma das Matrizes:\n\t");
        for(int i = 0; i < linhasA ; i++){
            for(int j = 0 ; j < colunasA ; j++){
                printf("%d ", matrizA[i][j] + matrizB[i][j]);
            }
            if(i != linhasA - 1){
                printf("\n\t");
            }else{
                printf("\n");
            }
        }
    }

    if(colunasA != linhasB){
        printf("Não é possível realizar a multiplicação das matrizes A e B\n");
    }else{
        printf("Multiplicação das Matrizes:\n\t");
        int matrizC[linhasA][colunasB];
        int somaprod=0;
        for(int i=0; i<linhasA; i++){
            for(int j=0; j<colunasB; j++){
                somaprod=0;
                for(int k=0; k<linhasA; k++){
                    somaprod+= matrizA[i][k]*matrizB[k][j];
                }
                printf("%d ", somaprod);
            }
            if(i != linhasA - 1){
                printf("\n\t");
            }else{
                printf("\n");
            }
        }
    }

    return 0;
}