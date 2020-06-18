#include<stdio.h>
#include<stdlib.h>

struct Term
{
    double coeff;
    int exp;
};

struct Poly
{
    int num;
    struct Term *term;
};

void setPoly(struct Poly *poly);
void dispPoly(const struct Poly *poly);
void addPoly(struct Poly *poly1, struct Poly *poly2);
void multiplyPoly(struct Poly *poly1, struct Poly *poly2);

int main(void)
{
    struct Poly poly1;
    puts("Enter details of 1st polynomial:");
    setPoly(&poly1);
    struct Poly poly2;
    puts("Enter details of 2nd polynomial:");
    setPoly(&poly2);
    addPoly(&poly1, &poly2);
    multiplyPoly(&poly1, &poly2);
}

void setPoly(struct Poly *poly)
{
    puts("Enter the number of terms: ");
    scanf("%d", &poly->num);
    poly->term = (struct Term *)malloc(sizeof(struct Term) * poly->num);
    puts("Enter the terms:");
    for(int index = 0; index < poly->num; index++)
    {
        printf("Enter term %d:\n", index + 1);
        puts("Enter the coefficient: ");
        scanf("%lf", &poly->term[index].coeff);
        puts("Enter the exponent: ");
        scanf("%d", &poly->term[index].exp);
    }
}

void dispPoly(const struct Poly *poly)
{
    for(size_t index = 0; index < poly->num; index++)
    {
        printf("%fx^%d", poly->term[index].coeff, poly->term[index].exp);
        if(index < poly->num - 1)
            printf(" + ");
    }
    fputs("\n", stdout);
}

void addPoly(struct Poly *poly1, struct Poly *poly2)
{
    struct Poly sum;
    sum.num = poly1->num + poly2->num;
    sum.term = (struct Term *)malloc(sizeof(struct Term) * sum.num);
    int index1 = 0, index2 = 0, index3 = 0;
    while(index1 < poly1->num && index2 < poly2->num)
    {
        if(poly1->term[index1].exp < poly2->term[index2].exp)
            sum.term[index3++] = poly1->term[index1];
        else if(poly1->term[index1].exp > poly2->term[index2].exp)
            sum.term[index3++] = poly2->term[index2];
        else
        {
            sum.term[index3].exp = poly1->term[index1].exp;
            sum.term[index3].coeff = poly1->term[index1].coeff + poly2->term[index2].coeff;
            index1++;
            index2++;
            index3++;
        }
    }
    puts("The sum of the polynomials is:");
    dispPoly(&sum);
    free(sum.term);
}

void multiplyPoly(struct Poly *poly1, struct Poly *poly2)
{
    struct Poly prod;
    prod.num = poly1->num * poly2->num;
    prod.term = (struct Term *)malloc(sizeof(struct Term) * prod.num);
    int index1 = 0, index2 = 0, index3 = 0;
    for(size_t index1 = 0; index1 < poly1->num; index1++)
    {
        for(size_t index2 = 0; index2 < poly1->num; index2++)
        {
            prod.term[index3].coeff = poly1->term[index1].coeff * poly2->term[index2].coeff;
            prod.term[index3].exp = poly1->term[index1].exp + poly2->term[index2].exp;
            index3++;
        }
    }
    puts("The product of the polynomials is:");
    dispPoly(&prod);
    free(prod.term);
}