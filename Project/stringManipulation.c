#include <stdlib.h>

int extractMessage(char string[], char message[], int l, int length, int pos){

    for(int i = pos; i < length; i++){
        if (string[i] >= 97 && string[i] <= 122){
            message[l] = string[i];
            l++;
            continue;
        }
        else if (string[i] >= 65 && string[i] <= 90){
            message[l] = string[i] + 32;
            l++;
            continue;
        }
        else{
            continue;
        }
    }
    message[l] = '\0';

    return l;
}

void setKeyOrder(int key[], int m, char* argv[]){
    int pos = 0;
    for(int i = 2; i < m + 2; i++){
        key[atoi(argv[i]) - 1] = pos;
        pos++;
    }
}