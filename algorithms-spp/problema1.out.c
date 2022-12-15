#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
double x;
scanf("%lf", &x);
double y;
scanf("%lf", &y);
double c;
scanf("%lf", &c);
double r;
double t0 = x*x;
double t1 = t0-y;
double t2 = t1+c;
r = t2;
{if(1==2) goto if1; goto else1;
if1:{
int x;
x = 10;
// begin int_to_string
int t3 = x;
int t4 = snprintf(NULL, 0, "%d", t3);
char* t5 = malloc(t4+1);
snprintf(t5, t4+1, "%d", t3);
// end int_to_string
printf("%s", t5);

printf("%s", "\n");


goto nextif1;
}}
{else1:{
int x;
x = 11;
// begin int_to_string
int t6 = x;
int t7 = snprintf(NULL, 0, "%d", t6);
char* t8 = malloc(t7+1);
snprintf(t8, t7+1, "%d", t6);
// end int_to_string
printf("%s", t8);

printf("%s", "\n");

}}
nextif1:{}
// begin double_to_string
double t9 = x;
int t10 = snprintf(NULL, 0, "%f", t9);
char* t11 = malloc(t10+1);
snprintf(t11, t10+1, "%f", t9);
// end double_to_string
printf("%s", t11);

printf("%s", "\n");

// begin double_to_string
double t12 = r;
int t13 = snprintf(NULL, 0, "%f", t12);
char* t14 = malloc(t13+1);
snprintf(t14, t13+1, "%f", t12);
// end double_to_string
printf("%s", t14);


}