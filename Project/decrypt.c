#include "railcipher.utils.h"

void decrypt(char string[], int position, int m, char* argv[]){
    // Retrieving the message from the string command
    char ciphertext[MAX_SIZE]; 
    int length = strlen(string);
    int l = 0;

    l = extractMessage(string, ciphertext, l, length, position);

    // Setting up the matrix Anxm
    int n = strlen(ciphertext) / m;
    char matrix[n][m];

    // Set Key order
    int order[m];
    setKeyOrder(order, m, argv);

    // Write in matrix the message
    int indexCipher = 0;
    for(int j = 0; j < m; j++){
        int colIndex = order[j];
        for(int i = 0; i < n; i++){
            matrix[i][colIndex] = ciphertext[indexCipher];
            indexCipher++;
        }
    }

    // Print Decrypted Message
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%c", matrix[i][j] - 32);
        }
    }

    printf("\n");
}