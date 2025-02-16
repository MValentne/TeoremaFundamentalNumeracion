// Este programa convierte un número decimal a binario, hexadecimal y viceversa.

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Incluir para usar atoi

// Función para convertir un número decimal a binario
void decimalToBinary(int num) {
    if (num == 0) {
        printf("Binario: 0\n");
        return;
    }

    int binary[32], i = 0; // Array para almacenar dígitos binarios e índice
    while (num > 0) {
        binary[i++] = num % 2; // Almacenar el resto (dígito binario)
        num /= 2; // Dividir por 2
    }

    printf("Binario: ");
    for (int j = i - 1; j >= 0; j--) { // Imprimir dígitos binarios en orden inverso
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Función para convertir un número binario a decimal
void binaryToDecimal(char binary[]) {
    int decimal = 0, base = 1, length = strlen(binary); // Inicializar resultado decimal, valor base y longitud

    for (int i = length - 1; i >= 0; i--) { // Convertir cada dígito binario a decimal
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Actualizar base (2^n)
    }
    printf("Decimal: %d\n", decimal);
}

// Función para convertir un número decimal a hexadecimal
void decimalToHexadecimal(int num) {
    if (num == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    char hex[32]; // Array para almacenar dígitos hexadecimales
    int i = 0; // Índice
    while (num > 0) {
        int temp = num % 16; // Obtener el resto
        hex[i++] = (temp < 10) ? temp + '0' : temp - 10 + 'A'; // Convertir a dígito hexadecimal
        num /= 16; // Dividir por 16
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) { // Imprimir dígitos hexadecimales en orden inverso
        printf("%c", hex[j]);
    }
    printf("\n");
}

// Función para convertir un número hexadecimal a decimal
void hexadecimalToDecimal(char hex[]) {
    int decimal = 0, base = 1, length = 0; // Inicializar resultado decimal, valor base y longitud
    while (hex[length] != '\0') length++; // Calcular la longitud de la cadena hexadecimal

    for (int i = length - 1; i >= 0; i--) { // Convertir cada dígito hexadecimal a decimal
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base; // Convertir '0'-'9' a 0-9
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base; // Convertir 'A'-'F' a 10-15
        }
        base *= 16; // Actualizar base (16^n)
    }
    printf("Decimal: %d\n", decimal);
}

// Función para convertir un número hexadecimal a binario
void hexadecimalToBinary(char hex[]) {
    int decimal = 0, base = 1, length = 0;
    while (hex[length] != '\0') length++;

    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    decimalToBinary(decimal);
}

// Función para convertir un número binario a hexadecimal
void binaryToHexadecimal(char binary[]) {
    int decimal = 0, base = 1, length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    decimalToHexadecimal(decimal);
}

int main() {
    int choice, number;
    char hex[32], binary[32];

    while (1) { // Bucle infinito para mantener el programa activo
        // Mostrar opciones del menú
        printf("Elija una opción:\n");
        printf("0. Salir\n");
        printf("1. Convertir Decimal a Binario\n");
        printf("2. Convertir Binario a Decimal\n");
        printf("3. Convertir Decimal a Hexadecimal\n");
        printf("4. Convertir Hexadecimal a Decimal\n");
        printf("5. Convertir Hexadecimal a Binario\n");
        printf("6. Convertir Binario a Hexadecimal\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice); // Obtener la elección del usuario

        if (choice == 0) {
            printf("Saliendo del programa.\n");
            break; // Salir del bucle y terminar el programa
        }

        switch (choice) {
            case 1:
                printf("Ingrese un número decimal: ");
                scanf("%d", &number); // Obtener número decimal del usuario
                decimalToBinary(number); // Convertir a binario
                break;
            case 2:
                printf("Ingrese un número binario: ");
                scanf("%s", binary); // Obtener número binario del usuario
                binaryToDecimal(binary); // Convertir a decimal
                break;
            case 3:
                printf("Ingrese un número decimal: ");
                scanf("%d", &number); // Obtener número decimal del usuario
                decimalToHexadecimal(number); // Convertir a hexadecimal
                break;
            case 4:
                printf("Ingrese un número hexadecimal: ");
                scanf("%s", hex); // Obtener número hexadecimal del usuario
                hexadecimalToDecimal(hex); // Convertir a decimal
                break;
            case 5:
                printf("Ingrese un número hexadecimal: ");
                scanf("%s", hex); // Obtener número hexadecimal del usuario
                hexadecimalToBinary(hex); // Convertir a binario
                break;
            case 6:
                printf("Ingrese un número binario: ");
                scanf("%s", binary); // Obtener número binario del usuario
                binaryToHexadecimal(binary); // Convertir a hexadecimal
                break;
            default:
                printf("Elección inválida.\n"); // Manejar elección inválida
                break;
        }
    }

    return 0;
}
