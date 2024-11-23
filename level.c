#include <stdio.h>

void printLevel();

int main() {
    printLevel();
    return 0;
}

void printLevel() {
    int width = 160;  // Escenario amplio
    int height = 15;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Suelo en la parte inferior
            if (y == height - 1) {
                printf("#");
            }
            // Mario
            else if (x == 5 && y == height - 2) {
                printf("8");
            }
            // Bloques de interrogación en distintas posiciones
            else if ((y == 5 && x == 20) || (y == 5 && x == 25) || (y == 5 && x == 30) || //BLOQUES HASTA LA IZQUIERDA
                     (y == 6 && x == 55) || (y == 6 && x == 60) || (y == 6 && x == 65) || //BLOQUES CENTRAL IZQUIERDA
                     (y == 3 && x == 90) || (y == 3 && x == 95) || (y == 3 && x == 100) || //BLOQUES CENTRAL DERECHA
                     (y == 2 && x == 120) || (y == 2 && x == 125) || (y == 2 && x == 130)) { //BLOQUES HASTA LA DERECHA
                printf("?");
            }
            // Plataforma de bloques normales
            else if ((y == 8 && x > 15 && x < 33) || //PLATAFORMA HASTA LA IZQUIERDA
                     (y == 10 && x > 45 && x < 70) || //PLATAFORMA CENTRAL IZQUIERDA
                     (y == 7 && x > 85 && x < 105) || //PLATAFORMA CENTRAL DERECHA
                     (y == 5 && x > 115 && x < 135)) { //PLATAFORMA HASTA LA DERECHA
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
}

