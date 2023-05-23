#include <stdio.h>
#include <math.h>

void bannerdisplay() {
    printf(" ██████╗░░██████╗░█████╗░. ░█████╗░██╗░░░░░░██████╗░░█████╗░\n");
    printf(" ██╔══██╗██╔════╝██╔══██╗. ██╔══██╗██║░░░░░██╔════╝░██╔══██╗\n");
    printf(" ██████╔╝╚█████╗░███████║. ███████║██║░░░░░██║░░██╗░██║░░██║\n");
    printf(" ██╔══██╗░╚═══██╗██╔══██║. ██╔══██║██║░░░░░██║░░╚██╗██║░░██║\n");
    printf(" ██║░░██║██████╔╝██║░░██║. ██║░░██║███████╗╚██████╔╝╚█████╔╝\n");
    printf(" ╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝  ╚═╝░░╚═╝╚══════╝░╚═════╝░░╚════╝░\n");
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int isPrime(int n) {
    if (n == 1) {
        return 0; // Not prime
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0; // Not prime
        }
    }

    return 1; // Prime
}

int main() {
    
   
    bannerdisplay();
    printf("\n");
    int p, q;
    int e;
    char message[10001];

    printf("Enter the message: ");
    scanf("%[^\n]%*c", message);

    do {
        printf("Enter the value of p: ");
        scanf("%d", &p);

        printf("Enter the value of q: ");
        scanf("%d", &q);

        if (!isPrime(p) || !isPrime(q)) {
            printf("Both numbers must be prime. Please try again.\n");
        }
    } while (!isPrime(p) || !isPrime(q));

    int n = p * q;
    int phi_n = (p - 1) * (q - 1);

    int choice;

    while (1) {
        printf("For encryption, enter 1\nFor decryption, enter 2\nEnter Choice: ");
        if (scanf("%d", &choice) == 1) {
            if (choice >= 1 && choice <= 2) {
                break;
            } else {
                printf("Invalid input for choice. Please enter a value between 1 and 2.\n");
            }
        } else {
            printf("Invalid input for choice. Please enter a numeric value.\n");
            scanf("%*[^\n]%*c"); 
        }
    }

    switch (choice) {
        case 1: {
            int x;
            do {
                printf("Enter the value of e for encryption: ");
                scanf("%d", &e);
                x = gcd(phi_n, e);
            } while (x != 1);

            printf("CipherText is: ");
            for (int i = 0; message[i] != '\0'; i++) {
                char cipherText = fmod(pow(message[i] - 97, e), n) + 97 - 32;
                printf("%c", cipherText);
            }
            break;
        }
        case 2: {
            int x;
            do {
                printf("Enter the value of e : ");
                scanf("%d", &e);
                x = gcd(phi_n, e);
            } while (x != 1);
            int d = (phi_n + 1) / e;
            printf("PlainText is: ");
            for (int i = 0; message[i] != '\0'; i++) {
                char plainText = fmod(pow(message[i] - 65, d), n) + 65 + 32;
                printf("%c", plainText);
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}