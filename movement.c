#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Para sleep()

void printLevel(int marioX, int marioY, int won);  // Dibuja el nivel con la posición de Mario y mensaje final
void moveMario(char direction, int *marioX, int *marioY, int width, int height, int *jumping, int *jumpHeight, int *won);  // Mueve a Mario

int main() {
    int marioX = 5, marioY = 13;  // Posición inicial de Mario
    char input;  // Para leer las teclas presionadas
    int jumping = 0;  // Indicador de si Mario está saltando
    int jumpHeight = 0;  // Para llevar un seguimiento de la altura del salto
    int won = 0;  // Indicador de si Mario ha ganado

    // Bucle principal del juego
    while (1) {
        system("clear");  // Limpiar la pantalla
        printLevel(marioX, marioY, won);  // Dibuja el nivel con la nueva posición de Mario

        printf("Control: w = Saltar, s = Abajo, a = Izquierda, d = Derecha, e = Subir diagonalmente, q = Salir\n");
        input = getchar();  // Obtener la tecla presionada (presionar 'Enter' después de la tecla)

        // Limpiar el buffer de entrada (para evitar que el 'Enter' quede en el buffer)
        while (getchar() != '\n');

        // Si se presiona 'q', el juego termina
        if (input == 'q') {
            break;  // Salir del bucle si presionas 'q'
        }

        // Mueve a Mario según la tecla presionada
        moveMario(input, &marioX, &marioY, 160, 15, &jumping, &jumpHeight, &won);

        // Si Mario ha ganado, terminar el juego
        if (won) {
            break;
        }
    }

    return 0;
}

// Dibuja el nivel con la posición actual de Mario y el mensaje de victoria
void printLevel(int marioX, int marioY, int won) {
    int width = 160;
    int height = 15;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Suelo en la parte inferior
            if (y == height - 1) {
                printf("#");
            }
            // Mario
            else if (x == marioX && y == marioY) {
                printf("8");
            }
            // Bloques de interrogación en distintas posiciones
            else if ((y == 5 && x == 20) || (y == 5 && x == 25) || (y == 5 && x == 30) ||
                     (y == 6 && x == 55) || (y == 6 && x == 60) || (y == 6 && x == 65) ||
                     (y == 3 && x == 90) || (y == 3 && x == 95) || (y == 3 && x == 100) ||
                     (y == 2 && x == 120) || (y == 2 && x == 125) || (y == 2 && x == 130)) {
                printf("?");
            }
            // Plataforma de bloques normales
            else if ((y == 8 && x > 15 && x < 33) ||
                     (y == 10 && x > 45 && x < 70) ||
                     (y == 7 && x > 85 && x < 105) ||
                     (y == 5 && x > 115 && x < 135)) {
                printf("#");
            }
            // Escalera para el final
            else if (x >= 137 && x < 146 && y >= height - 5 - (x - 140)) {
                printf("#");
            }
            // Poste de la bandera hasta la derecha
            else if (x == 155 && y < height - 1) {
                if (y == 1) {
                    printf(" > ");
                    x += 2;
                } else {
                    printf("|");
                }
            }
            // Espacio vacío para el fondo
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Si Mario ha tocado la bandera, mostrar "You Won!" en la parte derecha
    if (won) {
        printf("\n                          You Won!\n");
    }
}

// Mueve a Mario según la dirección
void moveMario(char direction, int *marioX, int *marioY, int width, int height, int *jumping, int *jumpHeight, int *won) {
    switch (direction) {
        case 'w':  // Saltar
            if (*jumping == 0) {
                // Iniciar el salto, subir 3 bloques
                *jumping = 1;
                *jumpHeight = 3;  // Altura del salto (3 bloques)

                // Subir a la altura del salto
                for (int i = 0; i < *jumpHeight; i++) {
                    (*marioY)--;  // Subir un bloque
                    system("clear");  // Limpiar pantalla
                    printLevel(*marioX, *marioY, *won);  // Dibuja el nivel con la nueva posición de Mario
                    sleep(1);  // Esperar 1 segundo entre cada subida
                }

                sleep(1);  // Mantener a Mario en el aire durante 1 segundo

                // Comienza a caer después de 1 segundo
                for (int i = 0; i < *jumpHeight; i++) {
                    (*marioY)++;  // Baja un bloque
                    system("clear");  // Limpiar pantalla
                    printLevel(*marioX, *marioY, *won);  // Dibuja el nivel con la nueva posición de Mario
                    sleep(1);  // Esperar 1 segundo entre cada bajada
                }

                *jumping = 0;  // Mario ha terminado de saltar
            }
            break;
        case 's':  // Abajo
            // No permitir que Mario baje si ya está en el suelo
            if (*marioY < height - 1 && *marioY < height - 1) {
                (*marioY)++;
            }
            break;
        case 'a':  // Izquierda
            if (*marioX > 0) {
                (*marioX)--;
                (*marioX)--;
                (*marioX)--;
            }
            break;
        case 'd':  // Derecha
            if (*marioX < width - 1) {
                (*marioX)++;
                (*marioX)++;
                (*marioX)++;
            }
            break;
        case 'e':  // Subir diagonalmente hacia la derecha
            // Verificar si Mario está en una escalera (en la parte derecha de la pantalla)
            if (*marioY > 0 && *marioX < width - 1) {
                (*marioX)++;  // Mover a la derecha
                (*marioY)--;  // Subir un bloque
            }
            break;
    }

    // Verificar si Mario ha tocado la bandera
    if (*marioX == 155 && *marioY == 1) {
        *won = 1;  // Mario ha ganado
    }
}
