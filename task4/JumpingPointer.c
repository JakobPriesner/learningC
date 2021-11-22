

int main(){
    int numb[5] = {2, 3, -1, 2, -2};
    int visitedArray[5] = {1};
    int k = 0;
    int counter = 0;
    while (1){
        k = k + numb[k];
        counter ++;
        if (k > 4 || k < 0){
            return counter;
        } else if ( visitedArray[k] == 1 ){
            return -1;
        } else {
            int isPassedThrough = 1;
            for ( int i = 0; i < 5; i++ ){
                if ( visitedArray[i] == 0 ){
                    isPassedThrough = 0;
                    break;
                }
            }
            if ( isPassedThrough == 1 ){
                return counter;
            }
        }
        visitedArray[k] = 1;
    }
}