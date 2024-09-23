/* Name: Devansh Chaudhary 
UID: U47398970
Desc: This program defines the decrypt function to decrypt the message according to the encrypted 
message input by the user. The program leverages the string-pointer method. */

#include <stdio.h>

void decrypt(char *input, char *output);

int main() {
    char input[1001];
    char output[1001];

    printf("Enter message: ");
    scanf("%s", input);

    decrypt(input, output); // calling decrypt function 

    printf("Output: %s\n", output);

    return 0;
}

void decrypt(char *input, char *output) {
    char *ptr_input = input;
    char *ptr_output = output;
    int count = 1; // Initialize character count. 

    while (*ptr_input != '\0') {
        *ptr_output = *ptr_input; 

        // Skip the repeated characters according to their count. 
        for (int i = 0; i < count; i++) {
            ptr_input++;
        }

        count++; 
        ptr_output++; 
    }

    // Null-terminate the output string. 
    *ptr_output = '\0';
}
