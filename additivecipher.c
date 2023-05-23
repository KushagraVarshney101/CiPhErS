#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void bannerdisplay(){
 printf("           ╔═╗────╔═╗───╔═╦╗─╔╗\n");
 printf("           ║╔╬═╦═╗║═╬═╦╦╣╔╬╬═╣╚╦═╦╦╗\n");
 printf("           ║╚╣╩╣╬╚╬═║╩╣╔╣╚╣║╬║║║╩╣╔╝\n");
 printf("           ╚═╩═╩══╩═╩═╩╝╚═╩╣╔╩╩╩═╩╝\n");
 printf("          ──────────────── ╚╝  \n");
 }

int main()
{
    bannerdisplay();
    int key, n;

    char message[10001];

    printf("Enter the message: ");
    scanf("%[^\n]%*c", message);

    while (true) {
        printf("For encryption, enter 1\nFor decryption, enter 2\nFor brute force, enter 3\nEnter n: ");
        if (scanf("%d", &n) == 1) {
            if (n >= 1 && n <= 3) {
                break;
            } else {
                printf("Invalid input for n. Please enter a value between 1 and 3.\n");
            }
        } else {
            printf("Invalid input for n. Please enter a numeric value.\n");
            scanf("%*[^\n]%*c");  // Clear the input buffer
        }
    }

    if (n == 1 || n == 3) {
        for (int i = 0;; i++) {
            if (message[i] >= 65 && message[i] <= 90) {
                printf("Restart the program and enter all characters in small letters.\n");
                return 0;
            }
            if (message[i] == '\0') {
                break;
            }
        }
    } else if (n == 2) {
        for (int i = 0;; i++) {
            if (message[i] >= 97 && message[i] <= 122) {
                printf("Restart the program and enter all characters in capital letters.\n");
                return 0;
            }
            if (message[i] == '\0') {
                break;
            }
        }
    }

    switch (n) {
        case 1:
            printf("Enter the key: ");
            scanf("%d", &key);
            printf("Cipher Text is: ");
            for (int i = 0;; i++) {
                char cipherText = (((int)message[i] - 97 + key) % 26) + 97 - 32;
                if (message[i] == '\0') {
                    break;
                }
                printf("%c", cipherText);
            }
            printf("\n");
            break;

        case 2:
            printf("Enter the key: ");
            scanf("%d", &key);
            printf("Plain Text is: ");
            for (int i = 0;; i++) {
                char plainText = (((int)message[i] - 65 - key) % 26) + 65 + 32;
                if (message[i] == '\0') {
                    break;
                }
                printf("%c", plainText);
            }
            printf("\n");
            break;

        case 3:
            char ciphertext[10001 + 1],d;
            scanf("%c",&d);
            printf("Enter the CipherText: ");
            scanf("%[^\n]%*c", ciphertext);

            for (int k = 0; k < 26; k++) {
                bool match = true;
                for (int i = 0;; i++) {
                    char CipherText = (((int)message[i] - 97 + k) % 26) + 97 - 32;
                    if (message[i] == '\0' || ciphertext[i] == '\0') {
                        break;
                    }
                    if (CipherText != ciphertext[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    printf("Matching key found: %d\n", k);
                    break;
                }
            }
    }
    return 0;
}