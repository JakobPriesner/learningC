#include <stdio.h>

void printString( char *c ){
    char *current = c;
    while ( *current != '\0' ){
        printf("%c", *current);
        current++;
    }
    printf("\n");
}

void printStringLength( char *c ){
    char *current = c;
    while ( *current != '\0' ) {
        current++;
    }
    printf("Length: %d\n", (current-c));
}

void testPattern ( char *source, void (*fun)(char *) ) {

}

int main(){
    char input[255];
    printf("Please enter a word: \n");
    scanf("%s", input);
    printStringLength(input);
    printString(input);

    return 0;
}