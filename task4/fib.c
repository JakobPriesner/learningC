#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int fib( unsigned int n ){
    if ( n == 0 ){
        return 0;
    } else if ( n == 1 ){
        return 1;
    } else {
        unsigned int first = 0;
        unsigned int second = 1;
        unsigned int counter = 2;
        while ( counter < n ){
            unsigned int new = first + second;
            first = second;
            second = new;
            counter ++;
        }
        return first + second;
    }
}

unsigned int slowFib( unsigned int n ){
    if ( n == 0 ){
        return 0;
    } else if ( n == 1 ){
        return 1;
    } else {
        return fib( n-1 ) + fib( n-2 );
    }
}

int main( int argc, char *argv[] ) {
    if ( argc == 0 || argc == -1 ){
        printf( "[ERROR] At least one argument expected" );
    } else {
        int nFounded = 0;
        char c = 'n';
        for ( int i = 0; i < argc; i++ ){
            if ( strcmp(argv[i], "-n") == 0 ){
                int val = atoi(argv[i+1]);
                printf("[RESULT] fib(%d): ", val);
                printf("%d", val);
                nFounded = 1;
            }
        }
        if ( nFounded == 0 ){
            printf("[ERROR] Algorithm requires a parameter with the name -n!");
        }
    }

    return 0;
}
