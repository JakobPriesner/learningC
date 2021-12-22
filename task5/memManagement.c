#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dividend, divisor;
} Fraction;

void readFraction( Fraction *fraction ){
    int *dividend = &fraction->dividend;
    int *divisor = &fraction->divisor;

    printf("Please enter a dividend: ");
    scanf("%d", dividend);

    printf("Please enter a divisor: ");
    scanf("%d", divisor);
}

void printFraction( Fraction *fraction ){
    printf("Dividend: %d, ", fraction->dividend);
    printf("Divisor: %d\n", fraction->divisor);
}

void truncateFraction( Fraction *fraction ) {
    int comparisonVariable = fraction->divisor < fraction->dividend ? fraction->divisor : fraction->dividend;
    for (int i = comparisonVariable; i > 1; i--){
        if (fraction->divisor % i == 0 &&
            fraction->dividend % i == 0){
            fraction->divisor /= i;
            fraction->dividend /= i;
        }
    }
}

Fraction* addFractions( Fraction *first, Fraction *second ){
    Fraction tempFirst, tempSecond;
    tempFirst.divisor = first->divisor * second->divisor;
    tempFirst.dividend = first->dividend * second->divisor;

    tempSecond.divisor = second->divisor * first->divisor;
    tempSecond.dividend = second->dividend * first->divisor;

    static Fraction newFraction;
    newFraction.dividend = tempFirst.dividend + tempSecond.dividend;
    newFraction.divisor = tempFirst.divisor;
    truncateFraction(&newFraction);
    return &newFraction;
}

int compareFractions( Fraction *first,  Fraction *second ){
    if (first->divisor != second->divisor){
        return 1;
    }
    if (first->dividend != second->dividend){
        return 1;
    }

    return 0;
}

Fraction* multiplyFractions( Fraction *first,  Fraction *second ){
    static Fraction newFraction;
    newFraction.dividend = first->dividend * second->dividend;
    newFraction.divisor = first->divisor * second->divisor;
    truncateFraction(&newFraction);
    return &newFraction;
}

void testFraction(){
    Fraction first;
    Fraction second;

    Fraction *pfirst = &first;
    Fraction *psecond = &second;
    printf("----------First Fraction ----------\n");
    readFraction(pfirst);
    printf("----------Second Fraction----------\n");
    readFraction(psecond);

    printFraction(pfirst);
    printFraction(psecond);

    Fraction *addedFractions = addFractions(pfirst, psecond);
    printf("Added Fractions: ");
    printFraction(addedFractions);

    Fraction *multipliedFractions = multiplyFractions(pfirst, psecond);
    printf("multiplied Fractions: ");
    printFraction(multipliedFractions);
}

int main(){
    testFraction();
    return 0;
}