#include "railcipher.utils.h"

// Check if the command prompted by the user is invalid
int invalidCommand(char commandString[], int keyLength, char* argv[]){
    if(commandString[COMMAND_SIZE] != ' '){
        return INVALID;
    }

    // Store the command. It should be a maximum of 7 characters long (encrypt or decrypt)
    char commandRead[COMMAND_SIZE + 1];
    
    // Get the command with substring
    strncpy(commandRead, commandString, COMMAND_SIZE);
    commandRead[COMMAND_SIZE] = '\0';

    // Encrypt the message
    if (strcmp(commandRead, "encrypt") == 0){
        encrypt(commandString, COMMAND_SIZE + 1, keyLength, argv);
        return VALID;
    }

    // Decrypt the message
    if (strcmp(commandRead, "decrypt") == 0){
        decrypt(commandString, COMMAND_SIZE + 1, keyLength, argv);
        return VALID;
    }

    return INVALID;
}

// Check if the pattern of the key is invalid
int invalidPattern(char* argv[], int argc, int keyLength){

    // Allocate memory for the pattern array
    char* pattern = (char*)malloc(keyLength + 1);
    if (pattern == NULL) {
        // Memory allocation failed
        return INVALID;
    }

    // Initialize all positions to '0'
    for (int i = 0; i < keyLength; i++)
        pattern[i] = '0';
    pattern[keyLength] = '\0';

    // Check if the pattern is valid
    for (int i = 2; i < argc; i++) {
        int keyValue = atoi(argv[i]);
        if (keyValue == 0 || keyValue > keyLength || pattern[keyValue - 1] == '1') {
            free(pattern);
            return INVALID;
        }
        pattern[keyValue - 1] = '1';
    }

    // Free dynamically allocated memory
    free(pattern);

    return VALID;
}

// Check if the key is composed of all integers values
int invalidKey(char* argv[], int length){
    for(int i = 2; i < length; i++){
        for(int j = 0; j < strlen(argv[i]); j++){
            if(argv[i][j] < 48 || argv[i][j] > 57)
                return INVALID;
        }
    }
    return VALID;
}

// Check if the length of the key is not an integer (it accepts explicit signs)
int invalidKeyLength(char* keyLength){
    if(strlen(keyLength) == 0)
        return INVALID;
    if(keyLength[0] == '-' || keyLength[0] == '+')
        keyLength++;
    while(*keyLength){
        if(*keyLength < 48 || *keyLength > 57){
            return INVALID;
        }
        keyLength++;
    }
    return VALID;
}

void displayOptions(){
    printf("\tWRITE AN OPTION\n");
    printf("1. encrypt [MESSAGE]\n");
    printf("2. decrypt [MESSAGE]\n");
    printf("3. quit\n\n");
}

int main(int argc, char* argv[]){
    // Check if enough command line arguments
    if(argc <= 2){
        printf("railcipher: Fatal error! Not enough command line arguments.\n");
        error(NOT_ENOUGH_ARGS, "Fatal error! Not enough command line arguments.");
    }

    // Check if the first command line argument is a valid integer (key length)
    if(invalidKeyLength(argv[1])){
        printf("railcipher: Fatal error! First CLA must be a valid integer.\n");
        error(NINT, "Fatal error! First CLA must be a valid integer.");
    }

    // Check if the given key is valid
    if(invalidKey(argv, argc)){
        printf("railcipher: Fatal error! Key must be valid integers (Key Pattern).\n");
        error(NINT, "Fatal error! Key must be valid integers (Key Pattern).");
    }

    // Get the length of the key based if an explicit sign ('+' || '-') is given
    int keyLength;
    if(argv[1][0] == '-' || argv[1][0] == '+'){
        char* substring = &argv[1][1];
        keyLength = atoi(substring);
    }
    else{
        keyLength = atoi(argv[1]);
    }

    // They key length cannot be greater than 26
    if(keyLength > 26){
        printf("railcipher: Fatal error! The encryption key length cannot exceed 26.\n");
        error(EXCEED_KEY_LENGTH, "Fatal error! The encryption key length cannot exceed 26.");
    }

    //Checks if the Key Length matches the length of the Key Pattern
    if(keyLength != (argc - 2)){
        printf("railcipher: Fatal error! Mismatch Key Length and Key Pattern.\n");
        error(MISMATCH_KEY, "Fatal error! Mismatch Key Length and Key Pattern.");
    }

    //array used to check if the key follows a valid pattern
    if(invalidPattern(argv, argc, keyLength)){
        printf("railcipher: Fatal error! The encryption key passed as CLAs is not valid.\n");
        error(WRONG_PATTERN, "Fatal error! The encryption key passed as CLAs is not valid.");
    }

    // command will store the command and plaintext/ciphertext
    char command[MAX_SIZE];

    displayOptions();
    
    // If user enters ctrl + d, the program will end.
    while(fgets(command, MAX_SIZE, stdin) != NULL){
        if (strcmp(command, "\n") == 0){
            printf("Invalid command, try [encrypt/decrypt] [MESSAGE]. Else, type [quit]\n");
            continue;
        }

        char* newline = strchr(command, '\n');
        if (newline != NULL){
            *newline = '\0';
        }

        if(strcmp(command, "quit") == 0)
            break;

        if(invalidCommand(command, keyLength, argv))
            printf("Invalid command, try [encrypt/decrypt] [MESSAGE]. Else, type [quit]\n");

        displayOptions();
    } 

    return 0;
}