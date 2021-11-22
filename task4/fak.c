#include <stdio.h>

//ab 17 ungenau, da größer als Interger.MAX

unsigned int rek_fak( int n ){
    if ( n < 1 ){
        return -1;
    }
    if ( n == 1 ){
        return 1;
    }
    return rek_fak( n-1 ) * n;
}

int it_fak( int n ){
    if ( n < 1 ){
        return -1;
    }
    int result = 1;
    for ( int i = 2; i <= n; i++ ){
        result *= i;
    }
    return result;
}

int main(){
    printf("Please enter a number: ");
    int n;
    scanf("%d", &n);
    printf("Rekursive fakt: %d\n", rek_fak(n));
    printf("Iterative fakt: %d\n", it_fak(n));
}