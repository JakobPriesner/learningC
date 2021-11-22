#include <stdio.h>


void convert( char *str ){
    int index = 0;

    while ( str[index] != '\0' && index < 255 ){
        if ( str[index] >= 97 && str[index] <= 122 ){
            str[index] = str[index]-32;
        } else if ( str[index] >= 65 && str[index] <= 90 ){
            str[index] = str[index]+32;
        }

        index ++;
    }
}

int main( void ) {
    char input[255];
    printf("Please enter a Word: ");
    scanf("%s", input);
    convert( input );
    printf("Result: %s\n", input );
}