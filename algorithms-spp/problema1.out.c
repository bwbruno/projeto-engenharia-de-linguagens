#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
double x;
x = 10.5;
double y;
y = 25.5;
int c;
c = 20;
double r;
double t0 = x*x;
double t1 = t0-y;
double t2 = t1+c;
r = t2;
// begin double_to_string
double t3 = r;
int t4 = snprintf(NULL, 0, "%f", t3);
char* t5 = malloc(t4+1);
snprintf(t5, t4+1, "%f", t3);
// end double_to_string
printf("%s", t5);


}