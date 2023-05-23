 #include <stdio.h>

void printBanner() {
    printf("///////////////////////////////\n");
    printf("//      Multiplicative      //\n");
    printf("//          Cipher           //\n");
    printf("///////////////////////////////\n");
    printf("\n");
}

int findInverse(int k) {
    int mod = 26;
    for (int i = 1; i < mod; i++) {
        if ((k * i) % mod == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    printBanner();

    char message[10001];
    printf("Enter the message: ");
    scanf(" %[^\n]%*c", message);

    int n;
    while (1) {
        printf("For encryption, enter 1\nFor decryption, enter 2\nto Exit, enter 3\nEnter n: ");
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

    if (n == 1) {
        for (int i = 0; message[i] != '\0'; i++) {
            if (message[i] >= 'A' && message[i] <= 'Z') {
                printf("Restart the program and enter all characters in small letters.\n");
                return 0;
            }
        }
    } else if (n == 2) {
        for (int i = 0; message[i] != '\0'; i++) {
            if (message[i] >= 'a' && message[i] <= 'z') {
                printf("Restart the program and enter all characters in capital letters.\n");
                return 0;
            }
        }
    }

    

    switch (n) {
        case 1:
            int k;
            printf("Enter the key: ");
            scanf("%d", &k);
            printf("CipherText is : ");
            for (int i = 0; message[i] != '\0'; i++) {
                message[i] = (((int)message[i] - 'a') * k) % 26 + 'a' - 32;
                printf("%c", message[i]);
            }
            break;

        case 2:
            printf("Enter the key: ");
            scanf("%d", &k);
            printf("PlainText is : ");
            int inverse = findInverse(k);
            if (inverse == -1) {
                printf("Inverse of %d does not exist.\n", k);
                return 0;
            }

            for (int i = 0; message[i] != '\0'; i++) {
                message[i] = (((int)message[i] - 'A') * inverse) % 26 + 'A' + 32;
                printf("%c", message[i]);
            }
            break;
        
        case 3: 
             return 0;
    }

    return 0;
}
