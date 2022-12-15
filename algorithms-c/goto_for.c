#include <stdio.h>

int main(){
    int i = 1;
    for1:
    if(i<5) goto forbody1; goto next1;
    forbody1:{
    printf("%d\n", i);
    }
    i++;
    goto for1;
    next1:{
    printf("saiuuu");
    }
    return 0;
}

