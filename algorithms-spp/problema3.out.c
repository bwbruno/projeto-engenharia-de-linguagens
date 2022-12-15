#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int linhasA,colunasA;
int linhasB,colunasB;
printf("%s", "Digite a quantidade de Linhas da Matriz A: ");

scanf("%i", &linhasA);
printf("%s", "Digite a quantidade de Colunas da Matriz A: ");

scanf("%i", &colunasA);
if(linhasA<=0&&colunasA<=0) goto if1; goto else1;
if1:{
printf("%s", "Error");

return 1;

}
else1:{
}
int matrizA[linhasA][colunasA];
{int i;
i = 0;
for1:
if(i<linhasA) goto for1body; goto next1;
for1body:{{int j;
j = 0;
for2:
if(j<colunasA) goto for2body; goto next2;
for2body:{scanf("%i", &matrizA[i][j]);
}
j++;
goto for2;
next2:{ }}
}
i++;
goto for1;
next1:{ }}
printf("%s", "Matriz A:\n\t");

{int i;
i = 0;
for3:
if(i<linhasA) goto for3body; goto next3;
for3body:{{int j;
j = 0;
for4:
if(j<colunasA) goto for4body; goto next4;
for4body:{// begin int_to_string
int t0 = matrizA[i][j];
int t1 = snprintf(NULL, 0, "%d", t0);
char* t2 = malloc(t1+1);
snprintf(t2, t1+1, "%d", t0);
// end int_to_string
printf("%s", t2);

printf("%s", " ");

}
j++;
goto for4;
next4:{ }}
int c;
int t3 = linhasA-1;
c = t3;
if(i!=c) goto if2; goto else2;
if2:{
printf("%s", "\n\t");

}
else2:{
printf("%s", "\n");

}
}
i++;
goto for3;
next3:{ }}
printf("%s", "Digite a quantidade de Linhas da Matriz B: ");

scanf("%i", &linhasB);
printf("%s", "Digite a quantidade de Colunas da Matriz B: ");

scanf("%i", &colunasB);
if(linhasB<=0&&colunasB<=0) goto if3; goto else3;
if3:{
printf("%s", "Error");

return 1;

}
else3:{
}
int matrizB[linhasB][colunasB];
{int i;
i = 0;
for5:
if(i<linhasB) goto for5body; goto next5;
for5body:{{int j;
j = 0;
for6:
if(j<colunasB) goto for6body; goto next6;
for6body:{scanf("%i", &matrizB[i][j]);
}
j++;
goto for6;
next6:{ }}
}
i++;
goto for5;
next5:{ }}
printf("%s", "Matriz B:\n\t");

{int i;
i = 0;
for7:
if(i<linhasB) goto for7body; goto next7;
for7body:{{int j;
j = 0;
for8:
if(j<colunasB) goto for8body; goto next8;
for8body:{// begin int_to_string
int t4 = matrizB[i][j];
int t5 = snprintf(NULL, 0, "%d", t4);
char* t6 = malloc(t5+1);
snprintf(t6, t5+1, "%d", t4);
// end int_to_string
printf("%s", t6);

printf("%s", " ");

}
j++;
goto for8;
next8:{ }}
int c;
int t7 = linhasB-1;
c = t7;
if(i!=c) goto if4; goto else4;
if4:{
printf("%s", "\n\t");

}
else4:{
printf("%s", "\n");

}
}
i++;
goto for7;
next7:{ }}
int soma;
soma = 0;
if(linhasA!=linhasB||colunasA!=colunasB) goto if6; goto else6;
if6:{
printf("%s", "Não é possível realizar a soma das matrizes A e B\n");

}
else6:{
printf("%s", "Soma das Matrizes:\n\t");

{int i;
i = 0;
for9:
if(i<linhasA) goto for9body; goto next9;
for9body:{{int j;
j = 0;
for10:
if(j<colunasA) goto for10body; goto next10;
for10body:{int soma;
int t8 = matrizA[i][j]+matrizB[i][j];
soma = t8;
// begin int_to_string
int t9 = soma;
int t10 = snprintf(NULL, 0, "%d", t9);
char* t11 = malloc(t10+1);
snprintf(t11, t10+1, "%d", t9);
// end int_to_string
printf("%s", t11);

printf("%s", " ");

}
j++;
goto for10;
next10:{ }}
int c;
int t12 = linhasA-1;
c = t12;
if(i!=c) goto if5; goto else5;
if5:{
printf("%s", "\n\t");

}
else5:{
printf("%s", "\n");

}
}
i++;
goto for9;
next9:{ }}
}
return 0;


}