#include <stdio.h>

int main(){
    const int upperLimit = 10;
    for( int i = 1; i < upperLimit; i++ ){
        for ( int j = 1; j < upperLimit; j++ ){
            printf("%d x %d = %d\n", i, j, i*j);
        }
        printf("\n");
    }
}