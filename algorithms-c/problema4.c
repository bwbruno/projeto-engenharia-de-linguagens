#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rational_t {
    int num;
    int den;
};

struct rational_t* newFraction(int n, int d) {
    if (d == 0) { printf("Erro! Denominador não pode ser zero."); exit(0); }
    struct rational_t* r = malloc(sizeof(struct rational_t));
    r->num = n;
    r->den = d;
    return r;
}

float areEquals(struct rational_t* r1, struct rational_t* r2) {
    float result = (r1->num * r2->den - r2->num * r1->den)/(r2->den*r1->den);
    printf("%f\n\n", result);
    if (result == 0) {
        return 1;
    }
    return 0;
}

struct rational_t* addFractions(struct rational_t* r1, struct rational_t* r2) {
    struct rational_t* aux = malloc(sizeof(struct rational_t));
    aux->num = r1->num * r2->den + r2->num * r1->den;
    aux->den = r1->den * r2->den;

    return aux;
}

struct rational_t* subtractFractions(struct rational_t* r1, struct rational_t* r2) {
    struct rational_t* aux = malloc(sizeof(struct rational_t));
    aux->num = r1->num * r2->den - r2->num * r1->den;
    aux->den = r1->den * r2->den;

    return aux;
}

struct rational_t* multiplyFractions(struct rational_t* r1, struct rational_t* r2) {
    struct rational_t* aux = malloc(sizeof(struct rational_t));
    aux->num = r1->num * r2->num;
    aux->den = r1->den * r2->den;

    return aux;
}

struct rational_t* divideFractions(struct rational_t* r1, struct rational_t* r2) {
    if(r2->den == 0) { printf("Error!\n"); exit(0); }
    struct rational_t* aux = malloc(sizeof(struct rational_t));
    aux->num = r1->num * r2->num;
    aux->den = r1->den * r2->den;

    return aux;
}

char* toStringFraction(char* str, struct rational_t* r) {
    sprintf(str, "%d/%d", r->num, r->den);
    return str;
}

void opInverseFraction(struct rational_t* r) {
    struct rational_t* aux = malloc(sizeof(struct rational_t));
    aux->num = r->den;
    aux->den = r->num;
    r->num = aux->num;
    r->den = aux->den;
    free(aux);
}

int main() {

    char str[10];
    struct rational_t* r1 = newFraction(1, 3);
    struct rational_t* r2 = newFraction(1, 6);

    printf("r1: %s\n", toStringFraction(str, r1));
    printf("r2: %s\n", toStringFraction(str, r2));
    float result = areEquals(r1, r2);
    printf("r1 and r2 are iguals: %s\n", result ? "true" : "false");

    opInverseFraction(r1);
    printf("inverse r1: %s\n", toStringFraction(str, r1));
    opInverseFraction(r1);

    struct rational_t* r3 = addFractions(r1, r2);
    printf("r1 + r2: %s\n", toStringFraction(str, r3));

    r3 = subtractFractions(r1, r2);
    printf("r1 - r2: %s\n", toStringFraction(str, r3));

    r3 = multiplyFractions(r1, r2);
    printf("r1 * r2: %s\n", toStringFraction(str, r3));
    return 0;
}