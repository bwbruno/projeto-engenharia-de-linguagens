#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int input;
int i0_25;
i0_25 = 0;
int i26_50;
i26_50 = 0;
int i51_75;
i51_75 = 0;
int i76_100;
i76_100 = 0;
dowhile1:{
scanf("%i", &input);
{if(input>=0&&input<=25) goto if1; goto else1;
if1:{
i0_25++;

goto nextif1;
}}
{else1:{
}}
nextif1:{}
{if(input>=26&&input<=50) goto if2; goto else2;
if2:{
i26_50++;

goto nextif2;
}}
{else2:{
}}
nextif2:{}
{if(input>=51&&input<=75) goto if3; goto else3;
if3:{
i51_75++;

goto nextif3;
}}
{else3:{
}}
nextif3:{}
{if(input>=76&&input<=100) goto if4; goto else4;
if4:{
i76_100++;

goto nextif4;
}}
{else4:{
}}
nextif4:{}
}if(input>=0) goto dowhile1;
printf("%s", "\n[0, 25]: ");

// begin int_to_string
int t0 = i0_25;
int t1 = snprintf(NULL, 0, "%d", t0);
char* t2 = malloc(t1+1);
snprintf(t2, t1+1, "%d", t0);
// end int_to_string
printf("%s", t2);

printf("%s", "\n[26, 50]: ");

// begin int_to_string
int t3 = i26_50;
int t4 = snprintf(NULL, 0, "%d", t3);
char* t5 = malloc(t4+1);
snprintf(t5, t4+1, "%d", t3);
// end int_to_string
printf("%s", t5);

printf("%s", "\n[51, 75]: ");

// begin int_to_string
int t6 = i51_75;
int t7 = snprintf(NULL, 0, "%d", t6);
char* t8 = malloc(t7+1);
snprintf(t8, t7+1, "%d", t6);
// end int_to_string
printf("%s", t8);

printf("%s", "\n[76, 100]: ");

// begin int_to_string
int t9 = i76_100;
int t10 = snprintf(NULL, 0, "%d", t9);
char* t11 = malloc(t10+1);
snprintf(t11, t10+1, "%d", t9);
// end int_to_string
printf("%s", t11);

printf("%s", "\n");

return 0;


}