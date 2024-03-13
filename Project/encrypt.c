#include "railcipher.utils.h"

void encrypt(char string[], int position, int m, char* argv[]){
    // Retrieving the message from the string command
    char plaintext[MAX_SIZE]; 
    int length = strlen(string);
    int l = 0; 

    l = extractMessage(string, plaintext, l, length, position);

    // Setting up the matrix Anxm
    int n = (int)ceil((double)l / m);
    char matrix[n][m];

    // Fill out matrix
    int k = 0;
    int ascii;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(plaintext[k] != '\0')
                matrix[i][j] = plaintext[k];
            else{
                k--;
                ascii = 122 - (m * (n - 1 - i) + (m - 1 - j));
                matrix[i][j] = ascii;
            }
            k++;
        }
    }

    // Set Key order
    int order[m];
    setKeyOrder(order, m, argv);

    // Print Encrypted message
    for(int j = 0; j < m; j++){
        int colIndex = order[j];
        for(int i = 0; i < n; i++){
            printf("%c", matrix[i][colIndex] - 32);
        }
    }

    printf("\n");
}