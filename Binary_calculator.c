#include <stdio.h>

// Custom function to get string length
int my_strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Custom function to copy string
void my_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Custom function to concatenate strings
void my_strcat(char* dest, const char* src) {
    int dest_len = my_strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

// Custom function to append a single character to string
void my_strncat_char(char* dest, char c) {
    int len = my_strlen(dest);
    dest[len] = c;
    dest[len + 1] = '\0';
}

// Custom function to convert char to uppercase
char my_toupper(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

// Custom function to reverse a string in place
void my_reverse(char* str) {
    int len = my_strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Function to convert decimal to binary (using fixed size array)
void decimal_to_binary(int num, char* result) {
    if (num == 0) {
        my_strcpy(result, "0");
        return;
    }
    int i = 0;
    while (num > 0) {
        result[i++] = (num % 2) + '0';
        num /= 2;
    }
    result[i] = '\0';
    my_reverse(result);
}

// Function to convert octal to binary (using fixed size array)
void octal_to_binary(const char* octal, char* result) {
    const char* map[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    result[0] = '\0';
    int len = my_strlen(octal);
    for (int i = 0; i < len; i++) {
        if (octal[i] < '0' || octal[i] > '7') {
            my_strcpy(result, "Invalid");
            return;
        }
        int idx = octal[i] - '0';
        my_strcat(result, map[idx]);
    }
    // Remove leading zeros
    int start = 0;
    while (result[start] == '0' && result[start + 1] != '\0') start++;
    if (result[start] == '\0') {
        my_strcpy(result, "0");
    } else {
        char temp[100];
        my_strcpy(temp, result + start);
        my_strcpy(result, temp);
    }
}

// Function to convert hexadecimal to binary (using fixed size array)
void hex_to_binary(const char* hex, char* result) {
    const char* map[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                           "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    result[0] = '\0';
    int len = my_strlen(hex);
    for (int i = 0; i < len; i++) {
        char c = my_toupper(hex[i]);
        int idx;
        if (c >= '0' && c <= '9') idx = c - '0';
        else if (c >= 'A' && c <= 'F') idx = 10 + (c - 'A');
        else {
            my_strcpy(result, "Invalid");
            return;
        }
        my_strcat(result, map[idx]);
    }
    // Remove leading zeros
    int start = 0;
    while (result[start] == '0' && result[start + 1] != '\0') start++;
    if (result[start] == '\0') {
        my_strcpy(result, "0");
    } else {
        char temp[100];
        my_strcpy(temp, result + start);
        my_strcpy(result, temp);
    }
}

// Function to convert binary to decimal
int binary_to_decimal(const char* bin) {
    int dec = 0;
    int len = my_strlen(bin);
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            dec += 1 << (len - 1 - i);
        }
    }
    return dec;
}

// Function to convert binary to octal (using fixed size array)
void binary_to_octal(const char* bin, char* result) {
    int len = my_strlen(bin);
    int pad = (3 - len % 3) % 3;
    char padded[100];
    for (int i = 0; i < pad; i++) padded[i] = '0';
    my_strcpy(padded + pad, bin);
    int new_len = len + pad;
    result[0] = '\0';
    for (int i = 0; i < new_len; i += 3) {
        int val = 0;
        for (int j = 0; j < 3; j++) {
            val = val * 2 + (padded[i + j] - '0');
        }
        char digit = val + '0';
        my_strncat_char(result, digit);
    }
}

// Function to convert binary to hexadecimal (using fixed size array)
void binary_to_hex(const char* bin, char* result) {
    int len = my_strlen(bin);
    int pad = (4 - len % 4) % 4;
    char padded[100];
    for (int i = 0; i < pad; i++) padded[i] = '0';
    my_strcpy(padded + pad, bin);
    int new_len = len + pad;
    result[0] = '\0';
    for (int i = 0; i < new_len; i += 4) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            val = val * 2 + (padded[i + j] - '0');
        }
        char digit;
        if (val < 10) digit = val + '0';
        else digit = 'A' + (val - 10);
        my_strncat_char(result, digit);
    }
}

int main() {
    int op;
    printf("1 To convert number to Binary\n2 To convert Binary Number\nChoose the operation (1 or 2): ");
    scanf("%d", &op);
    if (op == 1) {
        // num_to_binary equivalent
        while (1) {
            int operation;
            printf("1 For Decimal to Binary\n2 For Octal to Binary\n3 For Hexadecimal to Binary\nChoose the operation (1 to 3): ");
            scanf("%d", &operation);
            if (operation == 1) {
                int num;
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                char bin[100];
                decimal_to_binary(num, bin);
                printf("The binary representation of %d is %s\n", num, bin);
            } else if (operation == 2) {
                char octal[100];
                printf("Enter an octal number: ");
                scanf("%s", octal);
                char bin[100];
                octal_to_binary(octal, bin);
                if (bin[0] == 'I') {  // Invalid
                    printf("Invalid octal number\n");
                } else {
                    printf("The binary representation of octal %s is %s\n", octal, bin);
                }
            } else if (operation == 3) {
                char hex[100];
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                char bin[100];
                hex_to_binary(hex, bin);
                if (bin[0] == 'I') {  // Invalid
                    printf("Invalid hexadecimal number\n");
                } else {
                    printf("The binary representation of hexadecimal %s is %s\n", hex, bin);
                }
            } else {
                printf("Invalid operation selected. Please choose 1, 2 or 3.\n");
            }
        }
    } else if (op == 2) {
        // binary_to_number equivalent
        while (1) {
            int operation;
            printf("1 Binary to Decimal\n2 Binary to octal\n3 Binary to Hexadecimal\nChoose the operation (1, 2 or 3): ");
            scanf("%d", &operation);
            char bin_input[100];
            printf("Enter a binary number: ");
            scanf("%s", bin_input);
            // Check if valid binary
            int valid = 1;
            int len = my_strlen(bin_input);
            for (int i = 0; i < len; i++) {
                if (bin_input[i] != '0' && bin_input[i] != '1') {
                    valid = 0;
                    break;
                }
            }
            if (!valid) {
                printf("Invalid input. Please enter a valid binary number.\n");
                continue;
            }
            if (operation == 1) {
                int dec = binary_to_decimal(bin_input);
                printf("The decimal representation of binary %s is %d\n", bin_input, dec);
            } else if (operation == 2) {
                char octal[100];
                binary_to_octal(bin_input, octal);
                printf("The octal representation of binary %s is %s\n", bin_input, octal);
            } else if (operation == 3) {
                char hex[100];
                binary_to_hex(bin_input, hex);
                printf("The hexadecimal representation of binary %s is %s\n", bin_input, hex);
            } else {
                printf("Invalid operation selected. Please choose 1, 2 or 3.\n");
            }
        }
    } else {
        printf("Invalid operation selected. Please choose 1 or 2.\n");
    }
    return 0;
}
