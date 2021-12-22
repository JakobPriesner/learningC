#include <stdio.h>
#include <stdlib.h>

int main(){
    char chars[20];
    int size = 0;
    FILE *file;
    int c;

    file = fopen("test.txt", "r");

    if ( file == NULL ) {
        printf("File doesn't exist!");
        return 1;
    }

    while ( (c = fgetc(file)) != EOF ){
        if (size > 19){
            printf("Char Array full!");
            break;
        }
        chars[size++] = c;
    }

    chars[size] = 0;

    printf("%s\n", chars);
    fclose(file);
    return EXIT_SUCCESS;
}