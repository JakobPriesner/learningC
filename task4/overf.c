#include <stdio.h>

int overflow( int n ){
    static int s;
    s += n;
    int ret = 0;
    if ( s >= 10 ){
        ret = s / 10;
        s %= 10;
    }
    return ret;
}

int main(){
    printf("%d\n",overflow(5)); // S = 5; R ̈uckgabe 0
    printf("%d\n",overflow(6)); // S = 1; R ̈uckgabe 1
    printf("%d\n",overflow(12)); // S = 3; R ̈uckgabe 1
    printf("%d\n",overflow(7)); // S = 0; R ̈uckgabe 1
    printf("%d\n",overflow(2)); // S = 2; R ̈uckgabe 0
}