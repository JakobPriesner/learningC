
#include <stdio.h>

int checkIsbn(char *c){
    int amount = 0;
    for (int i = 1; i <= 10; i++){
        amount += (*c - 48) * i;
        c ++;
    }
    return (amount % 11);
}

void printISBN(char *isbn){
    for(int i = 0; i < 10; i++){
        printf("%c", *isbn++);
    }
}

int main(int argc, char **argv){
    // valid:       3598215002
    // invalid :    3598215003
    char *isbn = argv[1];
    if (argc == 0){
        printf("Missing parameters: ISBN!\n");
        return 1;
    }
    if (checkIsbn(isbn) == 0){
        printISBN(isbn);
        printf(" is a valid ISBN.\n");
        return 0;
    } else {
        printISBN(isbn);
        printf(" is NOT a valid ISBN.\n");
        return 1;
    }
}

