#include <stdio.h>

int isPermutation(char *a, char *b){
    int anz[26];
    for (int i = 0; i < 26; i++){
        anz[i] = 0;
    }

    char *counter = a;
    while (*counter != '\0'){
        int index = *counter-'a';
        anz[index] ++;
        counter ++;
    }

    char *counterB = b;
    while (*counterB != '\0'){
        int index = *counterB-'a';
        if (anz[index] <= 0){
            return 0;
        }
        anz[index]--;
        counterB ++;
    }

    for (int i = 0; i < 26; i++){
        if (anz[i] < 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    char a[255];
    char b[255];
    printf("Please type in word a:\n");
    scanf("%s", a);
    printf("Please type in word b:\n");
    scanf("%s", b);

    if (isPermutation(a, b) == 1){
        printf("a and b are premeditated");
    } else {
        printf("a and b aren't premeditated");
    }

    return 0;
}