#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 *
 * by Daniel Andrew
 *
 * caesar.c
 * 
 * command
 *  /caesar <key>
 * input
 *  plaintext: <insert text>
 * output
 *  ciphertext: <ciphered text>
 */

int main(int n, string args[]) {

    if (n != 2) {
        printf("Wrong arguments used!\n");
        printf("Usage: /caesar <key>\n");
        return 1;
    }

    int key = atoi(args[1]);
    
    if (key < 0) {
        printf("Non-positive integer cannot be implemented!\n");
        return 1;
    }

    printf("plaintext: ");
    string text = get_string("");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++) {
        if (islower(text[i])) {
            printf("%c", 97 + (text[i] - 97 + key) % 26);
        } else if (isupper(text[i])) {
            printf("%c", 65 + (text[i] - 65 + key) % 26);
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;
}