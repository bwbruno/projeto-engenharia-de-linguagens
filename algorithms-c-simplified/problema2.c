/*
    Entrada:
    0 10 20 30 40 50 60 70 80 900 1000 -1

    Saída esperada:
    
      [0, 25]: 3
     [26, 50]: 3
     [51, 75]: 2
    [76, 100]: 1

*/

#include <stdio.h>

int main()
{
    int input;
    int i0_25 = 0;
    int i26_50 = 0;
    int i51_75 = 0;
    int i76_100 = 0;


    dowhile: {
        scanf("%i", &input);

        if(input >= 0 && input <= 25) goto if1; goto else1;
        if1: {
            i0_25++;
        }
        else1: {}

        if(input >= 26 && input <= 50) goto if2; goto else2;
        if2: {
            i26_50++;
        }
        else2: {}

        if(input >= 51 && input <= 75) goto if3; goto else3;
        if3: {
            i51_75++;
        }
        else3: {}

        if(input >= 76 && input <= 100) goto if4; goto else4;
        if4: {
            i76_100++;
        }
        else4: {}

    } if(input >= 0) goto dowhile; 
    
    printf("\n");
    printf("  [0, 25]: %i\n", i0_25);
    printf(" [26, 50]: %i\n", i26_50);
    printf(" [51, 75]: %i\n", i51_75);
    printf("[76, 100]: %i\n", i76_100);

    return 0;
}
