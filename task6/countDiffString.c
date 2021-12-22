
#include <stdio.h>

int countDiffs(char * text1, char* text2 ){
    int diffs = 0;
    while ( *text1 != '\0' || *text2 != '\0' ){
        if ( *text1 == '\0' || *text2 == '\0' ) return -1;
        if (*text1 != *text2) diffs ++;
        text1 ++;
        text2 ++;
    }
    return diffs;
}

int main(){
    char test[5] = "Test\0";
    char teste[6] = "Teste\0";
    char hello1[6] = "Hello\0";
    char hello2[6] = "HEllo\0";
    char world[6] = "World\0";
    char workd[6] = "workd\0";

    printf("countDiffs(\"Test\", \"Teste\") returns %d.\n", countDiffs(test, teste));
    printf("countDiffs(\"Test\", \"Test\") returns %d.\n", countDiffs(test, test));
    printf("countDiffs(\"Hello\", \"HEllo\") returns %d.\n", countDiffs(hello1, hello2));
    printf("countDiffs(\"World\", \"workd\") returns %d.\n", countDiffs(world, workd));

    return 0;
}